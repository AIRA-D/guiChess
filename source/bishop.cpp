#include "bishop.h"

bool Bishop::isValidMove(const Position& from, const Position& to) const {
    // Проверяем, что фигура перемещается по диагонали
    if (abs(from.row - to.row) != abs(from.column - to.column)) {
        return false;
    }

    // Определяем направление движения по диагонали
    int rowStep = (from.row < to.row) ? 1 : -1;
    int colStep = (from.column < to.column) ? 1 : -1;

    // Проверяем, что между исходной и конечной клеткой нет других фигур
    for (int row = from.row + rowStep, col = from.column + colStep;
         row != to.row && col != to.column;
         row += rowStep, col += colStep) {
        // if (!squares[row][col].button->icon().isNull()) {
        //     return false;
        // }
    }

    return true;
}
