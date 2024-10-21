#include "queen.h"

bool Queen::isValidMove(const Position& from, const Position& to) const {
    // Проверяем, что ход осуществляется по горизонтали, вертикали или диагонали
    if (from.row == to.row || from.column == to.column ||
        abs(from.row - to.row) == abs(from.column - to.column)) {

        // Проверяем, что между исходной и конечной клеткой нет других фигур
        // Проверка для горизонтального и вертикального движения
        // if (from.row == to.row) {
        //     for (int col = std::min(from.column, to.column) + 1; col < std::max(from.column, to.column); ++col) {
        //         if (!squares[from.row][col].button->icon().isNull()) {
        //             return false;
        //         }
        //     }
        // } else if (from.column == to.column) {
        //     for (int row = std::min(from.row, to.row) + 1; row < std::max(from.row, to.row); ++row) {
        //         if (!squares[row][from.column].button->icon().isNull()) {
        //             return false;
        //         }
        //     }
        // }
        // // Проверка для диагонального движения
        // else {
        //     // Определяем направление движения по диагонали
        //     int rowStep = (from.row < to.row) ? 1 : -1;
        //     int colStep = (from.column < to.column) ? 1 : -1;

        //     for (int row = from.row + rowStep, col = from.column + colStep;
        //          row != to.row && col != to.column;
        //          row += rowStep, col += colStep) {
        //         if (!squares[row][col].button->icon().isNull()) {
        //             return false;
        //         }
        //     }
        // }

        return true;
    }

    return false;
}
