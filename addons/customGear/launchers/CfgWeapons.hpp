class CfgWeapons {
    // Base Classes
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };

    // CUP Inheritances
    class CUP_launch_M136_Loaded: Launcher_Base_F {
        class EventHandlers;
    };
    class CUP_launch_M136: CUP_launch_M136_Loaded {};
    class CUP_launch_M136_Used: CUP_launch_M136_Loaded {};
    class CUP_launch_M72A6_Loaded: Launcher_Base_F {
        class WeaponSlotsInfo;
        class EventHandlers;
    };
    class CUP_launch_M72A6: CUP_launch_M72A6_Loaded {};
    class CUP_launch_M72A6_Used: CUP_launch_M72A6_Loaded {};

    //// M136 (AT4) Variants
    // M136A1 AT4 Confined Space-Reduced Sensitivity
    class WEAPON(launch_M136A1_CS_Loaded): CUP_launch_M136_Loaded {
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        discreteDistance[] = {50,100,150,200,250};
        discreteDistanceCameraPoint[] = {"eye_1","eye_2","eye_4","eye_6","eye_8"};
        displayName = "M136A1 CS-RS";
        baseWeapon = QWEAPON(launch_M136A1_CS);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        ACEGVAR(overpressure,angle) = 45;
        ACEGVAR(overpressure,damage) = 0.8;
        ACEGVAR(overpressure,range) = 1;
        magazines[] = {QMAGAZINE(AT4CS_RS)};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 177.4;
        };
        class EventHandlers {
            fired = "_this call CBA_fnc_firedDisposable";
        };
    };
    class WEAPON(launch_M136A1_CS): WEAPON(launch_M136A1_CS_Loaded) {
        author = "Potato";
        baseWeapon = QWEAPON(launch_M136A1_CS);
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 177.4;
        };
    };
    class WEAPON(launch_M136A1_CS_Used): WEAPON(launch_M136A1_CS_Loaded) {
        author = "Potato";
        displayName = "M136A1 CS-RS (Used)";
        baseWeapon = QWEAPON(launch_M136A1_CS_Used);
        model = "\CUP\Weapons\CUP_Weapons_M136\CUP_AT4_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
    };
    // AT4 Confined Space Light Multipurpose Assault Weapon
    class WEAPON(launch_AT4CS_LMAW_Loaded): CUP_launch_M136_Loaded {
        ACEGVAR(overpressure,angle) = 45;
        ACEGVAR(overpressure,damage) = 0.8;
        ACEGVAR(overpressure,range) = 1;
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        discreteDistance[] = {50,100,150,200,250};
        discreteDistanceCameraPoint[] = {"eye_1","eye_2","eye_4","eye_6","eye_8"};
        displayName = "AT4CS LMAW";
        baseWeapon = QWEAPON(launch_AT4CS_LMAW);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(AT4CS_RS)};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_AT4CS_LMAW): WEAPON(launch_AT4CS_LMAW_Loaded) {
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 147.4;
        };
    };
    class WEAPON(launch_AT4CS_LMAW_Used): WEAPON(launch_AT4CS_LMAW_Loaded) {
        displayName = "AT4CS LMAW (Used)";
        baseWeapon = QWEAPON(launch_AT4CS_LMAW_Used);
        model = "\CUP\Weapons\CUP_Weapons_M136\CUP_AT4_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
    };
    // AT4 Confined Space High Penetration
    class WEAPON(launch_AT4CS_HP_Loaded): CUP_launch_M136_Loaded {
        ACEGVAR(overpressure,angle) = 45;
        ACEGVAR(overpressure,damage) = 0.8;
        ACEGVAR(overpressure,range) = 1;
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        discreteDistance[] = {50,100,150,200,250};
        discreteDistanceCameraPoint[] = {"eye_1","eye_2","eye_4","eye_6","eye_8"};
        displayName = "AT4CS HP";
        baseWeapon = QWEAPON(launch_AT4CS_HP);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(AT4CS_HP)};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 108;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_AT4CS_HP): WEAPON(launch_AT4CS_HP_Loaded) {
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 165;
        };
    };
    class WEAPON(launch_AT4CS_HP_Used): WEAPON(launch_AT4CS_HP_Loaded) {
        displayName = "AT4CS HP (Used)";
        baseWeapon = QWEAPON(launch_AT4CS_HP_Used);
    };

    //// M72 LAW Variants
    // M72A7 (HEDP)
    class WEAPON(launch_M72A7_Loaded): CUP_launch_M72A6_Loaded {
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        displayName = "M72A7";
        baseWeapon = QWEAPON(launch_M72A7_Loaded);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(M72A7_M)};
        descriptionShort = "High Explosive Dual Purpose<br/>Unguided";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 47.2;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_M72A7): WEAPON(launch_M72A7_Loaded) {
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 77;
        };
    };
    class WEAPON(launch_M72A7_Used): WEAPON(launch_M72A7_Loaded) {
        displayName = "M72A7 (Used)";
        baseWeapon = QWEAPON(launch_M72A7_Used);
        model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 47.2;
        };
    };
    // M72A8 (High Explosive Dual-Purpose, Fire From Enclosure)
    class WEAPON(launch_M72A8_Loaded): CUP_launch_M72A6_Loaded {
        ACEGVAR(overpressure,damage) = 0;
        ACEGVAR(overpressure,range) = 0;
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        displayName = "M72A8 (FFE)";
        baseWeapon = QWEAPON(launch_M72A8_Loaded);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(M72A8_M)};
        descriptionShort = "High Explosive Dual Purpose<br/>Fire From Enclosure<br/>Unguided";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 47.2;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_M72A8): WEAPON(launch_M72A8_Loaded) {
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 110;
        };
    };
    class WEAPON(launch_M72A8_Used): WEAPON(launch_M72A8_Loaded) {
        displayName = "M72A8 (FFE, Used)";
        baseWeapon = QWEAPON(launch_M72A8_Used);
        model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 47.2;
        };
    };
    // M72A9 (Light Anti-Structure Munition)
    class WEAPON(launch_M72A9_Loaded): CUP_launch_M72A6_Loaded {
        author = "Potato";
        discreteDistance[] = {50,100,150};
        discreteDistanceCameraPoint[] = {"eye_1","eye_2","eye_4"};
        scope = 1;
        scopeArsenal = 1;
        displayName = "M72A9 (LASM)";
        baseWeapon = QWEAPON(launch_M72A9_Loaded);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(M72A9_M)};
        descriptionShort = "Anti-structure missile launcher<br/>Unguided";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            allowedSlots[] = {901};
            mass = 47.4;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_M72A9): WEAPON(launch_M72A9_Loaded) {
        author = "Potato";
        maxRange = 150;
        baseWeapon = QWEAPON(launch_M72A9);
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 94.6;
        };
    };
    class WEAPON(launch_M72A9_Used): WEAPON(launch_M72A9_Loaded) {
        author = "Potato";
        displayName = "M72A9 (LASM) (Used)";
        scope = 1;
        baseWeapon = QWEAPON(launch_M72A9_Used);
        model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 72.4;
        };
    };
    // M72A10 (Light Anti-Structure Munition, Fire From Enclosure)
    class WEAPON(launch_M72A10_Loaded): CUP_launch_M72A6_Loaded {
        ACEGVAR(overpressure,damage) = 0;
        ACEGVAR(overpressure,range) = 0;
        author = "Potato";
        discreteDistance[] = {50,75,100,150};
        discreteDistanceCameraPoint[] = {"eye_1","eye_2","eye_3","eye_4"};
        discreteDistanceInitIndex = 1;
        scope = 1;
        scopeArsenal = 1;
        displayName = "M72A10 (LASM, FFE)";
        baseWeapon = QWEAPON(launch_M72A10_Loaded);
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {QMAGAZINE(M72A10_M)};
        descriptionShort = "Light Anti-Structure Munition<br/>Fire From Enclosure<br/>Unguided";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            allowedSlots[] = {901};
            mass = 47.2;
        };
        class EventHandlers: EventHandlers {};
    };
    class WEAPON(launch_M72A10): WEAPON(launch_M72A10_Loaded) {
        maxRange = 100;
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 127.6;
        };
    };
    class WEAPON(launch_M72A10_Used): WEAPON(launch_M72A10_Loaded) {
        displayName = "M72A10 (HEDP, FFE) (Used)";
        baseWeapon = QWEAPON(launch_M72A10_Used);
        model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 47.2;
        };
    };
};
