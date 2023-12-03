#include "AbstractPlayer.h"
#include "Board.h"

#ifndef _COMPUTER_H_
#define _COMPUTER_H_

class Computer : public AbstractPlayer
{
protected:
    Computer(bool isHuman, bool isInCheck, Board *myboard) : AbstractPlayer(isHuman, isInCheck, myboard) {}

public:
    virtual void makeMove(int startFile, int startRank, int endFile, int endRank) = 0;
    virtual ~Computer() = default;
};

#endif
