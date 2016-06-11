#include "script_component.hpp"
TRACE_1("params",_this);
params ["_unit"];

// ensure logic is in a thread.
[_unit] spawn {
    params ["_unit"];

    while (true) do { // oh boy do I hate infinite loops
        // if unit should stop running VCOM logic (i.e. dead/deleted), quit
        if ([_unit] call VFUNC(shouldExit)) exitWith { TRACE_1("Stopping logic loop",_unit); };

        // if the unit's group locality changes, quit and run the logic locally
        private _group = group _unit;
        if !(local _group) exitWith { [_unit, _group] call VFUNC(transferToNewOwner); };

        // every 20 seconds, check gear and stuff
        if ((_unit getVariable [VQGVAR(lastChecked),0]) < (diag_tickTime - 20)) then {
            [_unit] call VFUNC(buildingCheck);
            [_unit] call VFUNC(checkBag);
            [_unit] call VFUNC(hasMine);
            [_unit] call VFUNC(artillery);

            if (VGVAR(increaseAccuracyOnStaticTargets)) then {
            	[_unit] call VFUNC(focusedAccuracy);
            };
        };

        private _isLeader = leader _unit == _unit; // leader check
        private _inCombat = behaviour _unit == "COMBAT"; // combat check

        // if the unit is no longer in the vehicle, change the logic
        private _vehicle = vehicle _unit;
        if (_vehicle == _unit) then {
            // handle combat movement/support actions
            if (_inCombat) then {
                private _nearestEnemy = [_unit] call VFUNC(closestEnemy);
                [_unit,_nearestEnemy] call VFUNC(danger_combatMovement);

                switch (true) do {
                    // suppressed, move to cover
                    case (getSuppression _unit > 0 && {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}): {
                        [_unit] call VFUNC(moveToCover);
                    };
                    // try to flank
                    case (_isLeader
                            && {!(_unit getVariable [VQGVAR(isInside),false])}
                            && {!(_unit getVariable [VQGVAR(garrisoned),false])}
                            && {_unit getVariable [VQGVAR(allowFlankingUnit),false]}
                            && {(side _unit) in VGVAR(movementEnabledSides)}
                            && {[_unit,VQGVAR(flanking),VGVAR(flankThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)}): {
                        [_unit] call VFUNC(flankManeuver);
                    };
                    // check if unit has static to deploy
                    case (_unit getVariable [VQGVAR(hasStatic),false] && {_nearestEnemy distance _unit < VGVAR(maxEngagementDistance)}): {
                        [_unit,_nearestEnemy] call VFUNC(unpackStatic);
                    };
                    // check if the unit has a stachel to destroy a building/vehicle with
                    case (!(isNull _nearestEnemy)
                            && {count (_unit getVariable [VQGVAR(bombArray),[]]) > 0}
                            && {[_unit,VQGVAR(plantedBombRecently),VGVAR(bombThreshold)] call VFUNC(pastThreshold)}
                            && {(_unit distance _nearestEnemy) > VGVAR(maxDistanceToPlantCharge)}
                            && {([_nearestEnemy] call VFUNC(inBuilding) || _nearestEnemy != vehicle _nearestEnemy)}): {
                        [_unit,_nearestEnemy] call VFUNC(plantCharge);
                    };
                    // try to call in artillery on the nearest enemy group (must have 2+ units in enemy group)
                    case (_isLeader
                            && {VGVAR(canCallInArtillery)}
                            && {!(isNull _nearestEnemy)}
                            && {count (units (group _nearestEnemy))) > 2}
                            && {[_unit,VQGVAR(calledArtillery),VGVAR(artilleryThreshold)] call VFUNC(pastThreshold)}
                            && {VGVAR(chanceToUseArtillery) <= random 100}): {
                        [_unit,_nearestEnemy] call VFUNC(callArtillery);
                    };
                    // clear enemy occupied building
                    case (_isLeader &&
                            && {(!isNull _nearestEnemy)}
                            && {!(_unit getVariable [VQGVAR(isInside),false])}
                            && {!(_unit getVariable [VQGVAR(garrisoned),false])}
                            && {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)}
                            && {[_nearestEnemy] call VFUNC(inBuilding)}): {
                        [_unit] call VFUNC(garrisonClear);
                    };
                    // check if the unit has a mine to plant
                    case (!(isNull _nearestEnemy)
                            && {count (_unit getVariable [VQGVAR(mineArray),[]]) > 0}
                            && {[_unit,VQGVAR(plantedMineRecently),VGVAR(mineThreshold)] call VFUNC(pastThreshold)}
                            && {(_unit distance _nearestEnemy) > VGVAR(maxDistanceToPlantMine)}
                            && {VGVAR(chanceToUseMine) <= random 100}): {
                        [_unit] call VFUNC(placeMine);
                    };
                    // if the unit has a UAV, deploy it
                    case (_unit getVariable [VQGVAR(hasUAV),false]): {
                        [_unit] call VFUNC(deployUAV);
                    };
                    // arm a static if one is nearby
                    case (VGVAR(usePlacedStaticWeapons)
                            && {!(isNull _nearestEnemy)}
                            && {_nearestEnemy distance _unit < VCOM(maxEngagementDistance)}
                            && {[_unit] call VFUNC(checkStatic)}): {
                        [_unit] call VFUNC(armEmptyStatic);
                    };
                    // don't stay static in combat
                    case (!(_unit getVariable [VQGVAR(isInside),false])
                            && {!(_unit getVariable [VQGVAR(garrisoned),false])}
                            && {!(_unit getVariable [VQGVAR(canVisuallySee),false])}
                            && {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(movedRecently),VGVAR(movedRecentlyThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)}): {
                        [_unit] call VFUNC(moveInCombat);
                    };
                    // try to enter enemy building (but not actively clear it)
                    case (_isLeader
                            && {!(isNull _nearestEnemy)}
                            && {!(_unit getVariable [VQGVAR(isInside),false])}
                            && {!(_unit getVariable [VQGVAR(garrisoned),false])}
                            && {[_unit,VQGVAR(movedRecentlyCover),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold)}
                            && {[_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)}
                            && {VGVAR(lightGarrisonChance) <= random 100}): {
                        [_unit,_nearestEnemy] call VFUNC(lightGarrison);
                    };
                };
            } else {
                if (_isLeader) then {
                    private _waypointType = waypointType [_group, currentWaypoint _group];

                    switch (true) do {
                        // handle dismissed WP
                        case (VGVAR(loiteringEnabled)
                                && {(_waypointType == "DISMISS" || {_waypointType == "LOITER"})}
                                && {!(_unit getvariable [VQGVAR(loitering),false])}): {
                            [_unit,_group] call VFUNC(groupLoiter);
                        };
                        // handle hold WP
                        case (_waypointType == "HOLD" && {!(_unit getVariable [VQGVAR(garrisoned),false])}): {
                            [_unit] call VFUNC(garrison);
                        };
                    };

                    if ([_unit,VQGVAR(activelyClearing),VGVAR(clearingThreshold)] call VFUNC(pastThreshold)
                            && (!(isNull (_unit findNearestEnemy _unit))
                                || _unit getVariable [VQGVAR(shotsFired),false]
                                || [_unit] call VFUNC(danger_explosionDetection)
                                || [_unit] call VFUNC(danger_deadBodyDetection))) then {

                        _group setBehaviour "COMBAT";
                        [_group] call VFUNC(danger_moveToCoverGroup);

                        if (_unit getVariable [VQGVAR(shotsFired),false]) then {
                            _unit setVariable [VQGVAR(shotsFired),false,true];
                        };
                    };
                };
            };
        } else {
            // handle unit being driver
            if (driver _vehicle == _unit) then {
                if (_inCombat || {!([_unit,VQGVAR(movingToSupport),VGVAR(moveCompletedThreshold)] call VFUNC(pastThreshold))}) then {
                    [_unit] call VFUNC(moveInCombat);
                    [_unit] call VFUNC(vehicleHandle);
                };
            } else {
                //handle unit being gunner
                if (gunner _vehicle == _unit) then { // TODO: make this for any vehicle turret position
                    _unit setSkill ["aimingSpeed", 1];
                    _unit setSkill ["spotDistance", 1];

                    if (_inCombat) then {
                        [_unit,_vehicle] call VFUNC(gunnerTargeting);
                    };
                };
            };
        };

        // add sleep to loop to hopefully free up some cycles.
        sleep VGVAR(brainCycleWait) + (random 0.5);
    };
};
