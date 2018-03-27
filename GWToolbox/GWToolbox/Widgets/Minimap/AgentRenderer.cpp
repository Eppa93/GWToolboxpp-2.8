#include "AgentRenderer.h"

#include <GWCA\Managers\AgentMgr.h>
#include <GWCA\Managers\MapMgr.h>

#include "GuiUtils.h"
#include <Defines.h>

void AgentRenderer::LoadSettings(CSimpleIni* ini, const char* section) {
	//Player
	color_Player1 = Colors::Load(ini, section, VAR_NAME(color_Player1), 0x30DCDCDC);
	color_Player2 = Colors::Load(ini, section, VAR_NAME(color_Player2), 0x30DCDCDC);
	color_Player3 = Colors::Load(ini, section, VAR_NAME(color_Player3), 0x30DCDCDC);
	color_Player4 = Colors::Load(ini, section, VAR_NAME(color_Player4), 0x30DCDCDC);
	color_Player5 = Colors::Load(ini, section, VAR_NAME(color_Player5), 0x30DCDCDC);
	color_Player6 = Colors::Load(ini, section, VAR_NAME(color_Player6), 0x30DCDCDC);
	color_Player7 = Colors::Load(ini, section, VAR_NAME(color_Player7), 0x30DCDCDC);
	color_Player8 = Colors::Load(ini, section, VAR_NAME(color_Player8), 0x30DCDCDC);
	//Spirits NPCs
	color_agent_modifier = Colors::Load(ini, section, VAR_NAME(color_agent_modifier), 0x001E1E1E);
	color_eoe = Colors::Load(ini, section, VAR_NAME(color_eoe), 0x3200FF00);
	color_CoT = Colors::Load(ini, section, VAR_NAME(color_CoT), 0x00DCDCDC);
	color_TC = Colors::Load(ini, section, VAR_NAME(color_TC), 0x1EDCDCDC);
	color_Reapers = Colors::Load(ini, section, VAR_NAME(color_Reapers), 0x5000CD00);
	color_Escort = Colors::Load(ini, section, VAR_NAME(color_Escort), 0x30DCDCDC);
	color_PitsSoul = Colors::Load(ini, section, VAR_NAME(color_PitsSoul), 0x30DCDCDC);
	color_Griffons = Colors::Load(ini, section, VAR_NAME(color_Griffons), 0x50DCDCDC);
	color_Snakes = Colors::Load(ini, section, VAR_NAME(color_Snakes), 0x50DCDCDC);
	color_Rastigan = Colors::Load(ini, section, VAR_NAME(color_Rastigan), 0x50DCDCDC);
	color_Forgemaster = Colors::Load(ini, section, VAR_NAME(color_Forgemaster), 0x50DCDCDC);
	color_qz = Colors::Load(ini, section, VAR_NAME(color_qz), 0x320000FF);
	color_winnowing = Colors::Load(ini, section, VAR_NAME(color_winnowing), 0x32005A78);
	color_target = Colors::Load(ini, section, VAR_NAME(color_target), 0xFFFFFF00);
	color_player = Colors::Load(ini, section, VAR_NAME(color_player), 0xFFFF8000);
	color_player_dead = Colors::Load(ini, section, VAR_NAME(color_player_dead), 0x64FF8000);
	color_signpost = Colors::Load(ini, section, VAR_NAME(color_signpost), 0xFF0000C8);
	color_item = Colors::Load(ini, section, VAR_NAME(color_item), 0xFF0000F0);
	color_hostile = Colors::Load(ini, section, VAR_NAME(color_hostile), 0xFFF00000);
	color_hostile_damaged = Colors::Load(ini, section, VAR_NAME(color_hostile_damaged), 0xFF800000);
	color_hostile_dead = Colors::Load(ini, section, VAR_NAME(color_hostile_dead), 0xFF320000);
	color_neutral = Colors::Load(ini, section, VAR_NAME(color_neutral), 0xFF0000DC);
	color_ally = Colors::Load(ini, section, VAR_NAME(color_ally), 0xFF00B300);
	color_ally_npc = Colors::Load(ini, section, VAR_NAME(color_ally_npc), 0xFF99FF99);
	color_ally_spirit = Colors::Load(ini, section, VAR_NAME(color_ally_spirit), 0xFF00B400);
	color_ally_minion = Colors::Load(ini, section, VAR_NAME(color_ally_minion), 0xFF008060);
	color_ally_dead = Colors::Load(ini, section, VAR_NAME(color_ally_dead), 0x64006400);
	//--- EOTN ---
	color_StormcloudIncubus = Colors::Load(ini, section, VAR_NAME(color_StormcloudIncubus), 0xFFFFFF00);
	color_StormcloudIncubus_Damaged = Colors::Load(ini, section, VAR_NAME(color_StormcloudIncubus_Damaged), 0xFFFFFF00);
	//--- Underworld ---
	color_DeadCollector = Colors::Load(ini, section, VAR_NAME(color_DeadCollector), 0xFF0090FF);
	color_DeadCollector_Damaged = Colors::Load(ini, section, VAR_NAME(color_DeadCollector_Damaged), 0xFF0022D2);
	color_DeadThresher = Colors::Load(ini, section, VAR_NAME(color_DeadThresher), 0xFFF00000);
	color_DeadThresher_Damaged = Colors::Load(ini, section, VAR_NAME(color_DeadThresher_Damaged), 0xFF800000);
	color_ObsidianBehemoth = Colors::Load(ini, section, VAR_NAME(color_ObsidianBehemoth), 0xFFF00000);
	color_ObsidianBehemoth_Damaged = Colors::Load(ini, section, VAR_NAME(color_ObsidianBehemoth_Damaged), 0xFF800000);
	color_ObsidianGuardian = Colors::Load(ini, section, VAR_NAME(color_ObsidianGuardian), 0xFFF00000);
	color_ObsidianGuardian_Damaged = Colors::Load(ini, section, VAR_NAME(color_ObsidianGuardian_Damaged), 0xFF800000);
	color_KeeperOfSouls = Colors::Load(ini, section, VAR_NAME(color_KeeperOfSouls), 0xFFF00000);
	color_KeeperOfSouls_Damaged = Colors::Load(ini, section, VAR_NAME(color_KeeperOfSouls_Damaged), 0xFF800000);
	color_TerrorwebDryder = Colors::Load(ini, section, VAR_NAME(color_TerrorwebDryder), 0xFFF00000);
	color_TerrorwebDryder_Damaged = Colors::Load(ini, section, VAR_NAME(color_TerrorwebDryder_Damaged), 0xFF800000);
	color_TerrorwebDryderSilver = Colors::Load(ini, section, VAR_NAME(color_TerrorwebDryderSilver), 0xFFF00000);
	color_TerrorwebDryderSilver_Damaged = Colors::Load(ini, section, VAR_NAME(color_TerrorwebDryderSilver_Damaged), 0xFF800000);
	color_SmiteCrawler = Colors::Load(ini, section, VAR_NAME(color_SmiteCrawler), 0xFF0090FF);
	color_SmiteCrawler_Damaged = Colors::Load(ini, section, VAR_NAME(color_SmiteCrawler_Damaged), 0xFF0022D2);
	color_BanishedDreamRider = Colors::Load(ini, section, VAR_NAME(color_BanishedDreamRider), 0xFF0090FF);
	color_BanishedDreamRider_Damaged = Colors::Load(ini, section, VAR_NAME(color_BanishedDreamRider_Damaged), 0xFF0022D2);
	color_MindbladeSpectre = Colors::Load(ini, section, VAR_NAME(color_MindbladeSpectre), 0xFFC87841);
	color_MindbladeSpectre_Damaged = Colors::Load(ini, section, VAR_NAME(color_MindbladeSpectre_Damaged), 0xFFB4642D);
	color_TorturedSpirit = Colors::Load(ini, section, VAR_NAME(color_TorturedSpirit), 0xFFF00000);
	color_TorturedSpirit_Damaged = Colors::Load(ini, section, VAR_NAME(color_TorturedSpirit_Damaged), 0xFF800000);
	color_WailingLord = Colors::Load(ini, section, VAR_NAME(color_WailingLord), 0xFFF00000);
	color_WailingLord_Damaged = Colors::Load(ini, section, VAR_NAME(color_WailingLord_Damaged), 0xFF800000);
	color_BladedAatxe = Colors::Load(ini, section, VAR_NAME(color_BladedAatxe), 0xFFF00000);
	color_BladedAatxe_Damaged = Colors::Load(ini, section, VAR_NAME(color_BladedAatxe_Damaged), 0xFF800000);
	color_GraspingDarkness = Colors::Load(ini, section, VAR_NAME(color_GraspingDarkness), 0xFFF00000);
	color_GraspingDarkness_Damaged = Colors::Load(ini, section, VAR_NAME(color_GraspingDarkness_Damaged), 0xFF800000);
	color_DyingNightmare = Colors::Load(ini, section, VAR_NAME(color_Nightmare), 0xFFA400D6);
	color_DyingNightmare_Damaged = Colors::Load(ini, section, VAR_NAME(color_DyingNightmare_Damaged), 0xFF8200BE);
	color_ChargedBlackness = Colors::Load(ini, section, VAR_NAME(color_ChargedBlackness), 0xFF1E1E1E);
	color_ChargedBlackness_Damaged = Colors::Load(ini, section, VAR_NAME(color_ChargedBlackness_Damaged), 0xFF000000);
	color_ColdfireNight = Colors::Load(ini, section, VAR_NAME(color_ColdfireNight), 0xFFF00000);
	color_ColdfireNight_Damaged = Colors::Load(ini, section, VAR_NAME(color_ColdfireNight_Damaged), 0xFF800000);
	color_StalkingNight = Colors::Load(ini, section, VAR_NAME(color_StalkingNight), 0xFFF00000);
	color_StalkingNight_Damaged = Colors::Load(ini, section, VAR_NAME(color_StalkingNight_Damaged), 0xFF800000);
	color_ChampionOfDhuum = Colors::Load(ini, section, VAR_NAME(color_ChampionOfDhuum), 0xFFF00000);
	color_ChampionOfDhuum_Damaged = Colors::Load(ini, section, VAR_NAME(color_ChampionOfDhuum_Damaged), 0xFF800000);
	color_MinionOfDhuum = Colors::Load(ini, section, VAR_NAME(color_MinionOfDhuum), 0xFFF00000);
	color_MinionOfDhuum_Damaged = Colors::Load(ini, section, VAR_NAME(color_MinionOfDhuum_Damaged), 0xFF800000);
	color_SkeletonOfDhuum = Colors::Load(ini, section, VAR_NAME(color_SkeletonOfDhuum), 0xFFFFFF00);
	color_SkeletonOfDhuum_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletonOfDhuum_Damaged), 0xFFC8C8800);
	color_SkeletonOfDhuum_Under50 = Colors::Load(ini, section, VAR_NAME(color_SkeletonOfDhuum_Under50), 0xFC969600);
	color_SkeletonOfDhuum_Under25 = Colors::Load(ini, section, VAR_NAME(color_SkeletonOfDhuum_Under25), 0xFC9696FF);
	color_ChainedSoul = Colors::Load(ini, section, VAR_NAME(color_ChainedSoul), 0xFFF00000);
	color_chainedSoul_Damaged = Colors::Load(ini, section, VAR_NAME(color_chainedSoul_Damaged), 0xFF800000);
	color_TerrorwebQueen = Colors::Load(ini, section, VAR_NAME(color_TerrorwebQueen), 0xFFFF66CC);
	color_TerrorwebQueen_Damaged = Colors::Load(ini, section, VAR_NAME(color_TerrorwebQueen_Damaged), 0xFF9650B4);
	color_Slayer = Colors::Load(ini, section, VAR_NAME(color_Slayer), 0xFFF00000);
	color_Slayer_Damaged = Colors::Load(ini, section, VAR_NAME(color_Slayer_Damaged), 0xFF800000);
	color_FourHorseman = Colors::Load(ini, section, VAR_NAME(color_FourHorseman), 0xFFF00000);
	color_FourHorseman_Damaged = Colors::Load(ini, section, VAR_NAME(color_FourHorseman_Damaged), 0xFF800000);
	color_Dhuum = Colors::Load(ini, section, VAR_NAME(color_Dhuum), 0xFFF00000);
	color_Dhuum_Damaged = Colors::Load(ini, section, VAR_NAME(color_Dhuum_Damaged), 0xFF800000);
	//--- Domain of Anguish ---
	//Margos
	color_MargoniteAnurKaya = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurKaya), 0xFFF00000);
	color_MargoniteAnurKaya_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurKaya_Damaged), 0xFF800000);
	color_MargoniteAnurDabi = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurDabi), 0xFFF00000);
	color_MargoniteAnurDabi_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurDabi_Damaged), 0xFF800000);
	color_MargoniteAnurSu = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurSu), 0xFFF00000);
	color_MargoniteAnurSu_damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurSu_damaged), 0xFF800000);
	color_MargoniteAnurKi = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurKi), 0xFFFF66CC);
	color_MargoniteAnurKi_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurKi_Damaged), 0xFF9650B4);
	color_MargoniteAnurVu = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurVu), 0xFFF00000);
	color_MargoniteAnurVu_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurVu_Damaged), 0xFF800000);
	color_MargoniteAnurTuk = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurTuk), 0xFFCC6600);
	color_MargoniteAnurTuk_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurTuk_Damaged), 0xFF963200);
	color_MargoniteAnurRuk = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurRuk), 0xFFF00000);
	color_MargoniteAnurRuk_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurRuk_Damaged), 0xFF800000);
	color_MargoniteAnurRund = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurRund), 0xFFF00000);
	color_MargoniteAnurRund_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurRund_Damaged), 0xFF800000);
	color_MargoniteAnurMank = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurMank), 0xFFF00000);
	color_MargoniteAnurMank_Damaged = Colors::Load(ini, section, VAR_NAME(color_MargoniteAnurMank_Damaged), 0xFF800000);
	//Stygians
	color_StygianHunger = Colors::Load(ini, section, VAR_NAME(color_StygianHunger), 0xFFA400D6);
	color_StygianHunger_Damaged = Colors::Load(ini, section, VAR_NAME(color_StygianHunger_Damaged), 0xFF8200BE);
	color_StygianBrute = Colors::Load(ini, section, VAR_NAME(color_StygianBrute), 0xFFF00000);
	color_StygianBrute_Damaged = Colors::Load(ini, section, VAR_NAME(color_StygianBrute_Damaged), 0xFF800000);
	color_StygianGolem = Colors::Load(ini, section, VAR_NAME(color_StygianGolem), 0xFFF00000);
	color_StygianGolem_Damaged = Colors::Load(ini, section, VAR_NAME(color_StygianGolem_Damaged), 0xFF800000);
	color_StygianHorror = Colors::Load(ini, section, VAR_NAME(color_StygianHorror), 0xFFF00000);
	color_StygianHorror_Damaged = Colors::Load(ini, section, VAR_NAME(color_StygianHorror_Damaged), 0xFF800000);
	color_StygianFiend = Colors::Load(ini, section, VAR_NAME(color_StygianFiend), 0xFF0090FF);
	color_StygianFiend_Damaged = Colors::Load(ini, section, VAR_NAME(color_StygianFiend_Damaged), 0xFF0078F);
	//Torms
	color_MindTormentor = Colors::Load(ini, section, VAR_NAME(color_MindTormentor), 0xFFF00000);
	color_MindTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_MindTormentor_Damaged), 0xFF800000);
	color_SoulTormentor = Colors::Load(ini, section, VAR_NAME(color_SoulTormentor), 0xFFFFFF00);
	color_SoulTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_SoulTormentor_Damaged), 0xFFC8C8800);
	color_SoulTormentor_Under50 = Colors::Load(ini, section, VAR_NAME(color_SoulTormentor_Under50), 0xFC969600);
	color_WaterTormentor = Colors::Load(ini, section, VAR_NAME(color_WaterTormentor), 0xFFCCFFFF);
	color_WaterTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_WaterTormentor_Damaged), 0xFFB4C8C8);
	color_HeartTormentor = Colors::Load(ini, section, VAR_NAME(color_HeartTormentor), 0xFFF00000);
	color_HeartTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_HeartTormentor_Damaged), 0xFF800000);
	color_FleshTormentor = Colors::Load(ini, section, VAR_NAME(color_FleshTormentor), 0xFFF00000);
	color_FleshTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_FleshTormentor_Damaged), 0xFF800000);
	color_SpiritTormentor = Colors::Load(ini, section, VAR_NAME(color_SpiritTormentor), 0xFF00FFFF);
	color_SpiritTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_SpiritTormentor_Damaged), 0xFF0078FF);
	color_EarthTormentor = Colors::Load(ini, section, VAR_NAME(color_EarthTormentor), 0xFFF00000);
	color_EarthTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_EarthTormentor_Damaged), 0xFF800000);
	color_SanityTormentor = Colors::Load(ini, section, VAR_NAME(color_SanityTormentor), 0xFF00FFFF);
	color_SanityTormentor_Damaged = Colors::Load(ini, section, VAR_NAME(color_SanityTormentor_Damaged), 0xFF0078FF);
	color_TheDarkness = Colors::Load(ini, section, VAR_NAME(color_TheDarkness), 0xFFCCFFFF);
	color_TheDarkness_Damaged = Colors::Load(ini, section, VAR_NAME(color_TheDarkness_Damaged), 0xFFB4C8C8);
	//Titans
	color_MiseryTitan = Colors::Load(ini, section, VAR_NAME(color_MiseryTitan), 0xFFF00000);
	color_MisaryTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_MisaryTitan_Damaged), 0xFF800000);
	color_RageTitan = Colors::Load(ini, section, VAR_NAME(color_RageTitan), 0xFFF00000);
	color_RageTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_RageTitan_Damaged), 0xFF800000);
	color_DementiaTitan = Colors::Load(ini, section, VAR_NAME(color_DementiaTitan), 0xFFF00000);
	color_DementiaTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_DementiaTitan_Damaged), 0xFF800000);
	color_AnguishTitan = Colors::Load(ini, section, VAR_NAME(color_AnguishTitan), 0xFFF00000);
	color_AnguishTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_AnguishTitan_Damaged), 0xFF800000);
	color_DespairTitan = Colors::Load(ini, section, VAR_NAME(color_DespairTitan), 0xFFF00000);
	color_DespairTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_DespairTitan_Damaged), 0xFF800000);
	color_FuryTitan = Colors::Load(ini, section, VAR_NAME(color_FuryTitan), 0xFFF00000);
	color_FuryTitan_Damaged = Colors::Load(ini, section, VAR_NAME(color_FuryTitan_Damaged), 0xFF800000);
	//Dryder
	color_TorturewebDryder = Colors::Load(ini, section, VAR_NAME(color_TorturewebDryder), 0xFFCC6600);
	color_TorturewebDryder_Damaged = Colors::Load(ini, section, VAR_NAME(color_TorturewebDryder_Damaged), 0xFF8C4600);
	//Ghost
	color_GreatDreamRider = Colors::Load(ini, section, VAR_NAME(color_GreatDreamRider), 0xFFF00000);
	color_GreatDreamRider_Damaged = Colors::Load(ini, section, VAR_NAME(color_GreatDreamRider_Damaged), 0xFF800000);
	//Boss-like foes
	color_BlackBeastOfArgh = Colors::Load(ini, section, VAR_NAME(color_BlackBeastOfArgh), 0xFFF00000);
	color_BlackBeastOfArgh_Damaged = Colors::Load(ini, section, VAR_NAME(color_BlackBeastOfArgh_Damaged), 0xFF800000);
	color_SmotheringTendril = Colors::Load(ini, section, VAR_NAME(color_SmotheringTendril), 0xFFF00000);
	color_SmotheringTendril_Damaged = Colors::Load(ini, section, VAR_NAME(color_SmotheringTendril_Damaged), 0xFF800000);
	color_Fury = Colors::Load(ini, section, VAR_NAME(color_Fury), 0xFFF00000);
	color_Fury_Damaged = Colors::Load(ini, section, VAR_NAME(color_Fury_Damaged), 0xFF800000);
	color_LordJadoth = Colors::Load(ini, section, VAR_NAME(color_LordJadoth), 0xFFF00000);
	color_LordJadoth_Damaged = Colors::Load(ini, section, VAR_NAME(color_LordJadoth_Damaged), 0xFF800000);
	//--- Fissure of Woe ---
	//Arachnids
	color_ArmoredCaveSpider = Colors::Load(ini, section, VAR_NAME(color_ArmoredCaveSpider), 0xFFF00000);
	color_ArmoredCaveSpider_Damaged = Colors::Load(ini, section, VAR_NAME(color_ArmoredCaveSpider_Damaged), 0xFF800000);
	//Dragons
	color_ObsidianFurnanceDrake = Colors::Load(ini, section, VAR_NAME(color_ObsidianFurnanceDrake), 0xFFF00000);
	color_ObsidianFurnanceDrake_Damaged = Colors::Load(ini, section, VAR_NAME(color_ObsidianFurnanceDrake_Damaged), 0xFF800000);
	//Dryders
	color_DoubtersDryder = Colors::Load(ini, section, VAR_NAME(color_DoubtersDryder), 0xFFF00000);
	color_DoubtersDryder_Damaged = Colors::Load(ini, section, VAR_NAME(color_DoubtersDryder_Damaged), 0xFF800000);
	//Elementals
	color_ShardWolf = Colors::Load(ini, section, VAR_NAME(color_ShardWolf), 0xFFFFFF00);
	color_ShardWolf_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShardWolf_Damaged), 0xFFC8C8800);
	//Ghosts
	color_TraitorousTempleGuard = Colors::Load(ini, section, VAR_NAME(color_TraitorousTempleGuard), 0xFFF00000);
	color_TraitorousTempleGuard_Damaged = Colors::Load(ini, section, VAR_NAME(color_TraitorousTempleGuard_Damaged), 0xFF800000);
	color_TraitorousTempleGuard2 = Colors::Load(ini, section, VAR_NAME(color_TraitorousTempleGuard2), 0xFFF00000);
	color_TraitorousTempleGuard3 = Colors::Load(ini, section, VAR_NAME(color_TraitorousTempleGuard3), 0xFF800000);
	color_Banshee = Colors::Load(ini, section, VAR_NAME(color_Banshee), 0xFFF00000);
	color_Banshee_Damaged = Colors::Load(ini, section, VAR_NAME(color_Banshee_Damaged), 0xFF800000);
	//Hydras
	color_MahgoHydra = Colors::Load(ini, section, VAR_NAME(color_MahgoHydra), 0xFFF00000);
	color_MahgoHydra_Damaged = Colors::Load(ini, section, VAR_NAME(color_MahgoHydra_Damaged), 0xFF800000);
	//Plants
	color_SnarlingDriftwood = Colors::Load(ini, section, VAR_NAME(color_SnarlingDriftwood), 0xFFF00000);
	color_SnarlingDriftwood_Damaged = Colors::Load(ini, section, VAR_NAME(color_SnarlingDriftwood_Damaged), 0xFF800000);
	color_SpiritWood = Colors::Load(ini, section, VAR_NAME(color_SpiritWood), 0xFFF00000);
	color_SpiritWood_Damaged = Colors::Load(ini, section, VAR_NAME(color_SpiritWood_Damaged), 0xFF800000);
	color_SeedOfCorruption = Colors::Load(ini, section, VAR_NAME(color_SeedOfCorruption), 0xFF0090FF);
	color_SeedOfCorruption_Damaged = Colors::Load(ini, section, VAR_NAME(color_SeedOfCorruption_Damaged), 0xFF0040FF);
	color_SpiritShepherd = Colors::Load(ini, section, VAR_NAME(color_SpiritShepherd), 0xFFF00000);
	color_SpiritShepherd_Damaged = Colors::Load(ini, section, VAR_NAME(color_SpiritShepherd_Damaged), 0xFF800000);
	//Rider
	color_SmokeWalker = Colors::Load(ini, section, VAR_NAME(color_SmokeWalker), 0xFFF00000);
	color_SmokeWalker_Damaged = Colors::Load(ini, section, VAR_NAME(color_SmokeWalker_Damaged), 0xFF800000);
	//Nightmares
	color_ShadowPatrol = Colors::Load(ini, section, VAR_NAME(color_ShadowPatrol), 0xFFF00000);
	color_ShadowPatrol_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowPatrol_Damaged), 0xFF800000);
	color_Abyssal = Colors::Load(ini, section, VAR_NAME(color_Abyssal), 0xFF0090FF);
	color_Abyssal_Damaged = Colors::Load(ini, section, VAR_NAME(color_Abyssal), 0xFF0040FF);
	color_ShadowOverLord = Colors::Load(ini, section, VAR_NAME(color_ShadowOverLord), 0xFFF00000);
	color_ShadowOverLord_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowOverLord_Damaged), 0xFF800000);
	color_ShadowWarrior = Colors::Load(ini, section, VAR_NAME(color_ShadowWarrior), 0xFFF00000);
	color_ShadowWarrior_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowWarrior_damaged), 0xFF800000);
	color_ShadowRanger = Colors::Load(ini, section, VAR_NAME(color_ShadowRanger), 0xFFF00000);
	color_ShadowRanger_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowRanger_Damaged), 0xFF800000);
	color_ShadowMonk = Colors::Load(ini, section, VAR_NAME(color_ShadowMonk), 0xFFF00000);
	color_ShadowMonk_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowMonk_Damaged), 0xFF800000);
	color_ShadowBeast = Colors::Load(ini, section, VAR_NAME(color_ShadowBeast), 0xFFF00000);
	color_ShadowBeast_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowBeast_Damaged), 0xFF800000);
	color_ShadowMesmer = Colors::Load(ini, section, VAR_NAME(color_ShadowMesmer), 0xFFF00000);
	color_ShadowMesmer_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowMesmer_Damaged), 0xFF800000);
	color_ShadowElemental = Colors::Load(ini, section, VAR_NAME(color_ShadowElemental), 0xFFF00000);
	color_ShadowElemental_Damaged = Colors::Load(ini, section, VAR_NAME(color_ShadowElemental_Damaged), 0xFF800000);
	//Skale
	color_AncientSkale = Colors::Load(ini, section, VAR_NAME(color_AncientSkale), 0xFFF00000);
	color_AncientSkale_Damaged = Colors::Load(ini, section, VAR_NAME(color_AncientSkale_Damaged), 0xFF800000);
	//Skeletons
	color_SkeletalBerserker = Colors::Load(ini, section, VAR_NAME(color_SkeletalBerserker), 0xFFF00000);
	color_SkeletalBerserker_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletalBerserker_Damaged), 0xFF800000);
 	color_SkeletalImpaler = Colors::Load(ini, section, VAR_NAME(color_SkeletalImpaler), 0xFFF00000);
	color_SkeletalImpaler_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletalImpaler_Damaged), 0xFF800000);
	color_SkeletalBond = Colors::Load(ini, section, VAR_NAME(color_SkeletalBond), 0xFFF00000);
	color_SkeletalBond_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletalBond_Damaged), 0xFF800000);
	color_SkeletalEtherBreaker = Colors::Load(ini, section, VAR_NAME(color_SkeletalEtherBreaker), 0xFFF00000);
	color_SkeletalEtherBreaker_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletalEtherBreaker_Damaged), 0xFF800000);
	color_SkeletalIcehand = Colors::Load(ini, section, VAR_NAME(color_SkeletalIcehand), 0xFFF00000);
	color_SkeletalIcehand_Damaged = Colors::Load(ini, section, VAR_NAME(color_SkeletalIcehand_Damaged), 0xFF800000);
	//Worms
	color_RockBorerWorm = Colors::Load(ini, section, VAR_NAME(color_RockBorerWorm), 0xFFF00000);
	color_RockBorerWorm_Damaged = Colors::Load(ini, section, VAR_NAME(color_RockBorerWorm_Damaged), 0xFF800000);
	//Wurms
	color_InfernalWurm = Colors::Load(ini, section, VAR_NAME(color_InfernalWurm), 0xFFF00000);
	color_InfernalWurm_Damaged = Colors::Load(ini, section, VAR_NAME(color_InfernalWurm_Damaged), 0xFF800000);
	//Zombies
	color_DragonLich = Colors::Load(ini, section, VAR_NAME(color_DragonLich), 0xFFF00000);
	color_DragonLich_Damaged = Colors::Load(ini, section, VAR_NAME(color_DragonLich_Damaged), 0xFF800000);
	//Bosses
	color_Menzies = Colors::Load(ini, section, VAR_NAME(color_Menzies), 0xFFF00000);
	color_Menzies_Damaged = Colors::Load(ini, section, VAR_NAME(color_Menzies_Damaged), 0xFF800000);
	color_LordKhobay = Colors::Load(ini, section, VAR_NAME(color_LordKhobay), 0xFFF00000);
	color_LordKhobay_Damaged = Colors::Load(ini, section, VAR_NAME(color_LordKhobay_Damaged), 0xFF800000);

	//--- Urgoz ---
	color_HoppingVampire = Colors::Load(ini, section, VAR_NAME(color_HoppingVampire), 0xFFFFFF00);

	size_default = (float)ini->GetDoubleValue(section, VAR_NAME(size_default), 75.0);
	size_player = (float)ini->GetDoubleValue(section, VAR_NAME(size_player), 100.0);
	size_signpost = (float)ini->GetDoubleValue(section, VAR_NAME(size_signpost), 50.0);
	size_item = (float)ini->GetDoubleValue(section, VAR_NAME(size_item), 25.0);
	size_boss = (float)ini->GetDoubleValue(section, VAR_NAME(size_boss), 125.0);
	size_minion = (float)ini->GetDoubleValue(section, VAR_NAME(size_minion), 50.0);
	size_MVP = (float)ini->GetDoubleValue(section, VAR_NAME(size_MVP), 105.0);

	Invalidate();
}

