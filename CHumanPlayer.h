#ifndef CHUMANPLAYER_H
#define	CHUMANPLAYER_H

#include "COpponent.h"

class CHumanPlayer : COpponent{
public:
    CHumanPlayer();
    CHumanPlayer(const CHumanPlayer& orig);
    virtual ~CHumanPlayer();
    void makeMove() const; 
    
private:

};




#endif	/* CHUMANPLAYER_H */

