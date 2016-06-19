/*
 * Author: AACO
 * Function used to add units from the faction unit list to the pending list
 * Should only be called from UI events
 *
 * Arguments:
 * 0: index of the unit in the faction unit list <NUMBER>
 *
 * Examples:
 * [1] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the first index
 * [5] call potato_zeusHC_fnc_buildAGroupDialogAdd; //unit in the fifth index
 *
 * Public: No
 */

#include "script_component.hpp"
disableSerialization;
TRACE_1("Params",_this);

params ["_mapControl"];

//Map's height / Screen height:
private _mapSize = ((ctrlPosition _mapControl) select 3) / (getResolution select 4);
private _sizeFactor = (_mapSize + 1) / 2;

if ((player != player) || {!alive player}) exitWith {};

/*
if ((diag_tickTime - F_Markers_lastUpdate) > 5) then {
  [] call F_Markers_fnc_setupDrawThings;
  F_Markers_lastUpdate = diag_tickTime;
};

{
  _data = _x getVariable ["f_var_drawSettings", []];
  if (_data isEqualTo []) then {
    diag_log format ["[BW] Bad f_var_drawSettings on %1", _x]
  } else {
    _data params ["_text", "_texture", "_color", "_size", "_pos", "_time"];

    if (((time - _time) > F_Markers_delay) && !isNull _x) then {
      if (_x isEqualType grpNull) then { _pos = getpos leader _x };
      if (_x isEqualType objNull) then { _pos = getpos _x };
      _time = time;
      _data set [4, _pos];
      _data set [5, _time];
    };

    _mapControl drawIcon [_texture, _color, _pos, (_size select 0) * _sizeFactor, (_size select 1) * _sizeFactor, 0, _text, 1, (([0.05,0] select (((ctrlMapScale _mapControl) * _mapSize) > 0.1)) * _sizeFactor), 'TahomaB', "right"];
  };
  nil
} count F_Markers_thingsToDraw;
*/

if (GVAR(intraFireteamEnabled) && {(ctrlMapScale _mapControl) < 0.5}) then {
    {
        private _color = switch (assignedTeam _x) do {
            case "RED": { RED_ARRAY };
            case "YELLOW": { YELLOW_ARRAY };
            case "GREEN": { GREEN_ARRAY };
            case "BLUE": { BLUE_ARRAY };
            default { WHITE_ARRAY };
        };

        private _unitPosition = position _x;
        private _unitName = if (alive _x) then { name _x } else { "" };

        if (count _unitPosition == 3) then { //handle weird/dead group members
            _mapControl drawIcon [UNIT_MARKER_ICON,
                                  _color,
                                  _unitPosition,
                                  UNIT_MARKER_SIZE * _sizeFactor,
                                  UNIT_MARKER_SIZE * _sizeFactor,
                                  direction _x,
                                  _unitName,
                                  1,
                                  (([0,0.02] select (((ctrlMapScale _mapControl) * _mapSize) < 0.005)) * _sizeFactor),
                                  'TahomaB',
                                  "left"];
        };

        nil
    } count (units (group player));
};
