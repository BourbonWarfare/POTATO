#include "\z\ace\addons\medical_engine\script_macros_medical.hpp"
#include "\z\ace\addons\medical_engine\script_macros_config.hpp"
#include "\z\ace\addons\main\script_mod.hpp"
#include "\z\ace\addons\main\script_macros.hpp"

params ["_unit"];

if (GET_BLOOD_VOLUME(_unit) > BLOOD_VOLUME_CLASS_2_HEMORRHAGE) exitwith {true};

if ((GET_BLOOD_VOLUME(_unit) <= BLOOD_VOLUME_CLASS_2_HEMORRHAGE) && {random 3 < 1}) exitwith {true};

if ((GET_BLOOD_VOLUME(_unit) <= BLOOD_VOLUME_CLASS_4_HEMORRHAGE) && {random 6 < 1}) exitwith {true}; // Maybe up to 5?

// The below code is intended to add a mechanic wherein if players are not stable but woke up, they have a %chance to go back uncon so as to simulate a fade-in fade-out mechanic

// if ((GET_BLOOD_VOLUME(_unit) <= BLOOD_VOLUME_CLASS_2_HEMORRHAGE) && {random 2 < 1} && (IS_UNCONSCIOUS(_unit) == true)) exitwith {false};

// if ((GET_BLOOD_VOLUME(_unit) <= BLOOD_VOLUME_CLASS_4_HEMORRHAGE) && {random 2 < 1} && (IS_UNCONSCIOUS(_unit) == true)) exitwith {false};