void AgentRenderer::SaveSettings(CSimpleIni* ini, const char* section) const {
	//Player
	Colors::Save(ini, section, VAR_NAME(color_Player1), color_Player1);
	Colors::Save(ini, section, VAR_NAME(color_Player2), color_Player2);
	Colors::Save(ini, section, VAR_NAME(color_Player3), color_Player3);
	Colors::Save(ini, section, VAR_NAME(color_Player4), color_Player4);
	Colors::Save(ini, section, VAR_NAME(color_Player5), color_Player5);
	Colors::Save(ini, section, VAR_NAME(color_Player6), color_Player6);
	Colors::Save(ini, section, VAR_NAME(color_Player7), color_Player7);
	Colors::Save(ini, section, VAR_NAME(color_Player8), color_Player8);
	//Spirits NPCs
	Colors::Save(ini, section, VAR_NAME(color_agent_modifier), color_agent_modifier);
	Colors::Save(ini, section, VAR_NAME(color_eoe), color_eoe);
	Colors::Save(ini, section, VAR_NAME(color_CoT), color_CoT);
	Colors::Save(ini, section, VAR_NAME(color_TC), color_TC);
	Colors::Save(ini, section, VAR_NAME(color_Reapers), color_Reapers);
	Colors::Save(ini, section, VAR_NAME(color_Escort), color_Escort);
	Colors::Save(ini, section, VAR_NAME(color_PitsSoul), color_PitsSoul);
	Colors::Save(ini, section, VAR_NAME(color_Griffons), color_Griffons);
	Colors::Save(ini, section, VAR_NAME(color_Snakes), color_Snakes);
	Colors::Save(ini, section, VAR_NAME(color_Rastigan), color_Rastigan);
	Colors::Save(ini, section, VAR_NAME(color_Forgemaster), color_Forgemaster);
	Colors::Save(ini, section, VAR_NAME(color_qz), color_qz);
	Colors::Save(ini, section, VAR_NAME(color_winnowing), color_winnowing);
	Colors::Save(ini, section, VAR_NAME(color_target), color_target);
	Colors::Save(ini, section, VAR_NAME(color_player), color_player);
	Colors::Save(ini, section, VAR_NAME(color_player_dead), color_player_dead);
	Colors::Save(ini, section, VAR_NAME(color_signpost), color_signpost);
	Colors::Save(ini, section, VAR_NAME(color_item), color_item);
	Colors::Save(ini, section, VAR_NAME(color_hostile), color_hostile);
	Colors::Save(ini, section, VAR_NAME(color_hostile_damaged), color_hostile_damaged);
	Colors::Save(ini, section, VAR_NAME(color_hostile_dead), color_hostile_dead);
	Colors::Save(ini, section, VAR_NAME(color_neutral), color_neutral);
	Colors::Save(ini, section, VAR_NAME(color_ally), color_ally);
	Colors::Save(ini, section, VAR_NAME(color_ally_npc), color_ally_npc);
	Colors::Save(ini, section, VAR_NAME(color_ally_spirit), color_ally_spirit);
	Colors::Save(ini, section, VAR_NAME(color_ally_minion), color_ally_minion);
	Colors::Save(ini, section, VAR_NAME(color_ally_dead), color_ally_dead);
	//--- EOTN ---
	Colors::Save(ini, section, VAR_NAME(color_StormcloudIncubus), color_StormcloudIncubus);
	Colors::Save(ini, section, VAR_NAME(color_StormcloudIncubus_Damaged), color_StormcloudIncubus_Damaged);
	//--- Underworld ---
	Colors::Save(ini, section, VAR_NAME(color_DeadCollector), color_DeadCollector);
	Colors::Save(ini, section, VAR_NAME(color_DeadCollector_Damaged), color_DeadCollector_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_DeadThresher), color_DeadThresher);
	Colors::Save(ini, section, VAR_NAME(color_DeadThresher_Damaged), color_DeadThresher_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ObsidianBehemoth), color_ObsidianBehemoth);
	Colors::Save(ini, section, VAR_NAME(color_ObsidianBehemoth_Damaged), color_ObsidianBehemoth_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ObsidianGuardian), color_ObsidianGuardian);
	Colors::Save(ini, section, VAR_NAME(color_ObsidianGuardian_Damaged), color_ObsidianGuardian_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_KeeperOfSouls), color_KeeperOfSouls);
	Colors::Save(ini, section, VAR_NAME(color_KeeperOfSouls_Damaged), color_KeeperOfSouls_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebDryder), color_TerrorwebDryder);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebDryder_Damaged), color_TerrorwebDryder_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebDryderSilver), color_TerrorwebDryderSilver);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebDryderSilver_Damaged), color_TerrorwebDryderSilver_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SmiteCrawler), color_SmiteCrawler);
	Colors::Save(ini, section, VAR_NAME(color_SmiteCrawler_Damaged), color_SmiteCrawler_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_BanishedDreamRider), color_BanishedDreamRider);
	Colors::Save(ini, section, VAR_NAME(color_BanishedDreamRider_Damaged), color_BanishedDreamRider_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MindbladeSpectre), color_MindbladeSpectre);
	Colors::Save(ini, section, VAR_NAME(color_MindbladeSpectre_Damaged), color_MindbladeSpectre_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_TorturedSpirit), color_TorturedSpirit);
	Colors::Save(ini, section, VAR_NAME(color_TorturedSpirit_Damaged), color_TorturedSpirit_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_WailingLord), color_WailingLord);
	Colors::Save(ini, section, VAR_NAME(color_WailingLord_Damaged), color_WailingLord_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_BladedAatxe), color_BladedAatxe);
	Colors::Save(ini, section, VAR_NAME(color_BladedAatxe_Damaged), color_BladedAatxe_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_GraspingDarkness), color_GraspingDarkness);
	Colors::Save(ini, section, VAR_NAME(color_GraspingDarkness_Damaged), color_GraspingDarkness_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_Nightmare), color_DyingNightmare);
	Colors::Save(ini, section, VAR_NAME(color_DyingNightmare_Damaged), color_DyingNightmare_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ChargedBlackness), color_ChargedBlackness);
	Colors::Save(ini, section, VAR_NAME(color_ChargedBlackness_Damaged), color_ChargedBlackness_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ColdfireNight), color_ColdfireNight);
	Colors::Save(ini, section, VAR_NAME(color_ColdfireNight_Damaged), color_ColdfireNight_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_StalkingNight), color_StalkingNight);
	Colors::Save(ini, section, VAR_NAME(color_StalkingNight_Damaged), color_StalkingNight_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ChampionOfDhuum), color_ChampionOfDhuum);
	Colors::Save(ini, section, VAR_NAME(color_ChampionOfDhuum_Damaged), color_ChampionOfDhuum_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MinionOfDhuum), color_MinionOfDhuum);
	Colors::Save(ini, section, VAR_NAME(color_MinionOfDhuum_Damaged), color_MinionOfDhuum_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletonOfDhuum), color_SkeletonOfDhuum);
	Colors::Save(ini, section, VAR_NAME(color_SkeletonOfDhuum_Damaged), color_SkeletonOfDhuum_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletonOfDhuum_Under50), color_SkeletonOfDhuum_Under50);
	Colors::Save(ini, section, VAR_NAME(color_SkeletonOfDhuum_Under25), color_SkeletonOfDhuum_Under25);
	Colors::Save(ini, section, VAR_NAME(color_ChainedSoul), color_ChainedSoul);
	Colors::Save(ini, section, VAR_NAME(color_chainedSoul_Damaged), color_chainedSoul_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebQueen), color_TerrorwebQueen);
	Colors::Save(ini, section, VAR_NAME(color_TerrorwebQueen_Damaged), color_TerrorwebQueen_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_Slayer), color_Slayer);
	Colors::Save(ini, section, VAR_NAME(color_Slayer_Damaged), color_Slayer_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_FourHorseman), color_FourHorseman);
	Colors::Save(ini, section, VAR_NAME(color_FourHorseman_Damaged), color_FourHorseman_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_Dhuum), color_Dhuum);
	Colors::Save(ini, section, VAR_NAME(color_Dhuum_Damaged), color_Dhuum_Damaged);
	//--- Domain of Anguish ---
	//Margos
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurKaya), color_MargoniteAnurKaya);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurKaya_Damaged), color_MargoniteAnurKaya_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurDabi), color_MargoniteAnurDabi);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurDabi_Damaged), color_MargoniteAnurDabi_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurSu), color_MargoniteAnurSu);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurSu_Damaged), color_MargoniteAnurSu_damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurKi), color_MargoniteAnurKi);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurKi_Damaged), color_MargoniteAnurKi_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurVu), color_MargoniteAnurVu);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurVu_Damaged), color_MargoniteAnurVu_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurTuk), color_MargoniteAnurTuk);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurTuk_Damaged), color_MargoniteAnurTuk_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurRuk), color_MargoniteAnurRuk);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurRuk_Damaged), color_MargoniteAnurRuk_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurRund), color_MargoniteAnurRund);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurRund_Damaged), color_MargoniteAnurRund_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurMank), color_MargoniteAnurMank);
	Colors::Save(ini, section, VAR_NAME(color_MargoniteAnurMank_Damaged), color_MargoniteAnurMank_Damaged);
	//Stygians
	Colors::Save(ini, section, VAR_NAME(color_StygianHunger), color_StygianHunger);
	Colors::Save(ini, section, VAR_NAME(color_StygianHunger_Damaged), color_StygianHunger_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_StygianBrute), color_StygianBrute);
	Colors::Save(ini, section, VAR_NAME(color_StygianBrute_Damaged), color_StygianBrute_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_StygianGolem), color_StygianGolem);
	Colors::Save(ini, section, VAR_NAME(color_StygianGolem_Damaged), color_StygianGolem_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_StygianHorror), color_StygianHorror);
	Colors::Save(ini, section, VAR_NAME(color_StygianHorror_Damaged), color_StygianHorror_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_StygianFiend), color_StygianFiend);
	Colors::Save(ini, section, VAR_NAME(color_StygianFiend_Damaged), color_StygianFiend_Damaged);
	//torments
	Colors::Save(ini, section, VAR_NAME(color_MindTormentor), color_MindTormentor);
	Colors::Save(ini, section, VAR_NAME(color_MindTormentor_Damaged), color_MindTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SoulTormentor), color_SoulTormentor);
	Colors::Save(ini, section, VAR_NAME(color_SoulTormentor_Damaged), color_SoulTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SoulTormentor_Under50), color_SoulTormentor_Under50);
	Colors::Save(ini, section, VAR_NAME(color_WaterTormentor), color_WaterTormentor);
	Colors::Save(ini, section, VAR_NAME(color_WaterTormentor_Damaged), color_WaterTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_HeartTormentor), color_HeartTormentor);
	Colors::Save(ini, section, VAR_NAME(color_HeartTormentor_Damaged), color_HeartTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_FleshTormentor), color_FleshTormentor);
	Colors::Save(ini, section, VAR_NAME(color_FleshTormentor_Damaged), color_FleshTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SpiritTormentor), color_SpiritTormentor);
	Colors::Save(ini, section, VAR_NAME(color_SpiritTormentor_Damaged), color_SpiritTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_EarthTormentor), color_EarthTormentor);
	Colors::Save(ini, section, VAR_NAME(color_EarthTormentor_Damaged), color_EarthTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SanityTormentor), color_SanityTormentor);
	Colors::Save(ini, section, VAR_NAME(color_SanityTormentor_Damaged), color_SanityTormentor_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_TheDarkness), color_TheDarkness);
	Colors::Save(ini, section, VAR_NAME(color_TheDarkness_Damaged), color_TheDarkness_Damaged);
	//Titans
	Colors::Save(ini, section, VAR_NAME(color_MiseryTitan), color_MiseryTitan);
	Colors::Save(ini, section, VAR_NAME(color_MisaryTitan_Damaged), color_MisaryTitan_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_RageTitan), color_RageTitan);
	Colors::Save(ini, section, VAR_NAME(color_RageTitan_Damaged), color_RageTitan_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_DementiaTitan), color_DementiaTitan);
	Colors::Save(ini, section, VAR_NAME(color_DementiaTitan_Damaged), color_DementiaTitan_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_AnguishTitan), color_AnguishTitan);
	Colors::Save(ini, section, VAR_NAME(color_AnguishTitan_Damaged), color_AnguishTitan_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_DespairTitan), color_DespairTitan);
	Colors::Save(ini, section, VAR_NAME(color_DespairTitan_Damaged), color_DespairTitan_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_FuryTitan), color_FuryTitan);
	Colors::Save(ini, section, VAR_NAME(color_FuryTitan_Damaged), color_FuryTitan_Damaged);
	//Dryder
	Colors::Save(ini, section, VAR_NAME(color_TorturewebDryder), color_TorturewebDryder);
	Colors::Save(ini, section, VAR_NAME(color_TorturewebDryder_Damaged), color_TorturewebDryder_Damaged);
	//Ghost
	Colors::Save(ini, section, VAR_NAME(color_GreatDreamRider), color_GreatDreamRider);
	Colors::Save(ini, section, VAR_NAME(color_GreatDreamRider_Damaged), color_GreatDreamRider_Damaged);
	//bosslike
	Colors::Save(ini, section, VAR_NAME(color_BlackBeastOfArgh), color_BlackBeastOfArgh);
	Colors::Save(ini, section, VAR_NAME(color_BlackBeastOfArgh_Damaged), color_BlackBeastOfArgh_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SmotheringTendril), color_SmotheringTendril);
	Colors::Save(ini, section, VAR_NAME(color_SmotheringTendril_Damaged), color_SmotheringTendril_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_Fury), color_Fury);
	Colors::Save(ini, section, VAR_NAME(color_Fury_Damaged), color_Fury_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_LordJadoth), color_LordJadoth);
	Colors::Save(ini, section, VAR_NAME(color_LordJadoth_Damaged), color_LordJadoth_Damaged);
	//--- Fissue of Woe ---
	//Arachnids
	Colors::Save(ini, section, VAR_NAME(color_ArmoredCaveSpider), color_ArmoredCaveSpider);
	Colors::Save(ini, section, VAR_NAME(color_ArmoredCaveSpider_Damaged), color_ArmoredCaveSpider_Damaged);
	//Dragons
	Colors::Save(ini, section, VAR_NAME(color_ObsidianFurnanceDrake), color_ObsidianFurnanceDrake);
	Colors::Save(ini, section, VAR_NAME(color_ObsidianFurnanceDrake_Damaged), color_ObsidianFurnanceDrake_Damaged);
	//Dryders
	Colors::Save(ini, section, VAR_NAME(color_DoubtersDryder), color_DoubtersDryder);
	Colors::Save(ini, section, VAR_NAME(color_DoubtersDryder_Damaged), color_DoubtersDryder_Damaged);
	//Elementals
	Colors::Save(ini, section, VAR_NAME(color_ShardWolf), color_ShardWolf);
	Colors::Save(ini, section, VAR_NAME(color_ShardWolf_Damaged), color_ShardWolf_Damaged);
	//Ghosts
	Colors::Save(ini, section, VAR_NAME(color_TraitorousTempleGuard), color_TraitorousTempleGuard);
	Colors::Save(ini, section, VAR_NAME(color_TraitorousTempleGuard2), color_TraitorousTempleGuard2);
	Colors::Save(ini, section, VAR_NAME(color_TraitorousTempleGuard3), color_TraitorousTempleGuard3);
	Colors::Save(ini, section, VAR_NAME(color_TraitorousTempleGuard_Damaged), color_TraitorousTempleGuard_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_Banshee), color_Banshee);
	Colors::Save(ini, section, VAR_NAME(color_Banshee_Damaged), color_Banshee_Damaged);
	//Hydras
	Colors::Save(ini, section, VAR_NAME(color_MahgoHydra), color_MahgoHydra);
	Colors::Save(ini, section, VAR_NAME(color_MahgoHydra_Damaged), color_MahgoHydra_Damaged);
	//Plants
	Colors::Save(ini, section, VAR_NAME(color_SnarlingDriftwood), color_SnarlingDriftwood);
	Colors::Save(ini, section, VAR_NAME(color_SnarlingDriftwood_Damaged), color_SnarlingDriftwood_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SpiritWood), color_SpiritWood);
	Colors::Save(ini, section, VAR_NAME(color_SpiritWood_Damaged), color_SpiritWood_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SeedOfCorruption), color_SeedOfCorruption);
	Colors::Save(ini, section, VAR_NAME(color_SeedOfCorruption_Damaged), color_SeedOfCorruption_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SpiritShepherd), color_SpiritShepherd);
	Colors::Save(ini, section, VAR_NAME(color_SpiritShepherd_Damaged), color_SpiritShepherd_Damaged);
	//Riders
	Colors::Save(ini, section, VAR_NAME(color_SmokeWalker), color_SmokeWalker);
	Colors::Save(ini, section, VAR_NAME(color_SmokeWalker_Damaged), color_SmokeWalker_Damaged);
	//Nightmares
	Colors::Save(ini, section, VAR_NAME(color_Abyssal), color_Abyssal);
	Colors::Save(ini, section, VAR_NAME(color_Abyssal_Damaged), color_Abyssal_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowOverLord), color_ShadowOverLord);
	Colors::Save(ini, section, VAR_NAME(color_ShadowOverLord_Damaged), color_ShadowOverLord_Damaged);
	
	Colors::Save(ini, section, VAR_NAME(color_ShadowPatrol), color_ShadowPatrol);
	Colors::Save(ini, section, VAR_NAME(color_ShadowPatrol_Damaged), color_ShadowPatrol_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowWarrior), color_ShadowWarrior);
	Colors::Save(ini, section, VAR_NAME(color_ShadowWarrior_Damaged), color_ShadowWarrior_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowRanger), color_ShadowRanger);
	Colors::Save(ini, section, VAR_NAME(color_ShadowRanger_Damaged), color_ShadowRanger_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowMonk), color_ShadowMonk);
	Colors::Save(ini, section, VAR_NAME(color_ShadowMonk_Damaged), color_ShadowMonk_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowBeast), color_ShadowBeast);
	Colors::Save(ini, section, VAR_NAME(color_ShadowBeast_Damaged), color_ShadowBeast_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowMesmer), color_ShadowMesmer);
	Colors::Save(ini, section, VAR_NAME(color_ShadowMesmer_Damaged), color_ShadowMesmer_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_ShadowElemental), color_ShadowElemental);
	Colors::Save(ini, section, VAR_NAME(color_ShadowElemental_Damaged), color_ShadowElemental_Damaged);
	//Skale
	Colors::Save(ini, section, VAR_NAME(color_AncientSkale), color_AncientSkale);
	Colors::Save(ini, section, VAR_NAME(color_AncientSkale_Damaged), color_AncientSkale_Damaged);
	//Skeletons
	Colors::Save(ini, section, VAR_NAME(color_SkeletalBerserker), color_SkeletalBerserker);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalBerserker_Damaged), color_SkeletalBerserker_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalImpaler), color_SkeletalImpaler);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalImpaler_Damaged), color_SkeletalImpaler_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalBond), color_SkeletalBond);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalBond_Damaged), color_SkeletalBond_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalEtherBreaker), color_SkeletalEtherBreaker);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalEtherBreaker_Damaged), color_SkeletalEtherBreaker_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalIcehand), color_SkeletalIcehand);
	Colors::Save(ini, section, VAR_NAME(color_SkeletalIcehand_Damaged), color_SkeletalIcehand_Damaged);
	//Worms
	Colors::Save(ini, section, VAR_NAME(color_RockBorerWorm), color_RockBorerWorm);
	Colors::Save(ini, section, VAR_NAME(color_RockBorerWorm_Damaged), color_RockBorerWorm_Damaged);
	//Wurms
	Colors::Save(ini, section, VAR_NAME(color_InfernalWurm), color_InfernalWurm);
	Colors::Save(ini, section, VAR_NAME(color_InfernalWurm_Damaged), color_InfernalWurm_Damaged);
	//Zombies
	Colors::Save(ini, section, VAR_NAME(color_DragonLich), color_DragonLich);
	Colors::Save(ini, section, VAR_NAME(color_DragonLich_Damaged), color_DragonLich_Damaged);
	//Bosses
	Colors::Save(ini, section, VAR_NAME(color_Menzies), color_Menzies);
	Colors::Save(ini, section, VAR_NAME(color_Menzies_Damaged), color_Menzies_Damaged);
	Colors::Save(ini, section, VAR_NAME(color_LordKhobay), color_LordKhobay);
	Colors::Save(ini, section, VAR_NAME(color_LordKhobay_Damaged), color_LordKhobay_Damaged);

	//--- Urgoz ---
	Colors::Save(ini, section, VAR_NAME(color_HoppingVampire), color_HoppingVampire);

	ini->SetDoubleValue(section, VAR_NAME(size_default), size_default);
	ini->SetDoubleValue(section, VAR_NAME(size_player), size_player);
	ini->SetDoubleValue(section, VAR_NAME(size_signpost), size_signpost);
	ini->SetDoubleValue(section, VAR_NAME(size_item), size_item);
	ini->SetDoubleValue(section, VAR_NAME(size_boss), size_boss);
	ini->SetDoubleValue(section, VAR_NAME(size_minion), size_minion);
	ini->SetDoubleValue(section, VAR_NAME(size_MVP), size_MVP);
}

