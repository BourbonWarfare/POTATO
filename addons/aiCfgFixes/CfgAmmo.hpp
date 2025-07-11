class CfgAmmo {
    class Default;
    class BulletCore: Default {
        audibleFire = 16;
    };
    class RocketCore: Default {
        audibleFire = 32;
    };
    class GrenadeCore: Default {
        audibleFire = 0.25;
    };
    class ShellCore: Default {
        audibleFire = 16;
    };
    class SubmunitionCore: Default {
        audibleFire = 16;
    };
    class MissileCore: Default {
        audibleFire = 32;
    };
    class Grenade: Default {
        audibleFire = 0.25;
    };
    class LaserCore: Default {
        audibleFire = 32;
    };
    class TimeBombCore: Default {
        audibleFire = 0;
    };
    class ShotDeployCore: Default {
        audibleFire = 16;
    };
    class ShotgunCore: Default {
        audibleFire = 16;
    };
    class BulletBase: BulletCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class FakeAmmo: BulletCore {
        audibleFire = 16;
    };
    class cwr3_b_30mm_nr30_hedp_tracer_red: BulletBase {
        audibleFire = 32;
    };
    class cwr3_vickers_ammo: BulletBase {
        audibleFire = 13;
    };
    class cwr3_b_23x115_green_tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_25mm_APFSDS_White_Tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_25mm_HE_White_Tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_30mm_CAS_Red_Tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_30x113mm_M789_HEDP_Red_Tracer: BulletBase {
        audibleFire = 28;
    };
    class CUP_B_23mm_APHE_Green_Tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_23mm_APHE_No_Tracer: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_23mm_AA: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_23mm_APHE_Tracer_Green: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_20mm_AA: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_20mm_API_Tracer_Red: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_20mm_APHE_Tracer_Red: BulletBase {
        audibleFire = 32;
    };
    class CUP_B_20mm_AP_Tracer_Red: BulletBase {
        audibleFire = 28;
    };
    class CUP_B_19mm_HE: BulletBase {
        audibleFire = 18;
    };
    class CUP_B_145x115_AP_Green_Tracer: BulletBase {
        audibleFire = 25;
    };
    class CUP_B_127x108_Ball_Green_Tracer: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_127x107_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_762x25_Ball: BulletBase {
        audibleFire = 45;
    };
    class CUP_B_46x30_Ball: BulletBase {
        audibleFire = 7;
    };
    class CUP_B_50AE_Ball: BulletBase {
        audibleFire = 45;
    };
    class CUP_B_765x17_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_9x19_AP: BulletBase {
        audibleFire = 5;
    };
    class CUP_B_9x19_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_9x18_Ball: BulletBase {
        audibleFire = 5;
    };
    class CUP_B_86x70_Ball_noTracer: BulletBase {
        audibleFire = 22;
    };
    class CUP_B_9x39_SP5: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class CUP_B_762x54_Ball_White_Tracer: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_303_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_762x51_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_762x39_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_556x45_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_20mm_AP: BulletBase {
        audibleFire = 200;
    };
    class ammo_Gun35mmAABase: BulletBase {
        audibleFire = 200;
    };
    class ammo_Gun30mmAABase: BulletBase {
        audibleFire = 200;
    };
    class ammo_Gun20mmAABase: BulletBase {
        audibleFire = 200;
    };
    class B_570x28_Ball: BulletBase {
        audibleFire = 25;
    };
    class B_93x64_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_127x54_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class B_338_NM_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_338_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class Gatling_30mm_HE_Plane_CAS_01_F: BulletBase {
        audibleFire = 250;
    };
    class B_45ACP_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class B_coil_5g_spike: BulletBase {
        audibleFire = 0.01;
    };
    class B_35mm_AA: BulletBase {
        audibleFire = 200;
    };
    class B_30mm_AP: BulletBase {
        audibleFire = 200;
    };
    class B_25mm: BulletBase {
        audibleFire = 200;
    };
    class B_20mm: BulletBase {
        audibleFire = 200;
    };
    class B_19mm_HE: BulletBase {
        audibleFire = 150;
    };
    class B_127x108_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_127x99_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_127x33_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_408_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_9x21_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_56x15_dual: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class RocketBase: RocketCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class R_PG32V_F;
    class cwr3_r_carlgustaf_hedp: RocketBase {
        audibleFire = 16;
    };
    class CUP_R_SMAW_HEDP_N: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_RSHG2_HE: RocketBase {
        audibleFire = 16;
    };
    class CUP_R_PG26_AT: RocketBase {
        audibleFire = 16;
    };
    class CUP_R_RPG18_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_APILAS_AT: RocketBase {
        audibleFire = 16;
    };
    class CUP_R_MEEWS_HEDP: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 150;
    };
    class CUP_R_M136_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_SMAW_HEDP: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_70mm_Hydra_HE: RocketBase {
        aiAmmoUsageFlags = 64 + 128 + 512;
        allowAgainstInfantry = 1;
        cost = 100;
    };
    class CUP_R_PZF3IT_AT: RocketBase {
        audibleFire = 16;
    };
    class CUP_R_OG7_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_TBG7V_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256;
        allowAgainstInfantry = 1;
        cost = 150;
    };
    class CUP_R_PG7VR_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_PG7VL_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_PG7VM_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class CUP_R_PG7V_AT: RocketBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
    class cwr3_r_rpg75_at: R_PG32V_F {
        audibleFire = 16;
    };
    class GrenadeBase;
    class FlareCore;
    class SmokeShellCore: GrenadeCore {
        audibleFire = 0.25;
    };
    class G_40mm_HE: GrenadeBase {
        audibleFire = 30;
    };
    class M261_SM_MELB: GrenadeBase {
        audibleFire = 30;
    };
    class CUP_G_40mm_HE;
    class CUP_G_30mm_HE: CUP_G_40mm_HE {
        audibleFire = 18;
    };
    class CUP_R_CRV7_C18_HE: CUP_R_70mm_Hydra_HE {
        audibleFire = 32;
    };
    class CUP_B_9x19_Ball_SD: CUP_B_9x19_Ball {
        audibleFire = 0.35;
    };
    class CUP_B_9x18_SD: CUP_B_9x18_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class CUP_B_762x51_noTracer;
    class ACE_762x51_Ball_Subsonic: B_762x51_Ball {
        audibleFire = 5;
    };
    class CUP_B_762x51_White_Tracer_3RndBurst: CUP_B_762x51_noTracer {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_762x51_Red_Tracer_3RndBurst: CUP_B_762x51_noTracer {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class CUP_B_762x39_Ball_Subsonic: CUP_B_762x39_Ball {
        audibleFire = 3;
    };
    class CUP_B_762x39_Ball_Tracer_Green: CUP_B_762x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class ShellBase: ShellCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class ACE_HuntIR_Propell: ShellBase {
        audibleFire = 1;
    };
    class R_230mm_fly: ShellBase {
        audibleFire = 64;
    };
    class FH_545x39_Ball: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_556x45_dual: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class FH_545x39_EP: FH_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class FH_545x39_7u1: FH_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class SubmunitionBase;
    class VOG25P_SubMunition: SubmunitionBase {
        audibleFire = 6;
    };
    class SubmunitionBullet;
    class M257_Flare_MELB: FlareCore {
        audibleFire = 20;
    };
    class FlareBase;
    class MissileBase: MissileCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class ammo_Missile_CruiseBase: MissileBase {
        audibleFire = 64;
    };
    class M_Mo_155mm_AT;
    class M_Mo_230mm_AT: M_Mo_155mm_AT {
        audibleFire = 64;
    };
    class M_Mo_155mm_AT_LG;
    class M_Mo_230mm_AT_LG: M_Mo_155mm_AT_LG {
        audibleFire = 64;
    };
    class F_40mm_White: FlareBase {
        audibleFire = 20;
    };
    class GrenadeHand: Grenade {
        audibleFire = 0.05;
    };
    class B_30mm_HE: B_19mm_HE {
        audibleFire = 200;
    };
    class B_762x51_Minigun_Tracer_Red: SubmunitionBullet {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_65x39_Minigun_Caseless: SubmunitionBullet {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class R_80mm_HE;
    class potato_aiCfgFixes_he_rocket: R_80mm_HE {
        aiAmmoUsageFlags = 64 + 128 + 512;
        allowAgainstInfantry = 1;
        cost = 100;
    };
    class CUP_R_57mm_HE: RocketBase {
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 150;
    };
    class CUP_R_M72A6_AT: RocketBase {
        aiAmmoUsageFlags = 64 + 128 + 256 + 512;
        allowAgainstInfantry = 1;
        cost = 50;
    };
};

