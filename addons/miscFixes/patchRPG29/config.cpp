#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRPG29

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "RPG29", "potato_core", "CUP_Weapons_LoadOrder", "rhs_main_loadorder" };
        author = "Bourbon Warfare";
        authorURL = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CowsSlot;
class MuzzleSlot;
class SlotInfo;
class WeaponSlotsInfo;
class asdg_SlotInfo;
class asdg_OpticRail;
class asdg_OpticRail1913;
class asdg_MuzzleSlot;
class asdg_MuzzleSlot_338;
class PointerSlot;
class asdg_FrontSideRail;
class asdg_UnderSlot;
class BaseSoundModeType;
class CfgMagazineWells {
	class RPG29 {
		BI_Magazines[] = {"RPG29_AT","RPG29_HE_F","potato_RPG29_FRAG"};
	};
};
class CfgMagazines {
	class CA_Magazine;
	class CA_LauncherMagazine;
	class FakeMagazine;
	class RPG29_F: CA_Magazine {};
	class RPG29_AT: CA_LauncherMagazine {
		ammo = "ammo_RPG29_AT";
	};
	class RPG29_HE_F: CA_LauncherMagazine {
		ammo = "ammo_RPG29_HE";
	};
    class potato_RPG29_FRAG: CA_LauncherMagazine { // custom OG-29 HE-FRAG round
        author = "AChesheireCat";
		scope = 2;
		displayName = "OG-29";
		model = "\A3\weapons_f\launchers\RPG32\tbg32v_rocket_item.p3d";
		modelSpecial = "\RPG29\RPG_loaded.p3d";
		picture = "\CUP\Weapons\CUP_Weapons_Ammunition\data\ui\M_OG7V_ca.paa";
		initSpeed = 240;
		descriptionShort = "High Explosive / Fragmentation";
		displaynameshort = "OG-29";
		ammo = "ammo_RPG29_FRAG";
		type = "2*        256";
		mass = 90;
    };
};
class CfgAmmo {
	class ShellCore;
	class ShellBase;
	class ammo_Penetrator_Base;
    class RocketBase;
	class R_PG32V_F;
    class rhs_rpg26_rocket: R_PG32V_F {};
    class rhs_rpg7v2_pg7vl: rhs_rpg26_rocket {};
    class rhs_rpg7v2_og7v: rhs_rpg7v2_pg7vl {};
	class ammo_Penetrator_PRG29: ammo_Penetrator_Base {
		caliber = 70;
		warheadName = "TandemHEAT";
		hit = 390;
		submunitionAmmo = "ammo_Penetrator_PRG29k";
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionInitSpeed = 1000;
		submunitionParentSpeedCoef = 0;
		submunitionInitialOffset[] = {0,0,-0.2};
		triggerOnImpact = 1;
		deleteParentWhenTriggered = 0;
	};
	class ammo_Penetrator_PRG29k: ammo_Penetrator_Base {
		caliber = 50;
		warheadName = "TandemHEAT";
		hit = 500;
	};
    class ammo_RPG29_AT: R_PG32V_F {
        AIAmmoUsageFlags = "128+256+512";
		model = "\A3\weapons_f\launchers\RPG32\pg32v_rocket_item.p3d";
		submunitionAmmo = "ammo_Penetrator_PRG29";
        hit = 115;
		indirectHit = 20;
		indirectHitRange = 4;
		cost = 200;
		airFriction = 0.01;
		sideAirFriction = 0.0;
		simulationStep = 0.01;
		maxSpeed = 290;
		initTime = 0;
		thrust = 0.1;
		fuseDistance = 15;
		visibleFire = 28;
		audibleFire = 16;
		whistleDist = 32;
		timeToLive = 25;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
//		effectsMissileInit = "RocketBackEffectsRPG";
		effectsMissile = "missile3";
        airLock = 1;
		class CamShakeFire
		{
			power = 10;
			duration = 0.5;
			frequency = 20;
			distance = 30;
		};
		class CamShakePlayerFire
		{
			power = 5;
			duration = 0.1;
			frequency = 20;
		};
		soundFly[] = {"A3\Sounds_F\arsenal\weapons_static\Missile_Launcher\rocket_fly",1.1,0.7,250};
        class EventHandlers;
    };
    class ammo_RPG29_HE: ammo_RPG29_AT {
        warheadName = "HE";
        AIAmmoUsageFlags = "64+128+256";
        model = "\rhsafrf\addons\rhs_weapons\rpg7\projectiles\tbg7v";
        hit = 120;
        indirectHit = 60;
		indirectHitRange = 12;
        explosive = 1;
        allowAgainstInfantry = 1;
		cost = 100; // was 300
		maxSpeed = 290; // was 110
		initTime = 0; // was 0.15
		airfriction = 0.01; // was 0.9
		sideAirFriction = 0.0; // was 0.1
		thrust = 0.1; // was 120
		fuseDistance = 15; // was 5
		timeToLive = 60; // was 6
		airLock = 0; // was 1
        CraterEffects = "ArtyShellCrater";
		explosionEffects = "RHS_FAE_Explosion";
        submunitionConeAngle[] = {120,220};
		submunitionConeAngleHorizontal = 720;
		submunitionAutoleveling = 1;
		submunitionConeType[] = {"randomupcone",15};
		submunitionAmmo = "rhs_ammo_thermobaric_wave";
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionInitialOffset[] = {0,0,-0.4};
		submunitionParentSpeedCoef = 0;
		submunitionInitSpeed = 200;
		deleteParentWhenTriggered = 0;
		triggerTime = -1;
		triggerOnImpact = 1;
    };
    class ammo_RPG29_FRAG: rhs_rpg7v2_og7v {
		cost = 50; // was 300
		maxSpeed = 290; // was 110
		initTime = 0; // was 0.15
		airfriction = 0.01; // was 0.9
		sideAirFriction = 0.0; // was 0.1
		thrust = 0.1; // was 120
		fuseDistance = 15; // was 5
		timeToLive = 25; // was 6
		airLock = 0; // was 1
    };
};
class CfgWeapons {
	class Launcher;
	class Launcher_Base_F: Launcher {
		class WeaponSlotsInfo;
		class Eventhandlers;
	};
	class CUP_launch_MAAWS: Launcher_Base_F {};
	class RPG29_Lorad: CUP_launch_MAAWS {
		class Single: Mode_SemiAuto {
			sounds[] = {"StandardSound"};
			class StandardSound {
                weaponSoundEffect = "DefaultRifle";
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\rpg32",1.9952624,1,1500};
				soundBegin[] = {"begin1",1};
				soundSetShot[] = {"Launcher_MRAWS_Shot_SoundSet","Launcher_MRAWS_Tail_SoundSet"};
			};
		};
		magazines[] = {"RPG29_AT","RPG29_HE_F","potato_RPG29_FRAG"};
		magazineWell[] = {"RPG29"};
		reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\reload_RPG32",0.25118864,1,10};
		recoil = "recoil_rpg";
	};
};