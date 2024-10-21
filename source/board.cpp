#include "ui_board.h"
#include "board.h"
#include <QMessageBox>

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

    auto *chessboardLayout = findChild<QGridLayout *>("chessboardLayout");

    squares.resize(boardSize);
    pieces.resize(boardSize);

    for (int i = 0; i < boardSize; ++i) {
        squares[i].resize(boardSize, Square{WHITE, {i, 0}, nullptr});
    }
    pieces.resize(boardSize);
    for (int i = 0; i < boardSize; ++i) {
        pieces[i].resize(boardSize, nullptr);
    }

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

            QObject::connect(squares[row][col].button, &QPushButton::clicked, [this, row, col]() {
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


    // Rooks
    pieces[0][0] = Piece::createPiece(ROOK, BLACK_P, Position{0, 0});
    pieces[0][7] = Piece::createPiece(ROOK, BLACK_P, Position{0, 7});
    pieces[7][0] = Piece::createPiece(ROOK, WHITE_P, Position{7, 0});
    pieces[7][7] = Piece::createPiece(ROOK, WHITE_P, Position{7, 7});

    // Knights
    pieces[0][1] = Piece::createPiece(KNIGHT, BLACK_P, Position{0, 1});
    pieces[0][6] = Piece::createPiece(KNIGHT, BLACK_P, Position{0, 6});
    pieces[7][1] = Piece::createPiece(KNIGHT, WHITE_P, Position{7, 1});
    pieces[7][6] = Piece::createPiece(KNIGHT, WHITE_P, Position{7, 6});

    // Bishops
    pieces[0][2] = Piece::createPiece(BISHOP, BLACK_P, Position{0, 2});
    pieces[0][5] = Piece::createPiece(BISHOP, BLACK_P, Position{0, 5});
    pieces[7][2] = Piece::createPiece(BISHOP, WHITE_P, Position{7, 2});
    pieces[7][5] = Piece::createPiece(BISHOP, WHITE_P, Position{7, 5});

    // Queen
    pieces[0][3] = Piece::createPiece(QUEEN, BLACK_P, Position{0, 3});
    pieces[7][3] = Piece::createPiece(QUEEN, WHITE_P, Position{7, 3});

    // King
    pieces[0][4] = Piece::createPiece(KING, BLACK_P, Position{0, 4});
    pieces[7][4] = Piece::createPiece(KING, WHITE_P, Position{7, 4});

    // Pawns
    for (int i = 0; i < 8; ++i) {
        pieces[1][i] = Piece::createPiece(PAWN, BLACK_P, Position{1, i});
        pieces[6][i] = Piece::createPiece(PAWN, WHITE_P, Position{6, i});
    }

    // Установка иконок
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (pieces[row][col] != nullptr) {
                squares[row][col].button->setIcon(pieces[row][col]->getIcon());
            }
        }
    }
}


void Board::handleButtonClick(int row, int col) {

    Position clickedPosition = {row, col};
    // Piece* selectedPiece = nullptr;

    // Если это первый клик (выбор фигуры)
    if (firstClickedPosition.row == -1 && firstClickedPosition.column == -1) {
        if (squares[row][col].button->icon().isNull()) {
            return;
        }
        // Запоминаем выбранную фигуру
        firstClickedPosition = clickedPosition;
        squares[row][col].button->setStyleSheet("background-color: #00b4d8");
        return;

    } else {
        // Проверяем, что кликнули не по той же клетке
        if (clickedPosition.row == firstClickedPosition.row &&
            clickedPosition.column == firstClickedPosition.column) {
            firstClickedPosition = {-1, -1};
            if (squares[row][col].squareColor == WHITE) {
                squares[row][col].button->setStyleSheet("background-color: #ffffff");
            } else {
                squares[row][col].button->setStyleSheet("background-color: #fb6f92");
            }
            return;
        }

        Piece* clickedPiece = pieces[firstClickedPosition.row][firstClickedPosition.column];

        // Проверка на наличие фигуры на конечной клетке
        if (!squares[clickedPosition.row][clickedPosition.column].button->icon().isNull()) {
            Piece* targetPiece = pieces[clickedPosition.row][clickedPosition.column];
            if (targetPiece && clickedPiece && targetPiece->getColor() == clickedPiece->getColor()) {
                // Фигура того же цвета, ход невалиден
                // ... (возможно, вывести сообщение об ошибке)
                return;
            }
        }

        // Проверка на валидность хода
        if (clickedPiece && clickedPiece->isValidMove(firstClickedPosition, clickedPosition) != 0) {
            // Перемещаем иконку
            squares[clickedPosition.row][clickedPosition.column].button->setIcon(squares[firstClickedPosition.row][firstClickedPosition.column].button->icon());
            squares[clickedPosition.row][clickedPosition.column].button->setIconSize(QSize(50, 50));

            // Очищаем исходную клетку
            squares[firstClickedPosition.row][firstClickedPosition.column].button->setIcon(QIcon());
            squares[firstClickedPosition.row][firstClickedPosition.column].button->setStyleSheet("background-color: #ffffff");
            if (squares[firstClickedPosition.row][firstClickedPosition.column].squareColor == WHITE) {
                squares[firstClickedPosition.row][firstClickedPosition.column].button->setStyleSheet("background-color: #ffffff");
            } else {
                squares[firstClickedPosition.row][firstClickedPosition.column].button->setStyleSheet("background-color: #fb6f92");
            }

            // Обновляем массив pieces
            pieces[clickedPosition.row][clickedPosition.column] = clickedPiece;
            pieces[firstClickedPosition.row][firstClickedPosition.column] = nullptr;

            // Сбрасываем выбор и фон выбранной кнопки
            firstClickedPosition = {-1, -1};
            squares[row][col].button->setStyleSheet("background-color: #ffffff");
            if (squares[row][col].squareColor == WHITE) {
                squares[row][col].button->setStyleSheet("background-color: #ffffff");
            } else {
                squares[row][col].button->setStyleSheet("background-color: #fb6f92");
            }
        }
        else {
            QString errorMessage = "Невозможный ход (" + QString::number(firstClickedPosition.row) + ", " + QString::number(firstClickedPosition.column) + ") to (" + QString::number(clickedPosition.row) + ", " + QString::number(clickedPosition.column) + ").";
            QMessageBox::warning(this, "Невозможный ход", errorMessage);
            return;
        }
    }
}
