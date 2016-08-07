/*
 *
 */

#include "script_component.hpp"
TRACE_3("params",_this,GVAR(setBabel),GVAR(selectedLanguages));

if (GVAR(setBabel)) then {
    GVAR(selectedLanguages)
} else {
    true
}
