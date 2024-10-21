#include "knight.h"

bool Knight::isValidMove(const Position& from, const Position& to) const {
    // Конь перемещается "Г"-образно: на две клетки в одном направлении и на одну в другом
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.column - to.column);

    // Проверяем, что ход соответствует "Г"-образному перемещению
    if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
        // // Дополнительная проверка: на целевой клетке не должно быть фигуры того же цвета
        // if (!squares[to.row][to.column].button->icon().isNull() &&
        //     squares[to.row][to.column].button->icon() == color) {
        //     return false;
        // }

        return true;
    }

    return false;
}
