["MCLOS Missiles", [{
    private _enabled = false;
    {
        private _magazines = (magazinesAllTurrets _y) apply {_x#0};
        _magazines = _magazines arrayIntersect _magazines;
        if ((_magazines findIf {
            private _ammo = getText (configFile >> "CfgMagazines" >> _x >> "ammo");
            ("MCLOS" in getArray (configFile >> "CfgAmmo" >> _ammo >> "ace_missileguidance" >> "seekerTypes"))
        }) != -1) exitWith {
            _enabled = true;
        };
    } forEach _vehicles;
    _enabled
}, {"
Squad vehicle may be equiped with MCLOS missiles<br/><br/>

Fire missile and control with num-pad direction keys<br/>
-Keybind is changeable<br/>
-Make small adjustments<br/>
"}]]
