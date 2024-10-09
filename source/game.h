#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

private:
    void runGame();
    void updatePosition();
    void makeMove();
};

#endif // GAME_H
