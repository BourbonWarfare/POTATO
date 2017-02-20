#include "script_component.hpp"

[
    { ACEGVAR(common,settingsInitFinished) && {time > 1} },
    {
        if (didJip && {!isNil "potato_safeStart_safeStartEnabled" && {!potato_safeStart_safeStartEnabled}}) then {
            [player, playerSide] call FUNC(teleportToLeader);
        };
    }
] call CBA_fnc_waitUntilAndExecute;
