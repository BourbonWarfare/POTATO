#include "script_component.hpp"

private _author = "Scenario" get3DENMissionAttribute "author";
if (_author == "*** Insert author name here. ***") then {
   set3DENMissionAttributes [["Scenario", "author", profileName]];
   systemChat "New Mission";
   systemChat format ["Assigning %1 as author", profileName];

   // Warn on old framework, this will only be checked on brand new missions because it is after the author check
   private _bwmfVersion = getText (missionConfigFile >> "bwmfDate");
   INFO_1("Creating new mission on framework %1", _bwmfVersion);
   if ((_bwmfVersion find "2020") != 0) then { // todo real date comparision
      ERROR_WITH_TITLE("Old Framework", "~~~~~~~~~~~~~~~~~~~~ Download a newer framework ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
   };
};
