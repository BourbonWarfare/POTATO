#include "script_component.hpp"
#define ZEUS_DC_TIMEOUT 5

params ["_unit", "_giveZeus"];
TRACE_2("zeusConnectCurator",_unit,_giveZeus);

if (!isServer) exitWith {};
if (isNull _unit) exitWith {WARNING("Unit wasn null");};

private _zeusModule = getAssignedCuratorLogic _unit;

if (_giveZeus) then {
    if (isNull _zeusModule) then {

        // check for non player zeuses
        private _nonPlayerZeuses = [];
        private _canSkipWaiting = false;
        {
            private _assignedUnit = getAssignedCuratorUnit _x;
            if (isNull _assignedUnit) then {
                _canSkipWaiting = true;
            } else {
                if !(isPlayer _assignedUnit) then {
                    _nonPlayerZeuses pushBack _x;
                    unassignCurator _x;
                    diag_log text format ["[POTATO] Unassigning non-player [%1](%2) from zeus [%3]", _assignedUnit, typeOf _assignedUnit, _x];
                };
            };
        } forEach allCurators;

        [
            {
                params ["", "_canSkipWaiting", "_nonPlayerZeuses", "_timeOut"];
                _canSkipWaiting || {{ !(isNull getAssignedCuratorUnit _x) } count _nonPlayerZeuses == 0} || {diag_tickTime > _timeOut}
            },
            {
                params ["_unit"];

                // get available curator
                private _zeusModule = objNull;
                {
                    if (isNull (getAssignedCuratorUnit _x)) exitWith {
                        _zeusModule = _x;
                    };
                } forEach allCurators;

                if (isNull _zeusModule) then { //Only create a new zeus module if no free available
                    diag_log text format ["[POTATO] No free zeus module found, creating new"];

                    private _zeusGroup = createGroup GVAR(zeusCenter);
                    _zeusModule = _zeusGroup createUnit ["ModuleCurator_F", [0,0,0], [], 0, "NONE"];
                    _zeusModule setVariable ["Owner", "-1"];
                    _zeusModule setVariable ["Name", ""];
                    _zeusModule setVariable ["Addons", 3];
                    _zeusModule setVariable ["Forced", 0];

                    // ensure all units added to new curator
                    private _configs = "isArray (_x >> 'units') && {count (getArray (_x >> 'units')) > 0}" configClasses (configFile >> "CfgPatches");
                    _configs = _configs apply { configName _x };
                    _zeusModule addCuratorAddons _configs;
                };

                diag_log text format ["[POTATO] Assigning [%1] to Zeus [%2]", name _unit, _zeusModule];
                _unit assignCurator _zeusModule;
                ["potato_becomeZeus", [_unit], [_unit]] call CBA_fnc_targetEvent;

                if (missionNamespace getVariable ["ace_zeus_autoAddObjects", false]) then {
                    TRACE_1("adding all units and veh to zeus",_zeusModule);
                    _zeusModule addCuratorEditableObjects [vehicles, true];
                    _zeusModule addCuratorEditableObjects [entities "CaManBase", true];
                };
            },
            [_unit, _canSkipWaiting, _nonPlayerZeuses, diag_tickTime + ZEUS_DC_TIMEOUT]
        ] call CBA_fnc_waitUntilAndExecute;
    };
} else {
    if (!isNull _zeusModule) then {
        diag_log text format ["[POTATO] Unassign [%1] to Zeus [%2]", name _unit, _zeusModule];
        unassignCurator _zeusModule;
    };
};
