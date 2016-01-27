#include "script_component.hpp"

params ["_unit", "_giveZeus"];

if (!isServer) exitWith {};
if (isNull _unit) exitWith {};

private _zeusModule = getAssignedCuratorLogic _unit;

if (_giveZeus) then {
    if (isNull _zeusModule) then {
        private _moduleGroup = createGroup GVAR(zeusCenter);
        _zeusModule = _moduleGroup createUnit ["ModuleCurator_F",[0,0,0],[],0,"NONE"];
        _zeusModule setVariable ["Owner", "-1"];
        _zeusModule setVariable ["Name", ""];
        _zeusModule setVariable ["Addons", 2];
        _zeusModule setVariable ["Forced", 0];
        _unit assignCurator _zeusModule;
    };
    _unit setVariable [QGVAR(hasZeus), true, true];
} else {
    if (!isNull _zeusModule) then {
        unassignCurator _zeusModule;
        deleteVehicle _zeusModule;
    };
    _unit setVariable [QGVAR(hasZeus), false, true];
};
