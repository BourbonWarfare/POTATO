// License Attribution req: UI image authored by user grmarcstock via Vecteezy.com

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
class CfgWeapons {
    class ACE_ItemCore;
    class ACE_painkillers_Item: ACE_ItemCore {};
    class potato_pkblister: ACE_painkillers {
        scope = 2;
        author = "AChesheireCat";
        displayName = "Painkiller Blister Pack";
        descriptionShort = "For physical pain only";
        descriptionUse = "A blister pack containing individualized painkiller tablets, regularly issued in IFAKs";
        picture = QPATHTOEF(miscMedical,ui\pkblister_ca.paa);
    };
};