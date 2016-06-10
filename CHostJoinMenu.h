#ifndef CHOSTJOINMENU_H
#define	CHOSTJOINMENU_H

#include "CAbstractMenuScreen.h"
#include "CNetworking.h"

/**
 * Subclass of CAbstractMenuScreen for hosting a game server and joining it
 */
class CHostJoinMenu : public CAbstractMenuScreen{
public:
 /**
     *  Initializes the menu
     * 
     * @param Pointer to the previous menu
     */
    CHostJoinMenu(CAbstractMenuScreen* prPar = NULL);
    virtual ~CHostJoinMenu();
   
      /**
     *  Sets whatever there is to be set from this menu that is needed for game initialization or starts a game server
     * 
     */
    virtual void setStuff(CController* ctrler);
     
    /**
     *  Sets pointer to next menu
     * 
     */
    virtual void setNextMenu();

};



#endif	/* CHOSTJOINMENU_H */

