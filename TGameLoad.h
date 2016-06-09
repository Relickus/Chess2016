#ifndef TGAMELOAD_H
#define	TGAMELOAD_H

#include "CBoard.h"
#include "COLOR.h"

/**
 * A structure containing data used in game load
 */
struct TGameLoad {
    
    CBoard board;
    COLOR player1col;
    COLOR whosTurn;

};


#endif	/* TGAMELOAD_H */

