#include "script_component.hpp"

TRACE_2("export",_this);

private _fnc_formatList = {
    params ["_list"];
    if (!(_list isEqualType [])) exitWith {""};
    private _return = "";
    _list = _list select {_x != ""};
    {
        _return = _return + format ['"%1"', _x];
        if (_forEachIndex < ((count _list) -1)) then {_return = _return + ", ";};
    } forEach _list;
    if (_return == "") then {_return = '""';};
    TRACE_2("formatList",_list,_return);
    _return
};
private _fnc_getMags = {
    params ["_weapon", "_mags", ["_wantedRounds", -1]];
    if (!(_mags isEqualType [])) exitWith {""};
    _mags = _mags select {private _mag = _x; ({_mag == _x} count getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines")) > 0};
    private _magRounds = getNumber (configFile >> "CfgMagazines" >> (_mags param [0, ""]) >> "count");
    if (_magRounds == 0) exitWith {'"ERROR_no_valid_mags"'};
    private _return = "";
    {
        if (_wantedRounds <= 0) then {
            _return = _return + format ['"%1:1"', _x];
        } else {
            private _magCount = 2;
            if (_forEachIndex == 0) then {_magCount = 1 max ((ceil (_wantedRounds / _magRounds)) - 2 * ((count _mags) - 1));};
            _return = _return + format ['"%1:%2"', _x, _magCount];
        };
        if (_forEachIndex < ((count _mags) -1)) then {_return = _return + ", ";};
    } forEach _mags;
    if (_return == "") then {_return = '""';};
    TRACE_4("getMags",_weapon,_mags,_wantedRounds,_return);
    _return
};

private _lines = [];
_lines pushBack format ["// Camo set"];
_lines pushBack format ['#define CAMO_UNIFORM "%1"', GVAR(loadout_uniform)];
_lines pushBack format ['#define CAMO_VEST "%1"', GVAR(loadout_vest)];
_lines pushBack format ['#define CAMO_BACKPACK "%1"', GVAR(loadout_backpack)];
_lines pushBack format ['#define CAMO_HEADGEAR "%1"', GVAR(loadout_headgear)];

_lines pushBack format ["// Rifle"];
_lines pushBack format ['#define RIFLE "%1"', GVAR(loadout_rifle)];
_lines pushBack format ['#define RIFLE_MAG %1', [GVAR(loadout_rifle), GVAR(loadout_rifleMags), 300] call _fnc_getMags];
_lines pushBack format ['#define RIFLE_ATTACHMENTS %1', [GVAR(loadout_rifleAttachments)] call _fnc_formatList];
_lines pushBack format ['#define AAR_ATTACHMENTS RIFLE_ATTACHMENTS'];
_lines pushBack format ['#define ALT_OPTICS "optic_Aco","rhsusf_acc_compm4","rhsusf_acc_eotech_xps3","CUP_optic_CompM2_Black","CUP_optic_TrijiconRx01_black","BWA3_optic_RSAS","RKSL_optic_RMR_MS19"'];

_lines pushBack format ["// GL Rifle"];
_lines pushBack format ['#define GLRIFLE "%1"', GVAR(loadout_glrifle)];
_lines pushBack format ['#define GLRIFLE_MAG %1', [GVAR(loadout_glrifle), GVAR(loadout_glRifleMags), 300] call _fnc_getMags];

private _glMuzzle = (getArray (configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> "muzzles")) param [1, "no2ndMuzzle"];
private _glMags = getArray (configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> _glMuzzle >> "magazines");
switch (true) do {
    case (({"1Rnd_Smoke_Grenade_shell" == _x} count _glMags) > 0):{
        _lines pushBack format ['#define GLRIFLE_MAG_SMOKE "1Rnd_Smoke_Grenade_shell:2","1Rnd_SmokeRed_Grenade_shell:2"'];
        _lines pushBack format ['#define GLRIFLE_MAG_HE "1Rnd_HE_Grenade_shell:5"'];
        _lines pushBack format ['#define GLRIFLE_MAG_FLARE "UGL_FlareYellow_F:4"'];
    };
    case (({"rhs_GRD40_White" == _x} count _glMags) > 0):{
        _lines pushBack format ['#define GLRIFLE_MAG_SMOKE "rhs_GRD40_White:2","rhs_GRD40_Red:2"'];
        _lines pushBack format ['#define GLRIFLE_MAG_HE "rhs_VOG25:5"'];
        _lines pushBack format ['#define GLRIFLE_MAG_FLARE "rhs_VG40OP_red:4"'];
    };
    default {
        _lines pushBack format ["// WARNING - Unknown GL Muzzle [%1->%2]", GVAR(loadout_glrifle), _glMuzzle];
        _lines pushBack format ['#define GLRIFLE_MAG_SMOKE ""'];
        _lines pushBack format ['#define GLRIFLE_MAG_HE ""'];
        _lines pushBack format ['#define GLRIFLE_MAG_FLARE ""'];
    };
};

_lines pushBack format ["// Carbine"];
_lines pushBack format ['#define CARBINE "%1"', GVAR(loadout_carbine)];
_lines pushBack format ['#define CARBINE_MAG %1', [GVAR(loadout_carbine), GVAR(loadout_carbineMags), 300] call _fnc_getMags];

_lines pushBack format ["// AR"];
_lines pushBack format ['#define AR "%1"', GVAR(loadout_ar)];
_lines pushBack format ['#define AR_MAG %1', [GVAR(loadout_ar), GVAR(loadout_arMags), 500] call _fnc_getMags];

_lines pushBack format ["// AT"];
_lines pushBack format ['#define AT "%1"', GVAR(loadout_at)];
_lines pushBack format ['#define AT_MAG %1', [GVAR(loadout_at), GVAR(loadout_atMags), -1] call _fnc_getMags];

_lines pushBack format ["// MMG"];
_lines pushBack format ['#define MMG "%1"', GVAR(loadout_mmg)];
_lines pushBack format ['#define MMG_MAG %1', [GVAR(loadout_mmg), GVAR(loadout_mmgMags), 500] call _fnc_getMags];

_lines pushBack format ["// MAT"];
_lines pushBack format ['#define MAT "%1"', GVAR(loadout_at)];
_lines pushBack format ['#define MAT_MAG %1', [GVAR(loadout_at), GVAR(loadout_atMags), -1] call _fnc_getMags];
_lines pushBack format ['#define MAT_MAG2 %1', [GVAR(loadout_at), GVAR(loadout_atMags), -1] call _fnc_getMags];
_lines pushBack format ['#define MAT_OPTIC %1', [GVAR(loadout_matAttachments)] call _fnc_formatList];

{
    "ace_clipboard" callExtension _x;
    "ace_clipboard" callExtension "
";
} forEach _lines;
"ace_clipboard" callExtension "--COMPLETE--";
systemChat format ["Copied @ %1", CBA_missionTime];

