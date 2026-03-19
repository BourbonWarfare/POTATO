#include "script_component.hpp"

params ["_vehicle", ["_gmCustomization", false, [false]]];
TRACE_3("vehicleCustomizationSet",_vehicle,typeOf _vehicle,_gmCustomization);

// we need to delay a frame so the 3den garage attribute can be applyed
if (_gmCustomization) then {
    [{
        params ["_vehicle"];
        TRACE_2("gmVehicleCustomizationSet after 3den",_vehicle,typeOf _vehicle);
        if (!alive _vehicle) exitWith { ERROR_1("bad vehicle %1",_vehicle) };

        private _gmCustomization = +(_vehicle getVariable ["GM_VEHICLE_ATTRIBUTES", []]);
        if (_gmCustomization isEqualTo []) exitWith { ERROR_2("bad custom %1-%2",typeOf _vehicle,_gmCustomization) };
        (_gmCustomization#0) set [1, "-1"]; // license plate randomization
        if !(_gmCustomization#2#0 in [" ", ""]) then {
            (_gmCustomization#2) set [0, "-1"]; // hull # randomization if not cleared
        };

        if (GVAR(vehicleCustomization) set [typeOf _vehicle + "_gmCust", _gmCustomization]) then {
            WARNING_2("overwriting existing customization %1-%2",typeOf _vehicle,_gmCustomization)
        };
    }, _this] call CBA_fnc_execNextFrame;
} else {
    [{
        params ["_vehicle"];
        TRACE_2("vehicleCustomizationSet after 3den",_vehicle,typeOf _vehicle);
        if (!alive _vehicle) exitWith { ERROR_1("bad vehicle %1",_vehicle) };

        private _customization = [_vehicle] call BIS_fnc_getVehicleCustomization;
        TRACE_1("",_customization);
        if ((_customization param [0, []]) isEqualTo []) exitWith { ERROR_2("bad custom %1-%2",typeOf _vehicle,_customization) };

        if (GVAR(vehicleCustomization) set [typeOf _vehicle, _customization]) then {
            WARNING_2("overwriting existing customization %1-%2",typeOf _vehicle,_customization)
        };
    }, _this] call CBA_fnc_execNextFrame;
};
