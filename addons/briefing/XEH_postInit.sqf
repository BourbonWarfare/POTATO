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

    // TODO: BWC, remove this a while after (can't use movedToSQF = 1 here)
    if (isClass (missionConfigFile >> "ACE_Settings" >> QGVAR(brief_addCredits))) then {
        GVAR(brief_addCredits) = getNumber (missionConfigFile >> "ACE_Settings" >> QGVAR(brief_addCredits) >> "value") == 1;
    };
    if (isClass (missionConfigFile >> "ACE_Settings" >> QGVAR(brief_addOrbat))) then {
        GVAR(brief_addOrbat) = getNumber (missionConfigFile >> "ACE_Settings" >> QGVAR(brief_addOrbat) >> "value") == 1;
    };

    ["unit", {
        TRACE_1("playerChanged eh",ace_player);
        [
            {diag_tickTime > (_this select 1)},
            {[_this select 0] call FUNC(addBriefingToUnit);},
            [_this select 0, diag_tickTime + 1]
        ] call CBA_fnc_waitUntilAndExecute;
    }, true] call CBA_fnc_addPlayerEventHandler;
};
