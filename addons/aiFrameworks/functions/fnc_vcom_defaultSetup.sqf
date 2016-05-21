#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unit"];

// disable default FSM
_unit disableAI "FSM";

// add event handlers
_unit addEventHandler ["Killed",{_this call VFUNC(closestAllyWarn);}];
_unit addEventHandler ["Hit",{_this call VFUNC(aiHit);}];

// set unit timer defaults
_unit setVariable [VQGVAR(activelyClearing),0];
_unit setVariable [VQGVAR(calledArtillery),0];
_unit setVariable [VQGVAR(firedTime),0];
_unit setVariable [VQGVAR(firedTimeHearing),0];
_unit setVariable [VQGVAR(flanking),0];
_unit setVariable [VQGVAR(formationChanged),0];
_unit setVariable [VQGVAR(grenadeThrown),0];
_unit setVariable [VQGVAR(lastChecked),0];
_unit setVariable [VQGVAR(movedRecently),0];
_unit setVariable [VQGVAR(movedRecentlyCover),0];
_unit setVariable [VQGVAR(movingToSupport),0];
_unit setVariable [VQGVAR(plantedBombRecently),0];
_unit setVariable [VQGVAR(plantedMineRecently),0];

// set unit boolean defaults
_unit setVariable [VQGVAR(canVisuallySee),false];
_unit setVariable [VQGVAR(garrisoned),false];
_unit setVariable [VQGVAR(hasDeployed),false];
_unit setVariable [VQGVAR(hasStatic),false];
_unit setVariable [VQGVAR(hasUAV),false];
_unit setVariable [VQGVAR(inCover),false];
_unit setVariable [VQGVAR(isArtillery),false,true];
_unit setVariable [VQGVAR(leader),false];
_unit setVariable [VQGVAR(loitering),false];
_unit setVariable [VQGVAR(shotsFired),false,true];
_unit setVariable [VQGVAR(startedInside),false];
_unit setVariable [VQGVAR(staticNearby),false];
_unit setVariable [VQGVAR(subLeader),false];

// set other defaults
_unit setVariable [VQGVAR(assignedEnemyPos),[0,0,0]];
_unit setVariable [VQGVAR(bombArray),[]];
_unit setVariable [VQGVAR(lastStance), behaviour _unit];
_unit setVariable [VQGVAR(mineArray),[]];

// set cached defaults
[_unit] call VFUNC(resetCaches);

// set unit level settings
private _checkVar = _unit getVariable VQGVAR(allowFlankingUnit);
if (isNil "_checkVar") then {
    _unit setVariable [VQGVAR(allowFlankingUnit),VGVAR(allowFlanking)];
};

_checkVar = _unit getVariable VQGVAR(aiMutualSupportRangeUnit);
if (isNil "_checkVar") then {
    _unit setVariable [VQGVAR(aiMutualSupportRangeUnit),VGVAR(aiMutualSupportRange)];
};
