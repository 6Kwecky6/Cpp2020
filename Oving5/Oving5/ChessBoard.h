//
// Created by kwecky on 20.09.20.
//

#ifndef OVING5_CHESSBOARD_H
#define OVING5_CHESSBOARD_H
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        virtual  std::string shortType() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        King(Color color) : Piece(color) {}

        std::string type() const override {
            if(Piece::color == Color::WHITE) return "White king";
            else return "Black king";
        }

        std::string shortType() const override {
            if(Piece::color == Color::WHITE) return "WKi";
            else return "BKi";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            return ((abs(from_x - to_x) < 2) && (abs(from_y - to_y) < 2)) || !((abs(from_x - to_x) == 0) || abs(from_y - to_y) == 0);
        }
    };

    class Knight : public Piece {
    public:
        Knight(Color color) : Piece(color) {}

        std::string type() const override{
            if(Piece::color==Color::WHITE) return "White knight";
            else return "Black knight";
        }

        std::string shortType() const override {
            if(Piece::color == Color::WHITE) return "WKn";
            else return "BKn";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override{
            return (abs(from_x - to_x) == 2 && abs(from_y - to_y)==1)||((abs(from_x - to_x) == 1) && (abs(from_y - to_y) == 2));
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        cout << piece_to->type() << " is being removed from " << to << endl;
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            cout << king->color_string() << " lost the game" << endl;
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                        return false;
                    }
                }
                piece_to = move(piece_from);
                return true;
            } else {
                cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }
};

#endif //OVING5_CHESSBOARD_H
