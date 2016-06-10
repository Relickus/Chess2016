#ifndef ALLEXCEPTIONS_H
#define	ALLEXCEPTIONS_H

/**
 *Exception thrown and caught when checking if move is out of the chessboard
 */
class MoveOutOfBoardException{};
/**
 *Exception thrown and caught when loading a game from file fails
 */
class BadFileReadException{};
/**
 *Exception thrown and caught when loading a game from file reads unknown character
 */
class InvalidFileCharacterException{};
/**
 *Exception thrown and caught when user enters invalid input
 */
class BadInputException{};
/**
 *Exception thrown and caught when unknown command is demanded from user
 */
class BadCommandException{};


#endif	/* ALLEXCEPTIONS_H */

