#include "script_component.hpp"

TRACE_1("export",_this);

#define RIFLE_ROUNDS 300
#define AR_ROUNDS 400
#define MMG_ROUNDS 500
#define AT_ROUNDS 1
#define MAT_ROUNDS 2
#define HMG_ROUNDS 300
#define HAT_ROUNDS 2
#define SAM_ROUNDS 2
#define SNIPER_ROUNDS 100
#define SMG_ROUNDS 150
#define PISTOL_ROUNDS 30

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
private _fnc_default = {
    params ["_gvar",["_default",""]];
    if(isNil _gvar) exitWith {_default};
    _gvar
};
private _fnc_getMags = {
    params ["_weapon", "_mags", ["_wantedRounds", -1]];
    if (!(_mags isEqualType [])) exitWith {""};
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
_lines pushBack format ['#define CARRYALL "%1"', [GVAR(loadout_carryall),GVAR(loadout_backpack)] call _fnc_default];
_lines pushBack format ['#define CAMO_HEADGEAR "%1"', GVAR(loadout_headgear)];
_lines pushBack format ['#define CAMO_HEADGEAR_SPECIAL "%1"', [GVAR(loadout_headgear_alt),GVAR(loadout_headgear)] call _fnc_default];

_lines pushBack format ["// Pilot Camo set"];
_lines pushBack format ['#define CAMO_UNIFORM_PILOT "%1"', GVAR(loadout_pilot_uniform)];
_lines pushBack format ['#define CAMO_VEST_PILOT "%1"', GVAR(loadout_pilot_vest)];
_lines pushBack format ['#define CAMO_BACKPACK_PILOT "%1"', GVAR(loadout_pilot_backpack)];
_lines pushBack format ['#define CAMO_HEADGEAR_PILOT "%1"', GVAR(loadout_pilot_headgear)];

_lines pushBack format ["// Vic Crew Camo set"];
_lines pushBack format ['#define CAMO_UNIFORM_VICC "%1"', GVAR(loadout_vicc_uniform)];
_lines pushBack format ['#define CAMO_VEST_VICC "%1"', GVAR(loadout_vicc_vest)];
_lines pushBack format ['#define CAMO_BACKPACK_VICC "%1"', GVAR(loadout_vicc_backpack)];
_lines pushBack format ['#define CAMO_HEADGEAR_VICC "%1"', GVAR(loadout_vicc_headgear)];

_lines pushBack format ["// Rifle"];
_lines pushBack format ['#define RIFLE "%1"', GVAR(loadout_rifle)];
_lines pushBack format ['#define RIFLE_MAG %1', [GVAR(loadout_rifle), GVAR(loadout_rifleMags), RIFLE_ROUNDS] call _fnc_getMags];
_lines pushBack format ['#define RIFLE_ATTACHMENTS %1', [GVAR(loadout_rifleAttachments)] call _fnc_formatList];
_lines pushBack format ['#define AAR_ATTACHMENTS RIFLE_ATTACHMENTS'];
_lines pushBack format ['#define ALT_OPTICS "optic_Aco","CUP_optic_CompM2_Black","CUP_optic_TrijiconRx01_black","CUP_optic_MRad"'];

_lines pushBack format ["// GL Rifle"];
_lines pushBack format ['#define GLRIFLE "%1"', GVAR(loadout_glrifle)];
_lines pushBack format ['#define GLRIFLE_MAG %1', [GVAR(loadout_glrifle), GVAR(loadout_glRifleMags), RIFLE_ROUNDS] call _fnc_getMags];

private _glMuzzle = (getArray (configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> "muzzles")) param [1, "no2ndMuzzle"];
private _glMags = [configFile >> "CfgWeapons" >> GVAR(loadout_glrifle) >> _glMuzzle] call CBA_fnc_compatibleMagazines;
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
_lines pushBack format ['#define CARBINE_MAG %1', [GVAR(loadout_carbine), GVAR(loadout_carbineMags), RIFLE_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// AR"];
_lines pushBack format ['#define AR "%1"', GVAR(loadout_ar)];
_lines pushBack format ['#define AR_MAG %1', [GVAR(loadout_ar), GVAR(loadout_arMags), AR_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// AT"];
_lines pushBack format ['#define AT "%1"', GVAR(loadout_at)];
_lines pushBack format ['#define AT_MAG %1', [GVAR(loadout_at), GVAR(loadout_atMags), AT_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// MMG"];
_lines pushBack format ['#define MMG "%1"', GVAR(loadout_mmg)];
_lines pushBack format ['#define MMG_MAG %1', [GVAR(loadout_mmg), GVAR(loadout_mmgMags), MMG_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// MAT"];
_lines pushBack format ['#define MAT "%1"', GVAR(loadout_mat)];
_lines pushBack format ['#define MAT_MAG %1', [GVAR(loadout_mat), GVAR(loadout_matMags), MAT_ROUNDS] call _fnc_getMags];
_lines pushBack format ['#define MAT_OPTIC %1', [GVAR(loadout_matAttachments)] call _fnc_formatList];

_lines pushBack format ["// HMG"];
_lines pushBack format ['#define HMG "%1"', GVAR(loadout_hmg)];
_lines pushBack format ['#define HMG_TRI_HI "%1"', GVAR(loadout_hmg_tri_1)];
_lines pushBack format ['#define HMG_TRI_LO "%1"', [GVAR(loadout_hmg_tri_2),GVAR(loadout_hmg_tri_1)] call _fnc_default];
_lines pushBack format ['#define HMG_MAG %1', [GVAR(loadout_hmg), GVAR(loadout_hmgMags), HMG_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// HAT"];
_lines pushBack format ['#define HAT "%1"', GVAR(loadout_hat)];
_lines pushBack format ['#define HAT_TRI_HI "%1"', GVAR(loadout_hat_tri_1)];
_lines pushBack format ['#define HAT_TRI_LO "%1"', [GVAR(loadout_hat_tri_2),GVAR(loadout_hat_tri_1)] call _fnc_default];
_lines pushBack format ['#define HAT_MAG %1', [GVAR(loadout_hat), GVAR(loadout_hatMags), HAT_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// SAM"];
_lines pushBack format ['#define SAM "%1"', GVAR(loadout_sam)];
_lines pushBack format ['#define SAM_MAG %1', [GVAR(loadout_sam), GVAR(loadout_samMags), SAM_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// Sniper"];
_lines pushBack format ['#define SNIPER "%1"', GVAR(loadout_sniper)];
_lines pushBack format ['#define SNIPER_MAG %1', [GVAR(loadout_sniper), GVAR(loadout_sniperMags), SNIPER_ROUNDS] call _fnc_getMags];
_lines pushBack format ['#define SNIPER_OPTIC %1', [GVAR(loadout_sniperAttachments)] call _fnc_formatList];

_lines pushBack format ["// Spotter"];
_lines pushBack format ['#define SPOTTER "%1"', GVAR(loadout_spotter)];
_lines pushBack format ['#define SPOTTER_MAG %1', [GVAR(loadout_spotter), GVAR(loadout_spotterMags), RIFLE_ROUNDS] call _fnc_getMags];
_lines pushBack format ['#define SPOTTER_OPTIC %1', [GVAR(loadout_spotterAttachments)] call _fnc_formatList];

_lines pushBack format ["// SMG"];
_lines pushBack format ['#define SMG "%1"', GVAR(loadout_smg)];
_lines pushBack format ['#define SMG_MAG %1', [GVAR(loadout_smg), GVAR(loadout_smgMags), SMG_ROUNDS] call _fnc_getMags];

_lines pushBack format ["// Pistol"];
_lines pushBack format ['#define PISTOL "%1"', GVAR(loadout_pistol)];
_lines pushBack format ['#define PISTOL_MAG %1', [GVAR(loadout_pistol), GVAR(loadout_pistolMags), PISTOL_ROUNDS] call _fnc_getMags];
_lines pushBack format ['#define PISTOL_OPTIC %1', [GVAR(loadout_pistolAttachments)] call _fnc_formatList];

_lines pushBack format ["// Grenades"];
_lines pushBack format ["#define LEADER_GRENADES BASE_FRAG,LEADER_SMOKES,SIDE_CHEM_LIGHT"];

_lines pushBack format ["// Gear"];
_lines pushBack format ["#define TOOLS BASE_TOOLS"];
_lines pushBack format ["#define LEADER_TOOLS BASE_LEADER_TOOLS,SIDE_KEY"];
_lines pushBack format ["#define LINKED BASE_LINKED"];
_lines pushBack format ["#define LEADER_LINKED BASE_LEADER_LINKED"];

{
    "ace" callExtension ["clipboard:append", [_x + endl]];
} forEach _lines;
"ace" callExtension ["clipboard:complete", []];
systemChat format ["Copied @ %1", CBA_missionTime];
