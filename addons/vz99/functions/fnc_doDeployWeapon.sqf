/*
 * Author: PabstMirror
 * Deploys the vz99 into a static weapon and moves the player in
 *
 * Arguments:
 * 0: Target (player) <OBJECT>
 * 1: Player <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player, player] call potato_vz99_fnc_canDeployWeapon;
 *
 * Public: No
 */
#include "script_component.hpp"

params ["", "_player"];
TRACE_1("params",_player);

[{
    private _codeFinish = {
        TRACE_1("progressBar finish",_this);

        private _posATL = ACE_player getRelPos [0.5, 0]; //in front of player
        _posATL set [2, (getPosATL ACE_player) select 2];

        private _mortarVeh = QGVAR(mortar) createVehicle _posATL;
        _mortarVeh setPosATL _posATL;
        TRACE_3("created",_mortarVeh,_posATL,_mortarVeh distance ACE_player);

        ACE_player removeWeapon QGVAR(carryWeapon);

        //Level and set starting turret dir to player's dir:
        [_mortarVeh, (getDir ACE_player)] call FUNC(levelToGround);

        //Move in auto
        ACE_player moveInGunner _mortarVeh;
    };

    [2, [], _codeFinish, {TRACE_1("failed to deploy",_this);}, "Deploying..."] call ACEFUNC(common,progressBar);
}, []] call CBA_fnc_execNextFrame; //Delay a frame for interaction menu

_player playAction "SecondaryWeapon";
