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

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMPInterrupt {
        ADDON = QUOTE(_this call FUNC(mouseCatch););
    };
    class RscDisplayInterrupt {
        ADDON = QUOTE(_this call FUNC(mouseCatch););
    };
    class RscDisplayInterruptEditor3D {
        ADDON = QUOTE(_this call FUNC(mouseCatch););
    };
    class RscDisplayInterruptEditorPreview {
        ADDON = QUOTE(_this call FUNC(mouseCatch););
    };
};
