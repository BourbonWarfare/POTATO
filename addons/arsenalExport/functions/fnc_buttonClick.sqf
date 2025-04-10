#include "script_component.hpp"

params ["_display", "_fncString"];
TRACE_2("canAttach",_display,_fncString);

private _unit = missionNamespace getVariable ["ace_arsenal_center", player]; /// supports ace arsanal in 3den

switch (toLower _fncString) do {
case ("init"): {};
case ("uniform"): {
        GVAR(loadout_uniform) = uniform _unit;
        GVAR(loadout_vest) = vest _unit;
        GVAR(loadout_backpack) = backpack _unit;
        GVAR(loadout_headgear) = headgear _unit;
        systemChat format ["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_uniform), GVAR(loadout_vest), GVAR(loadout_backpack), GVAR(loadout_headgear)];
    };
case ("uniform_pilot"): {
        GVAR(loadout_pilot_uniform) = uniform _unit;
        GVAR(loadout_pilot_vest) = vest _unit;
        GVAR(loadout_pilot_backpack) = backpack _unit;
        GVAR(loadout_pilot_headgear) = headgear _unit;
        systemChat format ["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_pilot_uniform), GVAR(loadout_pilot_vest), GVAR(loadout_pilot_backpack), GVAR(loadout_pilot_headgear)];
    };
case ("uniform_vicc"): {
        GVAR(loadout_vicc_uniform) = uniform _unit;
        GVAR(loadout_vicc_vest) = vest _unit;
        GVAR(loadout_vicc_backpack) = backpack _unit;
        GVAR(loadout_vicc_headgear) = headgear _unit;
        systemChat format ["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_vicc_uniform), GVAR(loadout_vicc_vest), GVAR(loadout_vicc_backpack), GVAR(loadout_vicc_headgear)];
    };
case ("carryall"): {
        GVAR(loadout_carryall) = backpack _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_carryall)];
    };
case ("headgear_alt"): {
        GVAR(loadout_headgear_alt) = headgear _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_headgear_alt)];
    };
case ("rifle"): {
        GVAR(loadout_rifle) = primaryWeapon _unit;
        GVAR(loadout_rifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_rifle)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_rifleAttachments) = primaryWeaponItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_rifle), GVAR(loadout_rifleMags), GVAR(loadout_rifleAttachments)];
    };
case ("glrifle"): {
        GVAR(loadout_glrifle) = primaryWeapon _unit;
        GVAR(loadout_glRifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_glrifle)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_glrifle), GVAR(loadout_glRifleMags)];
    };
case ("carbine"): {
        GVAR(loadout_carbine) = primaryWeapon _unit;
        GVAR(loadout_carbineMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_carbine)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_carbine), GVAR(loadout_carbineMags)];
    };
case ("ar"): {
        GVAR(loadout_ar) = primaryWeapon _unit;
        GVAR(loadout_arMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_ar)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_ar), GVAR(loadout_arMags)];
    };
case ("mmg"): {
        GVAR(loadout_mmg) = primaryWeapon _unit;
        GVAR(loadout_mmgMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_mmg)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_mmg), GVAR(loadout_mmgMags)];
    };
case ("at"): {
        GVAR(loadout_at) = secondaryWeapon _unit;
        GVAR(loadout_atMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_at)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_at), GVAR(loadout_atMags)];
    };
case ("mat"): {
        GVAR(loadout_mat) = secondaryWeapon _unit;
        GVAR(loadout_matMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_mat)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_matAttachments) = secondaryWeaponItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_mat), GVAR(loadout_matMags), GVAR(loadout_matAttachments)];
    };
