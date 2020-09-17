class CBA_Extended_EventHandlers;

class CfgVehicles {
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

    // Add SMAW box
    class Box_NATO_Support_F;
    class GVAR(smawBox): Box_NATO_Support_F {
        scope = 1;
        displayName = "SMAW Weapon Box";
        transportMaxWeapons = 9001;
        transportMaxMagazines = 9001;
        transportMaxItems = 9001;
        maximumload = 1000;

        class TransportWeapons {
            MACRO_ADDWEAPON(rhs_weap_smaw,1);
        };
        class TransportMagazines {
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEAA,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_HEDP,10);
            MACRO_ADDMAGAZINE(rhs_mag_smaw_SR,8);
        };
        class TransportItems {
            MACRO_ADDITEM(rhs_weap_optic_smaw,1);
        };
        class TransportBackpacks {};
    };

    // Fix CBA XEH Fallback Code for misc logic/objects that don't support it: [Not needed for RHS as of 4.6]
    // x3 = [true] call CBA_fnc_supportMonitor;
    // {
    // _x params ["_vehType", "_addon"];
    // private _parent = configName inheritsFrom (configFile >> "CfgVehicles" >> _vehType);
    // diag_log text format ["class %1: %2 { SLX_XEH_DISABLED = 1; }; // %3 -> %4", _vehType, _parent, _addon, getText (configFile >> "CfgVehicles" >> _vehType >> "displayName")];
    // } forEach x3;

    class Car_F;
    class Wheeled_APC_F: Car_F {
        class EventHandlers;
    };
    class rhsusf_stryker_base: Wheeled_APC_F {
        class EventHandlers: EventHandlers {
            class RHSUSF_EventHandlers {
                init = "diag_log '[POTATO] Disabled Stryrker Lag Screen'; params ['_vehicle']; private _sections = getArray (configFile >> 'CfgVehicles' >> typeOf _vehicle >> 'hiddenSelections'); _vehicle setObjectTexture [_sections find 'BFT_screen', 'z\POTATO\addons\miscFixes\models\plotNvgView.paa'];";
            };
        };
    };



    // Fix: WARNING: MBG_WaterfallPlugin does not support Extended Event Handlers! Addon: @BourbonMapRotation
    class Logic;
    class MBG_WaterfallPlugin: Logic {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
};
