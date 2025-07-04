#include "script_component.hpp"

private _author = "Scenario" get3DENMissionAttribute "author";
if (_author == "*** Insert author name here. ***") then {
   set3DENMissionAttributes [["Scenario", "author", profileName]];
   systemChat "New Mission";
   systemChat format ["Assigning %1 as author", profileName];

   // Warn on old framework, this will only be checked on brand new missions because it is after the author check
   private _fnc_daysSinceJesus = {
      private _split = _this splitString "/";
      if (_split#1 == "20") then { _split set [1, "12"]; }; // lol
      (366 * parseNumber (_split param [0, ""])) + (31 * parseNumber (_split param [1, ""])) + (parseNumber (_split param [2, ""]));
   };
   private _missionBwmfVersion = getText (missionConfigFile >> "bwmfDate");
   // EXPECTED_BWMF is defined in core/script_mod.hpp
   INFO_2("Creating new mission on framework [Mission: %1 - Expected: %2]",_missionBwmfVersion,EXPECTED_BWMF);
    if (_missionBwmfVersion == "") exitWith {
        ERROR_WITH_TITLE("Problem Reading description.ext","");
    };
   if ((EXPECTED_BWMF call _fnc_daysSinceJesus) > (_missionBwmfVersion call _fnc_daysSinceJesus)) then {
      ERROR_WITH_TITLE("Old Framework","~~~~~~~~~~~~~~~~~~~~ Download a newer framework ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   };
};

private _current_uuid = QEGVAR(missiontesting,missionTestingInfo) get3DENMissionAttribute QGVAR(uuid);
diag_log format["POTATO - loaded UUID: %1", _current_uuid];
if (!(_current_uuid isEqualType "") || { _current_uuid isEqualTo "" }) then {
   // _current_uuid = call CBA_fnc_createUUID;
   _current_uuid = call {
      private _hexDigits = [
         "0", "1", "2", "3", "4", "5", "6", "7",
         "8", "9", "a", "b", "c", "d", "e", "f"
      ];
      private _versionByte = "4";
      private _variantByte = selectRandom ["8", "9", "a", "b"];

      private _uuid = [];
      for "_i" from 0 to 29 do {
         _uuid pushBack selectRandom _hexDigits;
      };

      _uuid insert [8, ["-"]];
      _uuid insert [13, ["-", _versionByte]];
      _uuid insert [18, ["-", _variantByte]];
      _uuid insert [23, ["-"]];
      _uuid joinString ""
   };
   diag_log format["POTATO - setting mission uuid: %1", _current_uuid];
   set3DENMissionAttributes [[QEGVAR(missiontesting,missionTestingInfo), QGVAR(uuid), _current_uuid]];
};
