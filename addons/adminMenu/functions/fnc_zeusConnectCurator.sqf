#include "script_component.hpp"

params ["_unit", "_giveZeus"];

if (!isServer) exitWith {};
if (isNull _unit) exitWith {};

private _zeusModule = getAssignedCuratorLogic _unit;

if (_giveZeus) then {
    if (isNull _zeusModule) then {

        {
            if (isNull (getAssignedCuratorUnit _x)) exitWith {
                _zeusModule = _x;
            };
        } forEach allCurators;

        if (isNull _zeusModule) then { //Only create a new zeus module if no free available
            diag_log text format ["[POTATO] No free zeus module found, creating new"];
            private _moduleGroup = createGroup GVAR(zeusCenter);
            _zeusModule = _moduleGroup createUnit ["ModuleCurator_F",[0,0,0],[],0,"NONE"];
            _zeusModule setVariable ["Owner", "-1"];
            _zeusModule setVariable ["Name", ""];
            _zeusModule setVariable ["Addons", 3];
            _zeusModule setVariable ["Forced", 0];
        };

        diag_log text format ["[POTATO] Assigning [%1] to Zeus [%2]", name _unit, _zeusModule];
        _unit assignCurator _zeusModule;

        if (missionNamespace getVariable ["ace_zeus_autoAddObjects", false]) then {
            TRACE_1("adding all units and veh to zeus",_zeusModule);
            {_zeusModule addCuratorEditableObjects [[_x],true]} foreach vehicles;
            {_zeusModule addCuratorEditableObjects [[_x],true]} foreach (entities "CaManBase");
        };
    };
} else {
    if (!isNull _zeusModule) then {
        diag_log text format ["[POTATO] Unassign [%1] to Zeus [%2]", name _unit, _zeusModule];
        unassignCurator _zeusModule;
    };
};
