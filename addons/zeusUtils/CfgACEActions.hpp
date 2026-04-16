class ACE_ZeusActions {
    class ACRE_RadioOptions {
        condition = "!isNil ""ACRE_IS_SPECTATOR"" && {ACRE_IS_SPECTATOR}";
        displayName = "Switch Active Radio";
        icon = "\a3\Ui_f\data\GUI\Cfg\CommunicationMenu\call_ca.paa";
        insertChildren = QUOTE(_this call FUNC(insertActiveRadioChildren));
    };
};
