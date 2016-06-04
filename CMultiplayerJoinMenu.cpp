#include "CMultiplayerJoinMenu.h"
#include "CColorMenu.h"
#include <climits>

void CMultiplayerJoinMenu::setNextMenu(){}

CMultiplayerJoinMenu::CMultiplayerJoinMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar) {

    title = "Zadejte IPv4 adresu serveru, nebo \"back\" pro navrat zpet:";
    
    nextMenu = new CColorMenu();

    setNumMenuItems();
}
CMultiplayerJoinMenu::~CMultiplayerJoinMenu() {

}

bool CMultiplayerJoinMenu::validIP(const string & ip) const{
    
    if(ip.length() < 7 || ip.length() > 15){
        return false;
    }
//    
//    TODO
//    
//    size_t dotIdx1 = ip.find('.');
//   
//    string sub = ip.substr(0,dotIdx);
//    
//    if(sub.size() > 3)
//        return false;
//    
//    int subIp1 = stoi(sub);
//    
//        if(subIp1 != 192 || subIp1 != 10 || subIp1 != 172)
//            return false;
//    
//    size_t dotIdx2 = ip.find('.',dotIdx1);
//    string sub = ip.substr(dotIdx1,dotIdx2-dotIdx1);
    
    return true;
}

int CMultiplayerJoinMenu::readInput(){
    
    string ipstr;    
    
    while(true){
        ipstr.clear();
        
        cin >> ipstr;

        if(!cin.good()){
            cin.clear();
            cin.ignore(INT_MAX);
            cout <<"Nezdarilo se zadavani adresy, znovu prosim:"<<endl;
            continue;
        }
        
        if(ipstr == "Back" || ipstr == "BACK" || ipstr == "back"){
            delete nextMenu;
            nextMenu = prevMenu;
            return 0;
        }
        
        if(ipstr.empty() || !validIP(ipstr)){
            cin.clear();
            //cin.ignore(INT_MAX,'\n');
            cout <<"Not valid IPv4, try again:"<<endl;
            continue;
        }
        else
            break;
    }
    
    IP = ipstr;
    

    return 0;
}

void CMultiplayerJoinMenu::setStuff(CController* ctrler) {

}
