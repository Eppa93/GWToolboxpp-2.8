#pragma once

#include <vector>

#include <GWCA\GameEntities\Agent.h>

#include "Color.h"
#include "VBuffer.h"

class AgentRenderer : public VBuffer {
public:
	AgentRenderer();

	void Render(IDirect3DDevice9* device) override;

	void DrawSettings();
	void LoadSettings(CSimpleIni* ini, const char* section);
	void SaveSettings(CSimpleIni* ini, const char* section) const;

private:
	static const size_t shape_size = 4;
	enum Shape_e { Tear, Circle, Quad, BigCircle };
	enum Color_Modifier { 
		None, // rgb 0,0,0
		Dark, // user defined
		Light, // user defined
		CircleCenter // alpha -50
	};
	struct Shape_Vertex : public GW::Vector2f {
		Shape_Vertex(float x, float y, Color_Modifier mod) 
			: GW::Vector2f(x, y), modifier(mod) {}
		Color_Modifier modifier;
	};
	struct Shape_t {
		std::vector<Shape_Vertex> vertices;
		void AddVertex(float x, float y, Color_Modifier mod);
	};
	Shape_t shapes[shape_size];

	void Initialize(IDirect3DDevice9* device) override;

	void Enqueue(GW::Agent* agent);
	Color GetColor(GW::Agent* agent) const;
	float GetSize(GW::Agent* agent) const;
	Shape_e GetShape(GW::Agent* agent) const;

	void Enqueue(Shape_e shape, GW::Agent* agent, float size, Color color);

	D3DVertex* vertices;		// vertices array
	unsigned int vertices_count;// count of vertices
	unsigned int vertices_max;	// max number of vertices to draw in one call
	unsigned int max_shape_verts;// max number of triangles in a single shape

	Color color_agent_modifier;
	Color color_eoe;
	Color color_winnowing;
	Color color_qz;
	Color color_target;
	Color color_player;
	Color color_player_dead;
	Color color_signpost;
	Color color_item;
	Color color_hostile;
	Color color_hostile_damaged;
	Color color_hostile_dead;
	Color color_neutral;
	Color color_ally;
	Color color_ally_npc;
	Color color_ally_spirit;
	Color color_ally_minion;
	Color color_ally_dead;

	//Player 1-8

	Color color_Player1;
	Color color_Player2;
	Color color_Player3;
	Color color_Player4;
	Color color_Player5;
	Color color_Player6;
	Color color_Player7;
	Color color_Player8;

	//EOTN
	Color color_StormcloudIncubus;
	Color color_StormcloudIncubus_Damaged;

	//UW
	Color color_Reapers;
	Color color_Escort;
	Color color_Escort2;
	Color color_Escort3;
	Color color_Escort4;
	Color color_Escort5;
	Color color_Escort6;
	Color color_PitsSoul;


	//FOW
	Color color_Griffons;
	Color color_Forgemaster;
	Color color_Rastigan;

	//DoA
	Color color_Snakes;
	Color color_CoT;
	Color color_TC;

	// -----Underworld-----

	//Abominations
	Color color_DeadCollector;
	Color color_DeadCollector_Damaged;
	Color color_DeadThresher;
	Color color_DeadThresher_Damaged;

	//Behemoths
	Color color_ObsidianBehemoth;
	Color color_ObsidianBehemoth_Damaged;
	Color color_ObsidianGuardian;
	Color color_ObsidianGuardian_Damaged;

	//Dryders
	Color color_KeeperOfSouls;
	Color color_KeeperOfSouls_Damaged;
	Color color_TerrorwebDryder;
	Color color_TerrorwebDryder_Damaged;
	Color color_TerrorwebDryderSilver;
	Color color_TerrorwebDryderSilver_Damaged;

	//Ghosts
	Color color_SmiteCrawler;
	Color color_SmiteCrawler_Damaged;
	Color color_BanishedDreamRider;
	Color color_BanishedDreamRider_Damaged;
	Color color_MindbladeSpectre;
	Color color_MindbladeSpectre_Damaged;
	Color color_TorturedSpirit;
	Color color_TorturedSpirit_Damaged;
	Color color_WailingLord;
	Color color_WailingLord_Damaged;