void AgentRenderer::DrawSettings() {
	if (ImGui::SmallButton("Restore Defaults")) {
		//Player
		color_Player1 = 0x30DCDCDC;
		color_Player2 = 0x30DCDCDC;
		color_Player3 = 0x30DCDCDC;
		color_Player4 = 0x30DCDCDC;
		color_Player5 = 0x30DCDCDC;
		color_Player6 = 0x30DCDCDC;
		color_Player7 = 0x30DCDCDC;
		color_Player8 = 0x30DCDCDC;
		//Spitits NPCs
		color_agent_modifier = 0x001E1E1E;
		color_eoe = 0x3200FF00;
		color_CoT = 0x00DCDCDC;
		color_TC = 0x1EDCDCDC;
		color_Reapers = 0x5000CD00;
		color_Escort = 0x30DCDCDC;
		color_PitsSoul = 0x30DCDCDC;
		color_Griffons = 0x50DCDCDC;
		color_Forgemaster = 0x50DCDCDC;
		color_Rastigan = 0x50DCDCDC;
		color_Snakes = 0x50DCDCDC;
		color_Forgemaster = 0x50DCDCDC;
		color_qz = 0x320000FF;
		color_winnowing = 0x32005A78;
		color_target = 0xFFFFFF00;
		color_player = 0xFFFF8000;
		color_player_dead = 0x64FF8000;
		color_signpost = 0xFF0000C8;
		color_item = 0xFF0000F0;
		color_hostile = 0xFFF00000;
		color_hostile_damaged = 0xFF800000;
		color_hostile_dead = 0xFF320000;
		color_neutral = 0xFF0000DC;
		color_ally = 0xFF00B300;
		color_ally_npc = 0xFF99FF99;
		color_ally_spirit = 0xFF00B400;
		color_ally_minion = 0xFF008060;
		color_ally_dead = 0x64006400;
		//--- EOTN ---
		color_StormcloudIncubus = 0xFFFFFF00;
		color_StormcloudIncubus_Damaged = 0xFFFFFF00;
		//--- Underworld ---
		color_DeadCollector = 0xFF0090FF;
		color_DeadCollector_Damaged = 0xFF0022D2;
		color_DeadThresher = 0xFFF00000;
		color_DeadThresher_Damaged = 0xFF800000;
		color_ObsidianBehemoth = 0xFFF00000;
		color_ObsidianBehemoth_Damaged = 0xFF800000;
		color_ObsidianGuardian = 0xFFF00000;
		color_ObsidianGuardian_Damaged = 0xFF800000;
		color_KeeperOfSouls = 0xFFF00000;
		color_KeeperOfSouls_Damaged = 0xFF800000;
		color_TerrorwebDryder = 0xFFF00000;
		color_TerrorwebDryder_Damaged = 0xFF800000;
		color_TerrorwebDryderSilver = 0xFFF00000;
		color_TerrorwebDryderSilver_Damaged = 0xFF800000;
		color_SmiteCrawler = 0xFF0090FF;
		color_SmiteCrawler_Damaged = 0xFF0022D2;
		color_BanishedDreamRider = 0xFF0090FF;
		color_BanishedDreamRider_Damaged = 0xFF0022D2;
		color_MindbladeSpectre = 0xFFC87841;
		color_MindbladeSpectre_Damaged = 0xFFB4642D;
		color_TorturedSpirit = 0xFFF00000;
		color_TorturedSpirit_Damaged = 0xFF800000;
		color_WailingLord = 0xFFF00000;
		color_WailingLord_Damaged = 0xFF800000;
		color_BladedAatxe = 0xFFF00000;
		color_BladedAatxe_Damaged = 0xFF800000;
		color_GraspingDarkness = 0xFFF00000;
		color_GraspingDarkness_Damaged = 0xFF800000;
		color_DyingNightmare = 0xFFA400D6;
		color_DyingNightmare_Damaged = 0xFF8200BE;
		color_ChargedBlackness = 0xFF1E1E1E;
		color_ChargedBlackness_Damaged = 0xFF000000;
		color_ColdfireNight = 0xFFF00000;
		color_ColdfireNight_Damaged = 0xFF800000;
		color_StalkingNight = 0xFFF00000;
		color_StalkingNight_Damaged = 0xFF800000;
		color_ChampionOfDhuum = 0xFF800000;
		color_ChampionOfDhuum_Damaged = 0xFF800000;
		color_MinionOfDhuum = 0xFF800000;
		color_MinionOfDhuum_Damaged = 0xFF800000;
		color_SkeletonOfDhuum = 0xFFFFFF00;
		color_SkeletonOfDhuum_Damaged = 0xFCC8C800;
		color_SkeletonOfDhuum_Under50 = 0xFC969664;
		color_SkeletonOfDhuum_Under25 = 0xFC9696FF;
		color_ChainedSoul = 0xFFF00000;
		color_chainedSoul_Damaged = 0xFF800000;
		color_TerrorwebQueen = 0xFFFF66CC;
		color_TerrorwebQueen_Damaged = 0xFF9650B4;
		color_Slayer = 0xFFF00000;
		color_Slayer_Damaged = 0xFF800000;
		color_FourHorseman = 0xFFF00000;
		color_FourHorseman_Damaged = 0xFF800000;
		color_Dhuum = 0xFF800000;
		color_Dhuum_Damaged = 0xFF800000;
		//--- Domain of Anguish ---
		//Margonites
		color_MargoniteAnurKaya = 0xFFF00000;
		color_MargoniteAnurKaya_Damaged = 0xFF800000;
		color_MargoniteAnurDabi = 0xFFF00000;
		color_MargoniteAnurDabi_Damaged = 0xFF800000;
		color_MargoniteAnurSu = 0xFFF00000;
		color_MargoniteAnurSu_damaged = 0xFF800000;
		color_MargoniteAnurKi = 0xFFFF66CC;
		color_MargoniteAnurKi_Damaged = 0xFF9650B4;
		color_MargoniteAnurVu = 0xFFF00000;
		color_MargoniteAnurVu_Damaged = 0xFF800000;
		color_MargoniteAnurTuk = 0xFFCC6600;
		color_MargoniteAnurTuk_Damaged = 0xFF963200;
		color_MargoniteAnurRuk = 0xFFF00000;
		color_MargoniteAnurRuk_Damaged = 0xFF800000;
		color_MargoniteAnurRund = 0xFFF00000;
		color_MargoniteAnurRund_Damaged = 0xFF800000;
		color_MargoniteAnurMank = 0xFFF00000;
		color_MargoniteAnurMank_Damaged = 0xFF800000;
		//Stygians
		color_StygianHunger = 0xFFA400D6;
		color_StygianHunger_Damaged = 0xFF8200BE;
		color_StygianBrute = 0xFFF00000;
		color_StygianBrute_Damaged = 0xFF800000;
		color_StygianGolem = 0xFFF00000;
		color_StygianGolem_Damaged = 0xFF800000;
		color_StygianHorror = 0xFFF00000;
		color_StygianHorror_Damaged = 0xFF800000;
		color_StygianFiend = 0xFF0090FF;
		color_StygianFiend_Damaged = 0xFF0040FF;
		//Tormentors
		color_MindTormentor = 0xFFF00000;
		color_MindTormentor_Damaged = 0xFF800000;
		color_SoulTormentor = 0xFFFFFF00;
		color_SoulTormentor_Damaged = 0xFCC8C800;
		color_SoulTormentor_Under50 = 0xFC969664;
		color_WaterTormentor = 0xFFCCFFFF;
		color_WaterTormentor_Damaged = 0xFFB4C8C8;
		color_HeartTormentor = 0xFFF00000;
		color_HeartTormentor_Damaged = 0xFF800000;
		color_FleshTormentor = 0xFFF00000;
		color_FleshTormentor_Damaged = 0xFF800000;
		color_SpiritTormentor = 0xFF00FFFF;
		color_SpiritTormentor_Damaged = 0xFF0078FF;
		color_EarthTormentor = 0xFFF00000;
		color_EarthTormentor_Damaged = 0xFF800000;
		color_SanityTormentor = 0xFF00FFFF;
		color_SanityTormentor_Damaged = 0xFF0078FF;
		color_TheDarkness = 0xFFCCFFFF;
		color_TheDarkness_Damaged = 0xFFB4C8C8;
		//Titan = 0xFFF00000s
		color_MiseryTitan = 0xFFF00000;
		color_MisaryTitan_Damaged = 0xFF800000;
		color_RageTitan = 0xFFF00000;
		color_RageTitan_Damaged = 0xFF800000;
		color_DementiaTitan = 0xFFF00000;
		color_DementiaTitan_Damaged = 0xFF800000;
		color_AnguishTitan = 0xFFF00000;
		color_AnguishTitan_Damaged = 0xFF800000;
		color_DespairTitan = 0xFFF00000;
		color_DespairTitan_Damaged = 0xFF800000;
		color_FuryTitan = 0xFFF00000;
		color_FuryTitan_Damaged = 0xFF800000;
		color_TorturewebDryder = 0xFFCC6600;
		color_TorturewebDryder_Damaged = 0xFF8C4600;
		color_GreatDreamRider = 0xFFF00000;
		color_GreatDreamRider_Damaged = 0xFF800000;
		//Boss-like foes
		color_BlackBeastOfArgh = 0xFFF00000;
		color_BlackBeastOfArgh_Damaged = 0xFF800000;
		color_SmotheringTendril = 0xFFF00000;
		color_SmotheringTendril_Damaged = 0xFF800000;
		color_Fury = 0xFFF00000;
		color_Fury_Damaged = 0xFF800000;
		color_LordJadoth = 0xFFF00000;
		color_LordJadoth_Damaged = 0xFF800000;
		//Fissure of Woe
		//Arachnids
		color_ArmoredCaveSpider = 0xFFF00000;
		color_ArmoredCaveSpider_Damaged = 0xFF800000;
		//Dragons
		color_ObsidianFurnanceDrake = 0xFFF00000;
		color_ObsidianFurnanceDrake_Damaged = 0xFF800000;
		//Dryders
		color_DoubtersDryder = 0xFFF00000;
		color_DoubtersDryder_Damaged = 0xFF800000;
		//Elementals
		color_ShardWolf = 0xFFFFFF00;
		color_ShardWolf_Damaged = 0xFCC8C800;
		//Ghosts
		color_TraitorousTempleGuard = 0xFFF00000;
		color_TraitorousTempleGuard_Damaged = 0xFF800000;
		color_TraitorousTempleGuard2 = 0xFFF00000;
		color_TraitorousTempleGuard3 = 0xFFF00000;
		color_Banshee = 0xFFF00000;
		color_Banshee_Damaged = 0xFF800000;
		//Hydras
		color_MahgoHydra = 0xFFF00000;
		color_MahgoHydra_Damaged = 0xFF800000;
		//Plants
		color_SnarlingDriftwood = 0xFFF00000;
		color_SnarlingDriftwood_Damaged = 0xFF800000;
		color_SpiritWood = 0xFFF00000;
		color_SpiritWood_Damaged = 0xFF800000;
		color_SeedOfCorruption = 0xFF0090FF;
		color_SeedOfCorruption_Damaged = 0xFF0040FF;
		color_SpiritShepherd = 0xFFF00000;
		color_SpiritShepherd_Damaged = 0xFF800000;
		//Riders
		color_SmokeWalker = 0xFFF00000;
		color_SmokeWalker_Damaged = 0xFF800000;
		//Nightmares
		color_Abyssal = 0xFF0090FF;
		color_Abyssal_Damaged = 0xFF0040FF;
		color_ShadowOverLord = 0xFFF00000;
		color_ShadowOverLord_Damaged = 0xFF800000;

		color_ShadowPatrol = 0xFFF00000;
		color_ShadowPatrol_Damaged = 0xFF800000;
		color_ShadowWarrior = 0xFFF00000;
		color_ShadowWarrior_Damaged = 0xFF800000;
		color_ShadowRanger = 0xFFF00000;
		color_ShadowRanger_Damaged = 0xFF800000;
		color_ShadowMonk = 0xFFF00000;
		color_ShadowMonk_Damaged = 0xFF800000;
		color_ShadowBeast = 0xFFF00000;
		color_ShadowBeast_Damaged = 0xFF800000;
		color_ShadowMesmer = 0xFFF00000;
		color_ShadowMesmer_Damaged = 0xFF800000;
		color_ShadowElemental = 0xFFF00000;
		color_ShadowElemental_Damaged = 0xFF800000;
		//Skale
		color_AncientSkale = 0xFFF00000;
		color_AncientSkale_Damaged = 0xFF800000;
		//Skeleton
		color_SkeletalBerserker = 0xFFF00000;
		color_SkeletalBerserker_Damaged = 0xFF800000;
		color_SkeletalImpaler = 0xFFF00000;
		color_SkeletalImpaler_Damaged = 0xFF800000;
		color_SkeletalBond = 0xFFF00000;
		color_SkeletalBond_Damaged = 0xFF800000;
		color_SkeletalEtherBreaker = 0xFFF00000;
		color_SkeletalEtherBreaker_Damaged = 0xFF800000;
		color_SkeletalIcehand = 0xFFF00000;
		color_SkeletalIcehand_Damaged = 0xFF800000;
		//Worms
		color_RockBorerWorm = 0xFFF00000;
		color_RockBorerWorm_Damaged = 0xFF800000;
		 //Wurms
		color_InfernalWurm = 0xFFF00000;
		color_InfernalWurm_Damaged = 0xFF800000;
		//Zombies
		color_DragonLich = 0xFFF00000;
		color_DragonLich_Damaged = 0xFF800000;
		//Bosses
		color_Menzies = 0xFFF00000;
		color_Menzies_Damaged = 0xFF800000;
		color_LordKhobay = 0xFFF00000;
		color_LordKhobay_Damaged = 0xFF800000;
		//Urgoz
		color_HoppingVampire = 0xFFFFFF00;
		//NPC Sizes
		size_default = 75.0f;
		size_player = 100.0f;
		size_signpost = 50.0f;
		size_item = 25.0f;
		size_boss = 125.0f;
		size_minion = 50.0f;
		size_MVP = 105.0f;
	}
	ImGui::Text("");
	ImGui::Text("");
	ImGui::Text("--- Player 1-8 Aggro ---");
	ImGui::Text("");
	Colors::DrawSetting("Player 1", &color_Player1);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 2", &color_Player2);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 3", &color_Player3);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 4", &color_Player4);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 5", &color_Player5);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 6", &color_Player6);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 7", &color_Player7);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	Colors::DrawSetting("Player 8", &color_Player8);
	ImGui::ShowHelp("Put alpha on 0 to dissable");
	ImGui::Text("");
	ImGui::Text("--- General ---");
	ImGui::Text("");
	Colors::DrawSetting("EoE", &color_eoe);
	ImGui::ShowHelp("This is the color at the edge, the color in the middle is the same, with alpha-50");
	Colors::DrawSetting("QZ", &color_qz);
	ImGui::ShowHelp("This is the color at the edge, the color in the middle is the same, with alpha-50");
	Colors::DrawSetting("Winnowing", &color_winnowing);
	ImGui::ShowHelp("This is the color at the edge, the color in the middle is the same, with alpha-50");
	Colors::DrawSetting("Target", &color_target);
	Colors::DrawSetting("Player (alive)", &color_player);
	Colors::DrawSetting("Player (dead)", &color_player_dead);
	Colors::DrawSetting("Signpost", &color_signpost);
	Colors::DrawSetting("Item", &color_item);
	Colors::DrawSetting("Hostile (>90%%)", &color_hostile);
	Colors::DrawSetting("Hostile (<90%%)", &color_hostile_damaged);
	Colors::DrawSetting("Hostile (dead)", &color_hostile_dead);
	Colors::DrawSetting("Neutral", &color_neutral);
	Colors::DrawSetting("Ally (player)", &color_ally);
	Colors::DrawSetting("Ally (NPC)", &color_ally_npc);
	Colors::DrawSetting("Ally (spirit)", &color_ally_spirit);
	Colors::DrawSetting("Ally (minion)", &color_ally_minion);
	Colors::DrawSetting("Ally (dead)", &color_ally_dead);
	Colors::DrawSetting("Agent modifier", &color_agent_modifier);
	ImGui::Text("");
	ImGui::Text("--- Friendly NPCs Aggro Boubble ---");
	ImGui::Text("");
	ImGui::Text("DoA");
	Colors::DrawSetting("CoT Range", &color_CoT);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Torment Claw Range", &color_TC);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Snake Range", &color_Snakes);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	ImGui::Text("UW");
	Colors::DrawSetting("Reaper Range", &color_Reapers);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Escort Souls Range", &color_Escort);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Pits Souls Range", &color_PitsSoul);
	ImGui::Text("FoW");
	Colors::DrawSetting("Griffon Range", &color_Griffons);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Rastigan", &color_Rastigan);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	Colors::DrawSetting("Forgemaster", &color_Forgemaster);
	ImGui::ShowHelp("Put alpha to 0 to dissable");
	ImGui::Text("");
	ImGui::Text("--- Eye of the North ---");
	ImGui::Text("");
	Colors::DrawSetting("Stormcloud Incubus (>90%%)", &color_StormcloudIncubus);
	Colors::DrawSetting("Stormcloud Incubus (<90%%)", &color_StormcloudIncubus_Damaged);
	ImGui::Text("");
	ImGui::Text("--- Underworld ---");
	ImGui::Text("");
	ImGui::Text("Abominations");
	Colors::DrawSetting("Collector (>90%%)", &color_DeadCollector);
	Colors::DrawSetting("Collector (<90%%)", &color_DeadCollector_Damaged);
	Colors::DrawSetting("Thresher (>90%%)", &color_DeadThresher);
	Colors::DrawSetting("Thresher (<90%%)", &color_DeadThresher_Damaged);
	ImGui::Text("Behemoths");
	Colors::DrawSetting("O. Behemoth (>90%%)", &color_ObsidianBehemoth);
	Colors::DrawSetting("O. Behemoth (<90%%)", &color_ObsidianBehemoth_Damaged);
	Colors::DrawSetting("O. Guardian (>90%%)", &color_ObsidianGuardian);
	Colors::DrawSetting("O. Guardian (<90%%)", &color_ObsidianGuardian_Damaged);
	ImGui::Text("Dryders");
	Colors::DrawSetting("Keeper (>90%%)", &color_KeeperOfSouls);
	Colors::DrawSetting("Keeper (<90%%)", &color_KeeperOfSouls_Damaged);
	Colors::DrawSetting("Terrorweb (>90%%)", &color_TerrorwebDryder);
	Colors::DrawSetting("Terrorweb (<90%%)", &color_TerrorwebDryder_Damaged);
	Colors::DrawSetting("S. Terrorweb (>90%%)", &color_TerrorwebDryderSilver);
	Colors::DrawSetting("S. Terrorweb (<90%%)", &color_TerrorwebDryderSilver_Damaged);
	ImGui::Text("Ghosts");
	Colors::DrawSetting("Smite Crawler (>90%%)", &color_SmiteCrawler);
	Colors::DrawSetting("Smite Crawler (<90%%)", &color_SmiteCrawler_Damaged);
	Colors::DrawSetting("Dreamrider (>90%%)", &color_BanishedDreamRider);
	Colors::DrawSetting("Dreamrider (<90%%)", &color_BanishedDreamRider_Damaged);
	Colors::DrawSetting("Mindblade (>90%%)", &color_MindbladeSpectre);
	Colors::DrawSetting("Mindblade (<90%%)", &color_MindbladeSpectre_Damaged);
	Colors::DrawSetting("Tortures S. (>90%%)", &color_TorturedSpirit);
	Colors::DrawSetting("Tortured S. (<90%%)", &color_TorturedSpirit_Damaged);
	Colors::DrawSetting("Wailing (>90%%)", &color_WailingLord);
	Colors::DrawSetting("Wailing (<90%%)", &color_WailingLord_Damaged);
	ImGui::Text("Nightmares");
	Colors::DrawSetting("Aatxe (>90%%)", &color_BladedAatxe);
	Colors::DrawSetting("Aatxe (<90%%)", &color_BladedAatxe_Damaged);
	Colors::DrawSetting("Grasping (>90%%)", &color_GraspingDarkness);
	Colors::DrawSetting("Grasping (<90%%)", &color_GraspingDarkness_Damaged);
	Colors::DrawSetting("Nightmare (>90%%)", &color_DyingNightmare);
	Colors::DrawSetting("Nightmare (<90%%)", &color_DyingNightmare_Damaged);
	Colors::DrawSetting("Blackness (>90%%)", &color_ChargedBlackness);
	Colors::DrawSetting("Blackness (<90%%)", &color_ChargedBlackness_Damaged);
	Colors::DrawSetting("Coldfire N. (>90%%)", &color_ColdfireNight);
	Colors::DrawSetting("Coldfire N. (<90%%)", &color_ColdfireNight_Damaged);
	Colors::DrawSetting("Stalking N. (>90%%)", &color_StalkingNight);
	Colors::DrawSetting("Stalking N. (<90%%)", &color_StalkingNight_Damaged);
	ImGui::Text("Zombies");
	Colors::DrawSetting("Chained Soul (>90%%)", &color_ChainedSoul);
	Colors::DrawSetting("Chained Soul (<90%%)", &color_chainedSoul_Damaged);
	ImGui::Text("Skeletons");
	Colors::DrawSetting("C. of Dhuum (>90%%)", &color_ChampionOfDhuum);
	Colors::DrawSetting("C. of Dhuum (<90%%)", &color_ChampionOfDhuum_Damaged);
	Colors::DrawSetting("M. of Dhuum (>90%%)", &color_MinionOfDhuum);
	Colors::DrawSetting("M. of Dhuum (<90%%)", &color_MinionOfDhuum_Damaged);
	Colors::DrawSetting("Skeleton (>90%%)", &color_SkeletonOfDhuum);
	Colors::DrawSetting("Skeleton (<90%%)", &color_SkeletonOfDhuum_Damaged);
	Colors::DrawSetting("Skeleton (<50%%)", &color_SkeletonOfDhuum_Under50);
	Colors::DrawSetting("Skeleton (<25%%)", &color_SkeletonOfDhuum_Under25);
	ImGui::Text("Boss-like foes");
	Colors::DrawSetting("T. W. Queen (>90%%)", &color_TerrorwebQueen);
	Colors::DrawSetting("T. W. Queen (<90%%)", &color_TerrorwebQueen_Damaged);
	Colors::DrawSetting("Slayer (>90%%)", &color_Slayer);
	Colors::DrawSetting("Slayer (<90%%)", &color_Slayer_Damaged);
	Colors::DrawSetting("4HM (>90%%)", &color_FourHorseman);
	Colors::DrawSetting("4HM (<90%%)", &color_FourHorseman_Damaged);
	Colors::DrawSetting("Dhuum (>90%%)", &color_Dhuum);
	Colors::DrawSetting("Dhuum (<90%%)", &color_Dhuum_Damaged);
	ImGui::Text("");
	ImGui::Text("--- Domain of Anguish ---");
	ImGui::Text("");
	ImGui::Text("Margonites");
	Colors::DrawSetting("Margonite Kaya (>90%%)", &color_MargoniteAnurKaya);
	Colors::DrawSetting("Margonite Kaya (<90%%)", &color_MargoniteAnurKaya_Damaged);
	Colors::DrawSetting("Margonite Dabi (>90%%)", &color_MargoniteAnurDabi);
	Colors::DrawSetting("Margonite Dabi (<90%%)", &color_MargoniteAnurDabi_Damaged);
	Colors::DrawSetting("Margonite Su (>90%%)", &color_MargoniteAnurSu);
	Colors::DrawSetting("Margonite Su (<90%%)", &color_MargoniteAnurSu_damaged);
	Colors::DrawSetting("Margonite Ki (>90%%)", &color_MargoniteAnurKi);
	Colors::DrawSetting("Margonite Ki (<90%%)", &color_MargoniteAnurKi_Damaged);
	Colors::DrawSetting("Margonite Vu (>90%%)", &color_MargoniteAnurVu);
	Colors::DrawSetting("Margonite Vu (<90%%)", &color_MargoniteAnurVu_Damaged);
	Colors::DrawSetting("Margonite Tuk (>90%%)", &color_MargoniteAnurTuk);
	Colors::DrawSetting("Margonite Tuk (<90%%)", &color_MargoniteAnurTuk_Damaged);
	Colors::DrawSetting("Margonite Ruk (>90%%)", &color_MargoniteAnurRuk);
	Colors::DrawSetting("Margonite Ruk (<90%%)", &color_MargoniteAnurRuk_Damaged);
	Colors::DrawSetting("Margonite Rund (>90%%)", &color_MargoniteAnurRund);
	Colors::DrawSetting("Margonite Rund (<90%%)", &color_MargoniteAnurRund_Damaged);
	Colors::DrawSetting("Margonite Mank (>90%%)", &color_MargoniteAnurMank);
	Colors::DrawSetting("Margonite Mank (<90%%)", &color_MargoniteAnurMank_Damaged);
	ImGui::Text("Stygians");
	Colors::DrawSetting("Stygian Hunger (>90%%)", &color_StygianHunger);
	Colors::DrawSetting("Stygian Hunger (<90%%)", &color_StygianHunger_Damaged);
	Colors::DrawSetting("Stygian Brute (>90%%)", &color_StygianBrute);
	Colors::DrawSetting("Stygian Brute (<90%%)", &color_StygianBrute_Damaged);
	Colors::DrawSetting("Stygian Golem (>90%%)", &color_StygianGolem);
	Colors::DrawSetting("Stygian Golem (<90%%)", &color_StygianGolem_Damaged);
	Colors::DrawSetting("Stygian Horror (>90%%)", &color_StygianHorror);
	Colors::DrawSetting("Stygian Horror (<90%%)", &color_StygianHorror_Damaged);
	Colors::DrawSetting("Stygian Fiend (>90%%)", &color_StygianFiend);
	Colors::DrawSetting("Stygian Fiend (<90%%)", &color_StygianFiend_Damaged);
	ImGui::Text("Tormentors");
	Colors::DrawSetting("Mind Tormenter (>90%%)", &color_MindTormentor);
	Colors::DrawSetting("Mind Tormentor (<90%%)", &color_MindTormentor_Damaged);
	Colors::DrawSetting("Soul Tormenter (>90%%)", &color_SoulTormentor);
	Colors::DrawSetting("Soul Tormentor (<90%%)", &color_SoulTormentor_Damaged);
	Colors::DrawSetting("Soul Tormentor (<50%%)", &color_SoulTormentor_Under50);
	Colors::DrawSetting("Water Tormenter (>90%%)", &color_WaterTormentor);
	Colors::DrawSetting("Water Tormentor (<90%%)", &color_WaterTormentor_Damaged);
	Colors::DrawSetting("Heart Tormenter (>90%%)", &color_HeartTormentor);
	Colors::DrawSetting("Heart Tormentor (<90%%)", &color_HeartTormentor_Damaged);
	Colors::DrawSetting("Flesh Tormenter (>90%%)", &color_FleshTormentor);
	Colors::DrawSetting("Flesh Tormentor (<90%%)", &color_FleshTormentor_Damaged);
	Colors::DrawSetting("Spirit Tormenter (>90%%)", &color_SpiritTormentor);
	Colors::DrawSetting("Spirit Tormentor (<90%%)", &color_SpiritTormentor_Damaged);
	Colors::DrawSetting("Earth Tormenter (>90%%)", &color_EarthTormentor);
	Colors::DrawSetting("Earth Tormentor (<90%%)", &color_EarthTormentor_Damaged);
	Colors::DrawSetting("Sanity Tormenter (>90%%)", &color_SanityTormentor);
	Colors::DrawSetting("Sanity Tormentor (<90%%)", &color_SanityTormentor_Damaged);
	Colors::DrawSetting("The Darkness (>90%%)", &color_TheDarkness);
	Colors::DrawSetting("The Darkness (<90%%)", &color_TheDarkness_Damaged);
	ImGui::Text("Titans");
	Colors::DrawSetting("Misery Titan (>90%%)", &color_MiseryTitan);
	Colors::DrawSetting("Misery Titan (<90%%)", &color_MisaryTitan_Damaged);
	Colors::DrawSetting("Rage Titan (>90%%)", &color_RageTitan);
	Colors::DrawSetting("Rage Titan (<90%%)", &color_RageTitan_Damaged);
	Colors::DrawSetting("Dementia Titan (>90%%)", &color_DementiaTitan);
	Colors::DrawSetting("Dementia Titan (<90%%)", &color_DementiaTitan_Damaged);
	Colors::DrawSetting("Anguish Titan (>90%%)", &color_AnguishTitan);
	Colors::DrawSetting("Anguish Titan (<90%%)", &color_AnguishTitan_Damaged);
	Colors::DrawSetting("Despair Titan (>90%%)", &color_DespairTitan);
	Colors::DrawSetting("Despair Titan (<90%%)", &color_DespairTitan_Damaged);
	Colors::DrawSetting("Fury Titan (>90%%)", &color_FuryTitan);
	Colors::DrawSetting("Fury Titan (<90%%)", &color_FuryTitan_Damaged);
	ImGui::Text("Dryders");
	Colors::DrawSetting("Tortureweb (>90%%)", &color_TorturewebDryder);
	Colors::DrawSetting("Tortureweb (<90%%)", &color_TorturewebDryder_Damaged);
	ImGui::Text("Ghosts");
	Colors::DrawSetting("Great D. Rider (>90%%)", &color_GreatDreamRider);
	Colors::DrawSetting("Great D. Rider (<90%%)", &color_GreatDreamRider_Damaged);
	ImGui::Text("Boss-like foes");
	Colors::DrawSetting("Black Beast (>90%%)", &color_BlackBeastOfArgh);
	Colors::DrawSetting("Black Beast (<90%%)", &color_BlackBeastOfArgh_Damaged);
	Colors::DrawSetting("S. Tendril (>90%%)", &color_SmotheringTendril);
	Colors::DrawSetting("S. Tendril (<90%%)", &color_SmotheringTendril_Damaged);
	Colors::DrawSetting("Fury (>90%%)", &color_Fury);
	Colors::DrawSetting("Fury (<90%%)", &color_Fury_Damaged);
	Colors::DrawSetting("Lord Jadoth (>90%%)", &color_LordJadoth);
	Colors::DrawSetting("Lord Jadoth (<90%%)", &color_LordJadoth_Damaged);
	ImGui::Text("");
	ImGui::Text("--- Fissure of Woe ---");
	ImGui::Text("");
	ImGui::Text("Archnids");
	Colors::DrawSetting("Cave Spider (>90%%)", &color_ArmoredCaveSpider);
	Colors::DrawSetting("Cave Spider (<90%%)", &color_ArmoredCaveSpider_Damaged);
	ImGui::Text("Dragons");
	Colors::DrawSetting("Furnance Drake (>90%%)", &color_ObsidianFurnanceDrake);
	Colors::DrawSetting("Furnance Drake (<90%%)", &color_ObsidianFurnanceDrake_Damaged);
	ImGui::Text("Dryders");
	Colors::DrawSetting("Doubters Dryder (>90%%)", &color_DoubtersDryder);
	Colors::DrawSetting("Doubters Dryder (<90%%)", &color_DoubtersDryder_Damaged);
	ImGui::Text("Elementals");
	Colors::DrawSetting("Shard Wolf (>90%%)", &color_ShardWolf);
	Colors::DrawSetting("Shard Wolf (<90%%)", &color_ShardWolf_Damaged);
	ImGui::Text("Ghosts");
	Colors::DrawSetting("T. T. Guard (>90%%)", &color_TraitorousTempleGuard);
	Colors::DrawSetting("T. T. Guard (<90%%)", &color_TraitorousTempleGuard_Damaged);
	Colors::DrawSetting("Banshee (>90%%)", &color_Banshee);
	Colors::DrawSetting("Banshee (<90%%)", &color_Banshee_Damaged);
	ImGui::Text("Hydras");
	Colors::DrawSetting("Mahgo Hydra (>90%%)", &color_MahgoHydra);
	Colors::DrawSetting("Mahgo Hydra (<90%%)", &color_MahgoHydra_Damaged);
	ImGui::Text("Plants");
	Colors::DrawSetting("Snarling Driftwood (>90%%)", &color_SnarlingDriftwood);
	Colors::DrawSetting("Snarling Driftwood (<90%%)", &color_SnarlingDriftwood_Damaged);
	Colors::DrawSetting("Spirit Wood (>90%%)", &color_SpiritWood);
	Colors::DrawSetting("Spirit Wood (<90%%)", &color_SpiritWood_Damaged);
	Colors::DrawSetting("Seed of C. (>90%%)", &color_SeedOfCorruption);
	Colors::DrawSetting("Seed of C. (<90%%)", &color_SeedOfCorruption_Damaged);
	Colors::DrawSetting("Spirit Shepherd(>90%%)", &color_SpiritShepherd);
	Colors::DrawSetting("Spirit Shepherd(<90%%)", &color_SpiritShepherd_Damaged);
	ImGui::Text("Riders");
	Colors::DrawSetting("Smoke Walker (>90%%)", &color_SmokeWalker);
	Colors::DrawSetting("Smoke Walker (<90%%)", &color_SmokeWalker_Damaged);
	ImGui::Text("Nightmares");
	Colors::DrawSetting("Abyssal (>90%%)", &color_Abyssal);
	Colors::DrawSetting("Abyssal (<90%%)", &color_Abyssal_Damaged);
	ImGui::ShowHelp("Abyssals, Shadow Partols and Shadow Overlords Have the same id. Because of that the same color aswell.");
	Colors::DrawSetting("Shadow Warrior (>90%%)", &color_ShadowWarrior);
	Colors::DrawSetting("Shadow Warrior (<90%%)", &color_ShadowWarrior_Damaged);
	Colors::DrawSetting("Shadow Ranger (>90%%)", &color_ShadowRanger);
	Colors::DrawSetting("Shadow Ranger (<90%%)", &color_ShadowRanger_Damaged);
	Colors::DrawSetting("Shadow Monk (>90%%)", &color_ShadowMonk);
	Colors::DrawSetting("Shadow Monk (<90%%)", &color_ShadowMonk_Damaged);
	Colors::DrawSetting("Shadow Beast (>90%%)", &color_ShadowBeast);
	Colors::DrawSetting("Shadow Beast (<90%%)", &color_ShadowBeast_Damaged);
	Colors::DrawSetting("Shadow Mesmer (>90%%)", &color_ShadowMesmer);
	Colors::DrawSetting("Shadow Mesmer (<90%%)", &color_ShadowMesmer_Damaged);
	Colors::DrawSetting("Shadow Elemental (>90%%)", &color_ShadowElemental);
	Colors::DrawSetting("Shadow Elemental (<90%%)", &color_ShadowElemental_Damaged);
	ImGui::Text("Skale");
	Colors::DrawSetting("Ancient Skale (>90%%)", &color_AncientSkale);
	Colors::DrawSetting("Ancient Skale (<90%%)", &color_AncientSkale_Damaged);
	ImGui::Text("Skeletons");
	Colors::DrawSetting("Skeletal Berserker (>90%%)", &color_SkeletalBerserker);
	Colors::DrawSetting("Skeletal Berserker (<90%%)", &color_SkeletalBerserker_Damaged);
	Colors::DrawSetting("Skeletal Impaler (>90%%)", &color_SkeletalImpaler);
	Colors::DrawSetting("Skeletal Impaler (<90%%)", &color_SkeletalImpaler_Damaged);
	Colors::DrawSetting("Skeletal Bond (>90%%)", &color_SkeletalBond);
	Colors::DrawSetting("Skeletal Bond (<90%%)", &color_SkeletalBond_Damaged);
	Colors::DrawSetting("Skeletal Ether Breaker (>90%%)", &color_SkeletalEtherBreaker);
	Colors::DrawSetting("Skeletal Ether Breaker (<90%%)", &color_SkeletalEtherBreaker_Damaged);
	Colors::DrawSetting("Skeletal Icehand (>90%%)", &color_SkeletalIcehand);
	Colors::DrawSetting("Skeletal Icehand (<90%%)", &color_SkeletalIcehand_Damaged);
	ImGui::Text("Worms");
	Colors::DrawSetting("Rock Borer Worm (>90%%)", &color_RockBorerWorm);
	Colors::DrawSetting("Rock Borer Worm (<90%%)", &color_RockBorerWorm_Damaged);
	ImGui::Text("Wurms");
	Colors::DrawSetting("Infernal Wurm (>90%%)", &color_InfernalWurm);
	Colors::DrawSetting("Infernal Wurm (<90%%)", &color_InfernalWurm_Damaged);
	ImGui::Text("Zombies");
	Colors::DrawSetting("Dragon Lich(>90%%)", &color_DragonLich);
	Colors::DrawSetting("Dragon Lich (<90%%)", &color_DragonLich_Damaged);
	ImGui::Text("Bosses");
	Colors::DrawSetting("Menzies (>90%%)", &color_Menzies);
	Colors::DrawSetting("Menzies (<90%%)", &color_Menzies_Damaged);
	Colors::DrawSetting("Lord Khobay (>90%%)", &color_LordKhobay);
	Colors::DrawSetting("Lord Khobay (<90%%)", &color_LordKhobay_Damaged);
	ImGui::Text("");
	ImGui::Text("--- Urgoz ---");
	ImGui::Text("");
	Colors::DrawSetting("H. Vampire ", &color_HoppingVampire);
	ImGui::Text("");
	ImGui::Text("");
	ImGui::ShowHelp("Each agent has this value removed on the border and added at the center\nZero makes agents have solid color, while a high number makes them appear more shaded.");

	ImGui::Text("Map GUI Sizes");
	ImGui::DragFloat("Default Size", &size_default, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("Player Size", &size_player, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("Signpost Size", &size_signpost, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("Item Size", &size_item, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("Boss Size", &size_boss, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("Minion Size", &size_minion, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::DragFloat("MVP Size", &size_MVP, 1.0f, 1.0f, 0.0f, "%.0f");
	ImGui::Text("");
	ImGui::Text("--- List of MVP's ---");
	ImGui::Text("");
	ImGui::Text(" Domain of Anguish");
	ImGui::Text("");
	ImGui::Text("- Stygian Fiends");
	ImGui::Text("- The Darkness");
	ImGui::Text("");
	ImGui::Text(" Underworld");
	ImGui::Text("");
	ImGui::Text("- Skeleton of Dhuum");
	ImGui::Text("- Dying Nightmare");
	ImGui::Text("");
}

AgentRenderer::AgentRenderer() : vertices(nullptr) {
	shapes[Tear].AddVertex(1.8f, 0, Dark);		// A
	shapes[Tear].AddVertex(0.7f, 0.7f, Dark);	// B
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(0.7f, 0.7f, Dark);	// B
	shapes[Tear].AddVertex(0.0f, 1.0f, Dark);	// C
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(0.0f, 1.0f, Dark);	// C
	shapes[Tear].AddVertex(-0.7f, 0.7f, Dark);	// D
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(-0.7f, 0.7f, Dark);	// D
	shapes[Tear].AddVertex(-1.0f, 0.0f, Dark);	// E
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(-1.0f, 0.0f, Dark);	// E
	shapes[Tear].AddVertex(-0.7f, -0.7f, Dark);	// F
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(-0.7f, -0.7f, Dark);	// F
	shapes[Tear].AddVertex(0.0f, -1.0f, Dark);	// G
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(0.0f, -1.0f, Dark);	// G
	shapes[Tear].AddVertex(0.7f, -0.7f, Dark);	// H
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O
	shapes[Tear].AddVertex(0.7f, -0.7f, Dark);	// H
	shapes[Tear].AddVertex(1.8f, 0.0f, Dark);	// A
	shapes[Tear].AddVertex(0.0f, 0.0f, Light);	// O

	int num_triangles = 8;
	float PI = static_cast<float>(M_PI);
	for (int i = 0; i < num_triangles; ++i) {
		float angle1 = 2 * (i + 0) * PI / num_triangles;
		float angle2 = 2 * (i + 1) * PI / num_triangles;
		shapes[Circle].AddVertex(std::cos(angle1), std::sin(angle1), Dark);
		shapes[Circle].AddVertex(std::cos(angle2), std::sin(angle2), Dark);
		shapes[Circle].AddVertex(0.0f, 0.0f, Light);
	}

	num_triangles = 32;
	for (int i = 0; i < num_triangles; ++i) {
		float angle1 = 2 * (i + 0) * PI / num_triangles;
		float angle2 = 2 * (i + 1) * PI / num_triangles;
		shapes[BigCircle].AddVertex(std::cos(angle1), std::sin(angle1), None);
		shapes[BigCircle].AddVertex(std::cos(angle2), std::sin(angle2), None);
		shapes[BigCircle].AddVertex(0.0f, 0.0f, CircleCenter);
	}

	shapes[Quad].AddVertex(1.0f, -1.0f, Dark);
	shapes[Quad].AddVertex(1.0f, 1.0f, Dark);
	shapes[Quad].AddVertex(0.0f, 0.0f, Light);
	shapes[Quad].AddVertex(1.0f, 1.0f, Dark);
	shapes[Quad].AddVertex(-1.0f, 1.0f, Dark);
	shapes[Quad].AddVertex(0.0f, 0.0f, Light);
	shapes[Quad].AddVertex(-1.0f, 1.0f, Dark);
	shapes[Quad].AddVertex(-1.0f, -1.0f, Dark);
	shapes[Quad].AddVertex(0.0f, 0.0f, Light);
	shapes[Quad].AddVertex(-1.0f, -1.0f, Dark);
	shapes[Quad].AddVertex(1.0f, -1.0f, Dark);
	shapes[Quad].AddVertex(0.0f, 0.0f, Light);

	max_shape_verts = 0;
	for (int shape = 0; shape < shape_size; ++shape) {
		if (max_shape_verts < shapes[shape].vertices.size()) {
			max_shape_verts = shapes[shape].vertices.size();
		}
	}
}

void AgentRenderer::Shape_t::AddVertex(float x, float y, AgentRenderer::Color_Modifier mod) {
	vertices.push_back(Shape_Vertex(x, y, mod));
}


void AgentRenderer::Initialize(IDirect3DDevice9* device) {
	type = D3DPT_TRIANGLELIST;
	vertices_max = max_shape_verts * 0x200; // support for up to 512 agents, should be enough
	vertices = nullptr;
	HRESULT hr = device->CreateVertexBuffer(sizeof(D3DVertex) * vertices_max, 0,
		D3DFVF_CUSTOMVERTEX, D3DPOOL_MANAGED, &buffer, NULL);
	if (FAILED(hr)) printf("AgentRenderer initialize error: %d\n", hr);
}

void AgentRenderer::Render(IDirect3DDevice9* device) {
	if (!initialized) {
		Initialize(device);
		initialized = true;
	}

	HRESULT res = buffer->Lock(0, sizeof(D3DVertex) * vertices_max, (VOID**)&vertices, D3DLOCK_DISCARD);
	if (FAILED(res)) printf("AgentRenderer Lock() error: %d\n", res);

	vertices_count = 0;

	// get stuff
	GW::AgentArray agents = GW::Agents::GetAgentArray();
	if (!agents.valid()) return;

	GW::NPCArray npcs = GW::Agents::GetNPCArray();
	if (!npcs.valid()) return;

	GW::Agent* player = GW::Agents::GetPlayer();
	GW::Agent* target = GW::Agents::GetTarget();

	// 1. eoes
	for (size_t i = 0; i < agents.size(); ++i) {
		GW::Agent* agent = agents[i];
		if (agent == nullptr) continue;
		if (agent->GetIsDead()) continue;
		switch (agent->PlayerNumber) {
		case GW::Constants::ModelID::Player::player1:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player1);
			break;
		case GW::Constants::ModelID::Player::player2:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player2);
			break;
		case GW::Constants::ModelID::Player::Player3:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player3);
			break;
		case GW::Constants::ModelID::Player::Player4:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player4);
			break;
		case GW::Constants::ModelID::Player::Player5:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player5);
			break;
		case GW::Constants::ModelID::Player::Player6:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player6);
			break;
		case GW::Constants::ModelID::Player::Player7:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player7);
			break;
		case GW::Constants::ModelID::Player::Player8:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Player8);
			break;
		case GW::Constants::ModelID::EoE:
			Enqueue(BigCircle, agent, GW::Constants::Range::Spirit, color_eoe);
			break;
		case GW::Constants::ModelID::QZ:
			Enqueue(BigCircle, agent, GW::Constants::Range::Spirit, color_qz);
			break;
		case GW::Constants::ModelID::Winnowing:
			Enqueue(BigCircle, agent, GW::Constants::Range::Spirit, color_winnowing);
			break;
			//Domain of Anguish
		case GW::Constants::ModelID::DoA::SoulTormentor:
			Enqueue(BigCircle, agent, GW::Constants::Range::CoT, color_CoT);
			break;
		case GW::Constants::ModelID::DoA::TormentClaw:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_TC);
			break;
		case GW::Constants::ModelID::DoA::StygianLordNecro:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_TC);
			break;
		case GW::Constants::ModelID::DoA::Snakes:
			Enqueue (BigCircle, agent, GW::Constants::Range::Earshot, color_Snakes);
			break;
			//Underworld
		case GW::Constants::ModelID::UW::Reapers:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Reapers);
			break;
		case GW::Constants::ModelID::UW::Escort:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::Escort2:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::Escort3:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::Escort4:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::Escort5:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::Escort6:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Escort);
			break;
		case GW::Constants::ModelID::UW::PitsSoul:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_PitsSoul);
			break;
		case GW::Constants::ModelID::UW::PitsSoul2:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_PitsSoul);
			break;
		case GW::Constants::ModelID::UW::PitsSoul3:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_PitsSoul);
			break;
		case GW::Constants::ModelID::UW::PitsSoul4:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_PitsSoul);
			break;
			//Fissure of Woe
		case GW::Constants::ModelID::FoW::Griffons:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Griffons);
			break;
		case GW::Constants::ModelID::FoW::Rastigan:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Rastigan);
			break;
		case GW::Constants::ModelID::FoW::Forgemaster:
			Enqueue(BigCircle, agent, GW::Constants::Range::Earshot, color_Forgemaster);
			break;
		default:
			break;
		}
	}
	// 2. non-player agents
	for (size_t i = 0; i < agents.size(); ++i) {
		GW::Agent* agent = agents[i];
		if (agent == nullptr) continue;
		if (agent->PlayerNumber <= 12) continue;
		if (agent->GetIsGadgetType()
			&& GW::Map::GetMapID() == GW::Constants::MapID::Domain_of_Anguish
			&& agent->ExtraType == 7602) continue;
		if (agent->GetIsCharacterType()
			&& agent->IsNPC()
			&& agent->PlayerNumber < npcs.size()
			&& (npcs[agent->PlayerNumber].NpcFlags & 0x10000) > 0) continue;
		if (target == agent) continue; // will draw target at the end

		Enqueue(agent);

		if (vertices_count >= vertices_max - 16 * max_shape_verts) break;
	}
	// 3. target if it's a non-player
	if (target && target->PlayerNumber > 12) {
		Enqueue(target);
	}

	// 4. players
	for (size_t i = 0; i < agents.size(); ++i) {
		GW::Agent* agent = agents[i];
		if (agent == nullptr) continue;
		if (agent->PlayerNumber > 12) continue;
		if (agent == player) continue; // will draw player at the end
		if (agent == target) continue; // will draw target at the end

		Enqueue(agent);

		if (vertices_count >= vertices_max - 4 * max_shape_verts) break;
	}

	// 5. target if it's a player
	if (target && target != player && target->PlayerNumber <= 12) {
		Enqueue(target);
	}

	// 6. player
	if (player) {
		Enqueue(player);
	}

	buffer->Unlock();

	if (vertices_count != 0) {
		device->SetStreamSource(0, buffer, 0, sizeof(D3DVertex));
		device->DrawPrimitive(D3DPT_TRIANGLELIST, 0, vertices_count / 3);
		vertices_count = 0;
	}
}

