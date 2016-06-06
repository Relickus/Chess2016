#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "COLOR.h"
#include <iostream>
#include "CBoard.h"

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

    
    CBoard gameBoard;
    COLOR currentPlayer;
    CPlayer * currPlayerPtr;
    string ipHost;
    string fileName;
    bool ready_flag;
    COLOR whosTurn;
    bool exitRequest;
    CPersistence * persistence;
    bool movePerformed;
    
    CPlayer * player1;
    CPlayer * player2;

    
private:        /// !!!!!!!!! gettery a settery
    
    
    
};



#endif	/* CGAMESESSION_H */

