#include "script_component.hpp"

params ["_display", "_fncString"];
TRACE_2("canAttach",_display,_fncString);

private _unit = missionNamespace getVariable ["ace_arsenal_center", player]; /// supports ace arsanal in 3den

switch (toLower _fncString)
  do {
    case ("init"): {systemChat "Init";};
    case ("uniform"): {
      if (typeName GVAR(loadout_uniform) == "STRING" && {
          GVAR(loadout_uniform) == "NotSet"
        }) then {
        GVAR(loadout_uniform) = uniform _unit;
      } else {
        if (typeName GVAR(loadout_uniform) == "STRING") then {
          if (GVAR(loadout_uniform) == "") then {
            GVAR(loadout_uniform) = uniform _unit;
          }
          else {
            private _UniformTMP = [uniform _unit];
            _UniformTMP pushBackUnique GVAR(loadout_uniform);
            GVAR(loadout_uniform) = _UniformTMP;
          };
        } else {
          private _UniformTMP = uniform _unit;
          if (_UniformTMP != "") then {
            GVAR(loadout_uniform) pushBackUnique _UniformTMP
          };
        };
      };
      if (typeName GVAR(loadout_vest) == "STRING" && {
          GVAR(loadout_vest) == "NotSet"
        }) then {
        GVAR(loadout_vest) = vest _unit;
        private _VestTMP = [vest _unit];
      } else {
        if (typeName GVAR(loadout_vest) == "STRING") then {
          if (GVAR(loadout_vest) == "") then {
            GVAR(loadout_vest) = vest _unit;
          }
          else {
            private _VestTMP = [vest _unit];
            _VestTMP pushBackUnique GVAR(loadout_vest);
            GVAR(loadout_vest) = _VestTMP;
          };
        } else {
          private _VestTMP = vest _unit;
          if (_VestTMP != "") then {
            GVAR(loadout_vest) pushBackUnique _VestTMP
          };
        };
      };
      if (typeName GVAR(loadout_backpack) == "STRING" && {
          GVAR(loadout_backpack) == "NotSet"
        }) then {
        GVAR(loadout_backpack) = backpack _unit;
      } else {
        if (typeName GVAR(loadout_backpack) == "STRING") then {
          if (GVAR(loadout_backpack) == "") then {
            GVAR(loadout_backpack) = backpack _unit;
          }
          else {
            private _BackpackTMP = [backpack _unit];
            _BackpackTMP pushBackUnique GVAR(loadout_backpack);
            GVAR(loadout_backpack) = _BackpackTMP;
          };
        } else {
          private _BackpackTMP = backpack _unit;
          if (_BackpackTMP != "") then {
            GVAR(loadout_backpack) pushBackUnique _BackpackTMP
          };
        };
      };
      if (typeName GVAR(loadout_headgear) == "STRING" && {
          GVAR(loadout_headgear) == "NotSet"
        }) then {
        GVAR(loadout_headgear) = headgear _unit;
      } else {
        if (typeName GVAR(loadout_headgear) == "STRING") then {
          if (GVAR(loadout_headgear) == "") then {
            GVAR(loadout_headgear) = headgear _unit;
          }
          else {
            private _HeadgearTMP = [headgear _unit];
            _HeadgearTMP pushBackUnique GVAR(loadout_headgear);
            GVAR(loadout_headgear) = _HeadgearTMP;
          };
        } else {
          private _HeadgearTMP = headgear _unit;
          if (_HeadgearTMP != "") then {
            GVAR(loadout_headgear) pushBackUnique _HeadgearTMP
          };
        };
      };
      systemChat format["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_uniform), GVAR(loadout_vest), GVAR(loadout_backpack), GVAR(loadout_headgear)];
    };
    case ("rifle"): {
      GVAR(loadout_rifle) = primaryWeapon _unit;
      GVAR(loadout_rifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_rifle)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_rifleAttachments) = primaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_rifle), GVAR(loadout_rifleMags), GVAR(loadout_rifleAttachments)];
    };
    case ("glrifle"): {
      GVAR(loadout_glrifle) = primaryWeapon _unit;
      GVAR(loadout_glRifleMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_glrifle)] call CBA_fnc_compatibleMagazines);
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_glrifle), GVAR(loadout_glRifleMags)];
    };
    case ("carbine"): {
      GVAR(loadout_carbine) = primaryWeapon _unit;
      GVAR(loadout_carbineMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_carbine)] call CBA_fnc_compatibleMagazines);
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_carbine), GVAR(loadout_carbineMags)];
    };
    case ("ar"): {
      GVAR(loadout_ar) = primaryWeapon _unit;
      GVAR(loadout_arMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_ar)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_arAttachments) = primaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_ar), GVAR(loadout_arMags), GVAR(loadout_arAttachments)];
    };
    case ("mmg"): {
      GVAR(loadout_mmg) = primaryWeapon _unit;
      GVAR(loadout_mmgMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_mmg)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_mmgAttachments) = primaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_mmg), GVAR(loadout_mmgMags), GVAR(loadout_mmgAttachments)];
    };
    case ("at"): {
      GVAR(loadout_at) = secondaryWeapon _unit;
      GVAR(loadout_atMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_at)] call CBA_fnc_compatibleMagazines);
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_at), GVAR(loadout_atMags)];
    };
    case ("mat"): {
      GVAR(loadout_mat) = secondaryWeapon _unit;
      GVAR(loadout_matMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_mat)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_matAttachments) = secondaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_mat), GVAR(loadout_matMags), GVAR(loadout_matAttachments)];
    };
    case ("hmg"): {
      GVAR(loadout_hmg) = secondaryWeapon _unit;
      GVAR(loadout_hmgMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_hmg)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_hmgAttachments) = secondaryWeaponItems _unit;
	  switch (GVAR(loadout_hmg)) do {
	  case "CUP_KORD_carry";
	  case "ace_compat_rhs_afrf3_kord_carry": {
      GVAR(loadout_hmgtrilo) = "ace_csw_kordCarryTripodLow";
      GVAR(loadout_hmgtrihi) = "ace_csw_kordCarryTripod";
	  };
	  case "CUP_m2_carry";
	  case "ace_csw_staticM2ShieldCarry";
	  case "ace_csw_staticHMGCarry";
	  case "ace_compat_rhs_usf3_m2_carry": {
      GVAR(loadout_hmgtrilo) = "ace_csw_m3CarryTripodLow";
      GVAR(loadout_hmgtrihi) = "ace_csw_m3CarryTripod";
	  };
	  default {
      GVAR(loadout_hmgtrilo) = "";
      GVAR(loadout_hmgtrihi) = "";
	  };
	  };
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_hmg), GVAR(loadout_hmgMags), GVAR(loadout_hmgAttachments)];
    };
    case ("hat"): {
      GVAR(loadout_hat) = secondaryWeapon _unit;
      GVAR(loadout_hatMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_hat)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_hatAttachments) = secondaryWeaponItems _unit;
      GVAR(loadout_hattrilo) = "";
      GVAR(loadout_hattrihi) = "";
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_hat), GVAR(loadout_hatMags), GVAR(loadout_hatAttachments)];
    };
    case ("sam"): {
      GVAR(loadout_sam) = secondaryWeapon _unit;
      GVAR(loadout_samMags) = ((secondaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_sam)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_samAttachments) = secondaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_sam), GVAR(loadout_samMags), GVAR(loadout_samAttachments)];
    };
    case ("sniper"): {
      GVAR(loadout_sniper) = primaryWeapon _unit;
      GVAR(loadout_sniperMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_sniper)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_sniperAttachments) = primaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_sniper), GVAR(loadout_sniperMags), GVAR(loadout_sniperAttachments)];
    };
    case ("spotter"): {
      GVAR(loadout_spotter) = primaryWeapon _unit;
      GVAR(loadout_spotterMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_spotter)] call CBA_fnc_compatibleMagazines);
      GVAR(loadout_spotterAttachments) = primaryWeaponItems _unit;
      systemChat format["[Set %1]: %2 %3 %4", _fncString, GVAR(loadout_spotter), GVAR(loadout_spotterMags), GVAR(loadout_spotterAttachments)];
    };
    case ("smg"): {
      GVAR(loadout_smg) = primaryWeapon _unit;
      GVAR(loadout_smgMags) = ((primaryWeaponMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_smg)] call CBA_fnc_compatibleMagazines);
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_smg), GVAR(loadout_smgMags)];
    };
    case ("pistol"): {
      GVAR(loadout_pistol) = handgunWeapon _unit;
      GVAR(loadout_pistolMags) = ((handgunMagazine _unit) + (magazines _unit)) arrayIntersect([GVAR(loadout_pistol)] call CBA_fnc_compatibleMagazines);
      systemChat format["[Set %1]: %2 %3", _fncString, GVAR(loadout_pistol), GVAR(loadout_pistolMags)];
    };
    case ("mtrt"): {
      GVAR(loadout_mtrt) = backpack _unit;
      systemChat format["[Set %1]: %2", _fncString, GVAR(loadout_mtrt)];
    };
    case ("mtrb"): {
      GVAR(loadout_mtrb) = backpack _unit;
      systemChat format["[Set %1]: %2", _fncString, GVAR(loadout_mtrb)];
    };
    case ("crewh"): {
      if (typeName GVAR(loadout_crewh) == "STRING" && {
          GVAR(loadout_crewh) == "NotSet"
        }) then {
        GVAR(loadout_crewh) = headgear _unit;
      } else {
        if (typeName GVAR(loadout_crewh) == "STRING") then {
          if (GVAR(loadout_crewh) == "") then {
            GVAR(loadout_crewh) = headgear _unit;
          }
          else {
            private _HeadgearTMP = [headgear _unit];
            _HeadgearTMP pushBackUnique GVAR(loadout_crewh);
            GVAR(loadout_crewh) = _HeadgearTMP;
          };
        } else {
          private _HeadgearTMP = headgear _unit;
          if (_HeadgearTMP != "") then {
            GVAR(loadout_crewh) pushBackUnique _HeadgearTMP
          };
        };
      };
      systemChat format["[Set %1]: %2", _fncString, GVAR(loadout_crewh)];
    };
    case ("pilot"): {
      if (typeName GVAR(loadout_puniform) == "STRING" && {
          GVAR(loadout_puniform) == "NotSet"
        }) then {
        GVAR(loadout_puniform) = uniform _unit;
      } else {
        if (typeName GVAR(loadout_puniform) == "STRING") then {
          if (GVAR(loadout_puniform) == "") then {
            GVAR(loadout_puniform) = uniform _unit;
          }
          else {
            private _UniformTMP = [uniform _unit];
            _UniformTMP pushBackUnique GVAR(loadout_puniform);
            GVAR(loadout_puniform) = _UniformTMP;
          };
        } else {
          private _UniformTMP = uniform _unit;
          if (_UniformTMP != "") then {
            GVAR(loadout_puniform) pushBackUnique _UniformTMP
          };
        };
      };
      if (typeName GVAR(loadout_pvest) == "STRING" && {
          GVAR(loadout_pvest) == "NotSet"
        }) then {
        GVAR(loadout_pvest) = vest _unit;
        private _VestTMP = [vest _unit];
      } else {
        if (typeName GVAR(loadout_pvest) == "STRING") then {
          if (GVAR(loadout_pvest) == "") then {
            GVAR(loadout_pvest) = vest _unit;
          }
          else {
            private _VestTMP = [vest _unit];
            _VestTMP pushBackUnique GVAR(loadout_pvest);
            GVAR(loadout_pvest) = _VestTMP;
          };
        } else {
          private _VestTMP = vest _unit;
          if (_VestTMP != "") then {
            GVAR(loadout_pvest) pushBackUnique _VestTMP
          };
        };
      };
      if (typeName GVAR(loadout_pbackpack) == "STRING" && {
          GVAR(loadout_pbackpack) == "NotSet"
        }) then {
        GVAR(loadout_pbackpack) = backpack _unit;
      } else {
        if (typeName GVAR(loadout_pbackpack) == "STRING") then {
          if (GVAR(loadout_pbackpack) == "") then {
            GVAR(loadout_pbackpack) = backpack _unit;
          }
          else {
            private _BackpackTMP = [backpack _unit];
            _BackpackTMP pushBackUnique GVAR(loadout_pbackpack);
            GVAR(loadout_pbackpack) = _BackpackTMP;
          };
        } else {
          private _BackpackTMP = backpack _unit;
          if (_BackpackTMP != "") then {
            GVAR(loadout_pbackpack) pushBackUnique _BackpackTMP
          };
        };
      };
      if (typeName GVAR(loadout_pheadgear) == "STRING" && {
          GVAR(loadout_pheadgear) == "NotSet"
        }) then {
        GVAR(loadout_pheadgear) = headgear _unit;
      } else {
        if (typeName GVAR(loadout_pheadgear) == "STRING") then {
          if (GVAR(loadout_pheadgear) == "") then {
            GVAR(loadout_pheadgear) = headgear _unit;
          }
          else {
            private _HeadgearTMP = [headgear _unit];
            _HeadgearTMP pushBackUnique GVAR(loadout_pheadgear);
            GVAR(loadout_pheadgear) = _HeadgearTMP;
          };
        } else {
          private _HeadgearTMP = headgear _unit;
          if (_HeadgearTMP != "") then {
            GVAR(loadout_pheadgear) pushBackUnique _HeadgearTMP
          };
        };
      };
      systemChat format["[Set %1]: %2 %3 %4 %5", _fncString, GVAR(loadout_puniform), GVAR(loadout_pvest), GVAR(loadout_pbackpack), GVAR(loadout_pheadgear)];
    };
    case ("gog"): {
      if (typeName GVAR(loadout_goggles) == "STRING" && {
          GVAR(loadout_goggles) == "NotSet"
        }) then {
        GVAR(loadout_goggles) = goggles _unit;
      } else {
        if (typeName GVAR(loadout_goggles) == "STRING") then {
          if (GVAR(loadout_goggles) == "") then {
            GVAR(loadout_goggles) = goggles _unit;
          }
          else {
            private _HeadgearTMP = [goggles _unit];
            _HeadgearTMP pushBackUnique GVAR(loadout_goggles);
            GVAR(loadout_goggles) = _HeadgearTMP;
          };
        } else {
          private _HeadgearTMP = goggles _unit;
          if (_HeadgearTMP != "") then {
            GVAR(loadout_goggles) pushBackUnique _HeadgearTMP
          };
        };
      };
      systemChat format["[Set %1]: %2", _fncString, GVAR(loadout_goggles)];
    };
    case ("nods"): {
      GVAR(loadout_nods) = hmd _unit;
      systemChat format["[Set %1]: %2", _fncString, GVAR(loadout_nods)];
    };
    case ("reset"): {
	GVAR(loadout_uniform) = "NotSet";
	GVAR(loadout_vest) = "NotSet";
	GVAR(loadout_backpack) = "NotSet";
	GVAR(loadout_headgear) = "NotSet";
	GVAR(loadout_rifle) = "NotSet";
	GVAR(loadout_rifleMags) = "NotSet";
	GVAR(loadout_rifleAttachments) = "NotSet";
	GVAR(loadout_glrifle) = "NotSet";
	GVAR(loadout_glRifleMags) = "NotSet";
	GVAR(loadout_carbine) = "NotSet";
	GVAR(loadout_carbineMags) = "NotSet";
	GVAR(loadout_ar) = "NotSet";
	GVAR(loadout_arMags) = "NotSet";
	GVAR(loadout_arAttachments) = "NotSet";
	GVAR(loadout_mmg) = "NotSet";
	GVAR(loadout_mmgMags) = "NotSet";
	GVAR(loadout_at) = "NotSet";
	GVAR(loadout_atMags) = "NotSet";
	GVAR(loadout_mat) = "NotSet";
	GVAR(loadout_matMags) = "NotSet";
	GVAR(loadout_goggles) = "NotSet";
	/*
	GVAR(loadout_hmg) = "NotSet";
	GVAR(loadout_hmgMags) = "NotSet";
	GVAR(loadout_hmgtrilo) = "NotSet";
	GVAR(loadout_hmgtrihi) = "NotSet";
	GVAR(loadout_hmgtrihi) = "NotSet";
	GVAR(loadout_hat) = "NotSet";
	GVAR(loadout_hatMags) = "NotSet";
	GVAR(loadout_sam) = "NotSet";
	GVAR(loadout_samMags) = "NotSet";
	GVAR(loadout_sniper) = "NotSet";
	GVAR(loadout_sniperMags) = "NotSet";
	GVAR(loadout_spotter) = "NotSet";
	GVAR(loadout_spotterMags) = "NotSet";
	GVAR(loadout_smg) = "NotSet";
	GVAR(loadout_smgMags) = "NotSet";
	GVAR(loadout_pistol) = "NotSet";
	GVAR(loadout_pistolMags) = "NotSet";
	GVAR(loadout_mtrt) = "NotSet";
	GVAR(loadout_mtrb) = "NotSet";
	GVAR(loadout_crewh) = "NotSet";
	GVAR(loadout_puniform) = "NotSet";
	GVAR(loadout_pvest) = "NotSet";
	GVAR(loadout_pbackpack) = "NotSet";
	GVAR(loadout_pheadgear) = "NotSet";
	GVAR(loadout_nods) = "NotSet";
	*/
    };
    default {
      ERROR_1("bad fnc [%1]", _fncString);
    };
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
