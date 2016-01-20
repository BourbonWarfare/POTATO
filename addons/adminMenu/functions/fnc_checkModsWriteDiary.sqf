#include "script_component.hpp"

if ((!hasInterface) || {isNull player}) exitWith {};

params ["_profileName", "_diaryEntry"];

player createDiaryRecord ["Admin Menu", [format ["Mod Check: %1", _profileName], _diaryEntry]];
