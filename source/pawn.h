#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn(PieceType type, PColor color, Position currentPiecePosition) : Piece(type, color, currentPiecePosition) {}
    QIcon getIcon() const override {
        return icon;
    }
    bool isValidMove(const Position& from, const Position& to) const override;
    bool isFirstMove(const Position& from, const Position& to);
};

#endif // PAWN_H
