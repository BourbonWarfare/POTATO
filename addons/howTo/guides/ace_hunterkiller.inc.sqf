["Hunter-Killer", [{
    private _enabled = false;
    {
        if ((_y getVariable ["ace_hunterkiller", false]) || { 
            private _cfg = configOf _y >> "ace_hunterkiller";
            isNumber _cfg || isArray _cfg
        }) exitWith {
            _enabled = true;
        };
    } forEach _vehicles;
    _enabled
}, {"
Squad vehicle may be equiped with ace_hunterkiller<br/><br/>

Observe other turret: Press Q<br/>
Override other turret: Press E<br/>
"}]]
