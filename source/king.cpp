#include "king.h"

bool King::isValidMove(const Position& from, const Position& to) const {
    // Король может двигаться на одну клетку в любом направлении
    int rowDiff = abs(from.row - to.row);
    int colDiff = abs(from.column - to.column);

    if (rowDiff <= 1 && colDiff <= 1) {
        return true;
    }

    return false;
}
