#ifndef CGUI_H
#define	CGUI_H

#include "CBoard.h"

class CGUI {
public:
    CGUI();
    CGUI(const CGUI& orig);
    virtual ~CGUI();
    void printBoard(const CBoard & board) const;
private:

};


#endif	/* CGUI_H */

