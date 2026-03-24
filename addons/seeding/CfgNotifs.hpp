class CfgNotifications {
    class Notif {
        title = "%1";
        description = "%2";
        duration = 10;
        priority = 0;
        iconPicture = "";
        iconText = "";
        sound = "vanillaDefaultNotification";
        soundClose = "vanillaDefaultNotificationClose";
    };
    class Notif_Picture: Notif {
        iconPicture = "%3";
        duration = 7.5;
    };
    class Info: Notif {
        iconPicture = "\a3\ui_f\data\GUI\Cfg\CommunicationMenu\instructor_ca.paa";
        duration = 20;
    };
    class SelfInteract: Notif {
        iconPicture = "\z\ace\addons\interaction\ui\Icon_Module_Interaction_ca.paa";
        duration = 20;
        title = "Mission Info";
        description = "<t color='#FFC000'>ACE self-interact</t> at any US flag pole to access the mission menu.";
    };
    class Info_Picture: Info {
        iconPicture = "%3";
    };
    class MapTeleport: Notif {
        title = "Forward Deploy";
        description = "Left-click near a flag to teleport the player.";
        iconPicture = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa";
    };
    class MapTeleportFireteam: MapTeleport {
        title = "Forward Deploy";
        description = "Left-click near a flag to teleport your group.";
    };
    class isrReport: Notif {
        title = "ISR Report";
        description = "%1";
        iconPicture = "a3\ui_f\data\gui\cfg\communicationmenu\call_ca.paa";
    };
    class Notif_Overrun: Notif {
        title = "Rally Overrun";
        description = "Defenseive rally point has been overrun";
        iconPicture = "a3\ui_f\data\gui\rsc\rscdisplayarcademap\icon_exit_cross_ca.paa";
    };
    class commIntercept : isrReport {
        title = "Enemy comms intercepted!";
    };
    class isrReport_short : isrReport {
        duration = 5;
    };
    class artyNotif: Notif {
        title = "Artillery Mission Update";
        duration = 5;
        iconPicture = "\a3\ui_f\data\gui\cfg\hints\icon_text\b_artillery_ca.paa";
        description = "%1";
    };
    class artyNoGunsNotif: artyNotif {
        description = "No guns available for requested mission";
    };
};
