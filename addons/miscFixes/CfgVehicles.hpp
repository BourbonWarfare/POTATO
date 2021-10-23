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
};
