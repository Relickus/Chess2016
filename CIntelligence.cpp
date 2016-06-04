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
    
    int bestIdx = getBestIdx(allMoves,gS.gameBoard);
    
    return allMoves.getMove(bestIdx);    
}

CCommand CIntelligence::getCommand(CGameSession & gS) {
    
    return CCommand(getMove(gS));
}

int CIntelligence::getBestIdx(MoveList& list,CBoard & board) const {

    if(difficulty == 0){
        srand(time(NULL));
        return rand() % (allMoves.size());
    }
    
    int bestValPcs = 0;
    int bestValSlot = 0;
    int bestIdxPcs = -1;
    int bestIdxSlot = -1;
    int bestIdxTotal = 0;
    int bestValueTotal = 0;
    
    
    for (int i = 0; i < list.size(); i++) {
        CPiece * pcs = list.getMove(i).figure;
        if(pcs == NULL)
            continue;
        int v = (pcs->getValue())*10; // !!!!!!!!!!!!!!! TODO VYRAZENA FIGURA
        
        if(v > bestValPcs){
            bestValPcs = v;
            bestIdxPcs = i;
        }
    }
    
    for (int i = 0; i < list.size(); i++) {
        
        MyMove tmp = list.getMove(i);
        int v = board.getSlotValue(tmp.toX,tmp.toY);
        if(v > bestValSlot){
            bestValSlot = v;
            bestIdxSlot = i;
        }
        if(list.getMove(i).figure == NULL)
            continue;
        else{
            
            if(list.getMove(i).figure->getValue()*10 + v > bestValueTotal){
                bestValueTotal = list.getMove(i).figure->getValue()*10 + v;
                bestIdxTotal = i;
            }
        }
    }
    
    if(difficulty == 1)
        return bestIdxPcs > bestIdxSlot ? bestIdxPcs : bestIdxSlot;
    
    else
        return bestIdxTotal;    
}
