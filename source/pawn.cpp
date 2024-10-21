#include "pawn.h"

bool Pawn::isValidMove(const Position& from, const Position& to) const {
    // Пешка может двигаться на одну клетку вперед
    int rowDiff = abs(to.row - from.row);

    if (from.row != to.row && from.column != to.column ) {
        return false;
    }

    if (from.row == to.row) {
        return false;
    }

    if (rowDiff > 2 ) {
        return false;
    }

    return true;
}

