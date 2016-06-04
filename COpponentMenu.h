
#ifndef COPPONENTMENU_H
#define	COPPONENTMENU_H

#include "CAbstractMenuScreen.h"
#include "CPlayer.h"


class COpponentMenu : public CAbstractMenuScreen{
public:
    COpponentMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~COpponentMenu();   
    CPlayer * getOpponent() const;
    void setNextMenu();

    virtual void setStuff(CController* ctrler);

    
private:

};


#endif	/* COPPONENTMENU_H */

