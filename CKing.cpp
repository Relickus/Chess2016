#include "CKing.h"
#include "CPiece.h"
#include "CBoard.h"
#include "CGameSession.h"


CKing::CKing() {
    name = KING;
    

    moveList.reserve(10);
    value = 50;

}

CKing::~CKing() {

}

CKing::CKing(COLOR clr , int row, int col) : CPiece(clr,row,col) {
    name = KING;
    

    moveList.reserve(10);
    value = 50;

}

MoveList & CKing::getLegalMoves(const CGameSession & gS) {

    moveList.clear();

    //up left

    int newRow = getRow() - 1;
    int newCol = getCol() + 1;

    this->checkField(newRow, newCol, gS.getBoard());

    // up right

    newRow = getRow() + 1;
    newCol = getCol() + 1;

    this->checkField(newRow, newCol, gS.getBoard());

    // down left

    newRow = getRow() - 1;
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, gS.getBoard());

    // down right

    newRow = getRow() + 1;
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, gS.getBoard());

    // up 

    newRow = getRow();
    newCol = getCol() + 1;

    this->checkField(newRow, newCol, gS.getBoard());
    // down

    newRow = getRow();
    newCol = getCol() - 1;

    this->checkField(newRow, newCol, gS.getBoard());
    // left

    newRow = getRow() - 1;
    newCol = getCol();

    this->checkField(newRow, newCol, gS.getBoard());
    // right

    newRow = getRow() + 1;
    newCol = getCol();

    this->checkField(newRow, newCol, gS.getBoard());


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
        } 
        else {  //kral bere figurku
    
        moveList.add(x, y,rowPos,colPos,tmp);
        return 1;
            
        }
    } else {
        moveList.add(x, y,rowPos,colPos,NULL);
        return 1;
    }
}

bool CKing::isChecked(const CBoard & board, bool currentPlayerDown) const {
    
    //search left up diagonal for checking enemy pieces 
    int newRow = getRow()+1;
    int newCol = getCol()-1;
    
    while(!board.outOfBoard(newRow,newCol)){
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow++;
            newCol--;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
                
            if( board.getPiece(newRow,newCol)->equals(KING)){  //na diagonale NEKDE ciha pawn nebo king
                if(newRow == getRow()+1 && newCol == getCol()-1){ // je v dosahu na sach
                    return true;
                }
                else    // neni v dosahu - je neskodnej
                    break;
            }
            else if( board.getPiece(newRow,newCol)->equals(PAWN)){
                if(currentPlayerDown && newRow == getRow()+1 && newCol == getCol()-1)
                    return true;
                else
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow++;
            newCol++;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
                
            if( board.getPiece(newRow,newCol)->equals(KING)){  //na diagonale NEKDE ciha pawn nebo king
                if(newRow == getRow()+1 && newCol == getCol()+1){ // je v dosahu
                    return true;
                }
                else    // neni v dosahu - je neskodnej
                    break;
            }
            else if( board.getPiece(newRow,newCol)->equals(PAWN)){
                if(currentPlayerDown && newRow == getRow()+1 && newCol == getCol()+1)
                    return true;
                else
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow--;
            newCol--;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(KING) && newCol == getCol()-1 && newRow == getRow()-1 ){ // v dosahu ciha king
                    return true;
            }
           else if( board.getPiece(newRow,newCol)->equals(PAWN)){
                if( currentPlayerDown==false && newRow == getRow()-1 && newCol == getCol()-1)
                    return true;
                else 
                    break;
           }
            else if( board.getPiece(newRow,newCol)->equals(BISHOP)  //na diagonale NEKDE ciha pawn nebo king
            ||  board.getPiece(newRow,newCol)->equals(QUEEN)){
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow--;
            newCol++;        
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
             
            if( board.getPiece(newRow,newCol)->equals(KING) && newCol == getCol()+1 && newRow == getRow()-1){ // v dosahu ciha king
                return true;
            }
            else if( board.getPiece(newRow,newCol)->equals(PAWN)){
                if( currentPlayerDown==false && newRow == getRow()-1 && newCol == getCol()+1)
                    return true;
                else
                    break;
            }
            else if( board.getPiece(newRow,newCol)->equals(BISHOP)
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newCol++;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
               
            if( board.getPiece(newRow,newCol)->equals(KING) && newCol == getCol()+1){  // v dosahu ciha king
                    return true;
            }
            else if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){
                
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newCol--;
            continue;        
        }          
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
            
            if( board.getPiece(newRow,newCol)->equals(KING) && newCol == getCol()-1){    // v dosahu ciha king
                return true;
            }
            else if( board.getPiece(newRow,newCol)->equals(TOWER)
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow--;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
           
            if( board.getPiece(newRow,newCol)->equals(KING) && newRow == getRow()-1){  // v dosahu ciha king
                    return true;
            }
            else if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN)  ){ 
                
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
        
        if(board.getPiece(newRow,newCol) == NULL){
            newRow++;
            continue;        
        }
                        
        if(board.getPiece(newRow,newCol)->isFriendPiece(this))    //friend figure
                break;
        
         else{   // enemy figure
              
            if( board.getPiece(newRow,newCol)->equals(KING) && newRow == getRow()+1 ){  // v dosahu ciha king
                    return true;
            }
            else if( board.getPiece(newRow,newCol)->equals(TOWER)
            ||  board.getPiece(newRow,newCol)->equals(QUEEN) ){
                
                return true;                
            }
            else
                break;
        }
        
        newRow = newRow++;
    }
    return false;
    
    
}

CPiece* CKing::copyPiece(const CPiece* pcs) const{
    return new CKing(pcs->getColor(),pcs->getRow(),pcs->getCol());
}