
#include "CLoadGameMenu.h"
#include <climits>

CLoadGameMenu::CLoadGameMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar) {

    title = "Zadejte nazev souboru s ulozenou hrou:";
    setNumMenuItems();
}

CLoadGameMenu::~CLoadGameMenu() {

}

void CLoadGameMenu::setNextMenu(){
    
}

int CLoadGameMenu::readInput(){
        
    string filestr;
    
    while(true){
        filestr.clear();
        
        getline(cin,filestr,'\n');

        if(!cin.good()){
            cin.clear();
            cin.ignore(INT_MAX);
            cout <<"Nezdarilo se cteni vstupu, znovu prosim:"<<endl;
            continue;
        }
        
        cout << "ZADANO: "<<filestr <<endl;
        
        if(filestr == "BACK" || filestr == "back" || filestr == "Back")
        {
            delete nextMenu;
            nextMenu = prevMenu;
            return 0;
        }
        
        // .........
    }
    
    fileGame = filestr;
        
    return 0;
}

void CLoadGameMenu::setStuff(CController* ctrler) {

}
