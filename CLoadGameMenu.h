#ifndef CLOADGAMEMENU_H
#define	CLOADGAMEMENU_H

#include "CAbstractMenuScreen.h"


class CLoadGameMenu : public CAbstractMenuScreen {
public:
    CLoadGameMenu(CAbstractMenuScreen * prPar=NULL);
    CLoadGameMenu(const CLoadGameMenu& orig);
    virtual ~CLoadGameMenu();
    virtual void setNextMenu();
    int readInput();

    virtual void setStuff(CController* ctrler);



private:
    
    string fileGame;

};


#endif	/* CLOADGAMEMENU_H */

