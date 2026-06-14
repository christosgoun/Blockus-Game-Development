#include <iostream>
#include <cstdlib>
#include "player.h"

// TODO: Implement here the methods of Player and all derived classes


Player::Player(int id)
{
    numPieces = 21;

    pieces = new Piece*[numPieces];

    this->id = id;

    if(id == 0)
    {
        name = "Player 1";
    }
    else if(id == 1)
    {
        name = "Player 2";
    }


    createPieces();

}


Player::~Player()
{
    for(int i=0; i<numPieces; i++)
    {
        delete pieces[i];
    }
    delete[] pieces;
}


int Player::getId()
{
    return id;
}


char Player::getSymbol()
{
    if(getId() == 0)
        symbol = '#';
    if(getId() == 1)
        symbol = 'O';

    return symbol;
}


string Player::getName()
{
    return name;
}


Piece* Player::getPiece(int index)
{
    return pieces[index];
}


int Player::getNumberOfPlacedPieces()
{
    int numPlacedPieces = 0;

    for(int i=0; i<numPieces; i++)
    {

        if(pieces[i]->isPlaced() == true)
        {
            numPlacedPieces++;
        }

    }
    return numPlacedPieces;
}


int Player::getNumberOfAvailablePieces()
{
    return (numPieces - getNumberOfPlacedPieces());
}


HumanPlayer::HumanPlayer(int id):Player(id){}


HumanPlayer::HumanPlayer(int id, string name):Player(id)
{

    this -> name = name;
}


int ComputerPlayer::getRandomPieceId()
{
    return (rand()%(21)+1);
}


Orientation ComputerPlayer::getRandomOrientation()
{
    return (Orientation) (rand()%(LEFT-UP+1)+UP);
}


Flip ComputerPlayer::getRandomFlip()
{
    return (Flip) (rand()%(YES-NO+1)+NO);
}


ComputerPlayer::ComputerPlayer(int id):Player(id){}




