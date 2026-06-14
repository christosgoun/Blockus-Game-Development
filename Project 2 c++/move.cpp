#include "move.h"

// TODO: Implement here the methods of Move
/**
     * Initializes a move setting its piece to be placed, the coordinates for the upper left square of the piece, the orientation,
     * and the flip of the piece to the values given as parameters.
     *
     * @param movePiece the piece that is placed.
     * @param moveX the row of the upper left square of the move.
     * @param moveY the column of the upper left square of the move.
     * @param moveOrientation the orientation of the piece that is placed.
     * @param moveFlip the flip of the piece that is placed.
     */
    Move::Move(Piece movePiece, int moveX, int moveY, char moveOrientation, char moveFlip)
    {
        piece = movePiece;
        x = moveX;
        y = moveY;
        orientation = moveOrientation;
        flip = moveFlip;
    }
   /**
     * Returns the piece that is placed by this move.
     *
     * @return the piece that is placed by this move.
     */
    Piece Move :: getPiece()
    {
        return piece;
    }

    /**
     * Returns the row of the upper left square of the move.
     *
     * @return the row of the upper left square of the move.
     */

    int Move::getX()
    {
        return x;
    }

    /**
     * Returns the column of the upper left square of the move.
     *
     * @return the column of the upper left square of the move.
     */

    int Move::getY()
    {
        return y;
    }

    /**
     * Returns the orientation of the piece of the move.
     *
     * @return the orientation of the piece of the move.
     */

    char Move::getOrientation()
    {
        return orientation;
    }

    /**
     * Returns the flip of the piece of the move.
     *
     * @return the flip of the piece of the move.
     */

    char Move::getFlip()
    {
       return flip;
    }
