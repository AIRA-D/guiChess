#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
public:

    static Game* getInstance(); // Функция получения экземпляра
    void startGame(); // Функция запуска игры
    void makeMove(const Position& from, const Position& to); // Метод для выполнения хода

private:
 // Приватный конструктор
    Game();
    ~Game();
    static Game* instance; // Указатель на единственный экземпляр
    Board *board;
};

#endif // GAME_H