	//Nightmares
	Color color_BladedAatxe;
	Color color_BladedAatxe_Damaged;
	Color color_GraspingDarkness;
	Color color_GraspingDarkness_Damaged;
	Color color_DyingNightmare;
	Color color_DyingNightmare_Damaged;
	Color color_ChargedBlackness;
	Color color_ChargedBlackness_Damaged;
	Color color_ColdfireNight;
	Color color_ColdfireNight_Damaged;
	Color color_StalkingNight;
	Color color_StalkingNight_Damaged;

	//Skeletons
	Color color_ChampionOfDhuum;
	Color color_ChampionOfDhuum_Damaged;
	Color color_MinionOfDhuum;
	Color color_MinionOfDhuum_Damaged;
	Color color_SkeletonOfDhuum;
	Color color_SkeletonOfDhuum_Damaged;
	Color color_SkeletonOfDhuum_Under50;
	Color color_SkeletonOfDhuum_Under25;

	//Zombies
	Color color_ChainedSoul;
	Color color_chainedSoul_Damaged;

	//Boss-like foes
	Color color_TerrorwebQueen;
	Color color_TerrorwebQueen_Damaged;
	Color color_Slayer;
	Color color_Slayer_Damaged;
	Color color_FourHorseman;
	Color color_FourHorseman_Damaged;
	Color color_Dhuum;
	Color color_Dhuum_Damaged;

	// -----Domain of Anguish-----

	//Margonites
	Color color_MargoniteAnurKaya;
	Color color_MargoniteAnurKaya_Damaged;
	Color color_MargoniteAnurDabi;
	Color color_MargoniteAnurDabi_Damaged;
	Color color_MargoniteAnurSu;
	Color color_MargoniteAnurSu_damaged;
	Color color_MargoniteAnurKi;
	Color color_MargoniteAnurKi_Damaged;
	Color color_MargoniteAnurVu;
	Color color_MargoniteAnurVu_Damaged;
	Color color_MargoniteAnurTuk;
	Color color_MargoniteAnurTuk_Damaged;
	Color color_MargoniteAnurRuk;
	Color color_MargoniteAnurRuk_Damaged;
	Color color_MargoniteAnurRund;
	Color color_MargoniteAnurRund_Damaged;
	Color color_MargoniteAnurMank;
	Color color_MargoniteAnurMank_Damaged;

	//Stygians
	Color color_StygianHunger;
	Color color_StygianHunger_Damaged;
	Color color_StygianBrute;
	Color color_StygianBrute_Damaged;
	Color color_StygianGolem;
	Color color_StygianGolem_Damaged;
	Color color_StygianHorror;
	Color color_StygianHorror_Damaged;
	Color color_StygianFiend;
	Color color_StygianFiend_Damaged;

	//Tormentors
	Color color_MindTormentor;
	Color color_MindTormentor_Damaged;
	Color color_SoulTormentor;
	Color color_SoulTormentor_Damaged;
	Color color_SoulTormentor_Under50;
	Color color_WaterTormentor;
	Color color_WaterTormentor_Damaged;
	Color color_HeartTormentor;
	Color color_HeartTormentor_Damaged;
	Color color_FleshTormentor;
	Color color_FleshTormentor_Damaged;
	Color color_SpiritTormentor;
	Color color_SpiritTormentor_Damaged;
	Color color_EarthTormentor;
	Color color_EarthTormentor_Damaged;
	Color color_SanityTormentor;
	Color color_SanityTormentor_Damaged;
	Color color_TheDarkness;
	Color color_TheDarkness_Damaged;

	//Titans
	Color color_MiseryTitan;
	Color color_MisaryTitan_Damaged;
	Color color_RageTitan;
	Color color_RageTitan_Damaged;
	Color color_DementiaTitan;
	Color color_DementiaTitan_Damaged;
	Color color_AnguishTitan;
	Color color_AnguishTitan_Damaged;
	Color color_DespairTitan;
	Color color_DespairTitan_Damaged;
	Color color_FuryTitan;
	Color color_FuryTitan_Damaged;
	Color color_RageTitan2;
	Color color_RageTitan2_Damaged;
	Color color_DementiaTitan2;
	Color color_DementiaTitan2_Damaged;

