class SteamManagerConfig {
    class GameRecording {
        class GVARMAIN(safeStart) {
            scope = 2; // Can be modded to 1 or 0 to disable the event. Must be 2 to be visible
            title = "Safe Start";
            description = "Safe start %1 (%2)"; // Format string, arguments are passed by eventArguments
            icon = "a3_steam_flag"; // Icon is enum, there is hardcoded set of available icons
            priority = 50; // See ISteamTimeline documentation
        };
        class GVARMAIN(missionEnd): GVARMAIN(safeStart) {
            title = "Mission End";
            description = "End of mission (%1)";
            icon = "a3_challenge_timer";
        };
        class GVARMAIN(uncon): GVARMAIN(safeStart) {
            title = "Uncon Event";
            description = "%1 at %2";
            icon = "a3_revive";
            priority = 40;
        };
        class GVARMAIN(reinforce): GVARMAIN(uncon) {
            title = "Reinforce";
            description = "Joined as reinforcement at %1";
            icon = "a3_respawn";
        };
        class GVARMAIN(aceThrow): GVARMAIN(safeStart) {
            title = "Grenade Thrown";
            description = "%1 thrown";
            icon = "a3_grenade_throw";
            priority = 20;
        };
    };
};
