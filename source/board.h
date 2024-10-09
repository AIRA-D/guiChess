#ifndef BOARD_H
#define BOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <QLabel>

enum Color {
    WHITE,
    BLACK
};

struct Position {
    int row;
    int column;
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

private:
    Ui::Board *ui;

    std::vector<std::vector<Square>> squares;
    Position selectedPiecePosition = {-1, -1};
    QTimer *doubleClickTimer;

    void initBoard();
    void initPieces();
    void handleButtonClick(int row, int col);
};

#endif // BOARD_H
