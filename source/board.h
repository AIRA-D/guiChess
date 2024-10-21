#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <vector>
#include "piece.h"

enum Color {
    WHITE,
    BLACK
};

struct Square {
    Color squareColor;
    Position squarePosition;
    QPushButton* button;
};

QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE

class Board : public QMainWindow
{
    Q_OBJECT

public:
    Board(QWidget *parent = nullptr);
    ~Board();

    void initBoard();
    void initPieces();

private:
    Ui::Board *ui;

    std::vector<std::vector<Square>> squares;
    std::vector<std::vector<Piece*>> pieces;

    Position firstClickedPosition = {-1, -1};

    QTimer *doubleClickTimer;
    QGridLayout *chessboardLayout;
    QLabel *horizontalLabel;
    QLabel *verticalLabel;

    void handleButtonClick(int row, int col);

};

#endif // BOARD_H
