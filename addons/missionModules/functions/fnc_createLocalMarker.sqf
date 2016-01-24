#include "script_component.hpp"

params ["_pos", ["_text", ""], ["_color", "ColorBlack"], ["_icon", "mil_dot"]];
TRACE_4("params",_pos,_text,_color,_icon);

private _nextIndex = missionNamespace getVariable [QGVAR(nextMarkerIndex), 0];
private _markerName = format [QGVAR(%1), _nextIndex];
missionNamespace setVariable [QGVAR(nextMarkerIndex), (_nextIndex + 1)];

createmarker [_markerName,_pos];
TRACE_1("Creating Marker",_markerName);
_markerName setMarkerPosLocal _pos;
_markerName setMarkerShapeLocal "ICON";
_markerName setMarkerTypeLocal _icon;
_markerName setMarkerTextLocal _text;
_markerName setMarkerColorLocal _color;
