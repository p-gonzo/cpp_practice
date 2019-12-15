#include <iostream>
using namespace std;

enum chessPiece {
    noPiece,
    pawn,
    knight,
    bishop,
    rook,
    queen,
    king
};

int main()
{

    chessPiece chessBoard[8][8] = {};
    chessBoard[0][0] = queen;
    chessBoard[7][7] = queen;

    for (auto &row : chessBoard)
    {
        for (auto piece : row)
        {
            cout << piece << " ";
        }
        cout << endl;
    }


    return 0;
}