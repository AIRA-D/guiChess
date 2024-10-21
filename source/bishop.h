#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece
{
public:
    Bishop(PieceType type, PColor color, Position currentPiecePosition) : Piece(type, color, currentPiecePosition) {}
    QIcon getIcon() const override {
        return icon;
    }
    bool isValidMove(const Position& from, const Position& to) const override; // Реализация проверки хода
};

#endif // BISHOP_H
