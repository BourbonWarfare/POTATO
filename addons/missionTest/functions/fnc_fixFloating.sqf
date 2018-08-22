#include "script_component.hpp"

private _mans = (all3DENEntities select 0) select {_x isKindOf "CaManBase"};
{
    if (_x isKindOf "CaManBase") then {
        private _pos =  (_x get3DENAttribute "position") select 0; // weird double array
        _pos set [2, 0];
        _x set3DENAttribute ["position", _pos];
    };
} forEach _mans;

systemChat format ["Zeroed height for %1 units", count _mans];
