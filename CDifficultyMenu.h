#ifndef CDIFFICULTYMENU_H
#define	CDIFFICULTYMENU_H

#include "CAbstractMenuScreen.h"

/**
 * Subclass of CAbstractMenuScreen for choosing difficulty of AI in a game against PC
 */
class CDifficultyMenu : public CAbstractMenuScreen{
public:
     /**
     * @brief Initializes the menu
     * 
     * @param Pointer to the previous menu
     */
    CDifficultyMenu(CAbstractMenuScreen * prPar=NULL);
    virtual ~CDifficultyMenu();
    
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



#endif	/* CDIFFICULTYMENU_H */

