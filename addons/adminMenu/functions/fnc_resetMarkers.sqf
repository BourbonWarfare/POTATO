#include "script_component.hpp"

params [["_unit", objNull, [objNull]]];
"Markers updated" remoteExec ["hint", _unit]; 

diag_log text format ["[POTATO] Reseting markers on %1 [%2]", (name _unit), _unit];
if (isNull _unit || {!local _unit}) exitWith {};

diag_log text format ["[POTATO] Calling %1", QEFUNC(markers,initMarkerHash)];
[] call EFUNC(markers,initMarkerHash);
