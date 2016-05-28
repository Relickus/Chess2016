#ifndef CMENUHANDLER_H
#define	CMENUHANDLER_H

#include "CAbstractMenuScreen.h"


class CMenuHandler {
public:
    CMenuHandler();
    CMenuHandler(CAbstractMenuScreen * defMenu);
    virtual ~CMenuHandler();
private:

};


#endif	/* CMENUHANDLER_H */

