#ifndef COPPONENT_H
#define	COPPONENT_H

class COpponent {
public:
    COpponent();
    COpponent(const COpponent& orig);
    virtual ~COpponent();
    virtual void makeMove() const = 0;
    
private:

};




#endif	/* COPPONENT_H */

