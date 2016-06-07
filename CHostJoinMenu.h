#ifndef CHOSTJOINMENU_H
#define	CHOSTJOINMENU_H

#include "CAbstractMenuScreen.h"
#include "CNetworking.h"

class CHostJoinMenu : public CAbstractMenuScreen{
public:

    CHostJoinMenu(CAbstractMenuScreen* prPar = NULL);
    virtual ~CHostJoinMenu();
   

    virtual void setStuff(CController* ctrler);
    virtual void setNextMenu();


private:

    CNetworking net;
};



#endif	/* CHOSTJOINMENU_H */

