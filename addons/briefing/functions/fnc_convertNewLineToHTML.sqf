#include "script_component.hpp"

params ["_input"];

private _out = [];

{
    if (_x != 10) then {
        _out pushBack _x;
    } else {
        _out append (toArray "<br/>");
    };
    nil
} count (toArray _input);

(toString _out)
