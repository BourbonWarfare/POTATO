class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        muzzles[] += {"potato_potatoMuzzle"};

        class ThrowMuzzle;
        class potato_potatoMuzzle: ThrowMuzzle {
            magazines[] = {"potato_potato"};
        };
    };
};
