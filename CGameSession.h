#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "COLOR.h"
#include <iostream>
#include "CBoard.h"
#include "CNetworking.h"
#include "CServer.h"

class CPersistence;
class CPlayer;

using namespace std;

class CGameSession {
public:
    static bool validateMove(const string & move);
    static bool validatePos(const string & move);
    
    CGameSession();
    ~CGameSession();
    
    void start();
    void end();
    
    const CBoard & getBoard() const;
    void setGameReady();
    bool gameReady() const;
    void setPlayerColors(COLOR col);
    void setTurn(COLOR col);
    bool performMove(const MyMove & move);
    void switchPlayers();
    bool isCheckMate() const;
    void assignKings();
    void updateKings();
    bool isTie() const;
    void netGameInit();

    
    COLOR currentPlayer;
    string ipHost;
    string fileName;
    bool ready_flag;
    COLOR whosTurn;
    bool exitRequest;
    bool movePerformed;
    bool onlineGame;
    
    CPlayer * player1;
    CPlayer * player2;
    CPlayer * currPlayerPtr;
    CPersistence * persistence;
    
    CNetworking networking;
    CServer server;
    
private:       
    CBoard gameBoard;
    
   friend class CLoadGameMenu; 
    
};



#endif	/* CGAMESESSION_H */

