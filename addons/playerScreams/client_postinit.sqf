potato_player_screams_var_soundList = ["hit_snd_01","hit_snd_02","hit_snd_03","hit_snd_04","hit_snd_05","hit_snd_06","hit_snd_07","hit_snd_08","hit_snd_09","hit_snd_10"];

["ace_unconscious", {
    params ["_unit", "_state"];

    if (!_state || { !alive _unit } || { !isNull objectParent _unit }) exitWith {};
    _unit say3D [(selectRandom potato_player_screams_var_soundList), 200, 1, false];
}] call CBA_fnc_addEventHandler;