case ("hmg"): {
        GVAR(loadout_hmg) = secondaryWeapon _unit;
        GVAR(loadout_hmgMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_hmg)] call CBA_fnc_compatibleMagazines);
        if (GVAR(loadout_hmgMags) isEqualTo [] && {isClass (configFile >> "CfgWeapons" >> GVAR(loadout_hmg) >> "ace_csw")}) then {
            // Find CSW vehicle
            private _cswCfg = configFile >> "CfgWeapons" >> GVAR(loadout_hmg) >> "ace_csw";
            private _vehicle = if (isClass (_cswCfg >> "assembleTo")) then {
                private _assembleTo = configName ((configProperties [_cswCfg >> "assembleTo"])#0);
                getText (_cswCfg >> "assembleTo" >> _assembleTo);
            } else {
                getText (_cswCfg >> "deploy");
            };
            // Find weapon and compatible magazines
            private _vehicleTurretCfg = configFile >> "CfgVehicles" >> _vehicle >> "Turrets";
            private _firstTurret = (configProperties [_vehicleTurretCfg, "isClass _x"])#0;
            private _weapon = (getArray (_firstTurret >> "weapons"))#0;
            private _compatibleMagazines = compatibleMagazines _weapon;
            // Find compatible player CSW mags
            private _unitMags = magazines _unit;
            private _cswGroups = configFile >> "ace_csw_groups";
            private _cswMagCfgs = [];
            {
                private _cfgPath = _cswGroups >> _x;
                if (isClass _cfgPath && {
                    private _convertMags = (configProperties [_cfgPath, "getNumber _x == 1"]) apply {configName _x};
                    (_convertMags arrayIntersect _compatibleMagazines) isNotEqualTo []
                }) then {
                    _cswMagCfgs pushBack _x;
                };
            } forEach (_unitMags arrayIntersect _unitMags);
            GVAR(loadout_hmgMags) = _cswMagCfgs;
        };
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_hmg), GVAR(loadout_hmgMags)];
    };
case ("hmg_tri_1"): {
        GVAR(loadout_hmg_tri_1) = secondaryWeapon _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_hmg_tri_1)];
    };
case ("hmg_tri_2"): {
        GVAR(loadout_hmg_tri_2) = secondaryWeapon _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_hmg_tri_2)];
    };
case ("hat"): {
        GVAR(loadout_hat) = secondaryWeapon _unit;
        GVAR(loadout_hatMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_hat)] call CBA_fnc_compatibleMagazines);
        if (GVAR(loadout_hatMags) isEqualTo [] && {isClass (configFile >> "CfgWeapons" >> GVAR(loadout_hat) >> "ace_csw")}) then {
            // Find CSW vehicle
            private _cswCfg = configFile >> "CfgWeapons" >> GVAR(loadout_hat) >> "ace_csw";
            private _vehicle = if (isClass (_cswCfg >> "assembleTo")) then {
                private _assembleTo = configName ((configProperties [_cswCfg >> "assembleTo"])#0);
                getText (_cswCfg >> "assembleTo" >> _assembleTo);
            } else {
                getText (_cswCfg >> "deploy");
            };
            // Find weapon and compatible magazines
            private _vehicleTurretCfg = configFile >> "CfgVehicles" >> _vehicle >> "Turrets";
            private _firstTurret = (configProperties [_vehicleTurretCfg, "isClass _x"])#0;
            private _weapon = (getArray (_firstTurret >> "weapons"))#0;
            private _compatibleMagazines = compatibleMagazines _weapon;
            // Find compatible player CSW mags
            private _unitMags = magazines _unit;
            private _cswGroups = configFile >> "ace_csw_groups";
            private _cswMagCfgs = [];
            {
                private _cfgPath = _cswGroups >> _x;
                if (isClass _cfgPath && {
                    private _convertMags = (configProperties [_cfgPath, "getNumber _x == 1"]) apply {configName _x};
                    (_convertMags arrayIntersect _compatibleMagazines) isNotEqualTo []
                }) then {
                    _cswMagCfgs pushBack _x;
                };
            } forEach (_unitMags arrayIntersect _unitMags);
            GVAR(loadout_hatMags) = _cswMagCfgs;
        };
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_hat), GVAR(loadout_hatMags)];
    };
