class RscText;
class RscCustomInfoMiniMap {
    class controls {
        class GVAR(addMarks): RscText {
            onLoad = QUOTE(((ctrlParent (_this select 0)) displayCtrl GPS_IDC) ctrlAddEventHandler [ARR_2('draw', {diag_log 'tick'; _this call FUNC(drawMarkers)})];);
        };
    };
};
