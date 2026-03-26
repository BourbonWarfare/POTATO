#include "..\..\script_component.hpp"
/**************************************************************//*
* Updates designated artillery marker
*
* Arguments:
* None
*
* Example:
* [] call lmd_fnc_ui_handleCircleSpawnMenu
*//**************************************************************/
params [
    "_args",
    ["_callPotPass", false, [false]],
    ["_initPos", [0, 0, 0], [[]]],
    ["_argsFunction", {}, [{}]]
];

if (_args isNotEqualTo []) then {
    _args params [
        ["_display", displayNull, [displayNull]],
        ["_exitCode", 2, [2]]
    ];
    removeMissionEventHandler ["MapSingleClick", GVAR(circleMapClickEH)];
    GVAR(circleMapClickEH) = -1;
    if (isNull _display || _exitCode != 1) exitWith {};
    private _rad = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_RAD);
    private _length = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_LENGTH);
    private _goalCnt = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_CNT);
    private _minCnt = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_MIN);
    private _maxCnt = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_MAX);
    private _period = sliderPosition (_display displayCtrl IDC_CIRCLESPAWN_PRD);
    GVAR(cirlceSpawnFunction) params ["_callPotPass",
        ["_argsFunction", {
            params ["_rad", "_length", "_goalCnt", "_minCnt", "_maxCnt", "_period"];
            [[GVAR(cirlceSpawnMarkInfo)#1, 500 max 0.35 * _rad, _rad],
            {_this*0.75},
            compile format ["16+8*(count (allPlayers select {alive _x && side _x == west}))*(0.5+0.5*sin(360*CBA_missionTime/%1))", _period],
            true, CBA_missionTime + _length, resistance, west
            ]
        }, [{}]]
    ];
    private _funcArgs = [_rad, _length, _goalCnt, _minCnt, _maxCnt, _period] call _argsFunction;
    if (_callPotPass) then {
        [_funcArgs, QFUNC(addCircleSpawner)] call potato_zeusHC_fnc_hcPassthrough;
    } else {
        _funcArgs remoteExecCall [QFUNC(addCircleSpawner), 2];
    };
} else {
    if (_argsFunction isEqualTo {}) then {
        GVAR(cirlceSpawnFunction) = [_callPotPass];
    } else {
        GVAR(cirlceSpawnFunction) = [_callPotPass, _argsFunction];
    };
    GVAR(cirlceSpawnMarkInfo) = [750, _initPos];
    private _display = createDialog [QGVAR(circleWaveSpawner)];
    private _mapCtrl = _display displayCtrl IDC_CIRCLESPAWN_MAP;
    _mapCtrl ctrlAddEventHandler ["Draw", {
        (_this#0) drawEllipse [GVAR(cirlceSpawnMarkInfo)#1, GVAR(cirlceSpawnMarkInfo)#0, GVAR(cirlceSpawnMarkInfo)#0, 0, [0,0,0.8,1], ""];
    }];
    //_mapCtrl ctrlMapSetPosition [-0.275, 0, 0.6875, 0.8];
    _mapCtrl ctrlMapAnimAdd [0, 0.25, _initPos];
    ctrlMapAnimCommit _mapCtrl;
    GVAR(circleMapClickEH) = addMissionEventHandler ["MapSingleClick", {
        params ["", "_pos"];
        GVAR(cirlceSpawnMarkInfo) set [1, _pos];
    }];
};
