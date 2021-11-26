#include<iostream>
#include"Chess.h"
using namespace std;
int main()
{
    cout<<"\n******Welcome to # CHESS GAME******\n";
    cout<<"RULES : \n1.Enter the coordinates of the chess piece to move it\n2.You should give from and to coordinates to move the pieces";
    cout<<"\n3.Pawn can move only one step forward\n4.Other rules are same as normal chess game\n5.W represents white,B represents Black which stand as the first character";
    cout<<"\n6.Pawn-P,King-K,Queen-Q,Knight-N,Bishop-B,Rook-R which stands as the second letter .";
    cout<<"\nNow the game STARTS\n";
    cout<<"*****ALL THE BEST PLAYERS!*****";
    Chess c;
    c.start();
    return 0;
}
