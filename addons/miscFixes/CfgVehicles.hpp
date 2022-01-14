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
};
