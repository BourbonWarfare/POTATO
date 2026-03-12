#define SET_SOUND_FLY(pitch,volume) soundFly[] = {"CUP\Weapons\CUP_Weapons_Ammunition\data\sound\shorter.wss",volume,pitch,1000}
#define PITCH_155MM 0.4
#define VOLUME_155MM 3.5
#define PITCH_122MM 1
#define VOLUME_122MM 3
#define PITCH_120MM 1.05
#define VOLUME_120MM 2.5
#define PITCH_105MM 1.5
#define VOLUME_105MM 2.25
#define PITCH_8XMM 2
#define VOLUME_8XMM 2
#define PITCH_110MM_ROCKET 0.5
#define VOLUME_110MM_ROCKET 0.5

#define CREATE_AMMOS_PITCH(parent,grandparent,pitch,volume) class parent: grandparent { SET_SOUND_FLY(pitch,volume); };\
class GVARMAIN(DOUBLES(parent,noFrag)): parent {\
    ACEGVAR(frag,skip) = 1;\
};\
class GVARMAIN(DOUBLES(parent,noSplash)): GVARMAIN(DOUBLES(parent,noFrag)) {\
    indirectHit = 0;\
    indirectHitRange = 0;\
    hit = 8;\
}

class CfgAmmo {
    CREATE_AMMOS(CUP_R_MLRS_HE);
    CREATE_AMMOS_SUBMUNTION(CUP_R_GRAD_HE,potato_R_GRAD_HE_fly);

    //// Audio effects
    // Vanilla
    class SubmunitionBase;
    class Sh_82mm_AMOS_guided: SubmunitionBase { SET_SOUND_FLY(PITCH_8XMM,VOLUME_8XMM); };
    class Sh_155mm_AMOS_guided: Sh_82mm_AMOS_guided { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };
    class Sh_82mm_AMOS_LG: Sh_82mm_AMOS_guided {};
    class Sh_155mm_AMOS_LG: Sh_82mm_AMOS_LG { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };
    class ShellBase;
    class Sh_155mm_AMOS: ShellBase { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };
    class Sh_82mm_AMOS: Sh_155mm_AMOS { SET_SOUND_FLY(PITCH_8XMM,VOLUME_8XMM); };
    class MissileBase;
    class M_Mo_82mm_AT: MissileBase { SET_SOUND_FLY(PITCH_8XMM,VOLUME_8XMM); };
    class M_Mo_120mm_AT: M_Mo_82mm_AT { SET_SOUND_FLY(PITCH_120MM,VOLUME_120MM); };
    class M_Mo_155mm_AT: M_Mo_120mm_AT { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };

    // GM
    //class gm_Submunition_base;
    //class gm_rocket_mlrs_110mm_base: gm_Submunition_base { SET_SOUND_FLY(PITCH_110MM_ROCKET); };
    class gm_shell_artillery_HE_Base;
    class gm_shell_120mm_he_dm51: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_120MM,VOLUME_120MM); };
    class gm_shell_120mm_he_of843: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_120MM,VOLUME_120MM); };
    class gm_shell_155mm_he_m107: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };
    class gm_shell_155mm_he_m795: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_155MM,VOLUME_155MM); };
    class gm_shell_122x447mm_he_of462: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_122MM,VOLUME_122MM); };
    class gm_shell_122x447mm_he_3of56: gm_shell_artillery_HE_Base { SET_SOUND_FLY(PITCH_122MM,VOLUME_122MM); };

    // CUP Audio and config
    CREATE_AMMOS_PITCH(CUP_Sh_105_HE,Sh_155mm_AMOS,PITCH_105MM,VOLUME_105MM);
    CREATE_AMMOS_PITCH(CUP_Sh_122_HE,Sh_155mm_AMOS,PITCH_122MM,VOLUME_122MM);
};
