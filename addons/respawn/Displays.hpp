#define TEXT_SIZE_FACTOR (safezoneH / 25)

// stubs
class RscText;
class RscTree;
class RscCombo;
class RscFrame;
class RscButton;
class RscListNBox;
class RscBackground;
class RscMapControl;
class RscControlsGroupNoScrollbars;

// admin respawn tool
class GVAR(adminRespawn) {
    idd = ADMIN_RESPAWN_IDD;

    onLoad = QUOTE(_this spawn FUNC(ui_handleAdminLoad));
    onUnload = QUOTE(_this call FUNC(ui_handleAdminUnload));

    class ControlsBackground {
        class BackGround: RscBackground {
            idc = ADMIN_BG_IDC;
            x = 0.27 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.46 * safezoneW;
            h = 0.54 * safezoneH;
            colorBackground[] = {0,0,0,0.33};
        };
        class BackGroundFrame: RscFrame {
            idc = ADMIN_BGF_IDC;
            text = "Wave Respawn Tool";
            x = 0.275 * safezoneW + safezoneX;
            y = 0.24 * safezoneH + safezoneY;
            w = 0.45 * safezoneW;
            h = 0.52 * safezoneH;
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class SpectatorBackGround: RscBackground {
            idc = ADMIN_SPEC_BG_IDC;
            x = 0.2875 * safezoneW + safezoneX;
            y = 0.3 * safezoneH + safezoneY;
            w = 0.1375 * safezoneW;
            h = 0.44 * safezoneH;
            colorBackground[] = {COLOR_BLACK};
        };
        class SpectatorFrame: RscFrame {
            idc = ADMIN_SPEC_FRAME_IDC;
            text = "Spectators (0)";
            x = 0.285 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.1425 * safezoneW;
            h = 0.47 * safezoneH;
            sizeEx = 0.5 * TEXT_SIZE_FACTOR;
        };
        class GroupsFrame: RscFrame {
            idc = GROUP_FRAME_IDC;
            text = "Active Groups";
            x = 0.435 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.1425 * safezoneW;
            h = 0.47 * safezoneH;
            sizeEx = 0.5 * TEXT_SIZE_FACTOR;
        };
        class ConfigurationFrame: RscFrame {
            idc = ADMIN_CONFIG_FRAME_IDC;
            text = "Configuration";
            x = 0.5875 * safezoneW + safezoneX;
            y = 0.28 * safezoneH + safezoneY;
            w = 0.125 * safezoneW;
            h = 0.47 * safezoneH;
            sizeEx = 0.5 * TEXT_SIZE_FACTOR;
        };
    };

