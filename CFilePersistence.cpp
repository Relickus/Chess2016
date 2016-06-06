#include <iostream>
#include <fstream>
#include "CFilePersistence.h"
#include "CPiece.h"
#include "CPlayer.h"
#include "CGameSession.h"

using namespace std;

CFilePersistence::CFilePersistence(CGameSession* gamePtr) : CPersistence(gamePtr){
}

CFilePersistence::CFilePersistence() : CPersistence() {
}


bool CFilePersistence::load(const char * file) const {
    
     
//        ifstream ifs( file );
//
//        if( ! ifs.is_open() ){
//            
//            cout << "Nepodarilo se nacist soubor \""<< file <<"\" "<<endl;
//            return false;
//        }

}

void CFilePersistence::save() const {
     
    string savefile;
    
    cout << "Zadejte nazev souboru:"<<endl;
    
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
            cout << "Nepovedlo se vytvorit soubor, zadejte jiny nazev:" << endl;
        }
        else
            break;
    }
    
    string line;
    string tmp;
    
    for(int i=7; i >=0 ;--i ){
        for (int j = 0; j < 8; j++) {
            
            CPiece * pcs =  gamePtr->gameBoard.getPiece(i,j);  
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
    
    ofs << gamePtr->player1->getPlayerColor()<<gamePtr->whosTurn;
    cout << "Hra uspesne ulozena."<<endl;
    ofs.close();
}
