#define TEXT_SIZE_FACTOR (safezoneH / 25)

// stubs
class RscText;
class RscTree;
class RscCombo;
class RscFrame;
class RscButton;
class RscListBox;
class RscBackground;
class RscMapControl;
class RscStructuredText;
class RscControlsGroupNoScrollbars;

// admin respawn tool
class GVAR(adminRespawn) {
    idd = ADMIN_RESPAWN_IDD;

    onLoad = QUOTE(_this spawn FUNC(ui_handleAdminLoad));
    onUnload = QUOTE(call FUNC(ui_handleAdminUnload));

    class ControlsBackground {
        class BackGround: RscBackground {
            idc = ADMIN_BG_IDC;
            x = QUOTE(0.27 * safezoneW + safezoneX);
            y = QUOTE(0.23 * safezoneH + safezoneY);
            w = QUOTE(0.46 * safezoneW);
            h = QUOTE(0.54 * safezoneH);
            colorBackground[] = {0,0,0,0.33};
        };
        class BackGroundFrame: RscFrame {
            idc = ADMIN_BGF_IDC;
            text = "Wave Reinforcement Tool";
            x = QUOTE(0.275 * safezoneW + safezoneX);
            y = QUOTE(0.24 * safezoneH + safezoneY);
            w = QUOTE(0.45 * safezoneW);
            h = QUOTE(0.52 * safezoneH);
            sizeEx = QUOTE(0.75 * TEXT_SIZE_FACTOR);
        };
        class SpectatorBackGround: RscBackground {
            idc = ADMIN_SPEC_BG_IDC;
            x = QUOTE(0.2875 * safezoneW + safezoneX);
            y = QUOTE(0.3 * safezoneH + safezoneY);
            w = QUOTE(0.1375 * safezoneW);
            h = QUOTE(0.44 * safezoneH);
            colorBackground[] = {COLOR_BLACK};
        };
        class SpectatorFrame: RscFrame {
            idc = ADMIN_SPEC_FRAME_IDC;
            text = "Spectators (0)";
            x = QUOTE(0.285 * safezoneW + safezoneX);
            y = QUOTE(0.28 * safezoneH + safezoneY);
            w = QUOTE(0.1425 * safezoneW);
            h = QUOTE(0.47 * safezoneH);
            sizeEx = QUOTE(0.5 * TEXT_SIZE_FACTOR);
        };
        class GroupsFrame: RscFrame {
            idc = ADMIN_GROUP_FRAME_IDC;
            text = "Active Groups";
            x = QUOTE(0.435 * safezoneW + safezoneX);
            y = QUOTE(0.28 * safezoneH + safezoneY);
            w = QUOTE(0.1425 * safezoneW);
            h = QUOTE(0.47 * safezoneH);
            sizeEx = QUOTE(0.5 * TEXT_SIZE_FACTOR);
        };
        class ConfigurationFrame: RscFrame {
            idc = ADMIN_CONFIG_FRAME_IDC;
            text = "Configuration";
            x = QUOTE(0.5875 * safezoneW + safezoneX);
            y = QUOTE(0.28 * safezoneH + safezoneY);
            w = QUOTE(0.125 * safezoneW);
            h = QUOTE(0.47 * safezoneH);
            sizeEx = QUOTE(0.5 * TEXT_SIZE_FACTOR);
        };
    };

