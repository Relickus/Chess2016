#ifndef CPIECE_H
#define	CPIECE_H

#include "COLOR.h"
#include "FIGURENAME.h"
#include "MoveList.h"

#include <iostream>

class CBoard;
class CGameSession;
class MyMove;

/**
 * 
 * Abstraktní nadtřída pro figurku
 * 
 */
class CPiece {
public:
    
    /**
     * 
     * @param c Písmeno identifikující figurku
     * @param row Řádek kde se nachází figurka
     * @param col Sloupec kde se nachází figurka
     * @return Ukazatel na figurku z šachovnice
     */
    static CPiece * getPieceByLetter(char c, int row, int col);
    
    /**
     * 
     * @param c Zjistí zda zadané písmeno je validní písmeno pro figurku
     */
    static bool validLetter(char c); 
    
    CPiece();
    /**
     * 
     * @param color Barva nové figurky
     * @param row Řádek kam umístít figurku
     * @param col Sloupec kam umístít figurku
     */
    CPiece(COLOR color,int row, int col);
    virtual ~CPiece();
    
    /**
     * @brief Vytiskne figurku do zadaného ostreamu
     * 
     * @param os Ostream kam se vypíše figurka
     */
    void printPiece(ostream & os) const;
    
    /**
     * @brief Vrátí jméno figurky
     * @return enum FIGURNAME identifikující figurku
     */
    FIGURENAME getName() const;
     /**
     * @brief Vrátí barvu figurky
     * @return enum COLOR značící barvu figurky
     */
    COLOR getColor() const;
     /**
     * @brief Vrátí řádek figurky
     * @return int řádek figurky
     */
    int getRow() const;
         /**
     * @brief Vrátí sloupec figurky
     * @return int sloupec figurky
     */
    int getCol() const;
    /**
     * @brief Vrátí hodnotu figurky
     * @return int hodnota figurky
     */
    int getValue() const;
    
    /**
     * @brief Nastaví hodnotu figurky
     * @param value hodnota figurky
     */
    void setValue(int val);
       
    /**
     * @brief Nastaví řádek figurky
     * @param r řádek figurky
     */
    void setRow(int r);
    /**
     * @brief Nastaví sloupec figurky
     * @param c sloupec figurky
     */
    void setCol(int c);
    
    /**
     * @brief Zjistí dostupné tahy pro tuto figurku
     * @param gS Reference na instanci hry
     * @return Reference na MoveList všech možných pohybů této figurky
     */
    virtual MoveList & getLegalMoves(const CGameSession & gS) = 0;
    
    /**
     * @brief Zjistí typ figurky 
     * @param fig Jméno figurky
     * @return typ figurky se rovná parametru nebo ne
     */
    bool equals(FIGURENAME fig) const;
    
    /**
     * @brief zjistí zda zadaná figurka je přátelská 
     * @param tmp ukazatel na porovnávanou figurku
     */
    bool isFriendPiece(const CPiece * tmp) const;
    /**
     * @brief zjistí zda je figurka stejné barvy jako parametr
     * @param col porovnávaná barva
     */
    bool isFriendPiece(COLOR col) const;
    /**
     * @brief Ověří zda se dá táhnou na toto políčko
     * @param row řádek nového políčka
     * @param col sloupec nového políčka 
     * @param board reference na instanci šachovnice
     * @return 0 pro kladnou odpověď , 1 pro zápornou
     */
    virtual int checkField(int row, int col, const CBoard & board);
    /**
     * @brief Pohne figurkou na zadané místo
     * @param move Určuje souřadnice tahu
     * @param board reference na instanci šachovnice
     * @return značí zda se zdařil přesun
     */
    bool moveTo(const MyMove & move, CBoard & board );    
    /**
     * @brief Zkopíruje instanci figurky
     * @param pcs ukazatel na figurku, která se má zkopírovat
     * @return nová instance figurky
     */
    virtual CPiece * copyPiece(const CPiece * pcs) const = 0;
    
    MoveList moveList;
    
protected:

    int rowPos;
    int colPos;
    COLOR color;
    FIGURENAME name;
    int value;
    
};


#endif	/* CPIECE_H */

