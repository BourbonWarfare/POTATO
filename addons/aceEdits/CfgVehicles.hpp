class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                class ACEGVAR(interaction,Gear) {
                    class GVAR(pickupPrimaryWeapon) {
                        displayName = "Take Primary";
                        condition = QUOTE([true] call FUNC(actionPickupWeapon_condition));
                        statement = QUOTE([true] call FUNC(actionPickupWeapon_statement));
                        modifierFunction = QUOTE([ARR_2(_this,true)] call FUNC(actionPickupWeapon_modifier));
                        icon = "\A3\ui_f\data\igui\cfg\actions\take_ca.paa";
                    };
                    class GVAR(pickupSecondaryWeapon): GVAR(pickupPrimaryWeapon) {
                        displayName = "Take Secondary";
                        condition = QUOTE([false] call FUNC(actionPickupWeapon_condition));
                        statement = QUOTE([false] call FUNC(actionPickupWeapon_statement));
                        modifierFunction = QUOTE([ARR_2(_this,false)] call FUNC(actionPickupWeapon_modifier));
                    };
                };
            };
        };
    };
};