#ifndef CFILEPERSISTENCE_H
#define	CFILEPERSISTENCE_H

#include "CPersistence.h"

class CFilePersistence : public CPersistence {
public:
    CFilePersistence();
    CFilePersistence(CGameSession * gamePtr);
    void save() const;
    bool load(const char * file) const;
    
private:

};



#endif	/* CFILEPERSISTENCE_H */

