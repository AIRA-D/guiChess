#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen(PieceType type, PColor color, Position currentPiecePosition) : Piece(type, color, currentPiecePosition) {}
    QIcon getIcon() const override {
        return icon;
    }
    bool isValidMove(const Position& from, const Position& to) const override;
};

#endif // QUEEN_H
