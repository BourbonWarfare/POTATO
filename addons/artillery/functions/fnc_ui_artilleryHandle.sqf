#include "..\script_component.hpp"
/**************************************************************//*
* This function handles the artillery menu both opening and closing,
* including making relevant calls on close and creating markers on open
*
* Arguments:
* _isClosing - True if dialog is closing
* _eventArgs - Array of arguments depending on state
*
* Only called via callback
*//**************************************************************/

params ["_isClosing", "_eventArgs", ["_initPos", [0, 0, 0], [[]]]];

if (_isClosing) then {
    _eventArgs params ["_display", ["_exitCode", 0]];
    private _map = _display displayCtrl IDC_ARTILLERY_MAP;
    _map ctrlRemoveEventHandler ["Draw", GVAR(artilleryMapEH)#0];
    _map ctrlRemoveEventHandler ["MouseButtonClick", GVAR(artilleryMapEH)#1];
    //_map ctrlRemoveEventHandler ["MouseMoving", GVAR(artilleryMapEH)#2];

    (_display getVariable [QGVAR(pos), [[0,0,0], 0, 0]]) params ["_pos", "_rad", "_dir"];
    GVAR(artilleryParams) set ["position", _pos];
    GVAR(artilleryParams) set ["dispersion", _rad];
    GVAR(artilleryParams) set ["rotation", _dir];
    GVAR(artilleryParams) set ["gunCount", lbCurSel (_display displayCtrl IDC_ARTILLERY_GUUNCOUNT)];
    private _ctrl = _display displayCtrl IDC_ARTILLERY_ROUNDTYPE;
    private _curSel = lbCurSel _ctrl;
    GVAR(artilleryParams) set ["roundType", [_ctrl lbValue _curSel, _ctrl lbData _curSel]];
    GVAR(artilleryParams) set ["missionType", lbCurSel (_display displayCtrl IDC_ARTILLERY_MISSIONTYPE)];
    GVAR(artilleryParams) set ["missionLength", sliderPosition (_display displayCtrl IDC_ARTILLERY_MISSIONGLENGTH)];
    GVAR(artilleryParams) set ["missionDelay", sliderPosition (_display displayCtrl IDC_ARTILLERY_MISSIONGDELAY)];
    GVAR(artilleryParams) set ["missionTimeLength", sliderPosition (_display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTIME)];
    if (_exitCode != 1) exitWith {};
    [QGVAR(addMission), [
        profileName + ":" + str CBA_missionTime,
        clientOwner,
        GVAR(artilleryParams)
    ]] call CBA_fnc_serverEvent;
} else { // initialize the display to sync menu values
    if (isNil QGVAR(artilleryParams)) then {
        GVAR(artilleryParams) = createHashMap;
    };
    _eventArgs params ["_display"];
    private _mapCtrl = _display displayCtrl IDC_ARTILLERY_MAP;
    private _initPos = GVAR(artilleryParams) getOrDefault ["position", [0, 0, 0]];
    _mapCtrl ctrlMapAnimAdd [0, 0.2, _initPos];
    ctrlMapAnimCommit _mapCtrl;
    private _dims = [
        _initPos,
        GVAR(artilleryParams) getOrDefault ["dispersion", 60],
        GVAR(artilleryParams) getOrDefault ["rotation", 0]
    ];
    _display setVariable [QGVAR(pos), _dims];
    GVAR(artilleryMapEH) = [-1, -1, -1];
    GVAR(artilleryMapEH) set [0, _mapCtrl ctrlAddEventHandler ["Draw", {
        params ["_map"];
        private _display = ctrlParent _map;
        private _scale = 6.4 * worldSize / 8192 * ctrlMapScale _map;
        private _dims = _display getVariable [QGVAR(pos), [[0, 0, 0], 0, 0]];
        _map drawIcon [
            "\A3\ui_f\data\map\markers\military\arrow_CA.paa",
            [0.8,0,0,1], _dims#0, 20 / _scale, 20 / _scale, _dims#2
        ];
        switch (lbCurSel (_display displayCtrl IDC_ARTILLERY_MISSIONTYPE)) do {
            case ARTILLERY_MISSIONTYPE_LINEAR_WITH_WALK;
            case ARTILLERY_MISSIONTYPE_LINEAR: {
                _map drawRectangle [_dims#0, 10, _dims#1, _dims#2, [0.8,0,0,1], ""];
            };
            case ARTILLERY_MISSIONTYPE_CREEPING: {
                private _nGuns = lbCurSel (_display displayCtrl IDC_ARTILLERY_GUUNCOUNT);
                private _ctrl = (_display displayCtrl IDC_ARTILLERY_ROUNDTYPE);
                private _roundIdx = lbCurSel _ctrl;
                private _caliber = _ctrl lbValue _roundIdx;
                private _step = switch (true) do {
                    case (_caliber < 100): {30};
                    case (_caliber < 120): {40};
                    case (_caliber < 150): {50};
                    case (_caliber < 200): {60};
                    default {40};
                };
                private _halfWidth = (_nGuns - 1) * _step;
                _map drawRectangle [_dims#0, _halfWidth max 1, _dims#1, _dims#2, [0.8,0,0,1], ""];
            };
            default {
                _map drawEllipse [_dims#0, _dims#1, ARTILLERY_ELLIPSE_COMPRESSION * (_dims#1), _dims#2, [0.8,0,0,1], ""];
            };
        };
    }]];
    GVAR(artilleryMapEH) set [1, _mapCtrl ctrlAddEventHandler ["MouseButtonClick", {
        params ["_map", "", "_xPos", "_yPos"];
        private _display = ctrlParent _map;
        private _dims = _display getVariable [QGVAR(pos), [[0, 0, 0], 0, 0]];
        private _newPos = (_map ctrlMapScreenToWorld [_xPos, _yPos]) + [0];
        _dims set [0, _newPos];
        GVAR(artilleryParams) set ["position", _newPos];
    }]];
    /*GVAR(artilleryMapEH) set [2, _mapCtrl ctrlAddEventHandler ["MouseMoving", {
        params ["_map", "_xPos", "_yPos", "_mouseOver"];
        if (_mouseOver) then {
            private _dims = _display getVariable [QGVAR(pos), [[0, 0, 0], 0, 0]];
            _map drawEllipse [(_map ctrlMapScreenToWorld [_xPos, _yPos]) + [0], _dims#1, _dims#1, 0, [0.8,0,0,0.5], ""];
        };
    }]];*/
    [_display] call FUNC(ui_initRoundTypes);
    (_display displayCtrl IDC_ARTILLERY_GUUNCOUNT) lbSetCurSel (GVAR(artilleryParams) getOrDefault ["gunCount", 2]);
    (_display displayCtrl IDC_ARTILLERY_MISSIONTYPE) lbSetCurSel (GVAR(artilleryParams) getOrDefault ["missionType", ARTILLERY_MISSIONTYPE_LAZY]);
    (_display displayCtrl IDC_ARTILLERY_ROUNDTYPE) lbSetCurSel (GVAR(artilleryAmmoTypes) find ((GVAR(artilleryParams) getOrDefault ["roundType", [0,0]])#1));
    (_display displayCtrl IDC_ARTILLERY_DISPERSION) sliderSetPosition (_dims#1);
    (_display displayCtrl IDC_ARTILLERY_ROTATION) sliderSetPosition (_dims#2);
    (_display displayCtrl IDC_ARTILLERY_AVOIDPLAYERS) cbSetChecked (GVAR(artilleryParams) getOrDefault ["avoidPlayers", true]);
    // update initial values
    private _missionLength = GVAR(artilleryParams) getOrDefault ["missionLength", 4];
    private _sliderControl = _display displayCtrl IDC_ARTILLERY_MISSIONGLENGTH;
    [[_sliderControl, _missionLength], IDC_ARTILLERY_MISSIONGLENGTH] call FUNC(ui_updateArtillleryMenu);
    _sliderControl sliderSetPosition _missionLength;
    private _missionDelay = GVAR(artilleryParams) getOrDefault ["missionDelay", 4];
    _sliderControl = _display displayCtrl IDC_ARTILLERY_MISSIONGDELAY;
    [[_sliderControl, _missionDelay], IDC_ARTILLERY_MISSIONGDELAY] call FUNC(ui_updateArtillleryMenu);
    _sliderControl sliderSetPosition _missionDelay;
    private _missionLengthTime = GVAR(artilleryParams) getOrDefault ["missionTimeLength", 180];
    _sliderControl = _display displayCtrl IDC_ARTILLERY_MISSIONGLENGTHTIME;
    [[_sliderControl, _missionLengthTime], IDC_ARTILLERY_MISSIONGLENGTHTIME] call FUNC(ui_updateArtillleryMenu);
    _sliderControl sliderSetPosition _missionLengthTime;
};
