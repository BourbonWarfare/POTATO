class Extended_DisplayLoad_EventHandlers {
    class RscMiniMap {
        ADDON = QUOTE([ARR_2(_this select 0, GPS_IDC)] call FUNC(addMarkersToDisplay););
    };
    class RscDiary {
        ADDON = QUOTE([ARR_2(_this select 0, MAP_IDC)] call FUNC(addMarkersToDisplay););
    };
};

class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};
