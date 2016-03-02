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
        _zeusModule setVariable ["Addons", 3];
        _zeusModule setVariable ["Forced", 0];
        _unit assignCurator _zeusModule;

        if (missionNamespace getVariable ["ace_zeus_autoAddObjects", false]) then {
            TRACE_1("adding all units and veh to zeus",_zeusModule);
            {_zeusModule addCuratorEditableObjects [[_x],true]} foreach vehicles;
            {_zeusModule addCuratorEditableObjects [[_x],true]} foreach (entities "CaManBase");
        };
    };
} else {
    if (!isNull _zeusModule) then {
        unassignCurator _zeusModule;
        deleteVehicle _zeusModule;
    };
};
