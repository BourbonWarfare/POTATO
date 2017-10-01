class CBA_Extended_EventHandlers;

class CfgVehicles {
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

    // Fix CBA XEH Fallback Code for misc logic/objects that don't support it:
    // x3 = [true] call CBA_fnc_supportMonitor;
    // {
    // _x params ["_vehType", "_addon"];
    // private _parent = configName inheritsFrom (configFile >> "CfgVehicles" >> _vehType);
    // diag_log text format ["class %1: %2 { SLX_XEH_DISABLED = 1; }; // %3 -> %4", _vehType, _parent, _addon, getText (configFile >> "CfgVehicles" >> _vehType >> "displayName")];
    // } forEach x3;

    class THIRSK_WeatherPreSet;
    class TH_SNOWING1: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Snowing Strenght 1
    class TH_SNOWING2: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Snowing Strenght 2
    class TH_SNOWING3: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Snowing Strenght 3
    class TH_SNOWING4: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Snowing Strenght 4
    class TH_FOG1: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Fog Strenght 1
    class TH_FOG2: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Fog Strenght 2
    class TH_FOG3: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Fog Strenght 3
    class TH_SNOWSTORM1: THIRSK_WeatherPreSet { SLX_XEH_DISABLED = 1; }; // @BourbonMapRotation -> Snowstorm
    class rq11_base_object;
    class rhsusf_RQ11MONITOR: rq11_base_object { SLX_XEH_DISABLED = 1; }; // @RHSUSAF -> [GCS] Ground Control Station
    class rhsusf_RQ11RAVEN_STATIC: rq11_base_object { SLX_XEH_DISABLED = 1; }; // @RHSUSAF -> [RQ-11] Raven A (static)
    class rhsusf_RQ11RAVEN_B_STATIC: rq11_base_object { SLX_XEH_DISABLED = 1; }; // @RHSUSAF -> [RQ-11] Raven B (static)
    class ThingX;
    class rhs_2P3_1: ThingX { SLX_XEH_DISABLED = 1; }; // @RHSAFRF -> 2-P-3 (1)
    
    class Plane_Base_F;
    class rhs_mig29s_base: Plane_Base_F {
        class Eventhandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };
    };
    
    class Logic;
    class CUP_satcom: Logic { SLX_XEH_DISABLED = 1; }; // @CUP_Vehicles -> (CUP) SatCom
    class CUP_crewduke: Logic { SLX_XEH_DISABLED = 1; }; // @CUP_Vehicles -> (CUP) CREW Duke
    class CUP_boomerang: Logic { SLX_XEH_DISABLED = 1; }; // @CUP_Vehicles -> (CUP) Boomerang

};
