#ifndef PIECE_H
#define PIECE_H

#include <QIcon>

enum PieceType {
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN
};

enum PColor {
    WHITE_P,
    BLACK_P
};

struct Position {
    int row;
    int column;
};


class Piece
{
public:
    static Piece* createPiece(PieceType type, PColor color, Position currentPiecePosition);

    virtual QIcon getIcon() const = 0;
    PColor getColor();
    Position getPosition();

    virtual bool isValidMove(const Position& from, const Position& to) const = 0;
    virtual ~Piece();

protected:
    Piece(PieceType type, PColor color, Position currentPiecePosition) : type(type), color(color), currentPiecePosition(currentPiecePosition) {
        initIcon();
    };

    PieceType type;
    PColor color;
    Position currentPiecePosition;
    QIcon icon;

private:
    void initIcon();
};

#endif // PIECE_H
