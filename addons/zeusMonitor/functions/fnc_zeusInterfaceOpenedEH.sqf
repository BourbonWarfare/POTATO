#include "script_component.hpp"

TRACE_1("params",_this);

[{
    if (isNull (findDisplay 312)) exitWith {
        TRACE_1("removing PFEH",_this);
        [_this select 1] call CBA_fnc_removePerFrameHandler;
    };
    
    private _aiCount = {!isPlayer _x} count allUnits;
    
    ((findDisplay 312) displayCtrl 777551) ctrlSetText format ["AI: %1", _aiCount];
}, 1, []] call CBA_fnc_addPerFrameHandler;
