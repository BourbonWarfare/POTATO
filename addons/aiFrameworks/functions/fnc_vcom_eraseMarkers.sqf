#include "script_component.hpp"
TRACE_1("params",_this);

{
	deleteMarker _x;
} foreach MarkerArray;
MarkerArray = [];
