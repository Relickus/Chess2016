
#include "CMultiplayerHostMenu.h"
//
//
//void CMultiplayerHostMenu::show() const{
//    
//    showTitle();
//    cout << "IP adresa serveru: " << server_addr<<endl;
//    cout << "Waiting for opponent..."<<endl;
//}

CMultiplayerHostMenu::CMultiplayerHostMenu(CAbstractMenuScreen* prPar /*=NULL*/) {

   title =  "Starting server...";
   prevMenu = prPar;
   
   setNumMenuItems();
}

CMultiplayerHostMenu::~CMultiplayerHostMenu(){
    
}

void CMultiplayerHostMenu::setNextMenu() {

}

void CMultiplayerHostMenu::setStuff(CController* ctrler) {

}

void CMultiplayerHostMenu::show() const {

    showTitle();
}
