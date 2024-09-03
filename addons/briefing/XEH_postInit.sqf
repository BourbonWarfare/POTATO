#include "script_component.hpp"

if (hasInterface) then {
    // listen for admin menu assignments
    ["potato_becomeZeus", FUNC(addIntentToZeus)] call CBA_fnc_addEventHandler;

    // listen for mission start assignment
    [QACEGVAR(zeus,zeusUnitAssigned), {
        params ["", ["_unit", objNull, [objNull]]];
        if (isNull _unit || {!local _unit}) exitWith {};
        [_unit] call FUNC(addIntentToZeus);
    }] call CBA_fnc_addEventHandler;
};
["CBA_settingsInitialized", {
    INFO_2("Briefing Settings: Credits: [%1] Orbat: [%2]",GVAR(brief_addCredits),GVAR(brief_addOrbat)); // Remove Me if no problems found

    if (isServer) then {
        [{
            INFO("Checking group ids");
            {
                if ((((units _x) findIf {isPlayer _x}) > -1) && {((groupId _x) find "-") > -1}) then {
                    private _markerText = _x getVariable [QEGVAR(markers,markerText), ""];
                    if (_markerText == "") then { _markerText = (leader _x) getVariable [QEGVAR(markers,markerText), ""]; };
                    WARNING_2("Player Group with vanilla callsign: %1 [Marker: %2]",_x,_markerText);
                    if (_markerText != "") then { _x setGroupIdGlobal [format ["%1 [%2?]", groupId _x, _markerText]]; };
                };
            } forEach allGroups;
        }, []] call CBA_fnc_execNextFrame;
    };
    
    ["unit", {
        TRACE_1("playerChanged eh",ace_player);
        [
        {diag_tickTime > (_this select 1)},
        {[_this select 0] call FUNC(addBriefingToUnit);},
        [_this select 0, diag_tickTime + 1]
        ] call CBA_fnc_waitUntilAndExecute;
    }, true] call CBA_fnc_addPlayerEventHandler;
}] call CBA_fnc_addEventHandler;
