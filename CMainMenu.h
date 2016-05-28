#ifndef CMAINMENU_H
#define	CMAINMENU_H

#include "CAbstractMenuScreen.h"

class CMainMenu : public CAbstractMenuScreen{
public:
    CMainMenu(CAbstractMenuScreen * prPar=NULL);
    CMainMenu(const CMainMenu& orig);
    virtual ~CMainMenu();
    virtual void setNextMenu();

    virtual void setStuff(CController* ctrler);


    
private:

};


#endif	/* CMAINMENU_H */

