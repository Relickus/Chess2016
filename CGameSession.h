#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "COpponent.h"
#include "COLOR.h"
#include <iostream>
#include "CBoard.h"


using namespace std;

class CGameSession {
public:
    CGameSession();
    CGameSession(const CGameSession & orig);
    virtual ~CGameSession();
    
    void start();
    void end();
    
    const CBoard & getBoard() const;
    
    CBoard gameBoard;
    COLOR player1color;
    string ipHost;
    COpponent * opponent;
    string fileName;
    int difficulty;
    
    
private:        /// !!!!!!!!! gettery a settery
    
    
    
};



#endif	/* CGAMESESSION_H */

