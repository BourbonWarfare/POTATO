[{
// Load vests
lmd_tst_fnc_vestTestRecurse = compileScript ["vestTestRecurse.sqf"];
lmd_tst_errors = 0;
private _vests ="(configName _x) isKindOf [""Vest_Camo_Base"", configFile >> ""CfgWeapons""]  && getNumber (_x >> ""scope"") > 1"  configClasses (configFile >> "CfgWeapons");
lmd_tst_vestArmors = createHashMap;
{
	private _infoArr = [];
	private _cfg = _x >> "ItemInfo" >> "HitpointsProtectionInfo";
	{
		_infoArr pushBack getNumber (_cfg >> _x >> "armor");
	} forEach ["Abdomen", "Chest", "Diaphragm", "Neck"];
	lmd_tst_vestArmors set [configName _x, _infoArr];
} forEach _vests;

// Create unit
private _grp = createGroup [east, true];
private _unit = _grp createUnit ["B_Soldier_F", getPosATL player vectorAdd [10, 10, 0], [], 0, "NONE"];
removeAllWeapons _unit;
_unit setUnitPos "UP";
_unit disableAI "ALL";
lmd_tst_unit = _unit;
if (isNull _grp || isNull _unit) exitWith {
    hintSilent parseText format ["Failed to load<br/>_grp:%1<br/>_unit:%2", _grp, _unit];
};
diag_log formatText ["Beginning vest armor testing of %1 vests", count _vests];
[{
    params ["_unit"];
    _unit removeAllEventHandlers "HandleDamage";

    // Replace existing ace medical damage event handler
    private _ehID = _unit addEventHandler ["HandleDamage", {
        params ["_unit", "", "_damage", "", "", "", "", "_hitpoint", "", ""];
        _hitpoint = toLowerANSI _hitpoint;
        private _idx = ["hitabdomen", "hitchest", "hitdiaphragm", "hitneck"] find _hitpoint;
        if (_idx >=0) then {
            private _vest = vest _unit;
            private _armor = lmd_tst_vestArmors getOrDefaultCall [_vest, {
                private _cfg = configFile >> "CfgWeapons" >> _vest >> "ItemInfo" >> "HitpointsProtectionInfo";
                private _infoArr = [];
                {
                    _infoArr pushBack getNumber (_cfg >> _x >> "armor");
                } forEach ["Abdomen", "Chest", "Diaphragm", "Neck"];
                _infoArr
            }, true];
            if (_armor#_idx > 0 && {_damage > 1.1 * 9 / (_armor#_idx)}) then {
                lmd_tst_errors = lmd_tst_errors + 1;
                diag_log formatText ["Vest: %5 || Damage: %1/9 to %2 | Armor Value: %3#%4",_damage, _hitpoint, _armor, _idx, _vest];
            };
        };
        0 // no damage
    }];
    _unit setVariable ["ace_medical_HandleDamageEHID", _ehID];

}, _unit, 1] call CBA_fnc_waitAndExecute;

_vests = _vests apply {configName _x};
[{
    _this call lmd_tst_fnc_vestTestRecurse;
}, [_vests, _unit], 1.1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_directCall;