    class Controls {
        class SpectatorList: RscListBox {
            idc = ADMIN_SPEC_LIST_IDC;
            x = QUOTE(0.2875 * safezoneW + safezoneX);
            y = QUOTE(0.3 * safezoneH + safezoneY);
            w = QUOTE(0.1375 * safezoneW);
            h = QUOTE(0.44 * safezoneH);
            colorBackground[] = {COLOR_EMPTY};
        };
        class GroupTree: RscTree {
            idc = GROUP_TREE_IDC;
            onTreeDblClick = QUOTE(call FUNC(ui_handleSlotClick));
            x = QUOTE(0.4375 * safezoneW + safezoneX);
            y = QUOTE(0.3 * safezoneH + safezoneY);
            w = QUOTE(0.1375 * safezoneW);
            h = QUOTE(0.44 * safezoneH);
            multiselectEnabled = 0;
            colorBorder[] = {COLOR_EMPTY};
            colorBackground[] = {COLOR_BLACK};
        };
        class FactionText: RscText {
            idc = ADMIN_FACTION_TEXT_IDC;
            text = "Faction:";
            x = QUOTE(0.5875 * safezoneW + safezoneX);
            y = QUOTE(0.32 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
            style = 1;
        };
        class FactionCombo: RscCombo {
            idc = ADMIN_FACTION_COMBO_IDC;
            onLBSelChanged = QUOTE(call FUNC(ui_handleFactionChange));
            x = QUOTE(0.625 * safezoneW + safezoneX);
            y = QUOTE(0.32 * safezoneH + safezoneY);
            w = QUOTE(0.075 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select faction (Note: changing this will reset the active groups)";
        };
        class GroupText: RscText {
            idc = ADMIN_GROUP_TEXT_IDC;
            text = "Group:";
            x = QUOTE(0.5875 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
            style = 1;
        };
        class GroupCombo: RscCombo {
            idc = ADMIN_GROUP_COMBO_IDC;
            onLBSelChanged = QUOTE(call FUNC(ui_handleGroupChange));
            x = QUOTE(0.625 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.075 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select Group";
        };
        class ConfigurationText: RscText {
            idc = ADMIN_CONFIG_TEXT_IDC;
            text = "Config:";
            x = QUOTE(0.5875 * safezoneW + safezoneX);
            y = QUOTE(0.4 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
            style = 1;
        };
        class ConfigurationCombo: RscCombo {
            idc = ADMIN_CONFIG_COMBO_IDC;
            x = QUOTE(0.625 * safezoneW + safezoneX);
            y = QUOTE(0.4 * safezoneH + safezoneY);
            w = QUOTE(0.075 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select Group Configuration";
        };
        class AddButton: RscButton {
            idc = ADMIN_ADD_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleAddClick));
            text = "Add";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.44 * safezoneH + safezoneY);
            w = QUOTE(0.045 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Adds currently configured group to the active group list";
            sizeEx = QUOTE(0.75 * TEXT_SIZE_FACTOR);
        };
        class DeleteButton: RscButton {
            idc = ADMIN_DELETE_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleDeleteClick));
            text = "Delete";
            x = QUOTE(0.655 * safezoneW + safezoneX);
            y = QUOTE(0.44 * safezoneH + safezoneY);
            w = QUOTE(0.045 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Removes the selected active group from the list";
            sizeEx = QUOTE(0.75 * TEXT_SIZE_FACTOR);
        };
        class SlotButton: RscButton {
            idc = ADMIN_SLOT_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleSlotClick));
            text = "Slot";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.48 * safezoneH + safezoneY);
            w = QUOTE(0.045 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Slots the selected spectator into the selected group";
            sizeEx = QUOTE(0.75 * (safezoneH / 25));
        };
        class UnslotButton: RscButton {
            idc = ADMIN_UNSLOT_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleUnslotClick));
            text = "Unslot";
            x = QUOTE(0.655 * safezoneW + safezoneX);
            y = QUOTE(0.48 * safezoneH + safezoneY);
            w = QUOTE(0.045 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Unslots the selected spectator from the selected group";
            sizeEx = QUOTE(0.75 * (safezoneH / 25));
        };
        class OpenRespawnButton: RscButton {
            idc = ADMIN_OPEN_RESPAWN_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleRespawnStateClick));
            text = "Open Reinforcements";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.52 * safezoneH + safezoneY);
            w = QUOTE(0.1 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorFocused[] = {COLOR_GREEN_INACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Open reinforcement wave to current spectators";
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
        };
        class CloseRespawnButton: OpenRespawnButton {
            idc = ADMIN_CLOSE_RESPAWN_BUTTON_IDC;
            text = "Close Reinforcements";
            colorFocused[] = {COLOR_RED_INACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            tooltip = "Close reinforcement slotting to current spectators";
        };
        class TriggerButton: RscButton {
            idc = ADMIN_TRIGGER_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleTriggerClick));
            text = "Trigger Reinforcements";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.58 * safezoneH + safezoneY);
            w = QUOTE(0.1 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorFocused[] = {COLOR_BLUE_ACTIVE};
            colorBackground[] = {COLOR_BLUE_INACTIVE};
            colorBackgroundActive[] = {COLOR_BLUE_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Trigger reinforcement wave with the players in the active groups";
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
        };
        class CancelButton: RscButton {
            idc = ADMIN_CANCEL_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleCancelClick));
            text = "Cancel Reinforcements";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.64 * safezoneH + safezoneY);
            w = QUOTE(0.1 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Cancels the currently configured reinforcements";
            sizeEx = QUOTE(0.6 * TEXT_SIZE_FACTOR);
        };
        class ChatButtonOn: RscButton {
            idc = ADMIN_CHAT_BUTTON_ON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleChatClick));
            text = "Chat";
            x = QUOTE(0.6 * safezoneW + safezoneX);
            y = QUOTE(0.7 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Sets ACRE to spectate chat (on)";
            sizeEx = QUOTE(0.75 * TEXT_SIZE_FACTOR);
        };
        class ChatButtonOff: ChatButtonOn {
            idc = ADMIN_CHAT_BUTTON_OFF_IDC;
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            tooltip = "Sets ACRE to spectate chat (off)";
        };
        class CloseButton: RscButton {
            idc = ADMIN_CLOSE_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleCloseClick));
            text = "Close";
            x = QUOTE(0.6625 * safezoneW + safezoneX);
            y = QUOTE(0.7 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.04 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Closes the dialog, but leaves the configuration in it's current state";
            sizeEx = QUOTE(0.75 * TEXT_SIZE_FACTOR);
        };
        class Map: RscMapControl {
            idc = ADMIN_MAP_IDC;
            onDraw = QUOTE(call FUNC(ui_handleMapDraw));
            onMouseButtonClick = QUOTE(call FUNC(ui_handleMapClick));
            x = QUOTE(0.27 * safezoneW + safezoneX);
            y = QUOTE(0.23 * safezoneH + safezoneY);
            w = QUOTE(0.46 * safezoneW);
            h = QUOTE(0.54 * safezoneH);
            maxSatelliteAlpha = 0.75;
            colorBackground[] = {1,1,1,1};
        };
    };
};

