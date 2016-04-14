#ifndef CPERSISTENCE_H
#define	CPERSISTENCE_H

class CPersistence {
public:
    CPersistence();
    CPersistence(const CPersistence& orig);
    virtual ~CPersistence();
    bool saveGame() const;
    bool loadGame(const char * file) const;
    
private:

};



#endif	/* CPERSISTENCE_H */

