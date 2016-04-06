#include "script_component.hpp"

ADDON = false;

DFUNC(tweak343_getCurrentChannelData) = {
    private _return = _this call acre_sys_prc343_fnc_getCurrentChannelData;
    _return setVariable ["power", 500];
    
    TRACE_1("tweaking acre data",_return);
    _return
};

ADDON = true;
