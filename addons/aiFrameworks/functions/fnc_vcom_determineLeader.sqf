#include "script_component.hpp"
TRACE_1("params",_this);

//Created on 8/14/14
// Modified on : 8/1/15

//This function is to determine if this unit is the group leader or not. And to define if unit is sub-leader or not.
_Unit = _this select 0;

_GroupLeader = leader (group (vehicle _Unit));
if (_GroupLeader isEqualTo _Unit) then {_Unit setVariable ["VCOM_GroupLeader",true,false];};

_SubLeader = isFormationLeader _Unit;
if (_SubLeader) then {_Unit setVariable ["VCOM_SubLeader",true,false];};


_Leader = _Unit getVariable "VCOM_GroupLeader";
if (isNil "_Leader") exitWith {};
_SubLeader = _Unit getVariable "VCOM_SubLeader";
_CheckArray = [_Leader,_SubLeader];
_CheckArray