    class Controls {
        class SpectatorList: RscListNBox {
            idc = ADMIN_SPEC_LIST_IDC;
            x = 0.2875 * safezoneW + safezoneX;
            y = 0.3 * safezoneH + safezoneY;
            w = 0.1375 * safezoneW;
            h = 0.44 * safezoneH;
            colorBackground[] = {COLOR_EMPTY};
        };
        class GroupTree: RscTree {
            idc = GROUP_TREE_IDC;
            x = 0.4375 * safezoneW + safezoneX;
            y = 0.3 * safezoneH + safezoneY;
            w = 0.1375 * safezoneW;
            h = 0.44 * safezoneH;
            multiselectEnabled = 0;
            colorBorder[] = {COLOR_EMPTY};
            colorBackground[] = {COLOR_BLACK};
        };
        class FactionText: RscText {
            idc = ADMIN_FACTION_TEXT_IDC;
            text = "Faction:";
            x = 0.5875 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.0375 * safezoneW;
            h = 0.03 * safezoneH;
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
            style = 1;
        };
        class FactionCombo: RscCombo {
            idc = ADMIN_FACTION_COMBO_IDC;
            onLBSelChanged = QUOTE(_this call FUNC(ui_handleFactionChange));
            x = 0.625 * safezoneW + safezoneX;
            y = 0.32 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select faction (Note: changing this will reset the active groups)";
        };
        class GroupText: RscText {
            idc = ADMIN_GROUP_TEXT_IDC;
            text = "Group:";
            x = 0.5875 * safezoneW + safezoneX;
            y = 0.36 * safezoneH + safezoneY;
            w = 0.0375 * safezoneW;
            h = 0.03 * safezoneH;
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
            style = 1;
        };
        class GroupCombo: RscCombo {
            idc = ADMIN_GROUP_COMBO_IDC;
            onLBSelChanged = QUOTE(_this call FUNC(ui_handleGroupChange));
            x = 0.625 * safezoneW + safezoneX;
            y = 0.36 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select Group";
        };
        class ConfigurationText: RscText {
            idc = ADMIN_CONFIG_TEXT_IDC;
            text = "Config:";
            x = 0.5875 * safezoneW + safezoneX;
            y = 0.4 * safezoneH + safezoneY;
            w = 0.0375 * safezoneW;
            h = 0.03 * safezoneH;
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
            style = 1;
        };
        class ConfigurationCombo: RscCombo {
            idc = ADMIN_CONFIG_COMBO_IDC;
            x = 0.625 * safezoneW + safezoneX;
            y = 0.4 * safezoneH + safezoneY;
            w = 0.075 * safezoneW;
            h = 0.03 * safezoneH;
            colorBackground[] = {COLOR_BLACK};
            tooltip = "Select Group Configuration";
        };
        class AddButton: RscButton {
            idc = ADMIN_ADD_BUTTON_IDC;
            onButtonClick = QUOTE(_this call FUNC(ui_handleAddClick));
            text = "Add";
            x = 0.6 * safezoneW + safezoneX;
            y = 0.44 * safezoneH + safezoneY;
            w = 0.03 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Adds currently configured group to the active group list";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class SlotButton: RscButton {
            idc = ADMIN_SLOT_BUTTON_IDC;
            text = "Slot";
            x = 0.635 * safezoneW + safezoneX;
        	y = 0.44 * safezoneH + safezoneY;
        	w = 0.03 * safezoneW;
        	h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_BLUE_ACTIVE};
            colorBackground[] = {COLOR_BLUE_INACTIVE};
            colorBackgroundActive[] = {COLOR_BLUE_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Slots the selected spectator into the selected group";
            sizeEx = 0.75 * (safezoneH / 25);
        };
        class DeleteButton: RscButton {
            idc = ADMIN_DELETE_BUTTON_IDC;
            onButtonClick = QUOTE(_this call FUNC(ui_handleDeleteClick));
            text = "Delete";
            x = 0.670 * safezoneW + safezoneX;
            y = 0.44 * safezoneH + safezoneY;
            w = 0.03 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Removes the selected active group from the list";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class OpenRespawnButton: RscButton {
            idc = ADMIN_OPEN_RESPAWN_BUTTON_IDC;
            onButtonClick = QUOTE(_this call FUNC(ui_handleRespawnStateClick));
            text = "Open Respawn";
            x = 0.6 * safezoneW + safezoneX;
            y = 0.52 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_GREEN_INACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Open respawn to current spectators";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class CloseRespawnButton: OpenRespawnButton {
            idc = ADMIN_CLOSE_RESPAWN_BUTTON_IDC;
            text = "Close Respawn";
            colorFocused[] = {COLOR_RED_INACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            tooltip = "Close respawn to current spectators";
        };
        class TriggerButton: RscButton {
            idc = ADMIN_TRIGGER_BUTTON_IDC;
            text = "Trigger Respawn";
            x = 0.6 * safezoneW + safezoneX;
            y = 0.58 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_BLUE_ACTIVE};
            colorBackground[] = {COLOR_BLUE_INACTIVE};
            colorBackgroundActive[] = {COLOR_BLUE_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Trigger respawn with the players in the active groups";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class CancelButton: RscButton {
            idc = ADMIN_CANCEL_BUTTON_IDC;
            onButtonClick = QUOTE(_this call FUNC(ui_handleCancelClick));
            text = "Cancel Respawn";
            x = 0.6 * safezoneW + safezoneX;
            y = 0.64 * safezoneH + safezoneY;
            w = 0.1 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Cancels the currently configured respawn";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class ChatButtonOn: RscButton {
            idc = ADMIN_CHAT_BUTTON_ON_IDC;
            onButtonClick = QUOTE(_this call FUNC(ui_handleChatClick));
            text = "Chat";
            x = 0.6 * safezoneW + safezoneX;
            y = 0.7 * safezoneH + safezoneY;
            w = 0.0375 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_GREEN_ACTIVE};
            colorBackground[] = {COLOR_GREEN_INACTIVE};
            colorBackgroundActive[] = {COLOR_GREEN_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Sets ACRE to spectate chat (on)";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
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
            onButtonClick = QUOTE(_this call FUNC(ui_handleCloseClick));
            text = "Close";
            x = 0.6625 * safezoneW + safezoneX;
            y = 0.7 * safezoneH + safezoneY;
            w = 0.0375 * safezoneW;
            h = 0.04 * safezoneH;
            colorFocused[] = {COLOR_RED_ACTIVE};
            colorBackground[] = {COLOR_RED_INACTIVE};
            colorBackgroundActive[] = {COLOR_RED_ACTIVE};
            colorBackgroundDisabled[] = {COLOR_BLACK};
            tooltip = "Closes the dialog, but leaves the configuration in it's current state";
            sizeEx = 0.75 * TEXT_SIZE_FACTOR;
        };
        class Map: RscMapControl {
            idc = ADMIN_MAP_IDC;

            //onDraw = QUOTE(_this call FUNC(ui_handleMapDraw));
            //onMouseButtonClick = QUOTE(_this call FUNC(ui_handleMapClick));

            x = 0.27 * safezoneW + safezoneX;
            y = 0.23 * safezoneH + safezoneY;
            w = 0.46 * safezoneW;
            h = 0.54 * safezoneH;

            maxSatelliteAlpha = 0.75;
            colorBackground[] = {1,1,1,1};
        };
    };
};
