#ifndef CPERSISTENCE_H
#define	CPERSISTENCE_H

class CPersistence {
public:
    CPersistence();
    CPersistence(const CPersistence& orig);
    virtual ~CPersistence();
    virtual bool saveGame() const = 0;
    virtual bool loadGame(const char * file) const = 0;
    
private:

};



#endif	/* CPERSISTENCE_H */