void AgentRenderer::Enqueue(GW::Agent* agent) {
	Color color = GetColor(agent);
	float size = GetSize(agent);
	Shape_e shape = GetShape(agent);

	if (GW::Agents::GetTargetId() == agent->Id) {
		Enqueue(shape, agent, size + 50.0f, color_target);
	}

	Enqueue(shape, agent, size, color);
}

Color AgentRenderer::GetColor(GW::Agent* agent) const {
	if (agent->Id == GW::Agents::GetPlayerId()) {
		if (agent->GetIsDead()) return color_player_dead;
		else return color_player;
	}

	if (agent->GetIsGadgetType()) return color_signpost;
	if (agent->GetIsItemType()) return color_item;

	// don't draw dead spirits
	auto npcs = GW::Agents::GetNPCArray();
	if (agent->GetIsDead() && npcs.valid() && agent->PlayerNumber < npcs.size()) {
		GW::NPC& npc = npcs[agent->PlayerNumber];
		switch (npc.ModelFileID) {
		case 0x22A34: // nature rituals
		case 0x2D0E4: // defensive binding rituals
		case 0x2D07E: // offensive binding rituals
			return IM_COL32(0, 0, 0, 0);
		default:
			break;
		}
	}

	// hostiles
	if (agent->Allegiance == 0x3) {
		//--- Domain of Anguish ---
		//Margos
	if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurKaya) {
		if (agent->HP > 0.9f) return color_MargoniteAnurKaya;
		if (agent->HP > 0.0f) return color_MargoniteAnurKaya_Damaged;
	}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurDabi) {
			if (agent->HP > 0.9f) return color_MargoniteAnurDabi;
			if (agent->HP > 0.0f) return color_MargoniteAnurDabi_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurSu) {
			if (agent->HP > 0.9f) return color_MargoniteAnurSu;
			if (agent->HP > 0.0f) return color_MargoniteAnurSu_damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurKi) {
			if (agent->HP > 0.9f) return color_MargoniteAnurKi;
			if (agent->HP > 0.0f) return color_MargoniteAnurKi_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurVu) {
			if (agent->HP > 0.9f) return color_MargoniteAnurVu;
			if (agent->HP > 0.0f) return color_MargoniteAnurVu_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurTuk) {
			if (agent->HP > 0.9f) return color_MargoniteAnurTuk;
			if (agent->HP > 0.0f) return color_MargoniteAnurTuk_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurRuk) {
			if (agent->HP > 0.9f) return color_MargoniteAnurRuk;
			if (agent->HP > 0.0f) return color_MargoniteAnurRuk_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurRund) {
			if (agent->HP > 0.9f) return color_MargoniteAnurRund;
			if (agent->HP > 0.0f) return color_MargoniteAnurRund_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MargoniteAnurMank) {
			if (agent->HP > 0.9f) return color_MargoniteAnurMank;
			if (agent->HP > 0.0f) return color_MargoniteAnurMank_Damaged;
		}
		//Stygians
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::StygianHunger) {
			if (agent->HP > 0.9f) return color_StygianHunger;
			if (agent->HP > 0.0f) return color_StygianHunger_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::StygianBrute) {
			if (agent->HP > 0.9f) return color_StygianBrute;
			if (agent->HP > 0.0f) return color_StygianBrute_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::StygianGolem) {
			if (agent->HP > 0.9f) return color_StygianGolem;
			if (agent->HP > 0.0f) return color_StygianGolem_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::StygianHorror) {
			if (agent->HP > 0.9f) return color_StygianHorror;
			if (agent->HP > 0.0f) return color_StygianHorror_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::StygianFiend) {
			if (agent->HP > 0.9f) return color_StygianFiend;
			if (agent->HP > 0.0f) return color_StygianFiend_Damaged;
		}
		//Torms
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MindTormentor) {
			if (agent->HP > 0.9f) return color_MindTormentor;
			if (agent->HP > 0.0f) return color_MindTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilMindTormentor) {
			if (agent->HP > 0.9f) return color_MindTormentor;
			if (agent->HP > 0.0f) return color_MindTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::SoulTormentor) {
			if (agent->HP > 0.9f) return color_SoulTormentor;
			if (agent->HP > 0.5f) return color_SoulTormentor_Damaged;
			if (agent->HP > 0.0f) return color_SoulTormentor_Under50;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilSoulTormentor) {
			if (agent->HP > 0.9f) return color_SoulTormentor;
			if (agent->HP > 0.5f) return color_SoulTormentor_Damaged;
			if (agent->HP > 0.0f) return color_SoulTormentor_Under50;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::WaterTormentor) {
			if (agent->HP > 0.9f) return color_WaterTormentor;
			if (agent->HP > 0.0f) return color_WaterTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilWaterTormentor) {
			if (agent->HP > 0.9f) return color_WaterTormentor;
			if (agent->HP > 0.0f) return color_WaterTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::HeartTormentor) {
			if (agent->HP > 0.9f) return color_HeartTormentor;
			if (agent->HP > 0.0f) return color_HeartTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilHeartTormentor) {
			if (agent->HP > 0.9f) return color_HeartTormentor;
			if (agent->HP > 0.0f) return color_HeartTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::FleshTormentor) {
			if (agent->HP > 0.9f) return color_FleshTormentor;
			if (agent->HP > 0.0f) return color_FleshTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilFleshTormentor) {
			if (agent->HP > 0.9f) return color_FleshTormentor;
			if (agent->HP > 0.0f) return color_FleshTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::SpiritTormentor) {
			if (agent->HP > 0.9f) return color_SpiritTormentor;
			if (agent->HP > 0.0f) return color_SpiritTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilSpiritTormentor) {
			if (agent->HP > 0.9f) return color_SpiritTormentor;
			if (agent->HP > 0.0f) return color_SpiritTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::EarthTormentor) {
			if (agent->HP > 0.9f) return color_EarthTormentor;
			if (agent->HP > 0.0f) return color_EarthTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilEarthTormentor) {
			if (agent->HP > 0.9f) return color_EarthTormentor;
			if (agent->HP > 0.0f) return color_EarthTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::SanityTormentor) {
			if (agent->HP > 0.9f) return color_SanityTormentor;
			if (agent->HP > 0.0f) return color_SanityTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::VeilSanityTormentor) {
			if (agent->HP > 0.9f) return color_SanityTormentor;
			if (agent->HP > 0.0f) return color_SanityTormentor_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::TheDarkness) {
			if (agent->HP > 0.9f) return color_TheDarkness;
			if (agent->HP > 0.0f) return color_TheDarkness_Damaged;
		}
		//Titans
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::MiseryTitan) {
			if (agent->HP > 0.9f) return color_MiseryTitan;
			if (agent->HP > 0.0f) return color_MisaryTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::RageTitan) {
			if (agent->HP > 0.9f) return color_RageTitan;
			if (agent->HP > 0.0f) return color_RageTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::RageTitan2) {
			if (agent->HP > 0.9f) return color_RageTitan;
			if (agent->HP > 0.0f) return color_RageTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::DementiaTitan) {
			if (agent->HP > 0.9f) return color_DementiaTitan;
			if (agent->HP > 0.0f) return color_DementiaTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::DementiaTitan2) {
			if (agent->HP > 0.9f) return color_DementiaTitan;
			if (agent->HP > 0.0f) return color_DementiaTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::AnguishTitan) {
			if (agent->HP > 0.9f) return color_AnguishTitan;
			if (agent->HP > 0.0f) return color_AnguishTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::DespairTitan) {
			if (agent->HP > 0.9f) return color_DespairTitan;
			if (agent->HP > 0.0f) return color_DespairTitan_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::FuryTitan) {
			if (agent->HP > 0.9f) return color_FuryTitan;
			if (agent->HP > 0.0f) return color_FuryTitan_Damaged;
		}
		//Dryder
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::TorturewebDryder) {
			if (agent->HP > 0.9f) return color_TorturewebDryder;
			if (agent->HP > 0.0f) return color_TorturewebDryder_Damaged;
		}
		//Ghost
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::GreaterDreamRider) {
			if (agent->HP > 0.9f) return color_GreatDreamRider;
			if (agent->HP > 0.0f) return color_GreatDreamRider_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::GreaterDreamRider2) {
			if (agent->HP > 0.9f) return color_GreatDreamRider;
			if (agent->HP > 0.0f) return color_GreatDreamRider_Damaged;
		}
		//Boss-like foes
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::BlackBeastOfArgh) {
			if (agent->HP > 0.9f) return color_BlackBeastOfArgh;
			if (agent->HP > 0.0f) return color_BlackBeastOfArgh_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::SmotheringTendril) {
			if (agent->HP > 0.9f) return color_SmotheringTendril;
			if (agent->HP > 0.0f) return color_SmotheringTendril_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::Fury) {
			if (agent->HP > 0.9f) return color_Fury;
			if (agent->HP > 0.0f) return color_Fury_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::DoA::LordJadoth) {
			if (agent->HP > 0.9f) return color_LordJadoth;
			if (agent->HP > 0.0f) return color_LordJadoth_Damaged;
		}
		//--- Underworld ---
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::DeadCollector) {
			if (agent->HP > 0.9f) return color_DeadCollector;
			if (agent->HP > 0.0f) return color_DeadCollector_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::DeadThresher) {
			if (agent->HP > 0.9f) return color_DeadThresher;
			if (agent->HP > 0.0f) return color_DeadThresher_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ObsidianBehemoth) {
			if (agent->HP > 0.9f) return color_ObsidianBehemoth;
			if (agent->HP > 0.0f) return color_ObsidianBehemoth_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ObsidianGuardian) {
			if (agent->HP > 0.9f) return color_ObsidianGuardian;
			if (agent->HP > 0.0f) return color_ObsidianGuardian_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::KeeperOfSouls) {
			if (agent->HP > 0.9f) return color_KeeperOfSouls;
			if (agent->HP > 0.0f) return color_KeeperOfSouls_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::TerrorwebDryder) {
			if (agent->HP > 0.9f) return color_TerrorwebDryder;
			if (agent->HP > 0.0f) return color_TerrorwebDryder_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::TerrorwebDryderSilver) {
			if (agent->HP > 0.9f) return color_TerrorwebDryderSilver;
			if (agent->HP > 0.0f) return color_TerrorwebDryderSilver_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::SmiteCrawler) {
			if (agent->HP > 0.9f) return color_SmiteCrawler;
			if (agent->HP > 0.0f) return color_SmiteCrawler_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::BanishedDreamRider) {
			if (agent->HP > 0.9f) return color_BanishedDreamRider;
			if (agent->HP > 0.0f) return color_BanishedDreamRider_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::MindbladeSpectre) {
			if (agent->HP > 0.9f) return color_MindbladeSpectre;
			if (agent->HP > 0.0f) return color_MindbladeSpectre_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::TorturedSpirit) {
			if (agent->HP > 0.9f) return color_TorturedSpirit;
			if (agent->HP > 0.0f) return color_TorturedSpirit_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::WailingLord) {
			if (agent->HP > 0.9f) return color_WailingLord;
			if (agent->HP > 0.0f) return color_WailingLord_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::BladedAatxe) {
			if (agent->HP > 0.9f) return color_BladedAatxe;
			if (agent->HP > 0.0f) return color_BladedAatxe_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::GraspingDarkness) {
			if (agent->HP > 0.9f) return color_GraspingDarkness;
			if (agent->HP > 0.0f) return color_GraspingDarkness_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::DyingNightmare) {
			if (agent->HP > 0.9f) return color_DyingNightmare;
			if (agent->HP > 0.0f) return color_DyingNightmare_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ChargedBlackness) {
			if (agent->HP > 0.9f) return color_ChargedBlackness;
			if (agent->HP > 0.0f) return color_ChargedBlackness_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ColdfireNight) {
			if (agent->HP > 0.9f) return color_ColdfireNight;
			if (agent->HP > 0.0f) return color_ColdfireNight_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::StalkingNight) {
			if (agent->HP > 0.9f) return color_StalkingNight;
			if (agent->HP > 0.0f) return color_StalkingNight_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ChampionOfDhuum) {
			if (agent->HP > 0.9f) return color_ChampionOfDhuum;
			if (agent->HP > 0.0f) return color_ChampionOfDhuum_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::MinionOfDhuum) {
			if (agent->HP > 0.9f) return color_MinionOfDhuum;
			if (agent->HP > 0.0f) return color_MinionOfDhuum_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::SkeletonOfDhuum) {
			if (agent->HP > 0.9f) return color_SkeletonOfDhuum;
			if (agent->HP > 0.5f) return color_SkeletonOfDhuum_Damaged;
			if (agent->HP > 0.25f) return color_SkeletonOfDhuum_Under50;
			if (agent->HP > 0.0f) return color_SkeletonOfDhuum_Under25;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::SkeletonOfDhuum2) {
			if (agent->HP > 0.9f) return color_SkeletonOfDhuum;
			if (agent->HP > 0.5f) return color_SkeletonOfDhuum_Damaged;
			if (agent->HP > 0.25f) return color_SkeletonOfDhuum_Under50;
			if (agent->HP > 0.0f) return color_SkeletonOfDhuum_Under25;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::ChainedSoul) {
			if (agent->HP > 0.9f) return color_ChainedSoul;
			if (agent->HP > 0.0f) return color_chainedSoul_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::TerrorwebQueen) {
			if (agent->HP > 0.9f) return color_TerrorwebQueen;
			if (agent->HP > 0.0f) return color_TerrorwebQueen_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::Slayer) {
			if (agent->HP > 0.9f) return color_Slayer;
			if (agent->HP > 0.0f) return color_Slayer_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::FourHorseman) {
			if (agent->HP > 0.9f) return color_FourHorseman;
			if (agent->HP > 0.0f) return color_FourHorseman_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::UW::Dhuum) {
			if (agent->HP > 0.9f) return color_Dhuum;
			if (agent->HP > 0.0f) return color_Dhuum_Damaged;
		}
		//Fissure of Woe
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ArmoredCaveSpider) {
			if (agent->HP > 0.9f) return color_ArmoredCaveSpider;
			if (agent->HP > 0.0f) return color_ArmoredCaveSpider_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ObsidianFurnanceDrake) {
			if (agent->HP > 0.9f) return color_ObsidianFurnanceDrake;
			if (agent->HP > 0.0f) return color_ObsidianFurnanceDrake_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::DoubtersDryder) {
			if (agent->HP > 0.9f) return color_DoubtersDryder;
			if (agent->HP > 0.0f) return color_DoubtersDryder_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShardWolf) {
			if (agent->HP > 0.9f) return color_ShardWolf;
			if (agent->HP > 0.0f) return color_ShardWolf_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::TraitorousTempleGuard) {
			if (agent->HP > 0.9f) return color_TraitorousTempleGuard;
			if (agent->HP > 0.0f) return color_TraitorousTempleGuard_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::TraitorousTempleGuard2) {
			if (agent->HP > 0.9f) return color_TraitorousTempleGuard;
			if (agent->HP > 0.0f) return color_TraitorousTempleGuard_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::TraitorousTempleGuard3) {
			if (agent->HP > 0.9f) return color_TraitorousTempleGuard;
			if (agent->HP > 0.0f) return color_TraitorousTempleGuard_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::Banshee) {
			if (agent->HP > 0.9f) return color_Banshee;
			if (agent->HP > 0.0f) return color_Banshee_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::MahgoHydra) {
			if (agent->HP > 0.9f) return color_MahgoHydra;
			if (agent->HP > 0.0f) return color_MahgoHydra_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SnarlingDriftwood) {
			if (agent->HP > 0.9f) return color_SnarlingDriftwood;
			if (agent->HP > 0.0f) return color_SnarlingDriftwood_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SpiritWood) {
			if (agent->HP > 0.9f) return color_SpiritWood;
			if (agent->HP > 0.0f) return color_SpiritWood_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SeedOfCorruption) {
			if (agent->HP > 0.9f) return color_SeedOfCorruption;
			if (agent->HP > 0.0f) return color_SeedOfCorruption_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SpiritShepherd) {
			if (agent->HP > 0.9f) return color_SpiritShepherd;
			if (agent->HP > 0.0f) return color_SpiritShepherd_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SmokeWalker) {
			if (agent->HP > 0.9f) return color_SmokeWalker;
			if (agent->HP > 0.0f) return color_SmokeWalker_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::Abyssal) {
			if (agent->HP > 0.9f) return color_Abyssal;
			if (agent->HP > 0.0f) return color_Abyssal_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowOverlord) {
			if (agent->HP > 0.9f) return color_ShadowOverLord;
			if (agent->HP > 0.0f) return color_ShadowOverLord_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowPatrol) {
			if (agent->HP > 0.9f) return color_ShadowPatrol;
			if (agent->HP > 0.0f) return color_ShadowPatrol_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowWarrior) {
			if (agent->HP > 0.9f) return color_ShadowWarrior;
			if (agent->HP > 0.0f) return color_ShadowWarrior_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowRanger) {
			if (agent->HP > 0.9f) return color_ShadowRanger;
			if (agent->HP > 0.0f) return color_ShadowRanger_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowMonk) {
			if (agent->HP > 0.9f) return color_ShadowMonk;
			if (agent->HP > 0.0f) return color_ShadowMonk_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowBeast) {
			if (agent->HP > 0.9f) return color_ShadowBeast;
			if (agent->HP > 0.0f) return color_ShadowBeast_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowMesmer) {
			if (agent->HP > 0.9f) return color_ShadowMesmer;
			if (agent->HP > 0.0f) return color_ShadowMesmer_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::ShadowElemental) {
			if (agent->HP > 0.9f) return color_ShadowElemental;
			if (agent->HP > 0.0f) return color_ShadowElemental_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::AncientSkale) {
			if (agent->HP > 0.9f) return color_AncientSkale;
			if (agent->HP > 0.0f) return color_AncientSkale_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SkeletalBerserker) {
			if (agent->HP > 0.9f) return color_SkeletalBerserker;
			if (agent->HP > 0.0f) return color_SkeletalBerserker_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SkeletalImpaler) {
			if (agent->HP > 0.9f) return color_SkeletalImpaler;
			if (agent->HP > 0.0f) return color_SkeletalImpaler_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SkeletalBond) {
			if (agent->HP > 0.9f) return color_SkeletalBond;
			if (agent->HP > 0.0f) return color_SkeletalBond_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SkeletalEtherBreaker) {
			if (agent->HP > 0.9f) return color_SkeletalEtherBreaker;
			if (agent->HP > 0.0f) return color_SkeletalEtherBreaker_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::SkeletalIcehand) {
			if (agent->HP > 0.9f) return color_SkeletalIcehand;
			if (agent->HP > 0.0f) return color_SkeletalIcehand_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::RockBorerWorm) {
			if (agent->HP > 0.9f) return color_RockBorerWorm;
			if (agent->HP > 0.0f) return color_RockBorerWorm_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::InfernalWurm) {
			if (agent->HP > 0.9f) return color_InfernalWurm;
			if (agent->HP > 0.0f) return color_InfernalWurm_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::DragonLich) {
			if (agent->HP > 0.9f) return color_DragonLich;
			if (agent->HP > 0.0f) return color_DragonLich_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::Menzies) {
			if (agent->HP > 0.9f) return color_Menzies;
			if (agent->HP > 0.0f) return color_Menzies_Damaged;
		}
		else if (agent->PlayerNumber == GW::Constants::ModelID::FoW::LordKhobay) {
			if (agent->HP > 0.9f) return color_LordKhobay;
			if (agent->HP > 0.0f) return color_LordKhobay_Damaged;
		}
		//Urgoz
		else if (agent->PlayerNumber == GW::Constants::ModelID::Urgoz::HoppingVampire) {
			if (agent->HP > 0.9f) return color_HoppingVampire;
			if (agent->HP > 0.0f) return color_HoppingVampire;
		}
		//EOTN Dungeons
		else if (agent->PlayerNumber == GW::Constants::ModelID::EotnDungeons::StormcloudIncubus) {
			if (agent->HP > 0.9f) return color_StormcloudIncubus;
			if (agent->HP > 0.0f) return color_StormcloudIncubus_Damaged;
		}

		if (agent->HP > 0.9f) return color_hostile;
		if (agent->HP > 0.0f) return color_hostile_damaged;
		return color_hostile_dead;
	}

	// neutrals
	if (agent->Allegiance == 0x2) return color_neutral;

	// friendly
	if (agent->GetIsDead()) return color_ally_dead;
	switch (agent->Allegiance) {
	case 0x1: return color_ally; // ally
	case 0x6: return color_ally_npc; // npc / minipet
	case 0x4: return color_ally_spirit; // spirit / pet
	case 0x5: return color_ally_minion; // minion
	default: break;
	}

	return IM_COL32(0, 0, 0, 0);
}

