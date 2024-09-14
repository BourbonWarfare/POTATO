class CfgVehicles {
    class gm_staticATGM_base;
    //// MILAN
    class gm_milan_launcher_tripod_base: gm_staticATGM_base {
        class ACE_Actions;
        class Turrets;
    };
    class gm_ge_army_milan_launcher_tripod_base: gm_milan_launcher_tripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class AnimationSources;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class gm_ge_army_milan_launcher_tripod: gm_ge_army_milan_launcher_tripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                selection = "mainturret_elev";
            };
        };
        class AnimationSources: AnimationSources {
            class MainTurret_realodMagazine_source;
            class MainTurret_revolving_source;
        };
        class assembleInfo;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Components;
                class GunClouds;
                class GunFire;
                class HitPoints;
                class MGunClouds;
                class Reflectors;
                class TurnIn;
                class TurnOut;
                class Turrets;
                class TurretSpec;
                class ViewGunner;
                class ViewOptics;
            };
        };
    };
    class gm_ge_army_milan_launcher_tripod_csw: gm_ge_army_milan_launcher_tripod {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                class ACE_csw_pickUp {
                    displayName = "Disassemble";
                    condition = "call ace_csw_fnc_canPickupTripod";
                    statement = "call ace_csw_fnc_assemble_pickupTripod";
                };
            };
        };
        class ACE_CSW {
            enabled = 1; // Enables ACE CSW for this weaponmmo handling interaction point location (custom pos)
            ammoLoadTime = 10 ;   // How long it takes in
            proxyWeapon = ""; // The proxy weapon created above. This can also be a function name that returns a proxy weapon - passed [_vehicle, _turret, _currentWeapon, _needed, _emptyWeapon]
            disassembleWeapon = "";  // Carryable weapon created above
            disassembleTurret = ""; // Which static tripod will appear when weapon is disassembled
            disassembleTo = QGVAR(gm_milan_backpack); // Abuse the tripods
            magazineLocation = "[0.204429,0.696469,-0.680236]"; // Aseconds to load ammo into the weapon
            ammoUnloadTime = 10; // How long it takes in seconds to unload ammo from the weapon
            desiredAmmo = 1;  // When the weapon is reloaded it will try and reload to this ammo capacity
        };
        class AnimationSources: AnimationSources {
            class MainTurret_realodMagazine_source: MainTurret_realodMagazine_source {
                source = "reloadmagazine";
                weapon = QGVAR(gm_milan_launcher_proxy);
            };
            class MainTurret_revolving_source: MainTurret_revolving_source {
                source = "revolving";
                weapon = QGVAR(gm_milan_launcher_proxy);
            };
        };
        class assembleInfo: assembleInfo {
            dissasembleTo[] = {};
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Components: Components;
                class GunClouds: GunClouds;
                class GunFire: GunFire;
                class HitPoints: HitPoints;
                class MGunClouds: MGunClouds;
                class Reflectors: Reflectors;
                class TurnIn: TurnIn;
                class TurnOut: TurnOut;
                class Turrets: Turrets;
                class TurretSpec: TurretSpec;
                class ViewGunner: ViewGunner;
                class ViewOptics: ViewOptics;
                weapons[] = {QGVAR(gm_milan_launcher_proxy)};
                magazines[] = {};
            };
        };
        displayName = "[CSW] MILAN";
        displayNameShort = "MILAN";
    };

    //// Fagot
    class gm_fagot_launcher_tripod_base: gm_staticATGM_base {
        class ACE_Actions;
        class Turrets;
    };
    class gm_gc_army_fagot_launcher_tripod_base: gm_fagot_launcher_tripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
        class AnimationSources;
        class Turrets: Turrets {
            class MainTurret;
        };
    };
    class gm_gc_army_fagot_launcher_tripod: gm_gc_army_fagot_launcher_tripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                selection = "mainturret_elev";
            };
        };
        class AnimationSources: AnimationSources {
            class MainTurret_realodMagazine_source;
            class MainTurret_revolving_source;
        };
        class assembleInfo;
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Components;
                class GunClouds;
                class GunFire;
                class HitPoints;
                class MGunClouds;
                class Reflectors;
                class TurnIn;
                class TurnOut;
                class Turrets;
                class TurretSpec;
                class ViewGunner;
                class ViewOptics;
            };
        };
    };
    class gm_gc_army_fagot_launcher_tripod_csw: gm_gc_army_fagot_launcher_tripod {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                class ACE_csw_pickUp {
                    displayName = "Disassemble";
                    condition = "call ace_csw_fnc_canPickupTripod";
                    statement = "call ace_csw_fnc_assemble_pickupTripod";
                };
            };
        };
        class ACE_CSW {
            enabled = 1; // Enables ACE CSW for this weaponmmo handling interaction point location (custom pos)
            ammoLoadTime = 10 ;   // How long it takes in
            proxyWeapon = ""; // The proxy weapon created above. This can also be a function name that returns a proxy weapon - passed [_vehicle, _turret, _currentWeapon, _needed, _emptyWeapon]
            disassembleWeapon = "";  // Carryable weapon created above
            disassembleTurret = ""; // Which static tripod will appear when weapon is disassembled
            disassembleTo = QGVAR(gm_fagot_backpack); // Abuse the tripods
            magazineLocation = "[0,0.4,-0.7]"; // Aseconds to load ammo into the weapon
            ammoUnloadTime = 10; // How long it takes in seconds to unload ammo from the weapon
            desiredAmmo = 1;  // When the weapon is reloaded it will try and reload to this ammo capacity
        };
        class AnimationSources: AnimationSources {
            class MainTurret_realodMagazine_source: MainTurret_realodMagazine_source {
                source = "reloadmagazine";
                weapon = QGVAR(gm_fagot_launcher_proxy);
            };
            class MainTurret_revolving_source: MainTurret_revolving_source {
                source = "revolving";
                weapon = QGVAR(gm_fagot_launcher_proxy);
            };
        };
        class assembleInfo: assembleInfo {
            dissasembleTo[] = {};
        };
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Components: Components;
                class GunClouds: GunClouds;
                class GunFire: GunFire;
                class HitPoints: HitPoints;
                class MGunClouds: MGunClouds;
                class Reflectors: Reflectors;
                class TurnIn: TurnIn;
                class TurnOut: TurnOut;
                class Turrets: Turrets;
                class TurretSpec: TurretSpec;
                class ViewGunner: ViewGunner;
                class ViewOptics: ViewOptics;
                weapons[] = {QGVAR(gm_fagot_launcher_proxy)};
                magazines[] = {};
            };
        };
        displayName = "[CSW] Fagot";
        displayNameShort = "Fagot";
    };

    //// MG3 AA
    class gm_staticMG_base;
    class gm_mg3_aatripod_base: gm_staticMG_base {
      class ACE_Actions;
    };
    class gm_ge_army_mg3_aatripod_base: gm_mg3_aatripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
    };
    class gm_ge_army_mg3_aatripod: gm_ge_army_mg3_aatripod_base {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                selection = "machinegunturret_01_elev";
            };
        };
        class ACE_CSW {
            enabled = 1; // Enables ACE CSW for this weaponmmo handling interaction point location (custom pos)
            ammoLoadTime = 0.1 ;   // How long it takes in
            proxyWeapon = ""; // The proxy weapon created above. This can also be a function name that returns a proxy weapon - passed [_vehicle, _turret, _currentWeapon, _needed, _emptyWeapon]
            disassembleWeapon = "gm_mg3_blk";  // Carryable weapon created above
            disassembleTurret = "ace_csw_m3CarryTripod"; // Which static tripod will appear when weapon is disassembled
            magazineLocation = "_target selectionPosition 'machinegunturret_01_magazine'"; // Aseconds to load ammo into the weapon
            ammoUnloadTime = 5; // How long it takes in seconds to unload ammo from the weapon
            desiredAmmo = 120;  // When the weapon is reloaded it will try and reload to this ammo capacity
        };
    };
};
// spg9 model location selectionName: "mainturret_rear"
