class ACEGVAR(missileguidance,type_AMRAAM);
class ACEGVAR(missileguidance,type_ASRAAM);
class ACEGVAR(missileguidance,type_Dagr);
class ACEGVAR(missileguidance,type_Dragon);
class ACEGVAR(missileguidance,type_ESSM);
class ACEGVAR(missileguidance,type_Hellfire);
class ACEGVAR(missileguidance,type_Hot);
class ACEGVAR(missileguidance,type_Javelin);
class ACEGVAR(missileguidance,type_Jdam);
class ACEGVAR(missileguidance,type_Maverick);
class ACEGVAR(missileguidance,type_Milan);
class ACEGVAR(missileguidance,type_Nlaw);
class ACEGVAR(missileguidance,type_Patriot);
class ACEGVAR(missileguidance,type_Paveway);
class ACEGVAR(missileguidance,type_RAM);
class ACEGVAR(missileguidance,type_RBS70);
class ACEGVAR(missileguidance,type_Redeye);
class ACEGVAR(missileguidance,type_Sidewinder);
class ACEGVAR(missileguidance,type_Stinger);
class ACEGVAR(missileguidance,type_TOW);
class ACEGVAR(missileguidance,type_Blowpipe);
class GVAR(laser_artillery) {
    enabled = 0;
    canVanillaLock = 0;
    pitchRate = 15;
    yawRate = 15;
    stabilityCoefficient = 0.2;
    bangBangGuidance = 1;
    defaultAttackProfile = "DIR";
    defaultSeekerType = "SALH";
    seekerTypes[] = { "SALH" };

    defaultSeekerLockMode = "LOAL";
    seekerLockModes[] = { "LOAL" };

    defaultNavigationType = "Direct";
    navigationTypes[] = { "Direct" };

    seekLastTargetPos = 1;
    seekerAngle = 30;
    seekerAccuracy = 1;

    seekerMinRange = 1;
    seekerMaxRange = 3000;
    attackProfiles[] = {"DIR"};
};