// respawn eula dialog
class GVAR(respawnEula) {
    idd = RESPAWN_EULA_IDD;

    class ControlsBackground {
        class BackGround: RscBackground {
            idc = EULA_BG_IDC;
            x = QUOTE(0.42 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.135 * safezoneW);
            h = QUOTE(0.325 * safezoneH);
            colorBackground[] = {0,0,0,0.33};
        };
        class BackGroundFrame: RscFrame {
            idc = EULA_BGF_IDC;
            text = "Wave Reinforcement Tool End User License Agreement";
            x = QUOTE(0.425 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.125 * safezoneW);
            h = QUOTE(0.32 * safezoneH);
            sizeEx = QUOTE(0.50 * TEXT_SIZE_FACTOR);
        };
    };

    class Controls {
        class EulaText: RscStructuredText {
            idc = EULA_TEXT_IDC;
            text = QUOTE(EULA_FULL_TEXT);
            x = QUOTE(0.43 * safezoneW + safezoneX);
            y = QUOTE(0.38 * safezoneH + safezoneY);
            w = QUOTE(0.115 * safezoneW);
            h = QUOTE(0.24 * safezoneH);
            colorBackground[] = {COLOR_EMPTY};
        };
        class AgreeButton: RscButton {
            idc = EULA_AGREE_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleAgreeClick));
            text = "Agree";
            x = QUOTE(0.4375 * safezoneW + safezoneX);
            y = QUOTE(0.64 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Agree to the EULA as described above, and open the Reinforcement tool";
            sizeEx = QUOTE(0.7 * TEXT_SIZE_FACTOR);
        };
        class DeclineButton: RscButton {
            idc = EULA_DECLINE_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleDeclineClick));
            text = "Decline";
            x = QUOTE(0.5 * safezoneW + safezoneX);
            y = QUOTE(0.64 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Decline to the EULA as described above, and close the dialog";
            sizeEx = QUOTE(0.7 * TEXT_SIZE_FACTOR);
        };
    };
};

