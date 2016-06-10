
#ifndef COPPONENTMENU_H
#define	COPPONENTMENU_H

#include "CAbstractMenuScreen.h"
class CPlayer;

/**
 * Subclass of CAbstractMenuScreen for choosing a type of opponent (Local human,Remote human, AI) in Multiplayer game
 */
class COpponentMenu : public CAbstractMenuScreen{
public:
     /**
     * @brief Initializes the menu
     * 
     * @param Pointer to the previous menu
     */
    COpponentMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~COpponentMenu();   
       /**
     * Sets next menu
     * 
     */
    virtual void setNextMenu();
   /**
     * @brief Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController* ctrler);

};


#endif	/* COPPONENTMENU_H */

