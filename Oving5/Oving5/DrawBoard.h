//
// Created by kwecky on 21.09.20.
//

#ifndef OVING5_DRAWBOARD_H
#define OVING5_DRAWBOARD_H

#include <iostream>
#include "ChessBoard.h"

const void Draw(vector<vector<unique_ptr<ChessBoard::Piece>>> *board) {
    for(vector<unique_ptr<ChessBoard::Piece>> &column : *board){
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
}

#endif //OVING5_DRAWBOARD_H
