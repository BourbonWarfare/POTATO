//Extended Event Handlers:
class Extended_PreInit_EventHandlers {
    class MISSION_GVAR_PREFIX {
        init = QUOTE(call compileScript [QQUOTE(\z\potato\addons\seeding\XEH_preInit.sqf)]);
    };
};
class Extended_PostInit_EventHandlers {
    class MISSION_GVAR_PREFIX {
        init = QUOTE(call compileScript [QQUOTE(\z\potato\addons\seeding\XEH_postInit.sqf)]);
    };
};
class Extended_InitPost_EventHandlers {
  class Car {
    class BWMF_NoBitchZone { init = "(_this select 0) allowCrewInImmobile true;"; };
    class BWMF_DisableThermals { init = "(_this select 0) disableTIEquipment true;"; exclude = "LSV_01_AT_base_F"; };
  };
  class Tank {
    class BWMF_NoBitchZone { init = "(_this select 0) allowCrewInImmobile true;"; };
    class BWMF_DisableThermals { init = "(_this select 0) disableTIEquipment true;"; };
  };
  class Helicopter {
    class BWMF_DisableThermals { init = "(_this select 0) disableTIEquipment true;"; };
  };
  class Plane {
    class BWMF_DisableThermals { init = "(_this select 0) disableTIEquipment true;"; };
  };
  class Ship_F {
    class BWMF_DisableThermals { init = "(_this select 0) disableTIEquipment true;"; };
  };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayCurator {
        ADDON = QUOTE({if !(PGVAR(core,playerAuth) || missionNamespace getVariable [ARR_2(QQGVAR(allowCurator),false)]) then {[getAssignedCuratorLogic player] remoteExecCall [ARR_2(QQUOTE(unassignCurator),2)]; (_this#0) closeDisplay -1;};});
    };
};

