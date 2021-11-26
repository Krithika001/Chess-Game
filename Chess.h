#ifndef BOARD_H
#define BOARD_H
#include"Board.h"
#endif // BOARD_H
class Chess
{
    char turn;
    Board board;
    public :
        Chess():turn('W'){};
        ~Chess() {};
        void start();
        void next_move(ChessPiece* qBoard[8][8]);
        void alter_turn();
        bool check_mate();
};
