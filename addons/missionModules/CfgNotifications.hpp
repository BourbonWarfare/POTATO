class CfgNotifications {
    class GVAR(baseNotif)   {
        title = "%1";
        description = "%2";
        duration = 10;
        priority = 0;
        iconPicture = "";
        iconText = "";
        sound = QGVAR(vanillaDefaultNotification);
        soundClose = QGVAR(vanillaDefaultNotificationClose);
    };
    class GVAR(MapTeleportVehicle): GVAR(baseNotif) {
        title = "Forward Deploy";
        description = "Left-click in shaded regions of the map to teleport the vehicle.";
        iconPicture = "\a3\ui_f\data\GUI\Rsc\RscDisplayArsenal\map_ca.paa";
    };
    class GVAR(MapTeleportUnit): GVAR(MapTeleportVehicle) {
        description = "Left-click in shaded regions of the map to teleport the player.";
    };
    class GVAR(MapTeleportGroup): GVAR(MapTeleportVehicle) {
        description = "Left-click in shaded regions of the map to teleport your group.";
    };
};
