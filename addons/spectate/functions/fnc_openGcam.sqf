/*
 * Author: tanaKa
 * Closes potato spec and opens gcam
 *
 *
 * Arguments:
 * 0: Player object
 *
 * Examples:
 * [] call potato_spectate_fnc_openGcam
 *
 * Public: No
 */
params["_unit"];

[] call potato_spectate_fnc_exit;
[_unit] execVM "gcam\gcam.sqf";
