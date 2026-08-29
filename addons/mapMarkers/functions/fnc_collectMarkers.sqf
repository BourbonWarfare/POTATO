/*
 * Author: Lambda.Tiger
 * This function will take all user defined map markers and return either a
 * hashmap or json string of them. It mainly focuses on two types of markers,
 * 1) Icon markers, and 2) polyline / drawn markers. Each hashmap entry is
 * key'd by the marker name and stores an array containing three or seven
 * elements depending on marker type. The first entry is whether the marker
 * is a polyline (BOOL), if it is, the next two entries are color and an
 * array of polyline points. If it isn't, the array consists of (in order):
 * marker color, position, direction, size, type, and text.
 *
 * Arguments:
 * 0: Whether the output should be converted to JSON (BOOL, default false)
 *
 * Return:
 * Either a hashmap of all user markers OR the hashmap toJSON'd
 *
 * Public: No
 */
params [["_jsonOutput", false, [false]]];
private _marks = allMapMarkers select {_x select [0,15]  == "_USER_DEFINED #"};
private _hashmap = createHashMap;
{
	if (markerShape _x == "POLYLINE") then {
		_hashmap set [_x,[true, getMarkerColor _x, markerPolyline _x]];

	} else {
		_hashmap set [_x,[false, getMarkerColor _x, getMarkerPos _x, markerDir _x, getMarkerSize _x, getMarkerType _x, markerText _x]];
	};
} forEach _marks;

if (_jsonOutput) then {
    toJSON _hashmap
} else {
    _hashmap
}
