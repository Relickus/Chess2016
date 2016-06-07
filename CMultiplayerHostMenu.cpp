#include "CMultiplayerHostMenu.h"
#include "CColorMenu.h"
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
   
   nextMenu = new CColorMenu(this);
   
}

CMultiplayerHostMenu::~CMultiplayerHostMenu(){
    
}

int CMultiplayerHostMenu::readInput() {

    string addr = "localhost:2666";
    cout <<"Startuji server na adrese : " << addr<<endl;
    
    net.startServer();
 
}


void CMultiplayerHostMenu::setNextMenu() {

}

void CMultiplayerHostMenu::setStuff(CController* ctrler) {

}

void CMultiplayerHostMenu::show() const {
    showTitle();
}
