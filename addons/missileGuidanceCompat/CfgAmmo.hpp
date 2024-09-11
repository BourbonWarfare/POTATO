class CfgAmmo {
    class CUP_M_Stinger_AA;
    class ShellBase;

    class ace_dragon_serviceCharge: ShellBase {
        soundSetExplosion[] = {};
    };
    class GVAR(redeye): CUP_M_Stinger_AA {
        maneuvrability = 0;
        ACE_MISSILE(Redeye);
    };
};

