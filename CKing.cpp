#include "CKing.h"
#include "CPiece.h"
#include "CBoard.h"

CKing::CKing() {
    name = KING;
    isLongRunner = false;

    moveList.reserve(10);
    value = 50;

}

CKing::~CKing() {

}

CKing::CKing(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = KING;
    isLongRunner = false;

    moveList.reserve(10);
    value = 50;

}
//
//void CKing::printPiece() const{
//        
//}

MoveList & CKing::getLegalMoves(const CBoard & board) {

    moveList.clear();

    //up left

    int newRow = getRow() - 1;
    int newCol = getCol() + 1;

    this->checkField(newRow, newCol, board);

    // up right

    newRow = getRow() + 1;
    newCol = getCol() + 1;

    this->checkField(newRow, newCol, board);

    // down left

    newRow = getRow() - 1;
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, board);

    // down right

    newRow = getRow() + 1;
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, board);

    // up 

    newRow = getRow();
    newCol = getCol() + 1;

    this->checkField(newRow, newCol, board);
    // down

    newRow = getRow();
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, board);
    // left

    newRow = getRow() - 1;
    newCol = getCol();

    this->checkField(newRow, newCol, board);
    // right

    newRow = getRow() + 1;
    newCol = getCol();

    this->checkField(newRow, newCol, board);


    return moveList;
}

int CKing::checkField(int x, int y, const CBoard& board) {

    if (board.outOfBoard(x, y))
        return 1;

    if (x == getRow() && y == getCol())
        return 0;

    CPiece * tmp = board.getPiece(x, y);

    if (tmp != NULL) {
        if (isFriendPiece(tmp)) {
            return 1;
        } else {
            // ....... VEZMI JI - LEGAL JEN POKUD SE NEDOSTANE DO SACHU                
//            if (!board.fieldChecked(x,y,tmp)) {
//                moveList.add(x, y, board.getPiece(x, y));
//                return 1;
//            } else {
//                return 1;
//            }
        }
    } else {
        moveList.add(x, y,rowPos,colPos);
        return 1;
    }
}

bool CKing::isChecked(const CBoard & board) const {
    
    //search left up diagonal for checking enemy pieces 
    int newRow = getRow()+1;
    int newCol = getCol()-1;
    
    while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
                
            if( board.getPiece(newRow,newCol)->equals(PAWN) ){  //na diagonale NEKDE ciha pawn
                if(newRow == getRow()-1 && newCol == getCol()+1){ // je v dosahu
                    return true;
                }
                else    // neni v dosahu - je neskodnej
                    break;
            }
            else if( board.getPiece(newRow,newCol)->equals(BISHOP)
                 ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){ // na diagonale sachujou bishop nebo queen
                
                return true;
                
            }
            else
                break;
        }
        
        newRow = newRow++;
        newCol = newCol--;
    }
    
    // right up
    
    newRow = getRow()+1;
    newCol = getCol()+1;
    
    while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
                
            if( board.getPiece(newRow,newCol)->equals(PAWN) ){  //na diagonale NEKDE ciha pawn
                if(newRow == getRow()-1 && newCol == getCol()+1){ // je v dosahu
                    return true;
                }
                else    // neni v dosahu - je neskodnej
                    break;
            }
            else if( board.getPiece(newRow,newCol)->equals(BISHOP)
                 ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){ // na diagonale sachujou bishop nebo queen
                
                return true;
                
            }
            else
                break;
        }
        
        newRow = newRow++;
        newCol = newCol++;
    }
     
     // left down
    
     newRow = getRow()-1;
     newCol = getCol()-1;
     
    while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(BISHOP)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){ // na diagonale sachujou bishop nebo queen
                
                return true;                
            }
            else
                break;
        }
        
        newRow = newRow--;
        newCol = newCol--;
    }
     
     // right down
    
     newRow = getRow()-1;
     newCol = getCol()+1;
     
     while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(BISHOP)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN)  ){ // na diagonale sachujou bishop nebo queen
                
                return true;                
            }
            else
                break;
        }
        
        newRow = newRow--;
        newCol = newCol++;
    }
     
      // right
    
     newRow = getRow();
     newCol = getCol()+1;
     
     while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){ // na diagonale sachujou bishop nebo queen
                
                return true;                
            }
            else
                break;
        }
        
        newCol = newCol++;
    }
     
      // left
    
     newRow = getRow();
     newCol = getCol()-1;
     
     while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN)  ){ 
                
                return true;                
            }
            else
                break;
        }
        
        newCol = newCol--;
    }
      // down
    
     newRow = getRow()-1;
     newCol = getCol();
     
     while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN)  ){ // na diagonale sachujou bishop nebo queen
                
                return true;                
            }
            else
                break;
        }
        
        newRow = newRow--;
    }
    
      // up
    
     newRow = getRow()+1;
     newCol = getCol();
     
     while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL)
            continue;        
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){ // na diagonale sachujou bishop nebo queen
                
                return true;                
            }
            else
                break;
        }
        
        newRow = newRow++;
    }
    return false;
    
    
}
