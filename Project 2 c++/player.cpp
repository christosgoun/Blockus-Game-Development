#include <iostream>
#include "player.h"

// TODO: Implement here the methods of Player
/**
     * Initializes a player setting the index and the name. The numPlacedPieces variable is also initialized to zero.
     * Finally, the createPieces method must be called to create all the pieces of the player.
     *
     * @param playerId the id of the player.
     */
    Player::Player(int playerId)
    {
        numPlacedPieces = 0;
        id = playerId;
        if(playerId == 0)
        {
            name = "Player 1";
        }
        else if(playerId == 1)
        {
            name = "Player 2";
        }
        createPieces();
    }

    /**
     * Returns the name of the player.
     *
     * @return the name of the player.
     */

    string Player::getName()
    {
        return name;
    }

    /**
     * Returns a piece of the player given its index.
     *
     * @param index the index of the piece to be returned.
     * @return a piece of the player given its index.
     */

    Piece Player :: getPiece(int index)
    {
        return pieces[index];
    }

    /**
     * Returns the number of the available pieces of the player, i.e. the number
     * of pieces that have not been placed yet.
     *
     * @return the number of the available pieces of the player.
     */

    int Player::getNumberOfAvailablePieces()
    {
        int availiablePieces;
        availiablePieces = 21 - numPlacedPieces;
        return availiablePieces;
    }

    /// THE METHODS BELOW THIS POINT ARE IMPLEMENTED IN FILE playerpieces.cpp
    /**
     * Creates the pieces of the player by calling the different constructors.
     */
    void createPieces();

    /**
     * Prints the given pieces from pstart to pend side by side.
     *
     * @param pieces the pieces to be printed.
     * @param pstart the start index of the array of pieces to be printed.
     * @param pend the end index of the array of pieces to be printed.
     */
    void printPiecesSideBySide(Piece pieces[], int pstart, int pend);

    /**
     * Prints the available pieces of the player, This method calls the printPiecesSideBySide method to
     * print the pieces side by side.
     */
    void printAvailablePieces();

    /**
     * Receives the current state of the board and returns a move. A move contains the piece
     * to be placed on the board, its position (x, y), its orientation, and its flip.
     * The information of the move is read by the console. Before returning, this method also
     * sets the piece to be returned as placed, and decreases the numPlacedPieces variable by 1.
     *
     * @return an object of type Move containing a piece, its position, its orientation, and its flip..
     */
    Move placePiece(Board board);
