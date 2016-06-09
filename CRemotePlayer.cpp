#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// -------------- includy pro sitovani ---------------

#include "CRemotePlayer.h"
#include "CGameSession.h"
#include "CCommand.h"

using namespace std;

CRemotePlayer::CRemotePlayer(int socket) : cliSocket(socket) {

}

CCommand CRemotePlayer::getCommand(const CGameSession& gS) {

    MyMove m = getMove(gS,cliSocket);
    MyMove exitm(-2,-2,-2,-2);
    if(m.isFicture()){
        return CCommand(SURRENDER);
    }
    else if(m == exitm){
        return CCommand(EXIT);
    }
    m.rotateMove();
    m.printMove();      
    m.figure = gS.getBoard().getPiece(m.toX,m.toY);
    
    return CCommand(m);
}

MyMove CRemotePlayer::getMove(const CGameSession& gS,int cliSocket) {

    return gS.networking.getMove(cliSocket);
}

int CRemotePlayer::getSocket() const {
    return cliSocket;
}
