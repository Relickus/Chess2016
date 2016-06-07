#ifndef CMULTIPLAYERHOSTMENU_H
#define	CMULTIPLAYERHOSTMENU_H

#include "CAbstractMenuScreen.h"
#include "CNetworking.h"


class CMultiplayerHostMenu : public CAbstractMenuScreen{
public:
    CMultiplayerHostMenu(CAbstractMenuScreen * prPar=NULL);
    CMultiplayerHostMenu(const CMultiplayerHostMenu& orig);
    virtual ~CMultiplayerHostMenu();

    virtual void setStuff(CController* ctrler);
    virtual void setNextMenu();
    virtual void show() const;
    virtual int readInput();

private:

    CNetworking net;
};



#endif	/* CMULTIPLAYERHOSTMENU_H */

