#include "CIntelligence.h"
#include "DIFFICULTY.h"
#include "CPiece.h"
#include "CCommand.h"
#include "CPawn.h"
#include "CGameSession.h"

CIntelligence::CIntelligence() : difficulty(0){
}

CIntelligence::CIntelligence(int d) : difficulty(d) {
    
}

CIntelligence::~CIntelligence() {

}


void CIntelligence::changeDifficulty(int d) {
    difficulty = d;
}


void CIntelligence::eraseCheckMoves(CMoveList & l, const CGameSession & gS){
        
    CMoveList tmplist;
    
    for(size_t i = 0; i < l.size();++i){
        CMyMove m = l.getMove(i);
        
        if( ! gS.getBoard().tryMove(m,gS)){
        }
        else{
            tmplist.add(m,m.figure);
        }        
//        gS.gameBoard.undoMove(move, gS);   
    }

    l.clear();
    l.concat(tmplist);    
}   


CMyMove CIntelligence::getMove(const CGameSession & gS) {
    
    allMoves.clear();
    CMoveList l;
    
    findAllFigures(gS.getBoard());    
    
    for(size_t i = 0; i < figuresVec.size(); ++i){        
          l = figuresVec.at(i)->getLegalMoves(gS); 
        
        allMoves.concat(l); 
    }
         
    eraseCheckMoves(allMoves,gS);
    
    //cout<<"moves:"<<endl;
    //allMoves.print();

    if(allMoves.isEmpty()){
        return CMyMove(-1,-1,-1,-1);
    }    
    
    // minimax vyhodi nejakej move a vrati ho...
    
    int bestIdx = getBestIdx(allMoves,gS.getBoard());
    
    return allMoves.getMove(bestIdx);    
}

CCommand CIntelligence::getCommand(const CGameSession & gS){
    
    CMyMove m = getMove(gS);
    if(m.isFicture()){
        return CCommand(SURRENDER);
    }
    m.printMove();
    return CCommand(m);
}

int CIntelligence::getBestIdx(CMoveList& list,const CBoard & board) const {

    if(difficulty == 0){
        srand(time(NULL));
        return rand() % (allMoves.size());
    }
    
    int bestValPcs = 0;
    int bestValSlot = 0;
    int bestIdxPcs = 0;
    int bestIdxSlot = 0;
    int bestIdxTotal = 0;
    int bestValueTotal = 0;
    
    
    for (size_t i = 0; i < list.size(); i++) {
        CPiece * pcs = list.getMove(i).figure;
        if(pcs == NULL)
            continue;
        int v = (pcs->getValue())*10; 
        
        if(v > bestValPcs){
            bestValPcs = v;
            bestIdxPcs = i;
        }
    }
    
    for (size_t i = 0; i < list.size(); i++) {
        
        CMyMove tmp = list.getMove(i);
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
    
    //cout << "BESTidxpcs/idxslot/idxtotal:"<< bestIdxPcs<<","<<bestIdxSlot<<","<<bestIdxTotal<<endl;
    if(difficulty == 1)
        return bestValPcs > bestValSlot ? bestIdxPcs : bestIdxSlot;
    
    // difficulty == 2
    
    if( (bestValueTotal >= bestValPcs && bestValPcs >= bestValSlot)
     || (bestValueTotal >= bestValSlot && bestValSlot >= bestValPcs ) )
        return bestIdxTotal;
    else
         return bestValPcs > bestValSlot ? bestIdxPcs : bestIdxSlot;  
}
