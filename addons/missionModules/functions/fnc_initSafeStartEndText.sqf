#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles initialization of end of safe start text. It adds
 * an eventhandler for safestart locally to each client with an interace and
 * on the correct side.
 *
 * Arguments:
 * 0: The module being initialized
 *
 * Examples:
 * Should be called by module init
 *
 * Public: No
 */
params ["_logic"];
if (!hasInterface) exitWith {
    TRACE_2("No interface",_logic,hasInterface);
};

if (isNull _logic) exitWith {
    WARNING_1("Attempted to initialize safe start text module at %1",diag_time);
};
private _side = [side player, west, east, resistance]#(_logic getVariable [QUOTE(side), 0]);
if (side player != _side) exitWith {
    TRACE_3("Player not on requisite side",_side,side ace_player,side player);
};
private _color = ["#FE7F50","#A21C1C","#FFFFFF"]#(_logic getVariable [QUOTE(missionNameColor), 0]);
private _lineOne = _logic getVariable [QUOTE(lineOne), ""];
private _lineTwo = _logic getVariable [QUOTE(lineTwo), ""];
private _lineThree = _logic getVariable [QUOTE(lineThree), ""];
private _lineFour = _logic getVariable [QUOTE(lineFour), ""];
TRACE_5("Mission Start Text params",_color,_lineOne,_lineTwo,_lineThree,_lineFour);
if (_lineOne == "" || _lineOne == " ") exitWith {
    ERROR_MSG_1("Safe start intro text module did not have first line of text %1",_logic);
};

private _text = [format ["<t shadow=""2"" font=""RobotoCondensedBold""color=""%1"" size=""1.5"">%2</t>", _color, _lineOne]];

{
    if (_x == "" || _x == " ") exitWith {TRACE_1("Stopped adding text at index",_forEachIndex)};
    _text pushBack format ["<t shadow=""2"" font=""RobotoCondensed"" size=""0.6"">%1</t>", _x];
} forEach [_lineTwo, _lineThree, _lineFour];
_text = _text joinString "<br/>";

//IGNORE_PRIVATE_WARNING["_thisArgs"];
["potato_safeStartOff", {
    _thisArgs params [["_text", "", [""]]];
    TRACE_3("Sending hint",_thisArgs,_text,CBA_missionTime);
    [{[_this, -safeZoneX, safeZoneH / 2, 5, 1, 0, SAFESTART_TEXT_RSCLAYER] spawn BIS_fnc_dynamicText}, _text, 10] call CBA_fnc_waitAndExecute;
}, [_text]] call CBA_fnc_addEventHandlerArgs;
