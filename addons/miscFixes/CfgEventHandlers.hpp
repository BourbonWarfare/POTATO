class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_SCRIPT(XEH_kilTracker));
        serverInit = QUOTE(call COMPILE_SCRIPT(XEH_serverPostInit));
    };
};
