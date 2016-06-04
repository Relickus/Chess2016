#include <cstdlib>

#include "CController.h"
#include "CPiece.h"
#include "CKing.h"

using namespace std;

int main(int argc, char** argv) {
        
    CController * c = new CController();

    c->showMenus();
    
    c->startGame();
    
//    CBoard & brd = c->getGameSess().gameBoard;
//
//    
//    brd.rotateBoard();
//    
//    brd.printBoard();
//    
//    MoveList l = brd.getPiece(1,3)->getLegalMoves(brd);
//    
//    l.print();
//    
//    brd.printPossibleMoves(l);
//    
//    
//   brd.getPiece(1,4)->moveTo(MyMove(3,4),brd);
//   brd.getPiece(1,3)->moveTo(MyMove(3,3),brd);
//   
//   brd.printBoard();
//   
//   l = brd.getPiece(0,4)->getLegalMoves(brd);
//
//   brd.printPossibleMoves(l);
//   
//   brd.getPiece(3,4)->moveTo(MyMove(1,3),brd);
   
   
    
//    
//    CKing * k = dynamic_cast<CKing*>(c->getGameSess().gameBoard.getPiece(0,4));
//    
//    cout<<endl << k->getName();
//    CBoard & b =c->getGameSess().gameBoard;
//    
//    cout << k->isChecked(b);
//    
    delete c;
    return 0;
}

