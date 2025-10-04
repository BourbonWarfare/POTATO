class CfgAmmo {
    class Default;
    class RocketCore: Default {
        audibleFire = 32;
    };
    class BulletCore: Default {
        audibleFire = 16;
    };
    class GrenadeCore: Default {
        audibleFire = 0.25;
    };
    class ShellCore: Default {
        audibleFire = 16;
    };
    class MissileCore: Default {
        audibleFire = 32;
    };
    class Grenade: Default {
        audibleFire = 0.25;
    };
    class SubmunitionCore: Default {
        audibleFire = 16;
    };
    class RocketBase: RocketCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class R_PG32V_F;
    class rhs_ammo_rpg75_rocket: R_PG32V_F {
        aiAmmoUsageFlags = 704;
        audibleFire = 16;
    };
    class rhs_rpg26_rocket: R_PG32V_F {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class BulletBase: BulletCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class vn_fakeammo: BulletCore {
        audibleFire = 16;
    };
    class B_556x45_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_762x51_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_19mm_HE: BulletBase {
        audibleFire = 150;
    };
    class vn_shrapnel_airburst_deploy_large: BulletBase {
        audibleFire = 64;
    };
    class vn_20x110: BulletBase {
        audibleFire = 200;
    };
    class vn_BulletBase;
    class vn_melee_stab: BulletBase {
        audibleFire = 0.1;
    };
    class B_9x21_Ball: BulletBase {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class B_35mm_AA: BulletBase {
        audibleFire = 200;
    };
    class B_30mm_AP: BulletBase {
        audibleFire = 200;
    };
    class RHS_Ammo_DIRCM_Vitebsk: BulletBase {
        audibleFire = 0;
    };
    class HLC_9x19_Ball;
    class HLC_3006_FMJ: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_68x43_FMJ: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_300WM_BTSP;
    class HLC_300WM_Tracer: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_300WM_FMJ: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_303Brit_B;
    class HLC_300Blackout_Ball;
    class HLC_556NATO_SPR: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_556NATO_SOST: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_556NATO_EPR: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_545x39_Ball: B_556x45_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_10mm_FMJ;
    class HLC_9x19_Subsonic: HLC_9x19_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class HLC_763x25_FMJ: HLC_10mm_FMJ {
        audibleFire = 3;
    };
    class HLC_GP11_FMJ;
    class rhs_B_762x39_Ball: B_762x51_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_762x54_Ball: B_762x51_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_GP11_tracer: HLC_GP11_FMJ {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class hlc_68x43_Sub: HLC_68x43_FMJ {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class hlc_68x43_OTM: HLC_68x43_FMJ {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_300WM_S_BT: HLC_300WM_BTSP {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class HLC_300WM_BTHP: HLC_300WM_BTSP {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_300WM_AP: HLC_300WM_BTSP {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_792x57_Ball: HLC_303Brit_B {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_792x57_AP: HLC_792x57_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_792x57_Tracer: HLC_792x57_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class HLC_300Blackout_RNBT: HLC_300Blackout_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class HLC_300Blackout_SMK: HLC_300Blackout_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class B_30mm_HE: B_19mm_HE {
        audibleFire = 200;
    };
    class GrenadeBase;
    class vn_m10_ammo: GrenadeBase {
        audibleFire = 100;
    };
    class vn_40mm_he_v_ammo: GrenadeBase {
        audibleFire = 6;
    };
    class ShellBase: ShellCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class vn_missile_type63_he_sub: ShellBase {
        audibleFire = 64;
    };
    class vn_flechette_airburst_deploy_rocket_70mm_darts: ShellBase {
        audibleFire = 5;
    };
    class R_230mm_fly: ShellBase {
        audibleFire = 64;
    };
    class MissileBase: MissileCore {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class vn_145x114: vn_20x110 {
        audibleFire = 25;
    };
    class vn_pistolbullet_base: vn_BulletBase {
        audibleFire = 20;
    };
    class vn_riflebullet_base: vn_BulletBase {
        audibleFire = 9;
    };
    class vn_mk1_udg_ammo: vn_pistolbullet_base {
        audibleFire = 0.01;
    };
    class vn_357: vn_pistolbullet_base {
        audibleFire = 18;
    };
    class vn_765x17: vn_pistolbullet_base {
        audibleFire = 0.035;
    };
    class vn_560x15: vn_pistolbullet_base {
        audibleFire = 0.035;
    };
    class vn_shotgunbase;
    class vn_40mm_m576_buck_ammo: vn_shotgunbase {
        audibleFire = 8;
    };
    class vn_12g_buck;
    class GrenadeHand: Grenade {
        audibleFire = 0.05;
    };
    class rhs_ammo_3d17_shell: Grenade {
        audibleFire = 0.05;
    };
    class vn_grenadehand: GrenadeHand {
        audibleFire = 0.05;
    };
    class vn_792x33;
    class vn_762x51: vn_riflebullet_base {
        audibleFire = 9;
    };
    class vn_556x45: vn_riflebullet_base {
        audibleFire = 6;
    };
    class vn_127x99: vn_riflebullet_base {
        audibleFire = 120;
    };
    class vn_792x57: vn_792x33 {
        audibleFire = 22;
    };
    class vn_762x51_m134: vn_762x51 {
        audibleFire = 22;
    };
    class vn_12g_fl: vn_12g_buck {
        audibleFire = 100;
    };
    class FlareBase;
    class vn_m127_flare_ammo: FlareBase {
        audibleFire = 20;
    };
    class rhs_B_9x21_7BT3: B_9x21_Ball {
        audibleFire = 5.65;
    };
    class rhs_B_9x21_7N29: B_9x21_Ball {
        audibleFire = 5.65;
    };
    class rhs_B_9x21_7N28: B_9x21_Ball {
        audibleFire = 5.65;
    };
    class rhs_B_9x18_57N181S: B_9x21_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_9x19_7N21: B_9x21_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_rpg7v2_pg7vl: rhs_rpg26_rocket {
        aiAmmoUsageFlags = 960;
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_9x39_SP5: rhs_B_762x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class rhs_B_762x39_U_Ball: rhs_B_762x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class rhs_B_545x39_7U1_Ball: rhs_B_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_1;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_1";
    };
    class rhs_B_545x39_7N24_Ball: rhs_B_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_545x39_7N22_Ball: rhs_B_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_545x39_7N10_Ball: rhs_B_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class rhs_B_545x39_7N6_Ball: rhs_B_545x39_Ball {
        audibleFire = AI_AUDIBLE_FIRE_0;
        GVAR(macroUsed) = "AI_AUDIBLE_FIRE_0";
    };
    class SubmunitionBase;
    class rhs_ammo_mixed_23x115mm: SubmunitionBase {
        audibleFire = 32;
    };
    class rhs_ammo_gsh30_mixed: SubmunitionBase {
        audibleFire = 32;
    };
    class RHS_ammo_23mm_AA: B_35mm_AA {
        audibleFire = 32;
    };
    class rhs_ammo_30x165mm_base: B_30mm_AP {
        audibleFire = 32;
    };
    class rhs_m21OF_fly: R_230mm_fly {
        audibleFire = 64;
    };
};

