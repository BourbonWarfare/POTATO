lmd_tst_groupHash = createHashMap;

["CAManBase", "initPost", {[{
        params ["_unit"];
        if (side _unit != west) exitWith {};
        _unit addEventHandler ["Suppressed", {
            params ["_unit", "_distance", "_shooter", "", "", "", "_ammoConfig"];
            private _groupArr = lmd_tst_groupHash getOrDefault [groupId group _unit, [0, createHashMap, group _unit], true];
            _groupArr params ["_threat"];
            if (side _shooter getFriend side _unit < 0.5) then {
                private _caliber = getNumber (_ammoConfig >> "caliber");
                _threat = _threat + 0.1 * _caliber * exp (-0.1 * _distance);
                _groupArr set [0, _threat];
            };
        }];
        _unit addEventHandler ["FiredMan", {
            params ["_unit", "", "", "", "_ammo"];
            private _groupArr = lmd_tst_groupHash getOrDefault [groupId group _unit, [0, createHashMap, group leader _unit], true];
            _groupArr params ["_threat", "_outBoundThreatHash"];
            private _threatOutput = _outBoundThreatHash getOrDefault [getObjectID _unit, [0, -1, _unit], true];
            private _caliber = getNumber (configFile >> "CfgAmmo" >> _ammo >> "caliber");
            private _dT = CBA_missionTime - (_threatOutput#1);
            private _inc = log (1 + _caliber) ;
            _groupArr set [0, _threat + (_inc * (0.1 min (_dT / 30)))];
            _threatOutput set [0, (_threatOutput#0) * exp (-_dT / 20) + _inc];
            _threatOutput set [1, CBA_missionTime];
        }];
    }, _this, 5] call CBA_fnc_waitAndExecute;
}, true, [], true] call CBA_fnc_addClassEventHandler;

addMissionEventHandler ["EntityKilled", {
    params ["_unit"];
    private _groupArr = lmd_tst_groupHash getOrDefault [groupId group _unit, []];
    if (_groupArr isEqualTo []) exitWith {};
    _groupArr params ["_threat"];
    _threat = _threat + 20;
    _groupArr set [0, _threat];
}];

["ace_unconscious", {
    params ["_unit", "_uncon"];
    if (_uncon && side _unit == west) then {
        private _groupArr = lmd_tst_groupHash getOrDefault [groupId group _unit, [0, createHashMap, group leader _unit], true];
        _groupArr params ["_threat"];
        _threat = _threat + 5;
        _groupArr set [0, _threat];
    };
}] call CBA_fnc_addEventHandler;

addMissionEventHandler ["Draw3D", {
    private _localCuratorModule = curatorCamera;
    private _factor = [1, exp(-diag_deltaTime * accTime / 100)] select (!isGamePaused);
    if (isNull _localCuratorModule) then {_localCuratorModule = ace_player};
    {
        _y params ["_threat", "_outboundHash", "_group"];
        drawIcon3D [
            "",
            [1, 1, 1, 0.8],
            ASLToAGL getPosASLVisual leader _group,
            1,
            2,
            0,
            format ["%1|%2", groupId _group, _threat toFixed 1],
            2,
            0.04
        ];
        _y set [0, _threat * _factor];
        /*{
            _y params ["_threat", "", "_unit"];
            drawIcon3D [
                "",
                [1, 1, 0.4, 0.8],
                ASLToAGL getPosASLVisual _unit,
                1,
                2,
                0,
                _threat toFixed 1,
                2,
                0.04
            ];
        } forEach _outboundHash;*/
        if ({alive _x} count units _group <= 0) then {lmd_tst_groupHash deleteAt _x};
    } forEach lmd_tst_groupHash;
}];
