#include "board.h"
#include "player.h"

// TODO: Implement here the method pieceCanBePlaced and computeScore of Board
// Do not implement any other methods of Board (as they are already implemented in file board.cpp)


/// коцы вяомийгс емдеиас г укопоигсг тгс леходоу pieceCanBePlaced еимаи глитекгс. то суцйейяилемо пяоцяалла паяацеи 2 лояжес енодым
/// амакоца ле тгм епикоцг тоу вягстг ма бцакеи та сулбока (/* йаи */) апо тис цяаллес 87 йаи 160 йаи ма бакеи се свокиа тис цяаллес
/// 165 еыс 455 амтистоива коцы тгс апотувиас лас ма суцвымеусоуле окоус тоу йамомес лафи, паяоко поу деивмоум ма еимаи ояхос укопоиглема,
/// то йах'ема невьыяиста. стгм пяытг пеяиптысг укопоиоумтаи ои йамомес 1, 3 йаи 4, емы стг деутеяг ои 1,2 йаи 5.



bool Board::pieceCanBePlaced(Piece* piece, int x, int y)
{


    if(playerHasPlacedNoPieces('#') == true)
    {
        if(piece->squareHasPiece(0,0)==true)
        {
            if(x==4 && y==4)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(piece->squareHasPiece(0,1)==true)
            {
                if(x==4 && y==4)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }



    if(playerHasPlacedNoPieces('O') == true)
    {
        if(piece->squareHasPiece(0,0)==true)
        {
            if(x==9 && y==9)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(piece->squareHasPiece(0,1)==true)
            {
                if(x==9 && y==9)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

/*



    if(playerHasPlacedNoPieces('#') == false || playerHasPlacedNoPieces('O') == false)
    {
     if(!piece->isPlaced())
     {
        for(int k=1;k<=5;k++)
        {
         for(int m=1;m<=3;m++)
         {
            if(piece->getSizeX()==k )
               {
                   if(y>14-m || y<0)
                   {
                      return false;
                   }
                   else
                   {
                           if(piece->getSizeY()== m)
                           {
                               if(x>14-k || x<0)
                               {
                                   return false;
                               }
                               else
                               {
                                   for(int i=0;i<piece->getSizeX();i++)
                                    {
                                    for(int j=0;j<piece->getSizeY();j++)
                                        {
                                        if((piece->squareHasPiece(i,j)==false && hasPiece(x+i,y+j)==true) ||
                                            (piece->squareHasPiece(i,j)==true && hasPiece(x+i,y+j)==false)||
                                            (piece->squareHasPiece(i,j)==false && hasPiece(x+i,y+j)==false))
                                            {
                                                continue;
                                            }
                                            else
                                            {
                                                return false;
                                            }
                                        }


                                    }

                                        return true; ///edo bazo to epomeno bouletaki!!!
                               }
                           }
                           else
                           {
                                continue;
                           }
                   }
               }
            else
                {
                    continue;
                }

        }
     }


     }
        else
        {
            return false;
        }
    }


*/




// /*
    if(playerHasPlacedNoPieces('#') == false || playerHasPlacedNoPieces('O') == false )
    {
        if(!piece->isPlaced())
        {

            if(x<0 || y<0 || x>12||y>12)
            {
                return false;
            }
            else
            {
                if(x<9 && y<9)
                {


                    for(int i=0; i<piece->getSizeX(); i++)
                    {
                        for(int j=0; j<piece->getSizeY(); j++)
                        {
                            if((piece->squareHasPiece(i,j)==false && hasPiece(x+i,y+j)==true) ||
                                    (piece->squareHasPiece(i,j)==true && hasPiece(x+i,y+j)==false)||
                                    (piece->squareHasPiece(i,j)==false && hasPiece(x+i,y+j)==false))
                            {
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }

                    }


                    if(piece->getPlayer()=='#')
                    {
                        if(y>=1 &&x>=1)
                        {

                            for(int i=0; i<piece->getSizeX(); i++)
                            {
                                for(int j=0; j<piece->getSizeY(); j++)
                                {
                                    if(piece->squareHasPiece(i,j)==true)
                                    {
                                        if(squareBelongsToPlayer(x+1+i,y+1+j,'#')==true || squareBelongsToPlayer(x+1,y-1,'#')==true ||
                                                squareBelongsToPlayer(x-1+i,y+1+j,'#')==true || squareBelongsToPlayer(x-1,y-1,'#')==true)
                                        {



                                            if(squareBelongsToPlayer(x-1+i,y+j,'#')==true || squareBelongsToPlayer(x+1+i,y+j,'#')==true ||
                                                    squareBelongsToPlayer(x+i,y-1+j,'#')==true || squareBelongsToPlayer(x+i,y+1+j,'#')==true)
                                            {
                                                return false;
                                            }
                                            else
                                            {

                                                continue;
                                            }



                                        }
                                        else
                                        {
                                            return false;
                                        }
                                    }
                                    else
                                    {
                                        continue;

                                    }
                                }


                            }


                        }
                        else
                        {
                            return false;
                        }

                    }
                    else if(piece->getPlayer()=='O')
                    {
                        if(y>=1 && x>=1)
                        {

                            for(int i=0; i<piece->getSizeX(); i++)
                            {

                                for(int j=0; j<piece->getSizeY(); j++)
                                {
                                    if(piece->squareHasPiece(i,j)==true)
                                    {
                                        if(squareBelongsToPlayer(x+1+i,y+1+j,'O')==true || squareBelongsToPlayer(x+1,y-1,'O')==true ||
                                                squareBelongsToPlayer(x-1+i,y+1+j,'O')==true || squareBelongsToPlayer(x-1,y-1,'O')==true)
                                        {


                                            if(squareBelongsToPlayer(x-1+i,y+j,'O')==true || squareBelongsToPlayer(x+1+i,y+j,'O')==true ||
                                                    squareBelongsToPlayer(x+i,y-1+j,'O')==true || squareBelongsToPlayer(x+i,y+1+j,'O')==true)
                                            {
                                                return false;
                                            }
                                            else
                                            {

                                                continue;
                                            }

                                        }
                                        else
                                        {
                                            return false;
                                        }
                                    }
                                    else
                                    {


                                        continue;
                                    }
                                }


                            }

                        }
                        else
                        {
                            return false;
                        }


                    }



                    if(piece->getSizeY()!=1)
                    {
                        for(int i=0; i<piece->getSizeX(); i++)
                        {
                            for(int j=0; j<piece->getSizeY(); j++)
                            {

                                if(piece->getPlayer()=='#')

                                {

                                    if(squareBelongsToPlayer(x+i,y+j,'#')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }


                                }
                                else if(piece->getPlayer()=='O')
                                {
                                    if(squareBelongsToPlayer(x+i,y+j,'O')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }


                            }
                        }


                        return true;
                    }


                    else
                    {
                        for(int i=0; i<piece->getSizeX(); i++)
                        {
                            for(int j=0; j<2; j++)
                            {

                                if(piece->getPlayer()=='#')

                                {

                                    if(squareBelongsToPlayer(x+i,y+j,'#')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }


                                }
                                else if(piece->getPlayer()=='O')
                                {
                                    if(squareBelongsToPlayer(x+i,y+j,'O')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }


                            }
                        }


                        for(int i=0; i<piece->getSizeX(); i++)
                        {
                            for(int j=0; j<2; j++)
                            {

                                if(piece->getPlayer()=='#')

                                {

                                    if(squareBelongsToPlayer(x+i,y+j,'#')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }


                                }
                                else if(piece->getPlayer()=='O')
                                {
                                    if(squareBelongsToPlayer(x+i,y+j,'O')==true)
                                    {
                                        return false;
                                    }
                                    else
                                    {
                                        continue;
                                    }
                                }


                            }
                        }
                        return true;

                    }




                }
                else
                {
                    return false;
                }

            }


        }
        else
        {
            return false;
        }

    }



    return true;

//*/

}





int Board::computeScore(Player* player)
{

    int score=0;

    for(int i=0; i<boardSizeX; i++)
    {
        for(int j=0; j<boardSizeY; j++)
        {
            if(squareBelongsToPlayer(i, j, player) == true)
                score += 1;
        }
    }

    if(player->getNumberOfAvailablePieces() == 0)
    {
        score += 15;
    }

    if(player->getNumberOfAvailablePieces() == 0 && getLastPiecePlayedByPlayer(player) == player->getPiece(0))
    {
        score += 5;
    }

    return score;
}
