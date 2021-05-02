// Bonus example civilian loadouts

#include "undef.hpp" // Reset defines

#define LINKED BASE_LINKED

class CIV_F {
  class C_man_1 {
    uniform[] = {"U_C_Poloshirt_blue","U_C_Poloshirt_burgundy","U_C_Poloshirt_stripped","U_C_Poloshirt_tricolour","U_C_Poloshirt_salmon","U_C_Poloshirt_redwhite"};
    vest[] = {};
    headgear[] = {};
    backpack[] = {};
    backpackItems[] = {};
    weapons[] = {};
    launchers[] = {};
    handguns[] = {};
    magazines[] = {};
    items[] = {BASE_MEDICAL};
    linkedItems[] = {LINKED};
    attachments[] = {};
  };
  class C_journalist_F: C_man_1 {
    uniform[] = {"U_C_Journalist"};
    vest[] = {"V_Press_F"};
    headgear[] = {"H_Cap_press"};
  };
  class CEO: C_man_1 {
    uniform[] = {"U_Marshal"};
    headgear[] = {"H_Hat_brown"};
  };
  class C_man_hunter_1_F: C_man_1 {
    uniform[] = {"U_C_HunterBody_grn"};
    headgear[] = {"H_Booniehat_grn"};
    backpack[] = {"B_OutdoorPack_blk"};
  };
};
