#include "board.h"
#include "ui_board.h"
#include <iostream>
#include <QLabel>

Board::Board(QWidget *parent) : QMainWindow(parent), ui(new Ui::Board)
{
    ui->setupUi(this);
    initBoard();
    initPieces();
}

Board::~Board()
{
    delete ui;
}

void Board::initBoard() {

    int boardSize = 8;

    squares.resize(boardSize);
    for (int i = 0; i < boardSize; ++i) {
        squares[i].resize(boardSize, Square{WHITE, {i, 0}, nullptr});
    }

    auto *chessboardLayout = findChild<QGridLayout *>("chessboardLayout");

    for (int row = 0; row < boardSize; ++row) {
        for (int col = 0; col < boardSize; ++col) {
            QPushButton *button = new QPushButton();
            button->setFixedSize(50, 50);
            button->setIconSize(QSize(50, 50));

            if ((row + col) % 2 == 0) {
                squares[row][col].squareColor = WHITE;
                button->setStyleSheet("background-color: #ffffff");
            }
            else {
                squares[row][col].squareColor = BLACK;
                button->setStyleSheet("background-color: #fb6f92");
            }

            squares[row][col].squarePosition = {row, col};
            squares[row][col].button = button;
            chessboardLayout->addWidget(button, row, col);

            connect(squares[row][col].button, &QPushButton::clicked, [this, row, col]() {
                handleButtonClick(row, col);
            });


            QStringList horizontalLabels = {"a", "b", "c", "d", "e", "f", "g", "h"};
            QStringList verticalLabels = {"8", "7", "6", "5", "4", "3", "2", "1"};

            for (int i = 0; i < boardSize; ++i) {
                auto *horizontalLabel = new QLabel(horizontalLabels.at(i), this);
                auto verticalLabel = new QLabel(verticalLabels.at(i), this);
                horizontalLabel->setAlignment(Qt::AlignHCenter);
                horizontalLabel->setStyleSheet("color: #ffffff");
                verticalLabel->setAlignment(Qt::AlignVCenter);
                verticalLabel->setStyleSheet("color: #ffffff");
                chessboardLayout->addWidget(horizontalLabel, boardSize, i, 1, 1, Qt::AlignHCenter);
                chessboardLayout->addWidget(verticalLabel, i, boardSize, 1, 1, Qt::AlignVCenter);
            }
        }
    }
}

void Board::initPieces() {

    //Rooks
    squares[0][0].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackRook.png"));
    squares[0][7].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackRook.png"));

    squares[7][0].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteRook.png"));
    squares[7][7].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteRook.png"));

    //Knights
    squares[0][1].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackKnight.png"));
    squares[0][6].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackKnight.png"));

    squares[7][1].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteKnight.png"));
    squares[7][6].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteKnight.png"));

    //Bishops
    squares[0][2].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackBishop.png"));
    squares[0][5].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackBishop.png"));

    squares[7][2].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteBishop.png"));
    squares[7][5].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteBishop.png"));

    //Queens
    squares[0][3].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackQueen.png"));
    squares[7][3].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteQueen.png"));

    //Kings
    squares[0][4].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackKing.png"));
    squares[7][4].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhiteKing.png"));


    //Pawns
    for (int i = 0; i < 8; ++i) {
        squares[1][i].button->setIcon(QIcon("/home/aira/Pictures/chess_images/BlackPawn.png"));
        squares[6][i].button->setIcon(QIcon("/home/aira/Pictures/chess_images/WhitePawn.png"));
    }

}

void Board::handleButtonClick(int row, int col) {

    Position clickedPosition = {row, col};

    // Если это первый клик (выбор фигуры)
    if (selectedPiecePosition.row == -1 && selectedPiecePosition.column == -1) {
        if (squares[row][col].button->icon().isNull()) {
            return;
        }
        // Запоминаем выбранную фигуру
        selectedPiecePosition = clickedPosition;
        squares[row][col].button->setStyleSheet("background-color: #00b4d8");

    } else {
        // Проверяем, что кликнули не по той же клетке
        if (clickedPosition.row == selectedPiecePosition.row &&
            clickedPosition.column == selectedPiecePosition.column) {
            selectedPiecePosition = {-1, -1};
            if (squares[row][col].squareColor == WHITE) {
                squares[row][col].button->setStyleSheet("background-color: #ffffff");
            }
            else {
                squares[row][col].button->setStyleSheet("background-color: #fb6f92");
            }

            return;
        }
        // Перемещаем иконку
        squares[clickedPosition.row][clickedPosition.column].button->setIcon(squares[selectedPiecePosition.row][selectedPiecePosition.column].button->icon());
        squares[clickedPosition.row][clickedPosition.column].button->setIconSize(QSize(50, 50));

        // Очищаем исходную клетку
        squares[selectedPiecePosition.row][selectedPiecePosition.column].button->setIcon(QIcon());
        squares[selectedPiecePosition.row][selectedPiecePosition.column].button->setStyleSheet("background-color: #ffffff");
        if (squares[selectedPiecePosition.row][selectedPiecePosition.column].squareColor == WHITE) {
            squares[selectedPiecePosition.row][selectedPiecePosition.column].button->setStyleSheet("background-color: #ffffff");
        }
        else {
            squares[selectedPiecePosition.row][selectedPiecePosition.column].button->setStyleSheet("background-color: #fb6f92");
        }

        // Сбрасываем выбор и фон выбранной кнопки
        selectedPiecePosition = {-1, -1};
        squares[row][col].button->setStyleSheet("background-color: #ffffff");
        if (squares[row][col].squareColor == WHITE) {
            squares[row][col].button->setStyleSheet("background-color: #ffffff");
        }
        else {
            squares[row][col].button->setStyleSheet("background-color: #fb6f92");
        }
    }
}



