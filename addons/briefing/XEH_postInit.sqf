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

    ["unit", {
        TRACE_1("playerChanged eh",ace_player);
        [{
            ACEGVAR(common,settingsInitFinished) && {diag_tickTime > (_this select 1)}
        }, {
            [_this select 0] call FUNC(addBriefingToUnit);
        }, [(_this select 0), diag_tickTime + 1]] call CBA_fnc_waitUntilAndExecute;
    }, true] call CBA_fnc_addPlayerEventHandler;
};