	Color color_TorturewebDryder;
	Color color_TorturewebDryder_Damaged;
	Color color_GreatDreamRider;
	Color color_GreatDreamRider_Damaged;

	//Boss-like foes
	Color color_BlackBeastOfArgh;
	Color color_BlackBeastOfArgh_Damaged;
	Color color_SmotheringTendril;
	Color color_SmotheringTendril_Damaged;
	Color color_Fury;
	Color color_Fury_Damaged;
	Color color_LordJadoth;
	Color color_LordJadoth_Damaged;

	// -----Fissure of Woe-----

	//Arachnids
	Color color_ArmoredCaveSpider;
	Color color_ArmoredCaveSpider_Damaged;

	//Dragons
	Color color_ObsidianFurnanceDrake;
	Color color_ObsidianFurnanceDrake_Damaged;

	//Dryders
	Color color_DoubtersDryder;
	Color color_DoubtersDryder_Damaged;

	//Elementals
	Color color_ShardWolf;
	Color color_ShardWolf_Damaged;

	//Ghosts
	Color color_TraitorousTempleGuard;
	Color color_TraitorousTempleGuard_Damaged;
	Color color_TraitorousTempleGuard2;
	Color color_TraitorousTempleGuard3;
	Color color_Banshee;
	Color color_Banshee_Damaged;

	//Hydras
	Color color_MahgoHydra;
	Color color_MahgoHydra_Damaged;

	//Plants
	Color color_SnarlingDriftwood;
	Color color_SnarlingDriftwood_Damaged;
	Color color_SpiritWood;
	Color color_SpiritWood_Damaged;
	Color color_SeedOfCorruption;
	Color color_SeedOfCorruption_Damaged;
	Color color_SpiritShepherd;
	Color color_SpiritShepherd_Damaged;

	//Riders
	Color color_SmokeWalker;
	Color color_SmokeWalker_Damaged;

	//Nightmares
	Color color_Abyssal;
	Color color_Abyssal_Damaged;
	Color color_ShadowOverLord;
	Color color_ShadowOverLord_Damaged;

	Color color_ShadowPatrol;
	Color color_ShadowPatrol_Damaged;
	Color color_ShadowWarrior;
	Color color_ShadowWarrior_Damaged;
	Color color_ShadowRanger;
	Color color_ShadowRanger_Damaged;
	Color color_ShadowMonk;
	Color color_ShadowMonk_Damaged;
	Color color_ShadowBeast;
	Color color_ShadowBeast_Damaged;
	Color color_ShadowMesmer;
	Color color_ShadowMesmer_Damaged;
	Color color_ShadowElemental;
	Color color_ShadowElemental_Damaged;

	//Skale
	Color color_AncientSkale;
	Color color_AncientSkale_Damaged;

	//Skeletons
	Color color_SkeletalBerserker;
	Color color_SkeletalBerserker_Damaged;
	Color color_SkeletalImpaler;
	Color color_SkeletalImpaler_Damaged;
	Color color_SkeletalBond;
	Color color_SkeletalBond_Damaged;
	Color color_SkeletalEtherBreaker;
	Color color_SkeletalEtherBreaker_Damaged;
	Color color_SkeletalIcehand;
	Color color_SkeletalIcehand_Damaged;

	//Worms
	Color color_RockBorerWorm;
	Color color_RockBorerWorm_Damaged;

	//Wurms
	Color color_InfernalWurm;
	Color color_InfernalWurm_Damaged;

	//Zombies
	Color color_DragonLich;
	Color color_DragonLich_Damaged;

	//Bosses
	Color color_Menzies;
	Color color_Menzies_Damaged;
	Color color_LordKhobay;
	Color color_LordKhobay_Damaged;

	// -----Urgoz-----

	Color color_HoppingVampire;

	float size_default;
	float size_player;
	float size_signpost;
	float size_item;
	float size_boss;
	float size_minion;
	float size_MVP;
};
