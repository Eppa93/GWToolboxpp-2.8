#include "SpamWidget.h"
#include <GWCA\Managers\MapMgr.h>
#include <GWCA\Managers\ChatMgr.h>
#include "GuiUtils.h"
#include <GWCA\Managers\PartyMgr.h> 
#include <GWCA\GameEntities\Party.h>
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
			case 1: sprintf_s(buf, "%s", "Can you go back to doing Dungeons?"); break;
			case 2: sprintf_s(buf, "%s", "I swear this is my last run"); break;
			case 3: sprintf_s(buf, "%s", "Yo, can someone not fail?"); break;
			case 4: sprintf_s(buf, "%s", "I'm weak"); break;
			case 5: sprintf_s(buf, "%s", "Someone cover this noob"); break;
			case 6: sprintf_s(buf, "%s", "Snoop, shut up..."); break;
			case 7: sprintf_s(buf, "%s", "Anja saves the day yet again"); break;
			case 8: sprintf_s(buf, "%s", "polska to szumowiny"); break;
			case 9: sprintf_s(buf, "%s", "Anja, can you ask Marcin to come carry us?"); break;
			case 10: sprintf_s(buf, "%s", "Anja go and scroll Espen please..."); break;
			case 11: sprintf_s(buf, "%s", "Can someone teach Espen how to glitch Mindblades?"); break;
			case 12: sprintf_s(buf, "%s", "Does Marcin have any Pstones left?"); break;
			case 13: sprintf_s(buf, "%s", "I heard if you press alt+f4 it speeds up the run"); break;
			case 14: sprintf_s(buf, "%s", "Sometimes i shit my pants"); break;
			case 15: sprintf_s(buf, "%s", "Could someone help the poor guy?"); break;
			case 16: sprintf_s(buf, "%s", "..."); break;
			case 17: sprintf_s(buf, "%s", "Omar failed Griffs two times in a row!"); break;
			case 18: sprintf_s(buf, "%s", "Could someone do something usefull?"); break;
			case 19: sprintf_s(buf, "%s", "I'm the best underworld player in the world anyone need a teach?"); break;
			case 20: sprintf_s(buf, "%s", "Whatsup bitches?"); break;
			case 21: sprintf_s(buf, "%s", "My farts smell nice"); break;
			case 22: sprintf_s(buf, "%s", "Have anyone seen the t2?"); break;
			case 23: sprintf_s(buf, "%s", "You guys should ask Gloomy for tutorials"); break;
			case 24: sprintf_s(buf, "%s", "When do these noobs get better in this game?"); break;
			case 25: sprintf_s(buf, "%s", "Let's form uw!"); break;
			case 26: sprintf_s(buf, "%s", "Anyone need eblade? i retire"); break;
			case 27: sprintf_s(buf, "%s", "Where do i go?"); break;
			case 28: sprintf_s(buf, "%s", "UW for life!"); break;
			case 29: sprintf_s(buf, "%s", "You donkey"); break;
			case 30: sprintf_s(buf, "%s", "We need carry"); break;
			case 31: sprintf_s(buf, "%s", "Lets form uw"); break;
			case 32: sprintf_s(buf, "%s", "Ether soloed UW"); break;
			case 33: sprintf_s(buf, "%s", "I'm retarded"); break;
			case 34: sprintf_s(buf, "%s", "It's unbelievable!"); break;
			case 35: sprintf_s(buf, "%s", "Whatss going on my fellow retards"); break;
			case 36: sprintf_s(buf, "%s", "Anyone wanna buy this account for 15 Underworld scrolls? i retire"); break;
			case 37: sprintf_s(buf, "%s", "My ballsack smells like peanuts"); break;
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
