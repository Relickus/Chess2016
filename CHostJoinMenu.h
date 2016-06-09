#ifndef CHOSTJOINMENU_H
#define	CHOSTJOINMENU_H

#include "CAbstractMenuScreen.h"
#include "CNetworking.h"

class CHostJoinMenu : public CAbstractMenuScreen{
public:
 /**
     * @brief Initializes a menu
     * 
     * @param Pointer to the previous menu
     */
    CHostJoinMenu(CAbstractMenuScreen* prPar = NULL);
    virtual ~CHostJoinMenu();
   
      /**
     * @brief Sets whatever there is to be set from this menu that is needed for game initialization
     * 
     */
    virtual void setStuff(CController* ctrler);
     
    /**
     * @brief Sets pointer to next menu
     * 
     */
    virtual void setNextMenu();

};



#endif	/* CHOSTJOINMENU_H */

