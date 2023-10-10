#include "script_component.hpp"

#define STATE_MOVING_TO_INGRESS 1
#define STATE_MOVING_TO_DZ 2
#define STATE_DROPPING 3
#define STATE_AFTER_DROP 4
#define STATE_MOVING_TO_EGRESS 5

/*
 * Author: Bailey
 * Launch a paradrop mission with the specified paradrop information
 *
 * Arguments:
 * 1: Ingress ID <NUMBER>
 * 2: Vehicles to launch mission with <ARRAY>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [45234, [myPlane1, myPlane2]] call potato_paradrop_fnc_launch;
 *
 * Public: Yes
 */
params ["_ingressId", "_vehicles"];

private _paradropInfo = GVAR(paradropObjects) get _ingressId;
private _ingressPos = _paradropInfo get "ingressPosition";
private _flyInHeight = _paradropInfo get "flyInHeight";

{
    if (local _x) then {
        private _dzPosition = selectRandom (_paradropInfo get "dzPositions");
        _x setVariable [QGVAR(state), STATE_MOVING_TO_INGRESS];
        _x setVariable [QGVAR(dzPosition), _dzPosition];

        private _planePos = getPosASLVisual _x;

        private _dirToTarget = _ingressPos vectorDiff _planePos;
        private _targetPos = _ingressPos vectorAdd ((vectorNormalized _dirToTarget) vectorMultiply 200);
        _targetPos set [2, _flyInHeight];
        _targetPos = ASLToATL _targetPos;
        _x doMove _targetPos;
        (driver _x) doMove _targetPos;

        private _group = group driver _x;

        _group setCombatMode "BLUE";
        _group setBehaviour "CARELESS";
        _x flyInHeight (_flyInHeight + 10);
        _x flyInHeightASL [_flyInHeight, _flyInHeight, _flyInHeight];

        private _expandedPos = _ingressPos vectorAdd (_ingressPos vectorDiff _planePos);
        private _origDot = (_planePos vectorDiff _ingressPos) vectorDotProduct (_expandedPos vectorDiff _ingressPos);
        _x setVariable [QGVAR(initialDot), _origDot];
        _x setVariable [QGVAR(expandedPos), _expandedPos];
    };
} forEach _vehicles;

