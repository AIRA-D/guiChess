#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece
{
public:
    Rook(PieceType type, PColor color, Position currentPiecePosition) : Piece(type, color, currentPiecePosition) {}
    QIcon getIcon() const override {
        return icon;
    }
    bool isValidMove(const Position& from, const Position& to) const override; // Реализация проверки хода для Rook
};

#endif // ROOK_H
