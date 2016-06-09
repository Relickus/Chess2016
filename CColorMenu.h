#ifndef CCOLORMENU_H
#define	CCOLORMENU_H

#include "CAbstractMenuScreen.h"

class CColorMenu : public CAbstractMenuScreen{
public:
    CColorMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CColorMenu();
    virtual void setNextMenu();
    virtual void setStuff(CController * ctrler);

};


#endif	/* CCOLORMENU_H */