// client respawn dialog
class GVAR(clientRespawn) {
    idd = CLIENT_RESPAWN_IDD;

    onLoad = QUOTE(_this spawn FUNC(ui_handleClientLoad));
    onUnload = QUOTE(call FUNC(ui_handleClientUnload));

    class ControlsBackground {
        class BackGround: RscBackground {
            idc = CLIENT_BG_IDC;
            x = QUOTE(0.37 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.235 * safezoneW);
            h = QUOTE(0.325 * safezoneH);
            colorBackground[] = {0,0,0,0.33};
        };
        class BackGroundFrame: RscFrame {
            idc = CLIENT_BGF_IDC;
            text = "Client Reinforcement Tool";
            x = QUOTE(0.375 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.225 * safezoneW);
            h = QUOTE(0.32 * safezoneH);
            sizeEx = QUOTE(0.5 * TEXT_SIZE_FACTOR);
        };
    };

    class Controls {
        class CloseText: RscText {
            idc = CLIENT_CLOSE_TEXT_IDC;
            text = "You may close this window post slotting";
            x = QUOTE(0.38 * safezoneW + safezoneX);
            y = QUOTE(0.38 * safezoneH + safezoneY);
            w = QUOTE(0.135 * safezoneW);
            h = QUOTE(0.025 * safezoneH);
            sizeEx = QUOTE(0.5 * TEXT_SIZE_FACTOR);
        };
        class CloseButton: RscButton {
            idc = CLIENT_CLOSE_BUTTON_IDC;
            onButtonClick = QUOTE([] call FUNC(closeClientRespawn));
            text = "x";
            x = QUOTE(0.595 * safezoneW + safezoneX);
            y = QUOTE(0.36 * safezoneH + safezoneY);
            w = QUOTE(0.01 * safezoneW);
            h = QUOTE(0.015 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Close";
            sizeEx = QUOTE(0.4 * TEXT_SIZE_FACTOR);
        };
        class GroupTree: RscTree {
            idc = GROUP_TREE_IDC;
            onTreeDblClick = QUOTE(call FUNC(ui_handleClientSlotClick));
            x = QUOTE(0.38 * safezoneW + safezoneX);
            y = QUOTE(0.405 * safezoneH + safezoneY);
            w = QUOTE(0.215 * safezoneW);
            h = QUOTE(0.23 * safezoneH);
            multiselectEnabled = 0;
            colorBorder[] = {COLOR_EMPTY};
            colorBackground[] = {COLOR_BLACK};
        };
        class SlotButton: RscButton {
            idc = CLIENT_SLOT_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleClientSlotClick));
            text = "Slot";
            x = QUOTE(0.4375 * safezoneW + safezoneX);
            y = QUOTE(0.64 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Slot into the selected unit";
            sizeEx = QUOTE(0.7 * TEXT_SIZE_FACTOR);
        };
        class UnslotButton: RscButton {
            idc = CLIENT_UNSLOT_BUTTON_IDC;
            onButtonClick = QUOTE(call FUNC(ui_handleClientUnslotClick));
            text = "Unslot";
            x = QUOTE(0.5 * safezoneW + safezoneX);
            y = QUOTE(0.64 * safezoneH + safezoneY);
            w = QUOTE(0.0375 * safezoneW);
            h = QUOTE(0.03 * safezoneH);
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Unslot";
            sizeEx = QUOTE(0.7 * TEXT_SIZE_FACTOR);
        };
    };
};
