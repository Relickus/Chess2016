
#ifndef COPPONENTMENU_H
#define	COPPONENTMENU_H

#include "CAbstractMenuScreen.h"
#include "COpponent.h"


class COpponentMenu : public CAbstractMenuScreen{
public:
    COpponentMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~COpponentMenu();   
    COpponent * getOpponent() const;
    void setNextMenu();

    virtual void setStuff(CController* ctrler);

    
private:

};


#endif	/* COPPONENTMENU_H */

