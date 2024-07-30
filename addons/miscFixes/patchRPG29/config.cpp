#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRPG29

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "RPG29", "potato_core", "rhs_main_loadorder" };
        skipWhenMissingDependencies = 1;
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
    class rhs_rpg7_PG7VL_mag: CA_LauncherMagazine {};
    class rhs_rpg7_PG7VR_mag: rhs_rpg7_PG7VL_mag {};
    class rhs_rpg7_TBG7V_mag: rhs_rpg7_PG7VL_mag {};
    class rhs_rpg7_OG7V_mag: rhs_rpg7_PG7VL_mag {};
	class RPG29_F: CA_Magazine {};
	class RPG29_AT: CA_LauncherMagazine {
		author = "NVGS";
		scope = 2;
		displayName = "PG-29V";
		model = "\A3\weapons_f\launchers\RPG32\pg32v_rocket_item.p3d";
		modelSpecial = "\RPG29\RPG_loaded.p3d";
		picture = "\A3\Weapons_F\launchers\RPG32\data\UI\gear_rpg32_rocket_ca.paa";
		initSpeed = 240;
		descriptionShort = "High Explosive Anti tank";
		displaynameshort = "PG-29V";
		ammo = "ammo_RPG29_AT";
		type = "2*        256";
		mass = 90;
	};
	class RPG29_HE_F: CA_LauncherMagazine {
		author = "NVGS";
		scope = 2;
		displayName = "TBG-29V";
		model = "\A3\weapons_f\launchers\RPG32\tbg32v_rocket_item.p3d";
		modelSpecial = "\RPG29\RPG_loaded.p3d";
		picture = "\A3\Weapons_F\launchers\RPG32\data\UI\gear_tbg32v_rocket_ca.paa";
		initSpeed = 240;
		descriptionShort = "High Explosive";
		displaynameshort = "TBG-29V";
		ammo = "ammo_RPG29_HE";
		type = "2*        256";
		mass = 90;
	};
    class potato_RPG29_FRAG: CA_LauncherMagazine { // OG-29 HE-FRAG round
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
    class rhs_rpg7v2_pg7vr: rhs_rpg7v2_pg7vl {};
    class rhs_rpg7v2_tbg7v: rhs_rpg7v2_pg7vl {};
    class rhs_rpg7v2_og7v: rhs_rpg7v2_pg7vl {};
	class ammo_Penetrator_PRG29: ammo_Penetrator_Base {
		caliber = 70;
		warheadName = "TandemHEAT";
		hit = 500;
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
		effectsMissile = "missile2";
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
	class InventoryOpticsItem_Base_F;
	class Rifle;
	class Rifle_Base_F: Rifle {
		class WeaponSlotsInfo;
		class GunParticles;
		class Eventhandlers;
	};
	class Rifle_Short_Base_F: Rifle_Base_F {
		class WeaponSlotsInfo;
	};
	class Pistol;
	class Pistol_Base_F: Pistol {
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class Rifle_Long_Base_F: Rifle_Base_F {
		class WeaponSlotsInfo;
	};
	class UGL_F;
	class EBR_base_F;
	class srifle_EBR_F: EBR_base_F {
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class Launcher;
	class Launcher_Base_F: Launcher {
		class WeaponSlotsInfo;
		class Eventhandlers;
	};
	class CUP_launch_MAAWS: Launcher_Base_F {}; //CUP_launch_MAAWS
	class RPG29_Lorad: CUP_launch_MAAWS {
		dlc = "NVGS";
		audiblefire = 20;
		author = "NVGS";
		scope = 2;
		displayName = "RPG-29";
		model = "RPG29\RPG.p3d";
		picture = "\RPG29\RPG.paa";
		handAnim[] = {"OFP2_ManSkeleton","\rhsafrf\addons\rhs_c_weapons\anims\igla.rtm"};
		reloadAction = "ReloadRPG";
		modelOptics = "-";
		weaponInfoType = "RscWeaponZeroing";
		memoryPointCamera = "OP_eye";
		opticsZoomMin = 0.1083;
		opticsZoomMax = 0.1083;
		opticsZoomInit = 0.1083;
		class OpticsModes {
			class irons {
				opticsID = 1;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				opticsZoomMin = 0.1083;
				opticsZoomMax = 0.1083;
				opticsZoomInit = 0.1083;
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				distanceZoomMin = 100;
				distanceZoomMax = 300;
				cameraDir = "OP_look";
				discreteDistance[] = {100,150,200,300};
				discreteDistanceCameraPoint[] = {"OP_eye2","OP_eye6","OP_eye3","OP_eye4"};
				discreteDistanceInitIndex = 0;
			};
			delete optic;
		};
		class GunParticles {
			class effect1 {
				positionName = "BackBlast2";
				directionName = "BackBlast1";
				effectName = "RocketBackEffectsRPGNT";
			};
		};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto {
			sounds[] = {"StandardSound"};
			class StandardSound {
                weaponSoundEffect = "DefaultRifle";
				begin1[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\rpg32",1.9952624,1,1500};
				soundBegin[] = {"begin1",1};
				soundSetShot[] = {"Launcher_MRAWS_Shot_SoundSet","Launcher_MRAWS_Tail_SoundSet"};
			};
			recoil = "recoil_single_law";
			aiRateOfFire = 7;
			aiRateOfFireDistance = 600;
			minRange = 10;
			minRangeProbab = 0.3;
			midRange = 400;
			midRangeProbab = 0.8;
			maxRange = 600;
			maxRangeProbab = 0.1;
			dispersion = 0.35;
		};
		magazines[] = {"RPG29_AT","RPG29_HE_F","potato_RPG29_FRAG"};
		magazineWell[] = {"RPG29"};
		drySound[] = {"A3\sounds_f\weapons\other\dry6",0.4466836,1,20};
		reloadMagazineSound[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\reload_RPG32",0.25118864,1,10};
		recoil = "recoil_rpg";
		soundFly[] = {"A3\sounds_f\weapons\rockets\rocket_fly_1",0.31622776,1.5,900};
		canLock = 0;
		weaponLockDelay = 3;
		lockAcquire = 0;
		inertia = 0.9;
		aimTransitionSpeed = 0.5;
		dexterity = 0.5;
		class WeaponSlotsInfo: WeaponSlotsInfo {
			allowedslots[] = {901};
			mass = "187,4";
			class CowsSlot {
				access = 1;
				compatibleitems[] = {"optic_PGO"};
				displayname = "Optics Slot";
				linkproxy = "\A3\data_f\proxies\weapon_slots\TOP";
				scope = 2;
			};
		};
	};
	class ItemCore;
	class optic_PGO: ItemCore {
		author = "NVGS";
		scope = 2;
		displayName = "PGO-29";
		picture = "\RPG29\RPG.paa";
		model = "RPG29\pgo-29.p3d";
		descriptionShort = "";
		weaponInfoType = "RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F {
			mass = 8;
			opticType = 0;
			optics = 2;
			modelOptics = "\rhsafrf\addons\rhs_weapons\acc\scopes\optics\rhs_pgo7v2_scope";
			class OpticsModes {
				class optic {
					opticsID = 2;
					useModelOptics = 1;
					opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
					discreteDistance[] = {500};
					discreteDistanceInitIndex = 0;
					opticsZoomMin = 0.12963;
					opticsZoomMax = 0.12963;
					opticsZoomInit = 0.12963;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = 1;
					opticsDisablePeripherialVision = 1;
					distanceZoomMin = 200;
					distanceZoomMax = 1000;
					cameraDir = "direction";
				};
			};
		};
		inertia = 0.1;
	};
};