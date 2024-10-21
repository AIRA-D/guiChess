#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
public:
    King(PieceType type, PColor color, Position currentPiecePosition) : Piece(type, color, currentPiecePosition) {}
    QIcon getIcon() const override {
        return icon;
    }
    bool isValidMove(const Position& from, const Position& to) const override;
};

#endif // KING_H
