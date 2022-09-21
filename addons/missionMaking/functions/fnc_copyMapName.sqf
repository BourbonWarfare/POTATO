#include "script_component.hpp"

copyToClipboard worldName;

private _displayName = getText (configFile >> "CfgWorlds" >> worldName >> "description");
systemChat format ["Use folder 'Mission.%1' for %2", worldName, _displayName];
systemChat format ["'%1' copied to clipboard", worldName];
