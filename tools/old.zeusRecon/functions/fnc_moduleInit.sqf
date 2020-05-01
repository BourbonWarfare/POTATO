#include "script_component.hpp"

params ["_logic"];
TRACE_1("moduleInit",_logic);

private _addPrePlacedUnits = _logic getVariable ["addPrePlacedUnits", false];

INFO_1("Zeus Recon Enabled [AddPrePlacedUnits: %1]",_addPrePlacedUnits);
GVAR(enabled) = true;

if (isServer) then {
    ["ace_zeus_autoAddObjects", false, true, true] call ace_common_fnc_setSetting;

    [QGVAR(addToCurator), {
        params ["_curator", "_addToCurator"];
        TRACE_2("",_curator,_addToCurator);
        _curator addCuratorEditableObjects [_addToCurator, false];
    }] call CBA_fnc_addEventHandler;

    [QGVAR(removeFromCurator), {
        params ["_curator", "_removeFromCurator"];
        TRACE_2("",_curator,_removeFromCurator);
        _curator removeCuratorEditableObjects [_removeFromCurator, false];
    }] call CBA_fnc_addEventHandler;

    if (_addPrePlacedUnits) then {
        [{
            private _prePlacedUnits = [];
            {
                if ((!(_x in playableUnits)) && {!(_x in switchableUnits)}) then {
                    _prePlacedUnits pushBackUnique _x;
                    _prePlacedUnits pushBackUnique (vehicle _x);
                };
            } forEach allUnits;
            INFO_1("Adding [%1] preplaced units to zeus",count _prePlacedUnits);
            TRACE_1("",_prePlacedUnits);
            _prePlacedUnits call EFUNC(core,addToCurator);
        }, [], 1] call CBA_fnc_waitAndExecute;

    };
};


#ifdef DEBUG_MODE_FULL
["zeusRecon", {
    private _return = [];
    if (isNil QGVAR(init)) then {
        _return pushBack "Not Active";
    } else {
        _return pushBack format ["State %1 - %2", GVAR(state), GVAR(stateSubIndex)];
        _return pushBack format ["Targets %1 - %2", count GVAR(allTargets), count GVAR(allTargetInfo)];
        _return pushBack format ["Target Groups %1", count GVAR(targetGroups)];
        _return pushBack format ["Friendly Objects %1", count GVAR(friendlyUnits)];
        _return pushBack format ["Friendly Groups %1", count GVAR(friendlyGroups)];
        _return pushBack format ["Friendly Reports %1", count GVAR(friendlyReports)];
    };
    _return joinString "<br/>"
}, [6]] call ACEFUNC(common,watchVariable);
#endif
