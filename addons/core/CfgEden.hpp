class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                items[] += {QUOTE(PREFIX)}; // += must be used; you want to expand the array, not override it!
                class PREFIX {
                    text = "POTATO"; // Item text
                    items[] = {};
                };
            };
        };
    };
};