[{
	params ["_args", "_pfhId"];
    _args params ["_paradropInfo", "_vehicles"];
    private _ingressPos = _paradropInfo get "ingressPosition";
    private _egressPos = _paradropInfo get "egressPosition";
    private _dropDelay = _paradropInfo get "dropDelay";
    private _parachuteClassname = _paradropInfo get "infantryParachuteClassname";
    private _flyInHeight = _paradropInfo get "flyInHeight";

	private _planesExist = false;
    {
        if (local _x && !isNull _x) then {
			_planesExist = true;
            private _state = _x getVariable QGVAR(state);
            private _origDot = _x getVariable QGVAR(initialDot);
            private _dropPos = _x getVariable QGVAR(dzPosition);
            private _expandedPos = _x getVariable QGVAR(expandedPos);
            private _planePos = getPosASLVisual _x;
            switch (_state) do {
                case STATE_MOVING_TO_INGRESS: {
                    private _dot = (_planePos vectorDiff _ingressPos) vectorDotProduct (_expandedPos vectorDiff _ingressPos);
                    if (_dot * _origDot < 0) then {
                        _x setVariable [QGVAR(state), STATE_MOVING_TO_DZ];
                        private _expandedPos = _dropPos vectorAdd (_dropPos vectorDiff _planePos);
                        private _origDot = (_planePos vectorDiff _dropPos) vectorDotProduct (_expandedPos vectorDiff _dropPos);
                        _x setVariable [QGVAR(initialDot), _origDot];
                        _x setVariable [QGVAR(expandedPos), _expandedPos];

                        private _dirToTarget = _dropPos vectorDiff _planePos;
                        private _targetPos = _dropPos vectorAdd ((vectorNormalized _dirToTarget) vectorMultiply 200);
                        _targetPos set [2, _flyInHeight];
                        _targetPos = ASLToATL _targetPos;
                        _x doMove _targetPos;
                        (driver _x) doMove _targetPos;

                        private _group = group driver _x;

                        _group setCombatMode "BLUE";
                        _group setBehaviour "CARELESS";
                        _x flyInHeight (_flyInHeight + 10);
                        _x flyInHeightASL [_flyInHeight, _flyInHeight, _flyInHeight];
                    };
                };
                case STATE_MOVING_TO_DZ: {
                    private _dot = (_planePos vectorDiff _dropPos) vectorDotProduct (_expandedPos vectorDiff _dropPos);
                    if (_dot * _origDot < 0) then {
                        _x setVariable [QGVAR(state), STATE_DROPPING];
                        _x setVariable [QGVAR(lastDropTime), 0];
                        _x setVariable [QGVAR(lastMoveTime), 0];
                    };
                };
                case STATE_DROPPING: {
                    private _directionOfTravel = vectorNormalized (_dropPos vectorDiff _ingressPos);
                    private _distanceToPlane = vectorMagnitude (_planePos vectorDiff _dropPos);

                    private _targetPos = _dropPos vectorAdd (_directionOfTravel vectorMultiply (300 max (_distanceToPlane * 2)));
                    _targetPos set [2, _flyInHeight];
                    _targetPos = ASLtoATL _targetPos;

                    // ARMA doesnt like doMoves in consecutive frames: we want to have some delay to correct, but allow the AI to make movements without confusion
                    private _lastMoveTime = _x getVariable QGVAR(lastMoveTime);
                    if (CBA_missionTime - _lastMoveTime >= 0.3) then {
                        _x doMove _targetPos;
                        (driver _x) doMove _targetPos;
                        _x setVariable [QGVAR(lastMoveTime), CBA_missionTime];
                    };

                    private _group = group _x;

                    _group setCombatMode "BLUE";
                    _group setBehaviour "CARELESS";

                    private _lastDrop = _x getVariable QGVAR(lastDropTime);

                    private _cargo = getVehicleCargo _x;
                    private _paratroopers =  fullCrew [_x, "cargo", false];
                    private _hasNothing = 0 == ((count _cargo) + (count _paratroopers));
                    if (_hasNothing) then {
                        _x setVariable [QGVAR(state), STATE_AFTER_DROP];
                        _x setVariable [QGVAR(finished), CBA_missionTime];
                        private _directionOfTravel = vectorNormalized (_dropPos vectorDiff _ingressPos);
                        private _distanceToPlane = vectorMagnitude (_planePos vectorDiff _dropPos);

                        private _targetPos = _dropPos vectorAdd (_directionOfTravel vectorMultiply (_distanceToPlane * 2));
                        _targetPos set [2, _flyInHeight];
                        _targetPos = ASLtoATL _targetPos;

                        _x doMove _targetPos;
                        (driver _x) doMove _targetPos;

                        private _group = group _x;

                        _group setCombatMode "BLUE";
                        _group setBehaviour "CARELESS";
                    } else {
                        if (CBA_missionTime - _lastDrop >= _dropDelay) then {
                            _x setVariable [QGVAR(lastDropTime), CBA_missionTime];
                            if (0 != count _paratroopers) then {
                                private _unit = (selectRandom _paratroopers) select 0;
                                private _velocity = velocity _x;

                                _unit disableAI "MOVE";
                                [QGVAR(ejectAndParachuteUnit), [_unit, _x, _parachuteClassname, _velocity, 2], _unit] call CBA_fnc_targetEvent;
                                _unit enableAI "MOVE";
                            };

                            if (0 != count _cargo) then {
                                private _cargoToEject = (_cargo select 0);
                                private _cargoParachuteClassname = _paradropInfo get "cargoParachuteClassname";
                                [_cargoToEject, _x, _cargoParachuteClassname] call FUNC(dropCargo);
                            };
                        };
                    };
                };
                case STATE_AFTER_DROP: {
                    private _endDropTime = _x getVariable QGVAR(finished);
                    if (CBA_missionTime - _endDropTime >= 3) then {
                        _x setVariable [QGVAR(state), STATE_MOVING_TO_EGRESS];
                        private _expandedPos = _egressPos vectorAdd (_egressPos vectorDiff _planePos);
                        private _origDot = (_planePos vectorDiff _egressPos) vectorDotProduct (_expandedPos vectorDiff _egressPos);
                        _x setVariable [QGVAR(initialDot), _origDot];
                        _x setVariable [QGVAR(expandedPos), _expandedPos];

                        _x doMove _egressPos;
                        (driver _x) doMove _egressPos;

                        private _group = group driver _x;

                        _group setCombatMode "BLUE";
                        _group setBehaviour "CARELESS";
                        _x flyInHeight (_flyInHeight + 10);
                        _x flyInHeightASL [_flyInHeight, _flyInHeight, _flyInHeight];
                    };
                };
                case STATE_MOVING_TO_EGRESS: {
                    private _dot = (_planePos vectorDiff _egressPos) vectorDotProduct (_expandedPos vectorDiff _egressPos);
                    if (_dot * _origDot < 0) then {
                        private _v = _x;
                        {
                            _v deleteVehicleCrew _x;
                        } forEach crew _v;
                        deleteVehicle _x;
                        _x = objNull;
                    };
                };
            };
        };
    } forEach _vehicles;

	if !(_planesExist) then {
		[_pfhId] call CBA_fnc_removePerFrameHandler;	
	};
}, 0, [_paradropInfo, _vehicles]] call CBA_fnc_addPerFrameHandler;
