#include <cstdlib>

#include "CController.h"
#include "CPiece.h"
#include "CKing.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
        
    CController * c = new CController();

    c->showMenus();
    
    c->getGameSess().start();
    
    MoveList l = c->getGameSess().gameBoard.getPiece(0,1)->getLegalMoves(c->getGameSess().gameBoard);
    
    l.print();
    
    c->getGameSess().gameBoard.printPossibleMoves(l);
//    
//    CKing * k = dynamic_cast<CKing*>(c->getGameSess().gameBoard.getPiece(0,4));
//    
//    cout<<endl << k->getName();
//    CBoard & b =c->getGameSess().gameBoard;
//    
//    cout << k->isChecked(b);
//    
    c->endGame();
    delete c;
    return 0;
}

