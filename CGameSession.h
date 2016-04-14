#ifndef CGAMESESSION_H
#define	CGAMESESSION_H

#include "CBoard.h"


class CGameSession {
public:
    CGameSession();
    CGameSession(const CGameSession& orig);
    virtual ~CGameSession();
    
    bool start();
private:

    CBoard gameBoard;
    CPiecesBox piecesBox;    
};



#endif	/* CGAMESESSION_H */