float AgentRenderer::GetSize(GW::Agent* agent) const {
	if (agent->Id == GW::Agents::GetPlayerId()) return size_player;
	if (agent->GetIsGadgetType()) return size_signpost;
	if (agent->GetIsItemType()) return size_item;
	if (agent->GetHasBossGlow()) return size_boss;

	switch (agent->Allegiance) {
	case 0x1: // ally
	case 0x2: // neutral
	case 0x4: // spirit / pet
	case 0x6: // npc / minipet
		return size_default;

	case 0x5: // minion
		return size_minion;

	case 0x3: // hostile
		switch (agent->PlayerNumber) {
			//Domain of Anguish
		case GW::Constants::ModelID::DoA::StygianLordNecro:
		case GW::Constants::ModelID::DoA::StygianLordMesmer:
		case GW::Constants::ModelID::DoA::StygianLordEle:
		case GW::Constants::ModelID::DoA::StygianLordMonk:
		case GW::Constants::ModelID::DoA::StygianLordDerv:
		case GW::Constants::ModelID::DoA::StygianLordRanger:
		case GW::Constants::ModelID::DoA::BlackBeastOfArgh:
		case GW::Constants::ModelID::DoA::SmotheringTendril:
		case GW::Constants::ModelID::DoA::LordJadoth:
			//Underworld
		case GW::Constants::ModelID::UW::KeeperOfSouls:
		case GW::Constants::ModelID::UW::FourHorseman:
		case GW::Constants::ModelID::UW::Slayer:
		case GW::Constants::ModelID::UW::Dhuum:
		case GW::Constants::ModelID::UW::TerrorwebQueen:
			//Fissure of Woe
		case GW::Constants::ModelID::FoW::ShardWolf:
		case GW::Constants::ModelID::FoW::SeedOfCorruption:
			//SoO
		case GW::Constants::ModelID::SoO::Brigand:
		case GW::Constants::ModelID::SoO::Fendi:
		case GW::Constants::ModelID::SoO::Fendi_soul:
			return size_boss;
		case GW::Constants::ModelID::DoA::StygianFiend:
		case GW::Constants::ModelID::DoA::TheDarkness:
		case GW::Constants::ModelID::UW::SkeletonOfDhuum:
		case GW::Constants::ModelID::UW::SkeletonOfDhuum2:
		case GW::Constants::ModelID::UW::DyingNightmare:
			return size_MVP;
		default:
			return size_default;
		}
		break;

	default:
		return size_default;
	}
}

