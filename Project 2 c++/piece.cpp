#include "piece.h"


/**
     * Initializes a piece setting its id to -1, its size to 5 and its player to '-'.
     * The piece is initially is not placed.
     */

Piece::Piece()
{
    id = -1;
    pieceSize = 5;
    player = '-';
}
/**
     * Initializes a piece given its id, setting its size to 5 and initializing its squares.
     * For each square one must set the coordinates (x, y) and the char of the player.
     * We must also set that the piece is initially is not placed.
     *
     * Hint: we have to use a loop over all squares, and for each individual square we have to set its x and its y, and call
     * its addPiece method if the square is occupied by the piece (i.e. if the corresponding boolean of pieceSquares is true).
     *
     * @param pieceId the id of the piece.
     * @param piecePlayer char of the player who owns the piece.
     * @param pieceSquares array of chars indicating whether each square is occupied by a piece (with char piecePlayer) or not.
     */
Piece::Piece(int pieceId, char piecePlayer, char pieceSquares[5][5])
{
    id = pieceId;
    pieceSize = 5;
    player = piecePlayer;

        for (int i = 0; i < 5 ; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                squares[i][j].setCoordinates(i,j);
                if (pieceSquares[i][j] == '#' || pieceSquares[i][j] == 'O')
                {
                    squares[i][j].addPiece(piecePlayer);
                }
            }
        }

}

/**
     * Returns the id of the piece.
     *
     * @return the id of the piece.
     */


int Piece::getId()
{
    return id;
}

/**
     * Returns the player that owns the piece.
     *
     * @return char of the player who owns the piece.
     */

char Piece::getPlayer()
{
    return player;
}

/**
     * Sets the placed variable of the piece to true.
     */

void Piece::setPlaced()
{
    placed = true;
}

/**
     * Checks whether the piece has been placed on the board.
     *
     * @return true if the piece has been placed on the board, or false otherwise.
     */


bool Piece::isPlaced()
{
    if(placed == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
     * Returns the size dimension of the piece.
     *
     * @return the size dimension of the piece.
     */

int Piece::getSize()
{
    return pieceSize;
}

 /**
     * Returns a specific square of the piece given its coordinates.
     *
     * @param x the row of the square to be returned.
     * @param y the column of the square to be returned.
     * @return the square of the piece at row x and column y.
     */


Square Piece :: getSquare(int x, int y)
{
    return squares[x][y];
}


/**
     * Checks whether a specific square has part of the piece given its coordinates.
     *
     * @param x the row of the square to be checked.
     * @param y the column of the square to be checked.
     * @return true if the square has part of the piece on it, or false otherwise.
     */


bool Piece::squareHasPiece(int x, int y)
{
    return squares[x][y].hasPiece();

}

/**
     * Rotates the piece clockwise. An example clockwise rotation is the following:
     *
     *       Initial state              Rotated
     *         - # - - -               - - # - -
     *         - # - - -               - - # # #
     *         # # - - -      ---->    - - - - -
     *         - - - - -               - - - - -
     *         - - - - -               - - - - -
     *
     * Warning: Each square has three variables, two for its coordinates (integers x and y) and one for its ownership (char player).
     *          The resulting piece squares must keep the correct coordinates, only the ownership of each square should change!
     * Hint: The rotation can be done in various ways. What is important is that the final result is placed in array squares of this class.
     */


void Piece::rotatePieceClockwise()
{
    for (int i = 0; i < 5 / 2; i++)
    {
        for (int j = i; j < 5 - i - 1; j++)
        {

            Square temp = squares[i][j];
            squares[i][j] = squares[4 - j][i];
            squares[4 - j][i] = squares[4 - i][4 - j];
            squares[4 - i][4 - j] = squares[j][4 - i];
            squares[j][4 - i] = temp;
        }
    }
}

/**
     * Rotates the piece according to the orientation received as input. Orientation 'u' means that the piece should not be
     * rotated at all, 'r' means that the piece must be rotated clockwise one time, 'd' means that it must be rotated clockwise
     * two times, and 'l' means that it must be rotated clockwise three times.
     *
     * Hint: We can call the rotatePieceClockwise method here.
     *
     * @param orientation the orientation of the square to be returned.
     */

void Piece::rotatePiece(char orientation)
{
    switch(orientation)
    {
    case 'u':
        break;
    case 'r':
        rotatePieceClockwise();
        break;
    case 'd':
        rotatePieceClockwise();
        rotatePieceClockwise();
        break;
    case 'l':
        rotatePieceClockwise();
        rotatePieceClockwise();
        rotatePieceClockwise();
        break;
    }
}

/**
     * Flips the piece horizontally. An example horizontal flip is the following:
     *
     *       Initial state              Flipped
     *         - # - - -               - - - # -
     *         - # - - -               - - - # -
     *         # # - - -      ---->    - - - # #
     *         - - - - -               - - - - -
     *         - - - - -               - - - - -
     *
     * Warning: Each square has three variables, two for its coordinates (integers x and y) and one for its ownership (char player).
     *          The resulting piece squares must keep the correct coordinates, only the ownership of each square should change!
     * Hint: The flip can be done in various ways. What is important is that the final result is placed in array squares of this class.
     */

void Piece::flipPiece()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<2; j++)
        {
            Square temp = squares[i][j];
            squares[i][j]=squares[i][4-j];
            squares[i][4-j]=temp;
        }
    }
}
