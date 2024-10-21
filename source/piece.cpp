#include "piece.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

Piece* Piece::createPiece(PieceType type, PColor color, Position currentPiecePosition){
    switch (type) {
    case ROOK:
        return new Rook(type, color, currentPiecePosition); // Класс Rook - наследник Piece
    case KNIGHT:
        return new Knight(type, color, currentPiecePosition); // Класс Knight - наследник Piece
    case BISHOP:
        return new Bishop(type, color, currentPiecePosition); // Класс Bishop - наследник Piece
    case QUEEN:
        return new Queen(type, color, currentPiecePosition); // Класс Queen - наследник Piece
    case KING:
        return new King(type, color, currentPiecePosition); // Класс King - наследник Piece
    case PAWN:
        return new Pawn(type, color, currentPiecePosition); // Класс Pawn - наследник Piece
    default:
        return nullptr;
    }
}

Piece::~Piece() {}

void Piece::initIcon() {
    QString imagePath = "/home/aira/Pictures/chess_images/";
    switch (type) {
    case ROOK:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhiteRook.png")
                   : QIcon(imagePath + "BlackRook.png");
        break;
    case KNIGHT:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhiteKnight.png")
                   : QIcon(imagePath + "BlackKnight.png");
        break;
    case BISHOP:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhiteBishop.png")
                   : QIcon(imagePath + "BlackBishop.png");
        break;
    case QUEEN:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhiteQueen.png")
                   : QIcon(imagePath + "BlackQueen.png");
        break;
    case KING:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhiteKing.png")
                   : QIcon(imagePath + "BlackKing.png");
        break;
    case PAWN:
        icon = (color == WHITE_P)
                   ? QIcon(imagePath + "WhitePawn.png")
                   : QIcon(imagePath + "BlackPawn.png");
        break;
    }
}

PColor Piece::getColor() {
    return color;
}

Position Piece::getPosition() {
    return currentPiecePosition;
}

