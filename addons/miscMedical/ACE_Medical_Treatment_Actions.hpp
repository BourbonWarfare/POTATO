class ace_medical_treatment_actions {
    class Morphine;
    class Naloxone: Morphine {
        displayName = "Inject Naloxone";
        displayNameProgress = "Injecting Naloxone";
        condition = "ace_medical_treatment_advancedMedication";
        items[] = {"potato_naloxone"};
        litter[] = {{"ACE_MedicalLitter_atropine"}};
    };
    class BasicBandage;
    class ApplyTourniquet: BasicBandage {
        sounds[] = {{"z\POTATO\addons\miscMedical\data\tourniquet.ogg",5,1,50}};
    };
    class Splint: BasicBandage {
        sounds[] = {{"z\POTATO\addons\miscMedical\data\splint.ogg",5,1,50}};
    };
    class Diagnose: BasicBandage {
        sounds[] = {{"z\POTATO\addons\miscMedical\data\diag.ogg",5,1,50}};
    };
};