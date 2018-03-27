#include "DomainOfAnguishTimer.h"

#include <GWCA\Managers\AgentMgr.h>
#include <GWCA\Managers\MapMgr.h>
#include <GWCA\Managers\ChatMgr.h>

#include "GuiUtils.h"
#include "GWToolbox.h"

#include "Modules\ToolboxSettings.h"
#include <Modules\Resources.h>

#include <GWCA\Constants\Constants.h>

void DomainOfAnguishTimer::Initialize() {
	ToolboxWindow::Initialize();
}

void DomainOfAnguishTimer::Terminate() {
	ToolboxWindow::Terminate();
}

void DomainOfAnguishTimer::Draw(IDirect3DDevice9* pDevice) {
	if (!visible) return;

	ImGui::SetNextWindowPosCenter(ImGuiSetCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(300, 0), ImGuiSetCond_FirstUseEver);
	if (ImGui::Begin(Name(), GetVisiblePtr(), GetWinFlags())) {

		static char citytime[32] = "";
		snprintf(citytime, 32, "%d:%02d:%02d", doaQ[0] / (60 * 60), (doaQ[0] / 60) % 60, doaQ[0] % 60);
		static char veiltime[32] = "";
		snprintf(veiltime, 32, "%d:%02d:%02d", doaQ[1] / (60 * 60), (doaQ[1] / 60) % 60, doaQ[1] % 60);
		static char gloomtime[32] = "";
		snprintf(gloomtime, 32, "%d:%02d:%02d", doaQ[2] / (60 * 60), (doaQ[2] / 60) % 60, doaQ[2] % 60);
		static char foundrytime[32] = "";
		snprintf(foundrytime, 32, "%d:%02d:%02d", doaQ[3] / (60 * 60), (doaQ[3] / 60) % 60, doaQ[3] % 60);

		//ImGui::PushItemWidth(-1.0f);
		//ImGui::PopItemWidth();		

		ImGui::Text("City: ");
		ImGui::SameLine(ImGui::GetWindowContentRegionWidth() / 2);
		ImGui::InputText("", citytime, 32, ImGuiInputTextFlags_ReadOnly);

		ImGui::Text("Veil: ");
		ImGui::SameLine(ImGui::GetWindowContentRegionWidth() / 2);
		ImGui::InputText("", veiltime, 32, ImGuiInputTextFlags_ReadOnly);

		ImGui::Text("Gloom: ");
		ImGui::SameLine(ImGui::GetWindowContentRegionWidth() / 2);
		ImGui::InputText("", gloomtime, 32, ImGuiInputTextFlags_ReadOnly);

		ImGui::Text("Foundry: ");
		ImGui::SameLine(ImGui::GetWindowContentRegionWidth() / 2);
		ImGui::InputText("", foundrytime, 32, ImGuiInputTextFlags_ReadOnly);



		if (ImGui::Button("Send", ImVec2(180.0f, 0))) {

			static char line0[32];
			static char line1[32];
			static char line2[32];
			static char line3[32];

			snprintf(line0, 32, "City: %d:%02d:%02d", doaQ[0] / (60 * 60), (doaQ[0] / 60) % 60, doaQ[0] % 60);
			snprintf(line1, 32, "Veil: %d:%02d:%02d", doaQ[1] / (60 * 60), (doaQ[1] / 60) % 60, doaQ[1] % 60);
			snprintf(line2, 32, "Gloom: %d:%02d:%02d", doaQ[2] / (60 * 60), (doaQ[2] / 60) % 60, doaQ[2] % 60);
			snprintf(line3, 32, "Foundry: %d:%02d:%02d", doaQ[3] / (60 * 60), (doaQ[3] / 60) % 60, doaQ[3] % 60);

			GW::Chat::SendChat('#', line0);
			GW::Chat::SendChat('#', line1);
			GW::Chat::SendChat('#', line2);
			GW::Chat::SendChat('#', line3);

		}

		ImGui::End();
	}


	if (GW::Map::GetInstanceType() == GW::Constants::InstanceType::Explorable
		&& GW::Map::GetMapID() == GW::Constants::MapID::Domain_of_Anguish) {

		if (reset) {
			for (int i = 0; i < 4; ++i) {
				doaQ[i] = 0;
			}
			reset = false;
		}

		GW::AgentArray agents = GW::Agents::GetAgentArray();

		if (!agents.valid()) return;
		for (unsigned int i = 0; i < agents.size(); ++i) {
			GW::Agent* agent = agents[i];
			if (agent == nullptr) continue; //Skip shit
			for (int j = 0; j < 4; ++j) {
				if (doaQ[j] == 0) {
					if (agent->X == doaChestX[j] && agent->Y == doaChestY[j] && agent->Owner == 12) {
						doaQ[j] = GW::Map::GetInstanceTime() / 1000;
						break;
					}
				}
			}
		}
	}
	else {
		reset = true;
	}

}

void DomainOfAnguishTimer::LoadSettings(CSimpleIni* ini) {
	ToolboxWindow::LoadSettings(ini);
}

void DomainOfAnguishTimer::SaveSettings(CSimpleIni* ini) {
	ToolboxWindow::SaveSettings(ini);
}