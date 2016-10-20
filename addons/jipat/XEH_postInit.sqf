#include "script_component.hpp"

if (didJip && {!isNil "potato_safeStart_safeStartEnabled" && {!potato_safeStart_safeStartEnabled}}) then {
    [
        { ACEGVAR(common,settingsInitFinished) && {time > 1} },
        {
            [player, playerSide] call FUNC(teleportToLeader);
        }
    ] call CBA_fnc_waitUntilAndExecute;
};