#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// Vehicle customization - order is a little weird
// preInit, 3den-vehicleCustomizationSet, 3den-bisGarage, vehicleCustomizationSet's nextFrame, 1 sec delay (pubVar), 5 sec delay (apply)
//
if (isServer) then {
    GVAR(vehicleCustomization) = createHashMap;
     [{
        publicVariable QGVAR(vehicleCustomization);
     }, [], 1] call CBA_fnc_waitAndExecute;
};
[{
    if (isNil QGVAR(vehicleCustomization)) exitWith { ERROR("hash nil?") };
    if ((count GVAR(vehicleCustomization)) == 0) exitWith {};
    INFO_1("applying %1 vehicle customizations",count GVAR(vehicleCustomization));
    {
        if (_x regexMatch ".*_gmCust") then {
            private _class = _x select [0, count _x - 7];
            [_class, "Init", {
                params ["_vehicle"];
                if !(alive _vehicle && local _vehicle) exitWith {};
                private _customization = +(GVAR(vehicleCustomization) getOrDefault [typeOf _vehicle + "_gmCust", []]);
                if (_customization isEqualTo []) exitWith {};
                _vehicle setVariable ["GM_VEHICLE_ATTRIBUTES", _customization];
                TRACE_2("applied",typeOf _vehicle,_customization);
            }, false, nil, true] call CBA_fnc_addClassEventHandler; // no inheritance, apply retro
        } else {
            [_x, "InitPost", {
                params ["_vehicle"];
                if ((!alive _vehicle) || {!local _vehicle}) exitWith {};
                private _customization = GVAR(vehicleCustomization) getOrDefault [typeOf _vehicle, []];
                private _ret = [_vehicle, _customization select 0, _customization select 1] call bis_fnc_initVehicle;
                TRACE_3("applied",typeOf _vehicle,_ret,_customization);
            }, false, nil, true] call CBA_fnc_addClassEventHandler; // no inheritance, apply retro
        };
    } forEach GVAR(vehicleCustomization);

    {
        if !(alive _x && local _x) then {continue};
        private _customization = GVAR(vehicleCustomization) getOrDefault [typeOf _x + "_gmCust", []];
        if (_customization isEqualTo []) then {continue};
        _x setVariable ["GM_VEHICLE_ATTRIBUTES", +_customization];
        [_x] call gm_core_vehicles_fnc_vehicleMarkingsInit;
    } forEach vehicles;
}, [], 5] call CBA_fnc_waitAndExecute;

ADDON = true;
