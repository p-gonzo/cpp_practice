#include <iostream>
#include <vector>

static const auto boardSize = 3;
using GameBoard = std::vector<std::vector<char>>;

struct Player
{
    Player(int ex, int why): x(ex), y(why) { };
    int x;
    int y;
};

void drawBoard(const GameBoard &board, const Player &player)
{
    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j)
        {
            if (i == player.y && j == player.x)
            {
                std::cout << "O" << " ";
            }
            else
            {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

struct Command
{
    virtual ~Command() { };
    virtual void Execute(Player &player) = 0;
    virtual void Undo(Player &player) = 0;
};

struct MoveDown : Command
{
    virtual ~MoveDown() { };
    virtual void Execute(Player &player) override
    {
        pX = player.x;
        pY = player.y;
        player.y += 1;
    }
    virtual void Undo(Player &player) override
    {
        player.x = pX;
        player.y = pY;
    }
    int pX;
    int pY;
};

struct MoveRight : Command
{
    virtual ~MoveRight() { };
    virtual void Execute(Player &player) override
    {
        pX = player.x;
        pY = player.y;
        player.x += 1;
    }
    virtual void Undo(Player &player) override
    {
        player.x = pX;
        player.y = pY;
    }
    int pX;
    int pY;
};

int main()
{
    GameBoard gameBoard (boardSize, std::vector<char>(boardSize, 'X'));
    Player player(0, 0);
    std::cout << "Initial Position:" << std::endl;
    drawBoard(gameBoard, player);

    std::vector<Command*> commands { new MoveDown, new MoveRight, new MoveDown, new MoveRight };

    std::cout << "Issue Commands from Array" << std::endl;
    for (auto i = commands.begin(); i != commands.end(); ++i)
    {
        std::cout << std::endl;
        (*i)->Execute(player);
        drawBoard(gameBoard, player);
    }

    std::cout << "Undo Commands from Array" << std::endl;
    for (auto i = commands.rbegin(); i != commands.rend(); ++i)
    {
        std::cout << std::endl;
        (*i)->Undo(player);
        drawBoard(gameBoard, player);
    }
    // Clean Up
    for (auto i = commands.begin(); i != commands.end(); ++i)
    {
        delete (*i);
    }
    return 0;
}