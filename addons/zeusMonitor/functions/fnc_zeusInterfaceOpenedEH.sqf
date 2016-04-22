#include "script_component.hpp"

TRACE_1("params",_this);

[{
    if (isNull (findDisplay 312)) exitWith {
        TRACE_1("removing PFEH",_this);
        [_this select 1] call CBA_fnc_removePerFrameHandler;
    };

    if (missionNamespace getVariable ["ACRE_IS_SPECTATOR", false]) then {
        ((findDisplay 312) displayCtrl 777550) ctrlSetTextColor [0,1,0,1];
    } else {
        ((findDisplay 312) displayCtrl 777550) ctrlSetTextColor [1,1,1,1];
    };
        
    private _aiCount = {!isPlayer _x} count allUnits;
    ((findDisplay 312) displayCtrl 777551) ctrlSetText format ["AI: %1", _aiCount];

}, 0.5, []] call CBA_fnc_addPerFrameHandler;
