#include "script_component.hpp"
if (!hasInterface) exitWith {};


private _condition = {
    ("potato_whistle" in ([_player] call ACEFUNC(common,uniqueItems)))
    && {[_player, objNull, []] call ACEFUNC(common,canInteractWith)}
};
private _statement = {
    // Maximum distance changeable via script, won't really be audible near max
    private _distance = missionNamespace getVariable [QGVAR(whistleMax), 1000];
    [_player, QGVAR(whistle_5), _distance] call CBA_fnc_globalSay3D;
};
private _action = [QGVAR(blow),"Blow Whistle", QPATHTOF(ui\whistle_ca.paa),_statement,_condition] call ACEFUNC(interact_menu,createAction);
["CAManBase", 1, ["ACE_SelfActions", "ACE_Equipment"], _action, true] call ACEFUNC(interact_menu,addActionToClass);
