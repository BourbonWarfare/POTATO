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
   INFO_2("Creating new mission on framework [Mission: %1 - Expected: %2]", _missionBwmfVersion, EXPECTED_BWMF);
   if ((EXPECTED_BWMF call _fnc_daysSinceJesus) > (_missionBwmfVersion call _fnc_daysSinceJesus)) then {
      ERROR_WITH_TITLE("Old Framework", "~~~~~~~~~~~~~~~~~~~~ Download a newer framework ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   };
};
