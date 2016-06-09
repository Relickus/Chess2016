#ifndef CMAINMENU_H
#define	CMAINMENU_H

#include "CAbstractMenuScreen.h"

class CMainMenu : public CAbstractMenuScreen{
public:
    CMainMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CMainMenu();
    virtual void setNextMenu();

    virtual void setStuff(CController* ctrler);
};


#endif	/* CMAINMENU_H */

