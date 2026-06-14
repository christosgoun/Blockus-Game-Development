#include <iostream>
#include "square.h"

// TODO: Implement here the methods of Square

/**
     * Initializes a square setting its coordinates to -1 and its player character to '-'
     * as no piece is placed on the square.
     */

Square::Square()
{
    x = -1;
    y = -1;
    player = '-';
}

/**
     * Sets the coordinates of this square to the ones given.
     *
     * @param newx the row of the square to be set.
     * @param newy the column of the square to be set.
     */

void Square::setCoordinates(int newx, int newy)
{
    x = newx;
    y = newy;
}

/**
     * Returns the row of the square.
     *
     * @return the row of the square.
     */

int Square::getX()
{
    return x;
}

/**
     * Returns the column of the square.
     *
     * @return the column of the square.
     */

int Square::getY()
{
    return y;
}

/**
     * Adds a part of a piece to this square by setting the corresponding player variable to the character given.
     *
     * @param piecePlayer char denoting which player owns the piece placed on the square ('#' for first or 'O' for second player).
     */

void Square::addPiece(char piecePlayer)
{
    player = piecePlayer;
}

/**
     * Removes the piece from this square by setting the corresponding variable of the player to the '-' character.
     */

void Square::removePiece()
{
    player = '-';
}

 /**
     * Checks if the square is occupied by a piece.
     *
     * @return true if the square is occupied by a piece, or false otherwise.
     */

bool Square::hasPiece()
{
    if(player == '-')
    {
        return false;
    }
    else
        return true;
}

/**
     * Returns the character of the player who owns the piece placed on this square.
     *
     * @return '#' for the first player, 'O' for the second player, or '-' if the square does not have any piece on it.
     */

char Square::getPlayer()
{
    if(player == '#')
    {
        return '#';
    }
    else if(player == 'O')
    {
        return 'O';
    }
    else
    {
        return '-';
    }
    return player;
}
