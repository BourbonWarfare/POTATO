class CBA_Extended_EventHandlers;

class CfgVehicles {
    // Handle fortify moving to acex
    class acex_fortify_setupModule; // these still use acex_
    class EGVAR(fortify,setupModule): acex_fortify_setupModule {
        scope = 1;
        displayName = "delete me and use acex_fortify_setupModule";
    };
    class acex_fortify_buildLocationModule;
    class EGVAR(fortify,buildLocationModule): acex_fortify_buildLocationModule {
        scope = 1;
        displayName = "delete me and use acex_fortify_buildLocationModule";
    };


    // Integrate invisibile backpack from SagJangi
    // https://forums.bohemia.net/forums/topic/222097-battle-belt/
    class Bag_Base;
    class B_Battle_Belt_F: Bag_Base {
        picture = "\A3\Characters_F\data\ui\icon_V_Belt_CA.paa";
        displayName = "Battle Belt";
        model = "\A3\weapons_f\empty";
        author = "SagJangi";
        maximumLoad = 80;
        mass = 8;
        mapSize = 0.47;
        scope = 2;
    };
    class B_Battle_Belt_XL_F: B_Battle_Belt_F {
        displayName = "Battle Belt XL";
        author = "Alablm";
        maximumLoad = 320;
        mass = 60;
    };

    // Add SMAW box
    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "Fucks given";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {};
        class TransportMagazines {};
        class TransportItems {};
        class TransportBackpacks {};
    };

    // Make vanilla Chinook and EH302 (IDAP/FIA transport heli) float on water. Matches CUP Chinook/CH-53e and other heavy lift helos. Should be extended to all helicopters from mods that could feasibly float. 
    class Helicopter_Base_H;
	class Heli_Transport_03_base_F: Helicopter_Base_H {waterLeakiness=0.1;};
    class Heli_Transport_02_base_F: Helicopter_Base_H {waterLeakiness=0.1;};

    // Fix CBA XEH Fallback Code for misc logic/objects that don't support it: [Not needed for RHS as of 4.6]
    // x3 = [true] call CBA_fnc_supportMonitor;
    // {
    // _x params ["_vehType", "_addon"];
    // private _parent = configName inheritsFrom (configFile >> "CfgVehicles" >> _vehType);
    // diag_log text format ["class %1: %2 { SLX_XEH_DISABLED = 1; }; // %3 -> %4", _vehType, _parent, _addon, getText (configFile >> "CfgVehicles" >> _vehType >> "displayName")];
    // } forEach x3;


    // Fix: Drongo's Spooks and Anomalies XEH
    class DSA_SpookBase;
    class DSA_SpookBase2;
    class DSA_AnomalyBase;
    class B_Soldier_F;
    class DSA_Vampire: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Vampire
    class DSA_Wendigo: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Wendigo
    class DSA_Shadowman: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Shadowman
    class DSA_Hatman: DSA_Shadowman { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Hatman
    class DSA_Mindflayer: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Mindflayer
    class DSA_411: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> 411
    class DSA_Rake: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Rake
    class DSA_Abomination: DSA_411 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Abomination
    class DSA_Snatcher: DSA_SpookBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Snatcher
    class DSA_Crazy: DSA_SpookBase2 { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Crazy
    class DSA_Launchpad: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Launchpad
    class DSA_Leech: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Leech
    class DSA_Zapper: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Zapper
    class DSA_Trapdoor: DSA_AnomalyBase { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Trapdoor
    class DSA_DeltaX_Operator: B_Soldier_F { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Delta X Operator
    class DSA_DeltaX_CBRN: B_Soldier_F { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; }; // Drongos Spooks and Anomalies> Delta X CBRN

    // AMP_Breaching_Charge
    class ACE_Explosives_Place_SLAM;
    class AMP_Breaching_Charge_Place: ACE_Explosives_Place_SLAM { class EventHandlers { class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {}; }; };


    // Fix fajita
	class Building;
	class NonStrategic: Building {
		class DestructionEffects;
	};	
	class HouseBase: NonStrategic {};	
	class House: HouseBase {
        class DestructionEffects: DestructionEffects {
			class Smoke1 {
				type="HouseDestructionSmoke3";
			};
			class Smoke2: Smoke1 {
				type="HouseDestructionSmoke4";
			};
			class Smoke3: Smoke1 {
				type="HouseDestrSmokeLong";
            };
		};
	};



    // CUP-ACE_Viewports compat
    class Wheeled_APC_F;
    class Tank_F;
    class CUP_BTR80_Common_Base: Wheeled_APC_F {
        class ace_viewports {
            class view_0 {
                camLocation[] = {0.734863, 0.143927, -0.291199};
                camAttach = 45;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_1 {
                camLocation[] = {0.950684, -0.00122738, -0.344391};
                camAttach = 90;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_2 {
                camLocation[] = {0.932129, -0.729811, -0.319};
                camAttach = 90;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_3 {
                camLocation[] = {-0.963379, -0.749183, -0.351501};
                camAttach = -90;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_4 {
                camLocation[] = {-0.973145, 0.0148516, -0.364868};
                camAttach = -90;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_5 {
                camLocation[] = {-0.73584, 0.119176, -0.291229};
                camAttach = -45;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
        };
    };
    class CUP_BTR90_Base: Wheeled_APC_F {
        class ace_viewports {
            class view_0 {
                camLocation[] = {0.533417, 2.4613, -0.309951};
                camAttach = 0;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_1 {
                camLocation[] = {0.877106, 2.38684, -0.306068};
                camAttach = 30;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_2 {
                camLocation[] = {1.04312, 0.0909424, -0.281996};
                camAttach = 60;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_3 {
                type = "";
                camLocation[] = {1.03799, -0.928223, -0.282196};
                camAttach = 80;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_4 {
                type = "";
                camLocation[] = {-0.90097, -0.913086, -0.282192};
                camAttach = -80;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
            class view_5 {
                type = "";
                camLocation[] = {-0.939301, 0.109985, -0.281992};
                camAttach = -60;
                compartments[]={"Compartment1"};
                roles[]={"cargo"};
            };
        };
    };
    class CUP_BTR90_HQ_Base: CUP_BTR90_base { delete ace_viewports; }; // no cargo seats

    class CUP_M2Bradley_Base: Tank_F {
        ace_hunterkiller = 1;
        class ace_viewports {
            class view_0 {
                camLocation[] = {0.987915, -0.324707, -0.0673385};
                camAttach = 70;
                roles[]={"cargo"};
            };
            class view_1 {
                camLocation[] = {0.90979, -0.970215, -0.043139};
                camAttach = 120;
                roles[]={"cargo"};
            };
            class view_2 {
                camLocation[] = {0.328003, -1.87402, -0.0408039};
                camAttach = 160;
                roles[]={"cargo"};
            };
            class view_3 {
                camLocation[] = {-0.357178, -1.89063, -0.0480237};
                camAttach = 175;
                roles[]={"cargo"};
            };
            class view_4 {
                camLocation[] = {-0.752075, -1.87061, -0.0522318};
                camAttach = 190;
                roles[]={"cargo"};
            };
            class view_5 {
                camLocation[] = {-0.936401, -0.0942383, -0.107764};
                camAttach = -75;
                roles[]={"cargo"};
            };
            class SLD { // suppose to only be only on A3, but the A2s have the screen on the model?
                screenLocation[] = {0.729126,-0.191597,-0.573349};
                maxDistance = 5;
                type = "screen";
                camLocation[] = {0,0,0.05};
                camAttach[] = {0,0};
                roles[]={"cargo"};
            };
        };
    };
};
