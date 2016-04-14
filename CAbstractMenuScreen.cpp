
#include "CAbstractMenuScreen.h"

CAbstractMenuScreen::CAbstractMenuScreen() {

}

CAbstractMenuScreen::~CAbstractMenuScreen(){
    
}

void CAbstractMenuScreen::show() const{
    
    int i = 0; 
    
    while(! (menuItems[i].empty()) ){        
        printMenuItem(i);
    }
}

void CAbstractMenuScreen::printMenuItem(int i) const{
    
    cout << i<<". " << menuItems[i] <<endl;
    
}