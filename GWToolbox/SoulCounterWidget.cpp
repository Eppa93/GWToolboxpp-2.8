#include "SoulCounterWidget.h"

#include <string>
#include <cmath>

#include <GWCA\Constants\Constants.h>
#include <GWCA\Managers\ItemMgr.h>
#include <GWCA\Managers\StoCMgr.h>
#include <GWCA\Managers\PartyMgr.h>

#include "GWToolbox.h"
#include "GuiUtils.h"
#include "Modules\ToolboxSettings.h"

#include <GWCA\Managers\AgentMgr.h>
#include <GWCA\Managers\MapMgr.h>


void SoulCounterWidget::Draw(IDirect3DDevice9* pDevice) {
	if (!visible) return;



	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
	ImGui::SetNextWindowSize(ImVec2(250.0f, 90.0f), ImGuiSetCond_FirstUseEver);
	if (ImGui::Begin(Name(), nullptr, GetWinFlags())) {
		static char Soul_Counter[32];

		int souls_count = 0;

		if (show_mobcount) {
			GW::AgentArray agents = GW::Agents::GetAgentArray();
			GW::Agent* player = GW::Agents::GetPlayer();
			if (GW::Map::GetInstanceType() != GW::Constants::InstanceType::Loading
				&& agents.valid()
				&& player != nullptr) {

				for (unsigned int i = 0; i < agents.size(); ++i) {
					GW::Agent* agent = agents[i];
					if (agent == nullptr) continue; // ignore nothings
					if (agent->Allegiance != 0x3) continue; // ignore non-hostiles
					if (agent->GetIsDead()) continue; // ignore dead 
					float sqrd = GW::Agents::GetSqrDistance(player->pos, agent->pos);

					if (agent->PlayerNumber == GW::Constants::ModelID::DoA::SoulTormentor
						|| agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilSoulTormentor) {
						if (sqrd < 1400.0f * 1400.0f) souls_count++;
					}
				}
			}
		}

		snprintf(Soul_Counter, 32, "%02d", souls_count);

		ImVec2 cur;

		// 'Soul Counter'
		ImGui::PushFont(GuiUtils::GetFont(GuiUtils::f16));
		cur = ImGui::GetCursorPos();
		ImGui::SetCursorPos(ImVec2(cur.x + 1, cur.y + 1));
		ImGui::TextColored(ImColor(0, 0, 0), "Soul Counter");
		ImGui::SetCursorPos(cur);
		ImGui::Text("Soul Counter");
		ImGui::PopFont();

		// Counts
		ImGui::PushFont(GuiUtils::GetFont(GuiUtils::f48));
		cur = ImGui::GetCursorPos();
		ImGui::SetCursorPos(ImVec2(cur.x + 2, cur.y + 2));
		ImGui::TextColored(ImColor(0, 0, 0), Soul_Counter);
		ImGui::SetCursorPos(cur);
		if (use_coloring) {
			if (souls_count <= 20) ImGui::TextColored(ImColor(255, 0, 0), Soul_Counter);
			if (souls_count > 20 && souls_count <= 40) ImGui::TextColored(ImColor(255, 200, 0), Soul_Counter);
			if (souls_count > 40) ImGui::TextColored(ImColor(55, 255, 0), Soul_Counter);
		}
		else {
			ImGui::TextColored(ImColor(255, 255, 255), Soul_Counter);
		}

		ImGui::Text(Soul_Counter);
		ImGui::PopFont();

	}
	ImGui::End();
	ImGui::PopStyleColor();
}

void SoulCounterWidget::LoadSettings(CSimpleIni* ini) {
	ToolboxWidget::LoadSettings(ini);
	use_coloring = ini->GetBoolValue(Name(), VAR_NAME(use_coloring), true);
}

void SoulCounterWidget::SaveSettings(CSimpleIni* ini) {
	ToolboxWidget::SaveSettings(ini);
	ini->SetBoolValue(Name(), VAR_NAME(use_coloring), use_coloring);
}

void SoulCounterWidget::DrawSettingInternal() {
	ImGui::Checkbox("Use Coloring?", &use_coloring);
	ImGui::ShowHelp("Displays the amount of souls in red when u have small amount of souls, yellow for decent and green for good");
}
