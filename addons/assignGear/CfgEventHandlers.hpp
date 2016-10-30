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


class Extended_Init_EventHandlers {
    class CAManBase {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearMan),_this)] call CBA_fnc_execNextFrame); };
    };
    class Car {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearVehicle),[ARR_2(_this select 0, 'Car')])] call CBA_fnc_execNextFrame); };
    };
    class Tank {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearVehicle),[ARR_2(_this select 0, 'Tank')])] call CBA_fnc_execNextFrame); };
    };
    class Helicopter {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearVehicle),[ARR_2(_this select 0, 'Helicopter')])] call CBA_fnc_execNextFrame); };
    };
    class Plane {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearVehicle),[ARR_2(_this select 0, 'Plane')])] call CBA_fnc_execNextFrame); };
    };
    class Ship_F {
        class ADDON { serverInit = QUOTE([ARR_2(FUNC(assignGearVehicle),[ARR_2(_this select 0, 'Ship_F')])] call CBA_fnc_execNextFrame); };
    };
};
