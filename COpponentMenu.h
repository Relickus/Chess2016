
#ifndef COPPONENTMENU_H
#define	COPPONENTMENU_H

#include "CAbstractMenuScreen.h"
class CPlayer;

class COpponentMenu : public CAbstractMenuScreen{
public:
    COpponentMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~COpponentMenu();   
    void setNextMenu();

    virtual void setStuff(CController* ctrler);

};


#endif	/* COPPONENTMENU_H */

