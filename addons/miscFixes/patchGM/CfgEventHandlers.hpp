#define QQUOTE(var1) QUOTE(QUOTE(var1))
class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call compileScript [QQUOTE(\z\potato\addons\miscFixes\patchGM\xeh_postInit.sqf)]);
    };
};
