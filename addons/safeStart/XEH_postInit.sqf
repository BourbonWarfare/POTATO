#include "script_component.hpp"

if (isServer) then {
    // Setting to sync to ace_fortify
    ["potato_safeStartOn", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), true, true];
    }] call CBA_fnc_addEventHandler;
    ["potato_safeStartOff", {
        if (!GVAR(syncFortify)) exitWith {};
        missionNamespace setVariable [QACEGVAR(fortify,fortifyAllowed), false, true];
    }] call CBA_fnc_addEventHandler;

    [
        {time > 0},
        { [GVAR(enabled)] call FUNC(toggleSafeStart); }
    ] call CBA_fnc_waitUntilAndExecute;
    call FUNC(initForceEndSafeStart);
};

if (didJIP) then {
    [
        {time > 1},
        {
            if (missionNamespace getVariable [QGVAR(startTime_PV), -1] == -1) then {
                ["potato_safeStartOff"] call CBA_fnc_localEvent;
            } else {
                ["potato_safeStartOn"] call CBA_fnc_localEvent;
            };
        }
    ] call CBA_fnc_waitUntilAndExecute;
};

if(hasInterface) then {
    [QGVAR(addMissionEndMarkerLocal),{
        params["_markerStr"];
        TRACE_1("Params",_this);

        private _markerName = "_USER_DEFINED missionEndMarker_0";
        private _markerExists = allMapMarkers find _markerName;

        if (_markerExists isNotEqualTo -1) then {deleteMarkerLocal _markerName;};

        _markerStr call BIS_fnc_stringToMarkerLocal;
    }] call CBA_fnc_addEventHandler;
    if (getMissionConfigValue ["bwmfDate", ""] != "") then { // non-bwmf missions don't need the timer
        private _ctrl = (findDisplay 12) displayCtrl IDC_MAPTIME_CLOCK;
        uiNamespace setVariable [QGVAR(missionClock), _ctrl];
        _ctrl ctrlSetBackgroundColor [0,0,0,0.7];
        _ctrl ctrlSetText "00:00:00";
        _ctrl ctrlSetPositionW (ctrlTextWidth _ctrl);
        _ctrl ctrlSetPositionH (ctrlTextHeight _ctrl);
        _ctrl ctrlCommit 0;
        GVAR(mapTimerID) = [FUNC(updateMapTimer), 0.25, []] call CBA_fnc_addPerFrameHandler;
    };
};
