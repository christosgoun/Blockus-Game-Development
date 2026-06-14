#include <iostream>
#include <cstdlib>
#include "board.h"

using namespace std;

/**
     * Initializes this board, by creating a 14 x 14 array of squares.
     *
     * Hint: we have to use a loop over all squares, and for each individual square we have to set its row and column.
     */

Board::Board() {
    boardSize = 14;
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            squares[i][j].setCoordinates(i, j);
        }
    }
}

/**
     * Checks if a square placed in (x, y) is occupied by a piece.
     *
     * @param x the row of the square.
     * @param y the column of the square.
     * @return true if the square is occupied by a piece, or false otherwise.
     */

bool Board::hasPiece(int x, int y){
    return squares[x][y].hasPiece();
}

/**
     * Checks if a square placed in (x, y) is occupied by a specific player piece.
     *
     * @param x the row of the square.
     * @param y the column of the square.
     * @param player the player of the square.
     * @return true if the square is occupied by a piece of the player, or false otherwise.
     */

bool Board::hasPlayerPiece(int x, int y, char player){
    return squares[x][y].getPlayer() == player;
}

/**
     * Places a piece of the player given its position (x, y), its orientation and its flip.
     *
     * @param piece the piece to be placed on the board.
     * @param x the row of the first (upper left) square of the piece.
     * @param y the column of the first (upper left) square of the piece.
     * @param orientation the rotation of the piece as a char ('u', 'd', 'l', 'r').
     * @param flip the flip of the piece as a char ('f', 'r').
     */

void Board::placePiece(Piece piece, int x, int y, char orientation, char flip){
    piece.rotatePiece(orientation);
    if (flip == 'r')
        piece.flipPiece();
    for(int i = 0; i < piece.getSize(); i++){
        for(int j = 0; j < piece.getSize(); j++){
            if (piece.squareHasPiece(i, j))
                squares[x + i][y + j].addPiece(piece.getPlayer());
        }
    }
}
