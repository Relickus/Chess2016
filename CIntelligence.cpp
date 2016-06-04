#include "CIntelligence.h"
#include "DIFFICULTY.h"
#include "CPiece.h"
#include "CCommand.h"
#include "CPawn.h"

CIntelligence::CIntelligence(){
}

CIntelligence::CIntelligence(int d) : difficulty(d) {
    
}

void CIntelligence::changeDifficulty(int d) {
    difficulty = d;
}

CIntelligence::~CIntelligence(){}

void CIntelligence::think() const{   
    
    // TODO   Minimax
    
}

MyMove CIntelligence::getMove(CGameSession & gS){
    
    allMoves.clear();
    
    findAllFigures(gS.gameBoard);    
    
    for(size_t i = 0; i < figuresVec.size(); ++i){
        MoveList l;
        if(figuresVec.at(i)->getName() == PAWN){
            CPawn * pwn = dynamic_cast<CPawn*>(figuresVec.at(i));
            l = pwn->getLegalMovesDown(gS.gameBoard);
        }
        else
            l = figuresVec.at(i)->getLegalMoves(gS.gameBoard); 
        
        allMoves.concat(l); 
    }
    
    allMoves.print();
    
    // minimax vyhodi nejakej move a vrati ho...
    
    srand(time(NULL));
    //int randIdx = rand() % (allMoves.size());
    //
    int bestIdx = getBestIdx(allMoves,gS.gameBoard);
    
    return allMoves.getMove(.....Idx);    
}

CCommand CIntelligence::getCommand(CGameSession & gS) {
    
    return CCommand(getMove(gS));
}

int CIntelligence::getBestIdx(MoveList& list,CBoard & board) const {

    int bestAvg = 99;
    int bestIdx = -1;
    
    
    for (int i = 0; i < list.size(); i++) {
        list.getMove(i).figure->getValue();

    }

    
    for (int i = 0; i < list.size(); i++) {
        
        MyMove tmp = list.getMove(i);
        board.getSlotValue(tmp.toX,tmp.toY);

    }

    
}
