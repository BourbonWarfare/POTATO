class CfgNotifications {
    class EGVAR(missionModules,baseNotif);
    class artyNotif: EGVAR(missionModules,baseNotif) {
        title = "Artillery Mission Update";
        duration = 5;
        iconPicture = "\a3\ui_f\data\gui\cfg\hints\icon_text\b_artillery_ca.paa";
        description = "%1";
    };
    class artyNoGunsNotif: artyNotif {
        description = "No guns available for requested mission";
    };
};
