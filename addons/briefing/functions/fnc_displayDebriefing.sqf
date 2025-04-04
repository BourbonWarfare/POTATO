_this spawn {
    params ["_control"];
    private _display = ctrlParent _control;
    TRACE_1("displayDebriefing",_display);
    private _end = diag_tickTime + 10;
    while {diag_tickTime < _end} do {
        uiSleep 0.05;
        private _button = _display displayCtrl 1;
        _button ctrlSetText format ["WAIT (%1 s)", (_end - diag_tickTime) toFixed 1];
        _button ctrlSetTextColor [1,0,0,1];
    };
    private _button = _display displayCtrl 1;
    _button ctrlSetText "Continue";
    _button ctrlSetTextColor [0,1,0,1];
};