AgentRenderer::Shape_e AgentRenderer::GetShape(GW::Agent* agent) const {
	if (agent->GetIsGadgetType()) return Quad;
	if (agent->GetIsItemType()) return Quad;

	if (agent->LoginNumber > 0) return Tear;	// players
	if (!agent->GetIsCharacterType()) return Quad; // shouldn't happen but just in case

	auto npcs = GW::Agents::GetNPCArray();
	if (npcs.valid() && agent->PlayerNumber < npcs.size()) {
		GW::NPC& npc = npcs[agent->PlayerNumber];
		switch (npc.ModelFileID) {
		case 0x22A34: // nature rituals
		case 0x2D0E4: // defensive binding rituals
		case 0x2963E: // dummies
			return Circle;
		default:
			break;
		}
	}
	return Tear;
}

void AgentRenderer::Enqueue(Shape_e shape, GW::Agent* agent, float size, Color color) {
	if ((color & IM_COL32_A_MASK) == 0) return;

	unsigned int i;
	for (i = 0; i < shapes[shape].vertices.size(); ++i) {
		const Shape_Vertex& vert = shapes[shape].vertices[i];
		GW::Vector2f pos = vert.Rotated(agent->Rotation_cos, agent->Rotation_sin) * size + agent->pos;
		Color vcolor = color;
		switch (vert.modifier) {
		case Dark: vcolor = Colors::Sub(color, color_agent_modifier); break;
		case Light: vcolor = Colors::Add(color, color_agent_modifier); break;
		case CircleCenter: vcolor = Colors::Sub(color, IM_COL32(0, 0, 0, 50)); break;
		case None: break;
		}
		vertices[i].z = 0.0f;
		vertices[i].color = vcolor;
		vertices[i].x = pos.x;
		vertices[i].y = pos.y;
	}
	vertices += shapes[shape].vertices.size();
	vertices_count += shapes[shape].vertices.size();
}
