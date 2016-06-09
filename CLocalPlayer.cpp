#include "AllExceptions.h"
#include "CLocalPlayer.h"
#include "CGameSession.h"
#include "CPawn.h"
#include "CCommand.h"
#include <climits>

MyMove CLocalPlayer::getMove(const CGameSession& gS, int cliSocket){
}


void CLocalPlayer::badInput() const{
    
    cout << "Bad input, read manual before playing." << endl;        
}

string CLocalPlayer::readInput() const{
                   
    string tmpstr;
    MyMove fict(-1,-1,-1,-1);
    CCommand com;
    
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
    
    cout<<"Na tahu je "<< (gS.currentPlayer == WHITE ? "BILY" : "CERNY") <<endl;
    cout<<"Zadejte prikaz:"<<endl;        
    tmp = readInput(); 
    
    }catch(BadInputException & ex){
        cout << "Bad input exc." << endl;
        return CCommand(UNKNOWN);
    }
     
    try{
    com.makeCommand(tmp);   // naplni com zadanym commandem od uzivatele
    }catch(BadCommandException & ex){
        cout << "Neplatny command" << endl;
        return CCommand(UNKNOWN);
    }
    return com;
}
