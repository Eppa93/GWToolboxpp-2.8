#include "SpamWidget.h"
#include <GWCA\Managers\MapMgr.h>
#include <GWCA\Managers\ChatMgr.h>
#include "GuiUtils.h"
#include "Modules\ToolboxSettings.h"
#include <random>


void SpamWidget::Draw(IDirect3DDevice9* pDevice) {

	if (GW::Map::GetInstanceType() == GW::Constants::InstanceType::Loading) {
		spam = false;
		resigned = false;
		return;
	}

	unsigned int realtime = GW::Map::GetInstanceTime() / 1000;
	unsigned int time = (realtime / 60) % 60;

	if (GW::Map::GetInstanceType() == GW::Constants::InstanceType::Outpost) {

		if (!spam && (time == 12 || time == 22 || time == 42 || time == 59)) {

			std::uniform_real_distribution<double> distribution(1, 39);
			std::random_device rd;
			std::default_random_engine generator(rd());
			int rand = distribution(generator);
			sprintf_s(buf, "%s", "whazzup noobs");
			switch (rand) {
			case 1: sprintf_s(buf, "%s", "doa is for shitpeople"); break;
			case 2: sprintf_s(buf, "%s", "only noobs play doa"); break;
			case 3: sprintf_s(buf, "%s", "uw is for the hard guys"); break;
			case 4: sprintf_s(buf, "%s", "opa come carry us uw"); break;
			case 5: sprintf_s(buf, "%s", "fucking doa noobs really think they're pro?"); break;
			case 6: sprintf_s(buf, "%s", "sup fucking noobs?"); break;
			case 7: sprintf_s(buf, "%s", "FUCK LIGHT!"); break;
			case 8: sprintf_s(buf, "%s", "polska to szumowiny"); break;
			case 9: sprintf_s(buf, "%s", "opa we need your uw carry"); break;
			case 10: sprintf_s(buf, "%s", "opa can u teach me t1 soloq pls"); break;
			case 11: sprintf_s(buf, "%s", "fuck light this retard!"); break;
			case 12: sprintf_s(buf, "%s", "fuck these doa monkeys"); break;
			case 13: sprintf_s(buf, "%s", "fucking uw cancer run"); break;
			case 14: sprintf_s(buf, "%s", "sometimes i shit my pants"); break;
			case 15: sprintf_s(buf, "%s", "only real pros play underworld"); break;
			case 16: sprintf_s(buf, "%s", "only pussys play doa"); break;
			case 17: sprintf_s(buf, "%s", "HEIL OPA!"); break;
			case 18: sprintf_s(buf, "%s", "lets kick light out ally"); break;
			case 19: sprintf_s(buf, "%s", "im the best underworld player in the world anyone need a teach?"); break;
			case 20: sprintf_s(buf, "%s", "whatsup fucking bitches?"); break;
			case 21: sprintf_s(buf, "%s", "my farts smell nice"); break;
			case 22: sprintf_s(buf, "%s", "poland is a shit country"); break;
			case 23: sprintf_s(buf, "%s", "fucking cancer runs only noobs"); break;
			case 24: sprintf_s(buf, "%s", "when do these noobs get better in this game?"); break;
			case 25: sprintf_s(buf, "%s", "lets form uw!"); break;
			case 26: sprintf_s(buf, "%s", "anyone need eblade? i retire"); break;
			case 27: sprintf_s(buf, "%s", "fuck doa"); break;
			case 28: sprintf_s(buf, "%s", "uw for life!"); break;
			case 29: sprintf_s(buf, "%s", "fucking doa monkeys"); break;
			case 30: sprintf_s(buf, "%s", "opa come uw we need carry"); break;
			case 31: sprintf_s(buf, "%s", "lets form uw"); break;
			case 32: sprintf_s(buf, "%s", "brb jerking off"); break;
			case 33: sprintf_s(buf, "%s", "im retarded"); break;
			case 34: sprintf_s(buf, "%s", "its unbelievable!"); break;
			case 35: sprintf_s(buf, "%s", "whatss going on my fellow retards"); break;
			case 36: sprintf_s(buf, "%s", "anyone wanna buy this account for 1k ectos? i retire"); break;
			case 37: sprintf_s(buf, "%s", "my ballsack smells like peanuts"); break;
			case 38: sprintf_s(buf, "%s", "I took a shit into a vase in a museum"); break;
			default: break;

			}

			GW::Chat::SendChat('%', buf);
			spam = true;
		}

		else if (spam && time != 12 && time != 22 && time != 42 && time != 59) {
			spam = false;
		}
	}

	else if (GW::Map::GetMapID() == GW::Constants::MapID::The_Underworld
		&& GW::Map::GetInstanceType() == GW::Constants::InstanceType::Explorable) {
		if (!spam && time == 32) {
			GW::PartyInfo* info = GW::PartyMgr::GetPartyInfo();
			GW::PlayerPartyMemberArray partymembers = info->players;

			sprintf_s(buf, "%s", "no subcon resign this noobs! ty");
			GW::Chat::SendChat('#', buf);

			spam = true;

			if (!resigned && partymembers.size() > 6) {
				GW::Chat::SendChat('/', "resign");
				resigned = true;
			}
		}
	}


}


void SpamWidget::LoadSettings(CSimpleIni* ini) {
	ToolboxWidget::LoadSettings(ini);
	visible = ini->GetBoolValue(Name(), VAR_NAME(visible), true);
}

void SpamWidget::SaveSettings(CSimpleIni* ini) {
	ToolboxWidget::SaveSettings(ini);
}
