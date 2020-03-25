
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;
TEST_CASE("Test replacement of v and w") {
    string text1 = "dont worry yyy";
    string text2 = "view wave yyy";
    //case 1
    CHECK(find(text1, "worry") == string("worry"));
    CHECK(find(text1, "vorry") == string("worry"));
    CHECK(find(text1, "Vorry") == string("worry"));
    //case 2
    CHECK(find(text2, "wave") == string("wave"));
    CHECK(find(text2, "vieV") == string("view"));
    CHECK(find(text2, "VIEW") == string("view"));
    CHECK(find(text2, "WawE") == string("wave"));
    CHECK(find(text2, "waWe") == string("wave"));
}
    /* Test replacement of b,p & f */
TEST_CASE("Test replacement of b f and p") {
    string text = "backflip xxyy" ;
    CHECK(find(text, "backflip") == string("backflip"));
    CHECK(find(text, "Packflip") == string("backflip"));
    CHECK(find(text, "FaCKflip") == string("backflip"));
    CHECK(find(text, "backBLip") == string("backflip"));
    CHECK(find(text, "backpLIp") == string("backflip"));
    CHECK(find(text, "backfLIB") == string("backflip"));
    CHECK(find(text, "baCKFlif") == string("backflip"));
    CHECK(find(text, "fackblip") == string("backflip"));
    CHECK(find(text, "PACKFLIF") == string("backflip"));
    CHECK(find(text, "packblib") == string("backflip"));

}
TEST_CASE("Test replacement of g and j") {
 string text1 = "jpeg yyy xxyy";
 string text2 = "judge judi xxyy";
 //case 1
 CHECK(find(text1, "jpeg") == string("jpeg"));
 CHECK(find(text1, "JPEG") == string("jpeg"));
 CHECK(find(text1, "gPEg") == string("jpeg"));
 CHECK(find(text1, "GpEJ") == string("jpeg"));
 //case 2
 CHECK(find(text2, "JudjE") == string("judge"));
 CHECK(find(text2, "GudjE") == string("judge"));
    CHECK(find(text2, "GUDI") == string("judi"));
    CHECK(find(text2, "gUDi") == string("judi"));
}
TEST_CASE("Test replacement of c k and q") {
    string text = "quick yyy quack";
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "kuIKk") == string("quick"));
    CHECK(find(text, "qUIkk") == string("quick"));
    CHECK(find(text, "quICC") == string("quick"));
    CHECK(find(text, "CUICK") == string("quick"));
    CHECK(find(text, "quIQk") == string("quick"));
    CHECK(find(text, "CUIqc") == string("quick"));

    CHECK(find(text, "quAck") == string("quack"));
    CHECK(find(text, "CUAcQ") == string("quack"));
    CHECK(find(text, "Kuack") == string("quack"));
    CHECK(find(text, "KuaKK") == string("quack"));

}
TEST_CASE("Test replacement of s and z") {
    string text = "zeus  siZe yyy";
    CHECK(find(text, "zeus") == string("zeus"));
    CHECK(find(text, "Seus") == string("zeus"));
    CHECK(find(text, "zeuz") == string("zeus"));
    CHECK(find(text, "seuZ") == string("zeus"));
    
    CHECK(find(text, "SIZE") == string("siZe"));
    CHECK(find(text, "ZiSe") == string("siZe"));
    CHECK(find(text, "ZIsE") == string("siZe"));
    CHECK(find(text, "SISe") == string("siZe"));


}
TEST_CASE("Test replacement of d and t") {
    string text = "yyy document dont";
    CHECK(find(text, "dont") == string("dont"));
    CHECK(find(text, "TonD") == string("dont"));
    CHECK(find(text, "DONT") == string("dont"));
    CHECK(find(text, "TOND") == string("dont"));

    CHECK(find(text, "document") == string("document"));
    CHECK(find(text, "dOCUMENt") == string("document"));
    CHECK(find(text, "DocumenD") == string("document"));
    CHECK(find(text, "TocUMenD") == string("document"));
    CHECK(find(text, "doCUMEnD") == string("document"));

}
TEST_CASE("Test replacement of o and u") {
    string text = "count acount out";
    CHECK(find(text, "acount") == string("acount"));
    CHECK(find(text, "AcuonT") == string("acount"));
    CHECK(find(text, "ACOUNT") == string("acount"));
    CHECK(find(text, "AcOOnT") == string("acount"));

    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "UUt") == string("out"));
    CHECK(find(text, "OOT") == string("out"));
    CHECK(find(text, "UoT") == string("out"));
    CHECK(find(text, "uoT") == string("out"));

    CHECK(find(text, "count") == string("count"));
    CHECK(find(text, "CUunT") == string("count"));
    CHECK(find(text, "cOOnt") == string("count"));
    CHECK(find(text, "CUonT") == string("count"));
    

}
TEST_CASE("Test replacement of y and i") {
    string text = "illuminati wifi yyy";

    CHECK(find(text, "illuminati") == string("illuminati"));
    CHECK(find(text, "ILLUMInati") == string("illuminati"));    
    CHECK(find(text, "YllumYnatY") == string("illuminati"));    
    CHECK(find(text, "YllUMynati") == string("illuminati"));    
    CHECK(find(text, "illUMYnati") == string("illuminati"));    
    CHECK(find(text, "yLLUmInatI") == string("illuminati"));    

    CHECK(find(text, "wifi") == string("wifi"));    
    CHECK(find(text, "wYfY") == string("wifi"));    
    CHECK(find(text, "WIfY") == string("wifi"));    
    CHECK(find(text, "wYfI") == string("wifi"));   

    CHECK(find(text, "yyy") == string("yyy"));    
    CHECK(find(text, "YIY") == string("yyy"));    
    CHECK(find(text, "IiI") == string("yyy"));    

}
TEST_CASE("Test replacement of all cases") {
    string text1 = "this is a new project";
    string text2 = "good luck in this semester";

    CHECK(find(text1, "ThYZ") == string("this"));    
    CHECK(find(text1, "dhYZ") == string("this"));    
    CHECK(find(text1, "thiz") == string("this"));    
    CHECK(find(text1, "Is") == string("is"));    
    CHECK(find(text1, "ys") == string("is"));    
    CHECK(find(text1, "iZ") == string("is"));    
    CHECK(find(text1, "froject") == string("project"));    
    CHECK(find(text1, "PrUject") == string("project"));    
    CHECK(find(text1, "proGect") == string("project"));    
    CHECK(find(text1, "pruJecd") == string("project"));    
    CHECK(find(text2, "goUt") == string("good"));    
    CHECK(find(text2, "jOUd") == string("good"));    
    CHECK(find(text2, "gUUd") == string("good"));    
    CHECK(find(text2, "jOOT") == string("good"));    
    CHECK(find(text2, "guut") == string("good"));    
    CHECK(find(text2, "zeMesDer") == string("semester"));    
    CHECK(find(text2, "semesTer") == string("semester"));    
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    //case 1    
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "HAppi") == string("Happi"));
    CHECK(find(text, "HaPpi") == string("Happi"));
    CHECK(find(text, "HapPi") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
    //case 2
    CHECK(find(text, "hAppi") == string("Happi"));
    CHECK(find(text, "haPpi") == string("Happi"));
    CHECK(find(text, "hapPi") == string("Happi"));
    CHECK(find(text, "happI") == string("Happi"));
    CHECK(find(text, "HAPpi") == string("Happi"));
    CHECK(find(text, "HApPi") == string("Happi"));
    CHECK(find(text, "HAppI") == string("Happi"));
    CHECK(find(text, "HaPPi") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    //case 3
    CHECK(find(text, "hAPpi") == string("Happi"));
    CHECK(find(text, "hApPi") == string("Happi"));
    CHECK(find(text, "hAppI") == string("Happi"));
    CHECK(find(text, "HAPPi") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HaPPI") == string("Happi"));
    
}
    //test exception
TEST_CASE("throwing errors"){
    string text = "this is not omg";
   
    CHECK_THROWS(find(text,"wow"));
    CHECK_THROWS(find(text,"DhYf"));
    CHECK_THROWS(find(text,"as"));
    CHECK_THROWS(find(text,"show"));
    CHECK_THROWS(find(text,"IIs"));
    CHECK_THROWS(find(text,"THISS"));
    CHECK_THROWS(find(text,"UMMG"));
    CHECK_THROWS(find(text,""));


}

/* Add more test cases here */
