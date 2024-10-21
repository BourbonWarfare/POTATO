// License Attribution req: UI image authored by user grmarcstock via Vecteezy.com

class CfgMagazines {
    class CA_Magazine;
    class ACE_painkillers: CA_Magazine {};
    class potato_pkblister: ACE_painkillers {
        author = "AChesheireCat";
        displayName = "Painkiller Blister Pack";
        descriptionShort = "For physical pain only";
        descriptionUse = "A blister pack containing individualized painkiller tablets, regularly issued in IFAKs";
        picture = QPATHTOEF(miscMedical,ui\pkblister_ca.paa);
        count = 2;
    };
};