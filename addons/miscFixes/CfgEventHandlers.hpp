class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILESCRIPT_FILE(XEH_kilTracker));
        serverInit = QUOTE(call COMPILESCRIPT_FILE(XEH_serverPostInit));
    };
};
