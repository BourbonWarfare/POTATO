class CfgAmmo {
    class ShellBase;
    class ammo_Penetrator_Base: ShellBase {
        delete submunitionConeType;
        delete submunitionDirectionType;
        delete submunitionInitialOffset;
        delete submunitionParentSpeedCoef;
        delete submunitionInitSpeed;
        delete deleteParentWhenTriggered;
        delete triggerTime;
        submunitionAmmo = "";
    };
};