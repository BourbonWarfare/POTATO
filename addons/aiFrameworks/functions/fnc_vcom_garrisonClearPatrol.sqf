#include "script_component.hpp"
TRACE_1("params",_this);

private ["_Locations", "_Unit", "_RandomPick"];

//Stop the AI - and then tell them to move to the house
_Locations = _this select 0;
_Unit = _this select 1;
_Unit setVariable ["VCOM_InCover",true,false];

while {(count _Locations) > 0 && (_Unit getvariable "VCOMAI_ActivelyClearing")} do
{
			sleep (random 2);
			//_RandomPick = _Locations call BIS_fnc_selectrandom;
			_RandomPick = _Locations select 0;
			_Locations = _Locations - [_RandomPick];
			_Unit doMove _RandomPick;
			waitUntil {(_Unit distance _RandomPick) < 2};

};

_Unit setVariable ["VCOM_InCover",false,false];
