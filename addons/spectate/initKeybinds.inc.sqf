#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#ifndef COMPONENT
#include "script_component.hpp"
#endif

[["Potato", "Spectate"], QGVAR(miniMap), ["Toggle minimap", "Toggles the spectate minimap"], {}, {}, [DIK_M, [false, true, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(mainMap), ["Toggle map", "Toggles the spectate map"], {}, {}, [DIK_M, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(incViewDist), ["Increase view distance", "Increases your view distance by 250m"], {}, {}, [DIK_PGUP, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(decViewDist), ["Decrease view distance", "Decreases your view distance by 250m"], {}, {}, [DIK_PGDN, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(cycleVisionMode), ["Toggle night vision mode", "Toggles current vision mode"], {}, {}, [DIK_N, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(toggleLight), ["Toggle lights", "Toggles camera and cursor lights"], {}, {}, [DIK_L, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(toggleTraces), ["Toggle bullet traces", "Toggles showing projectile traces"], {}, {}, [DIK_T, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(toggleStats), ["Toggle Kill Stats", "Toggles kills, hits, and radio menu"], {}, {}, [DIK_P, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(toggleGroundSpeed), ["Toggle camera ground speed", "Toggles proximity to ground effecting camera speed"], {}, {}, [DIK_V, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(toggleBrief), ["Toggle briefings", "Toggles showing the missions briefings"], {}, {}, [DIK_J, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(cycleMarks), ["Cycle unit/BFT markers", "Toggles markers between units, BFT, or none"], {}, {}, [DIK_BACKSLASH, [false, false, false]]] call CBA_fnc_addKeybind;
[["Potato", "Spectate"], QGVAR(cycleGravestones), ["Cycle player death marks", "Toggles whether no marker, a marker, or marker and name are shown"], {}, {}, [DIK_LBRACKET, [false, false, false]]] call CBA_fnc_addKeybind;
