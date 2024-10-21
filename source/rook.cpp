#include "rook.h"

bool Rook::isValidMove(const Position& from, const Position& to) const {
    // Проверяем, что фигура не перемещается по диагонали
    if (from.row != to.row && from.column != to.column) {
        return false;
    }

    // Проверяем, что фигура перемещается по вертикали или горизонтали
    if (from.row == to.row) {
        // Проверяем, что между исходной и конечной клеткой нет других фигур
        // for (int col = std::min(from.column, to.column) + 1; col < std::max(from.column, to.column); ++col) {
        //     if (!squares[from.row][col].button->icon().isNull()) {
        //         return false;
        //     }
        // }
    } else if (from.column == to.column) {
        // Проверяем, что между исходной и конечной клеткой нет других фигур
        // for (int row = std::min(from.row, to.row) + 1; row < std::max(from.row, to.row); ++row) {
        //     if (!squares[row][from.column].button->icon().isNull()) {
        //         return false;
        //     }
        // }
    }

    return true;
}
