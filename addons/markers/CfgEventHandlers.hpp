class Extended_DisplayLoad_EventHandlers {
    class RscDiary {
        ADDON = QUOTE([ARR_2(_this select 0,MAP_IDC)] call FUNC(addMarkersToDisplay););
    };
    class RscCustomInfoMiniMap {
        ADDON = QUOTE(diag_log text '[POTATO] (markers) Adding draw EH to RscCustomInfoMiniMap'; ((_this select 0) displayCtrl GPS_IDC) ctrlAddEventHandler [ARR_2('draw',{_this call FUNC(drawMarkers)})];);
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_postInit));
    };
};
