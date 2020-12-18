class CfgVehicles {
    class Item_Base_F;
    class potato_naloxoneItem: Item_Base_F {
      scope = 2;
      scopeCurator = 2;
      displayName = "Naloxone Autoinjector";
      author = "Alablm";
      vehicleClass = "Items";
      class TransportItems {
          MACRO_ADDITEM(potato_naloxone,1);
      };
    };
};
class CfgWeapons {
    class ACE_atropine;
    class potato_naloxone: ACE_atropine {
        scope = 2;
        author = "Alablm";
        displayName = "Naloxone Autoinjector";
        descriptionShort = "Used to treat opioid overdose";
        descriptionUse = "A drug widely used to treat opioid overdoses by blocking opioid receptors";
    };
};
class ace_medical_treatment_actions {
    class Morphine;
    class Naloxone: Morphine {
      displayName = "Inject Naloxone";
      displayNameProgress = "Injecting Naloxone";
      condition = "ace_medical_treatment_advancedMedication";
      items[] = {"potato_naloxone"};
      litter[] = {{"ACE_MedicalLitter_atropine"}};
    };
};
class ace_medical_treatment {
    class Medication {
        class Naloxone {
          painReduce = 0;
          hrIncreaseLow[] = {0, 0};
          hrIncreaseNormal[] = {0, 0};
          hrIncreaseHigh[] = {0, 0};
          timeInSystem = 180;
          timeTillMaxEffect = 1;
          maxDose = 0.1;
          onOverDose = FUNC(Naloxone);
          incompatibleMedication[] = {};
          viscosityChange = 0;
        };
    };
};
