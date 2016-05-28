#ifndef CMULTIPLAYERONLINEMENU_H
#define	CMULTIPLAYERONLINEMENU_H

#include "CAbstractMenuScreen.h"


class CMultiplayerOnlineMenu : public CAbstractMenuScreen{
public:
    CMultiplayerOnlineMenu(CAbstractMenuScreen * prPar=NULL);
    CMultiplayerOnlineMenu(const CMultiplayerOnlineMenu& orig);
    virtual ~CMultiplayerOnlineMenu();
    virtual void setNextMenu();
    int readInput();
    bool validIP(const string & ip) const;

    virtual void setStuff(CController* ctrler);


private:

    string IP;
};



#endif	/* CMULTIPLAYERONLINEMENU_H */

