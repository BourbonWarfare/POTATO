class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_preInit));
    };
};
class Extended_DisplayLoad_EventHandlers {
    class RscDisplayGameOptions {
        ADDON = QUOTE(call COMPILE_SCRIPT(XEH_displayGameOptions));
    };
};
