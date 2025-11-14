#include "script_component.hpp"

#ifdef ENABLE_NETWORK_MARKERS
[player] call FUNC(addMarkerInfoEvent);
#endif

["CBA_settingsInitialized", {
#ifdef ENABLE_NETWORK_MARKERS
    [player] call FUNC(addMarkerInfoEvent);
#endif
}] call CBA_fnc_addEventHandler;
