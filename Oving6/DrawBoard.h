//
// Created by kwecky on 21.09.20.
//

#ifndef OVING6_DRAWBOARD_H
#define OVING6_DRAWBOARD_H

#include <iostream>
#include "ChessBoard.h"

class ChessboardPrint{
public:
    ChessboardPrint(ChessBoard *board_):board(*board_){

        board.onBoardDraw = [](vector<vector<unique_ptr<ChessBoard::Piece>>> &pieces){
            for(vector<unique_ptr<ChessBoard::Piece>> &column : pieces){
                for(unique_ptr<ChessBoard::Piece> &square : column){
                    ChessBoard::Piece *piece;
                    if(dynamic_cast<ChessBoard::King*>(square.get()) || dynamic_cast<ChessBoard::Knight*>(square.get())){
                        cout << square->shortType() << "|";
                    }else{
                        cout << "   |";
                    }

                }
                cout << "\n";
            }
        };

        board.onMove=[](const ChessBoard::Piece &piece,const std::string &from,const std::string &to){
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };

        board.onPieceRemoved=[](const ChessBoard::Piece &piece,const std::string &to){
            cout << piece.type() << " is being removed from " << to << endl;
        };

        board.onLoose=[](const ChessBoard::Piece &piece){
            cout << piece.color_string() << " lost the game" << endl;
        };
        board.onIllegalMove=[](const ChessBoard::Piece &piece,const std::string &from,const std::string &to){
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };

        board.onEmptySelect=[](const std::string &from){
            cout << "no piece at " << from << endl;
        };
    }
private:
    ChessBoard &board;

};

#endif //OVING6_DRAWBOARD_H
