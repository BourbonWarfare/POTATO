/*
 * Author: AACO
 * Function used to update the timer
 * Should only be called from an event handler
 *
 * Examples:
 * [] call potato_safeStart_fnc_updateTimer;
 * [] call potato_safeStart_fnc_updateTimer;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

if !(isNull MESSAGE_DISPLAY) then {
    private _units = units (group player);
    TRACE_2("Squads",GVAR(oldSquad), _units);
    if !(GVAR(oldSquad) isEqualTo _units) then {
        GVAR(oldSquad) = _units;
        private _recruits = [];
        private _recruitCount = {
            // isPlayer _x &&
            private _squadParams = squadParams _x;
            if (alive _x && {_squadParams isEqualTo [] || {((_squadParams  select 0) select 1) != "Bourbon Warfare"}}) then {
                _recruits pushBack (name _x);
                true
            } else {
                false
            }
        } count _units;
        TRACE_2("Recruits",_recruits,_recruitCount);

        if (_recruitCount > 0) then {
            MESSAGE_CONTROL ctrlSetStructuredText parseText format [
                "<t size='0.75'>You have %1 in your group:<br/>%2<br/>Say hello and make sure you vote on their %3</t>",
                ["a recruit", "some recruits"] select (_recruitCount > 1),
                _recruits joinString "<br/>",
                ["thread", "threads"] select (_recruitCount > 1)
            ];
            MESSAGE_CONTROL ctrlSetPosition [
                0.88 * safezoneW + safezoneX,
                0.15 * safezoneH + safezoneY,
                0.105 * safezoneW,
                (2 + _recruitCount) * 0.017 * safezoneH
            ];
            MESSAGE_CONTROL ctrlCommit 0.25;
            TRACE_1("Message",_message);
        } else {
            MESSAGE_CONTROL ctrlSetStructuredText parseText "";
            MESSAGE_CONTROL ctrlSetPosition [
                0.88 * safezoneW + safezoneX,
                0.15 * safezoneH + safezoneY,
                0.105 * safezoneW,
                0
            ];
            MESSAGE_CONTROL ctrlCommit 0.25;

        };
    };
};
