class CfgWeapons {
    // Base Classes
    class Launcher;
    class Launcher_Base_F: Launcher {
        class WeaponSlotsInfo;
    };
    
    // CUP Inheritances
    class CUP_launch_M136_Loaded: Launcher_Base_F {
        class WeaponSlotsInfo;
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
    
    // M136 AT4 Confined Space-Reduced Sensitivity
    class potato_launch_M136A1_CS_Loaded: CUP_launch_M136_Loaded {
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        displayName = "M136A1 CS-RS";
        baseWeapon = "potato_launch_M136A1_CS_Loaded";
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        AGM_UsedTube = "AGM_launch_M136_Used_F";
        ace_overpressure_angle = 10;
        ace_overpressure_damage = 0.5;
        ace_overpressure_range = 4;
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 177.4;
        };
        class EventHandlers {
            fired = "_this call CBA_fnc_firedDisposable";
        };
    };
    class potato_launch_M136A1_CS: potato_launch_M136A1_CS_Loaded {
        author = "Potato";
        baseWeapon = "potato_launch_M136A1_CS";
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 177.4;
        };
    };
    class potato_launch_M136A1_CS_Used: potato_launch_M136A1_CS_Loaded {
        author = "Potato";
        displayName = "M136A1 CS-RS (Used)";
        scope = 1;
        baseWeapon = "potato_launch_M136A1_CS_Used";
        model = "\CUP\Weapons\CUP_Weapons_M136\CUP_AT4_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 117.4;
        };
    };
    
    // M72A9 (Light Anti-Structure Munition)
    class potato_launch_M72A9_Loaded: CUP_launch_M72A6_Loaded {
        author = "Potato";
        scope = 1;
        scopeArsenal = 1;
        displayName = "M72A9 (LASM)";
        baseWeapon = "potato_launch_M72A9_Loaded";
        jsrs_soundeffect = "JSRS2_Distance_Effects_Launcher";
        magazines[] = {"potato_M72A9_M"};
        descriptionShort = "Anti-structure missile launcher <br/>Unguided";
        class WeaponSlotsInfo: WeaponSlotsInfo {
            allowedSlots[] = {901};
			mass = 94.6;
        };
        class EventHandlers {
            fired = "_this call CBA_fnc_firedDisposable";
        };
    };
    class potato_launch_M72A9: potato_launch_M72A9_Loaded {
        author = "Potato";
        baseWeapon = "potato_launch_M72A9";
        scope = 2;
        scopeArsenal = 2;
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 94.6;
        };
    };
    class potato_launch_M72A9_Used: potato_launch_M72A9_Loaded {
        author = "Potato";
        displayName = "M72A9 (LASM) (Used)";
        scope = 1;
        baseWeapon = "potato_launch_M72A9_Used";
        model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
        magazines[] = {"CBA_FakeLauncherMagazine"};
        class WeaponSlotsInfo: WeaponSlotsInfo {
            mass = 72.4;
        };
    };
};