class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILESCRIPT_FILE(XEH_preStart));
    };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(_this spawn COMPILESCRIPT_FILE(functions\fnc_displayLoad));
    };
};
class Extended_DisplayUnload_EventHandlers {
    class RscDisplayMultiplayerSetup {
        ADDON = QUOTE(_this call COMPILESCRIPT_FILE(functions\fnc_displayUnload));
    };
};
