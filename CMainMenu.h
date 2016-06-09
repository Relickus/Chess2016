#ifndef CMAINMENU_H
#define	CMAINMENU_H

#include "CAbstractMenuScreen.h"

class CMainMenu : public CAbstractMenuScreen{
public:
     /**
     * @brief Initializes a menu
     * 
     * @param Pointer to the previous menu
     */
    CMainMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CMainMenu();
        /**
     * @brief Sets pointer to next menu
     * 
     */
    virtual void setNextMenu();
   /**
     * @brief Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController* ctrler);
};


#endif	/* CMAINMENU_H */

