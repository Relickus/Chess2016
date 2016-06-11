#include <iostream>
#include <fstream>
#include <climits>
#include "AllExceptions.h"
#include "CFilePersistence.h"
#include "CPiece.h"
#include "CPlayer.h"
#include "CGameSession.h"
#include "TGameLoad.h"

using namespace std;

CFilePersistence::CFilePersistence(CGameSession* gamePtr) : CPersistence(gamePtr){
}

CFilePersistence::~CFilePersistence() {

}


CFilePersistence::CFilePersistence() : CPersistence() {
}


bool CFilePersistence::load(const string & filename) {
        
ifstream ifs(filename);

    if (!ifs.is_open()) {
        cout << "Stream se nepovedlo otevřít." << endl;

        return false;
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
                cout << "Nevalidní znak v souboru. Končím načítání." << endl;

                ifs.close();
                return false;
            }
            
            tLoad.board.setField(i, j, tmp);
        }
    }

    
    string meta;
    
    if (!(ifs >> meta)) {
        cout << "Nepovedlo se přečíst barvu hráče nebo tah." << endl;
        ifs.close();
        return false;
    } 
   
    if (meta.size() == 2){
    
        if(meta.at(0) == 'W'){
            tLoad.player1col = WHITE;
        }
        else if(meta.at(0) == 'B'){
            tLoad.player1col = BLACK;
        }
        else{
             cout << "Chybný formát metadat souboru." << endl;
             ifs.close();
            return false;
        }
            // druhej znak urcuje kdo je na rade s tahem
        
        if(meta.at(1) == 'W'){
            tLoad.whosTurn = WHITE;
            ifs.close();
            return true;
        }
        else if(meta.at(1) == 'B'){
            tLoad.whosTurn = BLACK;
            ifs.close();
            return true;
        }
        else{
             cout << "Chybný formát metadat souboru." << endl;
             ifs.close();
            return false;
        }
    }
    
    cout << "Chybný formát metadat souboru." << endl;        
    ifs.close();
    return false;
}

void CFilePersistence::save() const {
     
    string savefile;
    
    cout << "Zadejte název souboru:"<<endl;
    
    ofstream ofs;
    while(true){

        cin.clear();
        //cin.ignore();
        getline(cin,savefile);
        ofs.open(savefile);

        if(!cin.good() || !ofs.good()){
            ofs.clear();
            cin.clear();
            savefile.clear();
            cout << "Nepovedlo se vytvořit soubor, zadejte jiný název:" << endl;
        }
        else
            break;
    }
    
    string line;
    string tmp;
    
    for(int i=7; i >=0 ;--i ){
        for (int j = 0; j < 8; j++) {
            
            CPiece * pcs =  gamePtr->getBoard().getPiece(i,j);  
            if(pcs == NULL){
                line+='#';
                continue;
            }
            if(pcs->getColor() == WHITE){
                tmp = toupper(pcs->getName());
            }
            else{
                tmp = tolower(pcs->getName());
            }
            line+= tmp;
        }
        line += '\n';
        ofs << line;
        line.clear();                
    }
    
    gamePtr->player1->printPlayerColor(ofs);    // ulozi tam jakou barvu ma hrac 1
    gamePtr->currPlayerPtr->printPlayerColor(ofs);  // ulozi tam znak kdo je na rade
    
    cout << "Hra úspěšně uložena."<<endl;
    ofs.close();
}
