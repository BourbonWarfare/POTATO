#include "script_component.hpp"

if (hasInterface) then {
    ["potato_becomeZeus", {
        params ["_unit"];
        systemChat "You have been assigned zeus";
        private _zeusIntent = getMissionConfigValue [QGVAR(zeusIntent), ""];
        if (_zeusIntent == "") exitWith {};

        _zeusIntent = [_zeusIntent] call FUNC(convertNewLineToHTML);
        systemChat "Mission has custom zeus briefing";
        _unit createDiaryRecord ["diary", ["Zeus",_zeusIntent]];
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
