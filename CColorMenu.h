#ifndef CCOLORMENU_H
#define	CCOLORMENU_H

#include "CAbstractMenuScreen.h"

/**
 * Subclass of CAbstractMenuScreen for choosing a player's color
 */
class CColorMenu : public CAbstractMenuScreen{
public:
     /**
     * @brief Initializes the menu
     * 
     * @param Pointer to the previous menu
     */
    CColorMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CColorMenu();
    /**
     * @brief Sets pointer to next menu
     * 
     */
    virtual void setNextMenu();
   /**
     * @brief Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController * ctrler);

};


#endif	/* CCOLORMENU_H */

