#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

if (hasInterface) then {
    // Register events
    ["potato_safeStartOn", {
        [GVAR(showMessage)] call FUNC(toggleRecruitInfo);
        [GVAR(showTags)] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;

    ["potato_safeStartOff", {
        [false] call FUNC(toggleRecruitInfo);
        [false] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;
};

if (isNil QGVAR(overriddenTagMembers)) then {
    GVAR(overriddenTagMembers) = [];
};

if (isServer) then {
    GVAR(overriddenTagMembers) = profileNamespace getVariable [QGVAR(overriddenTagMembers), []];
    publicVariable QGVAR(overriddenTagMembers);

    [QGVAR(whitelistMember), {
        params ["_steamId"];
        GVAR(overriddenTagMembers) pushBackUnique _steamId;
        profileNamespace setVariable [QGVAR(overriddenTagMembers), GVAR(overriddenTagMembers)];
        publicVariable QGVAR(overriddenTagMembers);
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
