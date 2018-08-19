private _mags = getArray (configFile >> "CfgWeapons" >> "rhs_weap_ak74m_Base_F" >> "magazines");
private _magsNeedingProxy = [];
{
    private _mag = _x;
    if ((getNumber (configFile >> "CfgMagazines" >> _mag >> "modelSpecialIsProxy")) == 0) then {
        if ((_magsNeedingProxy findIf {_mag isKindOf [_x, configFile >> "CfgMagazines"]}) == -1) then {
            private _add = true;
            {
                if (_x isKindOf [_mag, configFile >> "CfgMagazines"]) exitWith {
                    _add = false;
                    diag_log text format ["Replace %1 with %2", _x, _mag];
                    _magsNeedingProxy set [_forEachIndex, _mag];
                };
            } forEach _magsNeedingProxy;
            if (_add) then {
                diag_log text format ["Add %1", _mag];
                _magsNeedingProxy pushBack _mag;
            };
        } else {
                diag_log text format ["Already Covered %1", _mag];
        };
    };
} forEach _mags;
x3 = _magsNeedingProxy;