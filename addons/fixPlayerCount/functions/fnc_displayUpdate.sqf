/*
 * Author: AACO
 * Function used to update the ratio display
 *
 * Arguments:
 * 0: Number of sides (to use in ratio calculating) <NUMBER>
 * 1: Array of side statuses (enabled/disabled) in order [west,east,resistance] <ARRAY>
 *
 * Examples:
 * [_sideCount,_sideArray] call potato_ratios_displayUpdate;
 *
 * Public: No
 */

#include "script_component.hpp"
LOG("Updating");

// get literal count from the player list
PLAYER_DISPLAY ctrlSetText (str ((lbSize PLAYER_LIST) / 3)); // should just be able to use lnbSize, but no

// return if control is unloaded
!GET_UI_VAR(loaded)
