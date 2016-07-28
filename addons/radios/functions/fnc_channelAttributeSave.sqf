/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,GVAR(selected),GVAR(selectedChannels));

if (GVAR(setChannel)) then {
    [GVAR(setChannel),GVAR(selectedChannels)]
} else {
    nil
}
