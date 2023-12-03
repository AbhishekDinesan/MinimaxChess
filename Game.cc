#include "Game.h"
#include "Board.h"          // Assuming you have a board.h file
#include "AbstractPlayer.h" // Assuming you have a player.h file
#include "AbstractPiece.h"
#include "PawnPiece.h"
#include <ostream>
#include <utility>
using namespace std;

Game::Game(bool whiteToMove, bool customProvided, Board* theCustomBoard) : moveCount{0}, whiteToMove{whiteToMove}, board{theCustomBoard} { 
    
    if (!customProvided) { 
        board = new Board(false); 
    }
    printBoard(); 
}

Game::~Game()
{
    //delete board; IM USING UNIQUE POINTERS NOW 
}

void Game::init()
{
    //unique_ptr<Board> board = make_unique<Board>();
    //printBoard(); // this should create new 8 x 8 grid
    // PlayerOne = new Player();
    // PlayerTwo = new PlayerTwo();
    // Player currentPlayer = PlayerOne;
    // Vector pastmoves;
    // std::vector<std::vector<Move>> pastMoves;
    moveCount = 0;
}

bool Game::ValidBoard()
{
    int whiteKcount;
    int blackKcount;
    bool isCheck;
    for (int x = 0; x < 8; ++x)
    {
        for (int y = 0; y < 8; ++y)
        {
            
        }
    }
    return whiteKcount && !isCheck;
}

bool Game::endGame()
{ // consdier the stalemate case seperately
    // return board->isCheckMate();
    return true;
}

void Game::movePiece(int fromX, int fromY, int toX, int toY) // wouldn't this be called from the game function
{
    cout << "(2)" << endl;
    Move m = Move(board, fromX, fromY, toX, toY);
    cout << "(3)" << endl;
   if (m.isValidMove()) {
        board->movePiece(fromX, fromY, toX, toY);
        // ADD THE MOVE TO A VECTOR FOR THE UNDO FUNCTION
   }
}

void Game::addPiece(int x, int y, char piece) {
    board->addPiece(x, y, piece);
}

std::ostream &operator<<(std::ostream &out, const Game &g)
{
    out << g.board;
    return out;
}

void Game::printBoard()
{
    board->printBoard(); 
}
