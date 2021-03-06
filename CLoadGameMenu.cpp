#include "AllExceptions.h"
#include "CLoadGameMenu.h"
#include "CController.h"
#include "CPiece.h"
#include "CFilePersistence.h"
#include "CLocalPlayer.h"
#include "CIntelligence.h"
#include <climits>
#include <fstream>

CLoadGameMenu::CLoadGameMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar), loadSuccessful(false),persistence(NULL) {
    
    title = "Zadejte nazev souboru s ulozenou hrou:";
}

void CLoadGameMenu::show() const {
    showTitle();
}


CLoadGameMenu::~CLoadGameMenu() {
    delete persistence;
    persistence = NULL;
}

void CLoadGameMenu::setNextMenu() {
    if(loadSuccessful)
        nextMenu = NULL;
    else{
        nextMenu = prevMenu;
    }
}

bool CLoadGameMenu::findFile(const string & file) const {

    ifstream ifs(file.c_str());
    if (!ifs.good()){
        return false;
    }

    ifs.close();
    return true;
}

int CLoadGameMenu::readInput() {

    string filestr;
    filestr.clear();

    while (cin.good()) {

        cin >> filestr;

        if (!cin.good()) {

            filestr.clear();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Nezdařilo se čtení vstupu, znovu prosím:" << endl;
            continue;
        }

        if (filestr == "BACK" || filestr == "back" || filestr == "Back") {
            delete nextMenu;
            return 0;
        }

        //cout << "ZADANO: " << filestr << endl;

        if (!findFile(filestr)) {
            cout << "Soubor \"" << filestr << "\" nenalezen, zkuste to znvu." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }

        if (confirmLoad()) {
            fileGame = filestr;
            break;
        }
        else{
            return 1;
        }
    }


    loadFromFile(fileGame);
    return 0;
}

bool CLoadGameMenu::confirmLoad() {
    cout << "Soubor nalezen."<< endl;
    cout << "Chcete jej načíst? (A/N)" << endl;

    char c;

    while (cin.good()) {

        cin>>c;
        if (c == 'A')
            return true;
        else if (c == 'N') {
            return false;
        } else {
            cout << "Prosím zadejte A, nebo N." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    cout << "Akce zrušena..." << endl;
    cin.ignore(INT_MAX, '\n');
    cin.clear();
    return false;
}

void CLoadGameMenu::setStuff(CController* ctrler) {

    if(!loadSuccessful){
        return;
    }
    
    delete ctrler->getGameSess().player1;
    delete ctrler->getGameSess().player2;
    
     ctrler->getGameSess().player1 = new CLocalPlayer();
     
    cout << "Má druhým hráčem být AI nebo človek?"<<endl;
    cout << "Zadejte \"AI\", nebo \"HUMAN\"" << endl;
    
    string pl;
    
    while(cin >> pl){
        if(!cin.good() || (pl != "AI" && pl != "HUMAN") ){
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            cout << "Zadejte \"AI\", nebo \"HUMAN\"!" << endl;
        }
        else
            break;
    }
            
    if(pl == "AI"){
        cout << "Jakou chcete obtížnost AI? (1-3)"<<endl;
        int dif = 0;
        cin >> dif;
        while(!cin.good() || dif < 1 || dif > 3){            
            cin.clear();
            cin.ignore(INT_MAX,'\n');
            
            cout << "Zadejte 1 az 3 a potvrďte!"<<endl;
            cin >> dif;
        }
        delete ctrler->getGameSess().player2;
        ctrler->getGameSess().player2 = new CIntelligence(dif);
    }
    else{
        delete ctrler->getGameSess().player2;
        ctrler->getGameSess().player2 = new CLocalPlayer();
    }

    if (loadSuccessful && persistence != NULL) {
        ctrler->getGameSess().gameBoard.copy(persistence->tLoad.board);
        ctrler->getGameSess().setPlayerColors(persistence->tLoad.player1col);        
        ctrler->getGameSess().setTurn(persistence->tLoad.whosTurn);
        ctrler->getGameSess().fileName = fileGame;

        ctrler->getGameSess().setGameReady();

    } else {
        cout << "Načtení hry se nezdařilo." << endl;
    }
}

void CLoadGameMenu::loadFromFile(const string & filename) {    
    delete persistence;
    persistence = new CFilePersistence();

    if( ! persistence->load(filename)){
        
        loadSuccessful = false;
        return;
    }
    
    
    loadSuccessful = true;
}