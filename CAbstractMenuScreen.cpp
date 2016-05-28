
#include "CAbstractMenuScreen.h"
#include <climits>

CAbstractMenuScreen::CAbstractMenuScreen(CAbstractMenuScreen * prevPar /* =NULL*/) : nextMenu(NULL), prevMenu(prevPar),chosenOption(-1) {  
}

CAbstractMenuScreen::~CAbstractMenuScreen(){
    
}

void CAbstractMenuScreen::show() const{
    
    int i = 0; 
    showTitle();
    
    while( i < MAXITEMS && !menuItems[i].empty() ){        
        printMenuItem(i);
        ++i;
    }
}

void CAbstractMenuScreen::printMenuItem(int i) const{
    
    cout << i+1<<". " << menuItems[i] <<endl;
    
}

void CAbstractMenuScreen::setNumMenuItems(){
    
    int i = 0;
    
    while( i < MAXITEMS && !menuItems[i].empty()){
        ++i;
    }
    numItems = i;
}

bool CAbstractMenuScreen::validChoice(int i) const{
        
    if( i < 1 || i > numItems ){
        
        cout << "CHYBA: "<< i << " neni validni moznost menu."<<endl;
        return false;
    }
        
    return true;
}

void CAbstractMenuScreen::showTitle() const{
    
    cout << title<<endl;   
}


int CAbstractMenuScreen::readInput(){
    
    int choice = 0;
    
     while (true){         
         cin >> choice;
         if(!cin.good()){
             cin.clear();
             cin.ignore(INT_MAX,'\n');
             
             cout << "Spatny vstup, znova"<<endl;
             continue;
         }
         
         if(!validChoice(choice)){
             cout << "Moznost mimo rozsah,znova"<<endl;
             continue;
         }
         else
             break;
     }      
    
    chosenOption = choice;
    
    return choice;
}

int CAbstractMenuScreen::getChoice() const{
    return chosenOption;
}