case ("hat_tri_1"): {
        GVAR(loadout_hat_tri_1) = secondaryWeapon _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_hat_tri_1)];
    };
case ("hat_tri_2"): {
        GVAR(loadout_hat_tri_2) = secondaryWeapon _unit;
        systemChat format ["[Set %1]: %2", _fncString, GVAR(loadout_hat_tri_2)];
    };
case ("sam"): {
        GVAR(loadout_sam) = secondaryWeapon _unit;
        GVAR(loadout_samMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_sam)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_sam), GVAR(loadout_samMags)];
    };
case ("sniper"): {
        GVAR(loadout_sniper) = primaryWeapon _unit;
        GVAR(loadout_sniperMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_sniper)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_sniperAttachments) = primaryWeaponItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_sniper), GVAR(loadout_sniperMags), GVAR(loadout_sniperAttachments)];
    };
case ("spotter"): {
        GVAR(loadout_spotter) = primaryWeapon _unit;
        GVAR(loadout_spotterMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_spotter)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_spotterAttachments) = primaryWeaponItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_spotter), GVAR(loadout_spotterMags), GVAR(loadout_spotterAttachments)];
    };
case ("smg"): {
        GVAR(loadout_smg) = primaryWeapon _unit;
        GVAR(loadout_smgMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_smg)] call CBA_fnc_compatibleMagazines);
        systemChat format ["[Set %1]: %2 %3", _fncString, GVAR(loadout_smg), GVAR(loadout_smgMags)];
    };
case ("pistol"): {
        GVAR(loadout_pistol) = handgunWeapon _unit;
        GVAR(loadout_pistolMags) = ((handgunMagazine _unit) + (magazines _unit)) arrayIntersect ([GVAR(loadout_pistol)] call CBA_fnc_compatibleMagazines);
        GVAR(loadout_pistolAttachments) = handgunItems _unit;
        systemChat format ["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_pistol), GVAR(loadout_pistolMags), GVAR(loadout_pistolAttachments)];
    };
case ("grenades"): {
        private _throwables = (throwables _unit) apply {_x#0};
        _throwables = _throwables arrayIntersect _throwables;
        private _cfgMags = configFile >> "CfgMagazines";
        private _cfgAmmo = configFile >> "CfgAmmo";
        GVAR(loadout_smokeGrenade) = _throwables select {
            private _ammo = getText (_cfgMags >> _x >> "ammo");
            private _aiAmmoCfg = _cfgAmmo >> _ammo >> "aiAmmoUsageFlags";
            if (isText _aiAmmoCfg) then { // check if "4" flag is set for smoke
                private _aiAmmoValues = (((getText _aiAmmoCfg) splitString " +") apply {parseNumber _x});
                4 in _aiAmmoValues || {
                    private _tempBool = false;
                    {
                        _tempBool = _tempBool || [_x, 4] call BIS_fnc_bitflagsCheck
                    } forEach _aiAmmoValues;
                    _tempBool
                }
            } else {
                [getNumber _aiAmmoCfg, 4] call BIS_fnc_bitflagsCheck
            };
        };
        GVAR(loadout_handGrenade) = _throwables - GVAR(loadout_smokeGrenade);
        systemChat format ["[Set %1]: %2, %3", _fncString, GVAR(loadout_handGrenade), GVAR(loadout_smokeGrenade)];
    };
    default {ERROR_1("bad fnc [%1]",_fncString);};
};

{
    private _ctrlText = _x;
    private _output = "";
    {
        _output = _output + format ["%1 ", missionNamespace getVariable [_x, "err"]];
    } forEach (_ctrlText getVariable [QGVAR(vars), []]);
    _ctrlText ctrlSetText _output;
    _ctrlText ctrlSetTooltip _output;
} forEach (_display getVariable [QGVAR(ctrlsToUpdate), []]);
