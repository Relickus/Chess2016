#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "COLOR.h"
#include <iostream>
#include "CBoard.h"
#include "CNetworking.h"

class CPersistence;
class CPlayer;

using namespace std;

class CGameSession {
public:
    CGameSession();
    virtual ~CGameSession();
    
    void start();
    void end();
    
    CBoard & getBoard();
    void setGameReady();
    bool gameReady() const;
    void setPlayerColors(COLOR col);
    void setTurn(COLOR col);
    static bool validateMove(const string & move);
    static bool validatePos(const string & move);
    MyMove waitForMove();    
    bool performMove(const MyMove & move);
    bool movesQuery(string & str);
    void switchPlayers();
    bool isCheckMate();
    void assignKings();
    void updateKings();
    bool isTie() const;

    
    CBoard gameBoard;
    COLOR currentPlayer;
    string ipHost;
    string fileName;
    bool ready_flag;
    COLOR whosTurn;
    bool exitRequest;
    bool movePerformed;
    
    CPlayer * player1;
    CPlayer * player2;
    CPlayer * currPlayerPtr;
    CPersistence * persistence;
    
private:       
    
    
    
};



#endif	/* CGAMESESSION_H */

