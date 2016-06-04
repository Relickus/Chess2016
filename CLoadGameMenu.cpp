
#include "CLoadGameMenu.h"
#include "CController.h"
#include "CPiece.h"
#include <climits>
#include <fstream>

CLoadGameMenu::CLoadGameMenu(CAbstractMenuScreen * prPar /* =NULL*/) : CAbstractMenuScreen(prPar), loadSuccessful(false) {

    title = "Zadejte nazev souboru s ulozenou hrou:";
    setNumMenuItems();
}

CLoadGameMenu::~CLoadGameMenu() {

}

void CLoadGameMenu::setNextMenu() {

}

bool CLoadGameMenu::findFile(const string & file) const {

    ifstream ifs(file);
    if (!ifs.is_open())
        return false;

    return true;
}

int CLoadGameMenu::readInput() {

    string filestr;

    while (cin.good()) {

        cin >> filestr;

        if (!cin.good()) {

            filestr.clear();
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Nezdarilo se cteni vstupu, znovu prosim:" << endl;
            continue;
        }

        if (filestr == "BACK" || filestr == "back" || filestr == "Back") {
            delete nextMenu;
            nextMenu = prevMenu;
            return 0;
        }

        cout << "ZADANO: " << filestr << endl;

        if (!findFile(filestr)) {
            cout << "File \"" << filestr << "\" not found, try again." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }

        if (confirmLoad()) {
            fileGame = filestr;
            break;
        }

        return 0;
    }


    loadFromFile(fileGame);
    return 0;
}

bool CLoadGameMenu::confirmLoad() {
    cout << "Nalezen soubor se jmenem: " << fileGame << "." << endl;
    cout << "Chcete jej nacist? (A/N)" << endl;

    char c;

    while (cin.good()) {

        cin>>c;
        if (c == 'A')
            return true;
        else if (c == 'N') {

            delete nextMenu;
            nextMenu = prevMenu;
            return false;
        } else {
            cout << "Prosim zadejte A nebo N." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
    }

    cout << "Akce zrusena..." << endl;
    cin.ignore(INT_MAX, '\n');
    cin.clear();
    return false;
}

void CLoadGameMenu::setStuff(CController* ctrler) {

    if (loadSuccessful) {
        ctrler->getGameSess().gameBoard.copy(tmpboard);
        ctrler->getGameSess().setPlayerColors(tmpColor);        
        ctrler->setTurn(tmpTurn);

        ctrler->getGameSess().setGameReady();

    } else {
        cout << "Load wasnt successful." << endl;
    }

}

void CLoadGameMenu::loadFromFile(const string & filename) {

    ifstream ifs("filename");

    if (!ifs.is_open()) {
        cout << "stream failed to open or file not found" << endl;

        delete nextMenu;
        nextMenu = prevMenu;
        return;
    }

    string rowstr;

    for (int i = 7; i >= 0; --i) { // musim nacitat od 7 protoze prvni nahore v efilu jsou horni rows - tedy 7,6, ...
        getline(ifs, rowstr, '\n');
        if (!ifs.good()) {
            throw BadFileReadException();
        }
        for (int j = 0; j < 8; ++j) {

            CPiece * tmp = NULL;
            try {
                tmp = CPiece::getPieceByLetter(rowstr.at(j), i, j);
            } catch (InvalidFileCharacterException & ex) {
                cout << "Nonvalid character read. Cancelling loadfile." << endl;

                ifs.close();
                return;
            }
            tmpboard.setField(i, j, tmp);
        }
    }

    
    string meta;
    
    if (!(cin >> meta)) {
        cout << "nepovedlo se precist barvu hrace nebo turn" << endl;
        return;
    } 
   

        if (meta.size() != 2){
            
            if(meta.at(0) == 'W'){
                tmpColor = WHITE;
            }
            else if(meta.at(0) == 'B'){
                tmpColor = BLACK;
            }
            else{
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                ifs.close();
                return;
            }
            
            // druhej znak urcuje kdo je na rade s tahem
            
            if(meta.at(1) == 'W'){
                tmpTurn = WHITE;
                loadSuccessful = true;
            }
            else if(meta.at(1) == 'B'){
                tmpTurn = BLACK;
                loadSuccessful = true;
            }
            
            else{
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                ifs.close();
                return;
            }
            
    }

    cin.clear();
    cin.ignore(INT_MAX, '\n');
    ifs.close();
}