// Based on intro cutscene for MGB Celle 2 by Mondkalb
bw_celle_introCam = "camera" camCreate getPosATL player;
private _infoArray = [[[2375,1152,0],[2355,1141,2],[2364,1183,11], 10],
[[7449,1466,0],[7794,1458,8],[7585,1196,13], 10],
[[8775,2100,0],[9009,2275,58],[8995,2104,5], 10],
[[8465,6246,0],[8637,6245,7],[8434,6410,12], 20],
[[11106,11176,0],[10421,10652,12],[10785,10777,52], 20],
[[6679,7907,0],[6882,7931,11],[6764,8159,11], 20],
[[5777,4049,0],[5463,4050,9],[5642,3757,9], 20],
[[1624,4146,0],[1350,3929,6],[1546,3872,6], 10],
[[1709,9235,0],[1522,8441,6],[1634,9020,2], 20],
[[6051,5720,0],[6271,5835,0.5],[6081,5731,149], 10],
[[6932,6571,0],[7241,6743,10],[7007,6848,10], 20],
[[7106,5946,0],[7508,6230,1],[7425,6300,1], 20],
[[4249,8396,0],[3856,6545,7],[3864,6543,7], 10]];
[_infoArray, true] call CBA_fnc_shuffle;
private _fnc_camMove = {
    params [
        ["_focusPointAGL", [0, 0, 0], [[]]],
        ["_cameraGoalAGL", [0, 0, 0], [[]]],
        ["_transitionTime", 0, [0]]
    ];
    bw_celle_introCam camPrepareTarget _focusPointAGL;
    bw_celle_introCam camPreparePos _cameraGoalAGL;
    bw_celle_introCam camCommitPrepared _transitionTime;
};
bw_celle_introCam camPrepareFov 0.7;
bw_celle_introCam cameraEffect ["Internal", "BACK"];
titleText ["", "BLACK FADED"];
showCinemaBorder false;
bw_celle_introCam camCommitPrepared 0;


private _countIdx = 0;
while {missionNamespace getVariable ["BW_celle2IntroExit", true]} do {
    [_infoArray, true] call CBA_fnc_shuffle;
    {
        _x params ["_focus", "_startPosAGL", "_endPosAGL", "_baseTransTime"];
        private _transitionTime = _baseTransTime + random 3;
        [_focus, _startPosAGL] call _fnc_camMove;
        sleep 1;
        titleText ["", "BLACK IN"];
        sleep 0.5;
        [_focus, _endPosAGL, _transitionTime] call _fnc_camMove;
        sleep _transitionTime;
        titleText ["", "BLACK OUT"];
        sleep 1;
    } forEach _infoArray;
};
bw_celle_introCam cameraEffect ["terminate", "back"];
camDestroy bw_celle_introCam;
titleFadeOut 0;

