#include "script_component.hpp"
LOG("Post init start");

[
    {
        ACEGVAR(common,settingsInitFinished)
    },
    {
        TRACE_2("ACE Settings initilized",GVAR(groupAndUnitEnabled),GVAR(intraFireteamEnabled));
        if (GVAR(groupAndUnitEnabled) || {GVAR(intraFireteamEnabled)}) then {
            GVAR(skipInstallingEH) = false;

            [GVAR(viewBluForMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewOpForMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewIndyMarkers)] call EFUNC(core,stringArrayToSideArray);
            [GVAR(viewCivMarkers)] call EFUNC(core,stringArrayToSideArray);

            ACEGVAR(microDAGR,miniMapDrawHandlers) pushBack {_this call FUNC(drawMarkers)};
        } else {
            GVAR(skipInstallingEH) = true; // skip installing EH onto the GPS
        };
        GVAR(settingsInitialized) = true;

        {
            (_x select 1) call (_x select 0);
        } forEach GVAR(settingsDelayedFunctions);
    }
] call CBA_fnc_waitUntilAndExecute;

LOG("Post init end");
