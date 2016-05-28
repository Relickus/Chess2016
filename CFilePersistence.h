#ifndef CFILEPERSISTENCE_H
#define	CFILEPERSISTENCE_H

#include "CPersistence.h"

class CFilePersistence : public CPersistence {
public:
    CFilePersistence();
    CFilePersistence(const CFilePersistence& orig);
    virtual ~CFilePersistence();
    bool saveGame() const;
    bool loadGame(const char * file) const;
    
private:

};



#endif	/* CFILEPERSISTENCE_H */

