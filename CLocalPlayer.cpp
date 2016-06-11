#include "AllExceptions.h"
#include "CLocalPlayer.h"
#include "CGameSession.h"
#include "CPawn.h"
#include "CCommand.h"
#include <climits>

//CMyMove CLocalPlayer::getMove(const CGameSession& gS, int cliSocket){
//}


void CLocalPlayer::badInput() const{
    
    cout << "Špatný vstup, přečtěte si manuál ke hře." << endl;        
}

string CLocalPlayer::readInput() const{
                   
    string tmpstr;
    
    getline(cin,tmpstr);
        
    if(!cin.good() || tmpstr.empty()){
        throw BadInputException();
    }  
    
    return tmpstr;
}
CLocalPlayer::CLocalPlayer() {

}

CLocalPlayer::~CLocalPlayer() {

}

CCommand CLocalPlayer::getCommand(const CGameSession & gS){

    CCommand com;
    string tmp;
    
    try{
    
    cout<<"Na tahu je "<< (gS.currentPlayer == WHITE ? "BÍLÝ" : "ČERNÝ") <<endl;
    cout<<"Zadejte příkaz:"<<endl;        
    tmp = readInput(); 
    
    }catch(BadInputException & ex){
        cout << "Vyhozena vyjímka BadInput." << endl;
        return CCommand(UNKNOWN);
    }
     
    try{
    com.makeCommand(tmp);   // naplni com zadanym commandem od uzivatele
    }catch(BadCommandException & ex){
        cout << "Neplatný příkaz." << endl;
        return CCommand(UNKNOWN);
    }
    return com;
}
