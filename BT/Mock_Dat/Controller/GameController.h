#pragma once
#include <iostream>
#include "../config.h"
#include "../Model/CaroBoard.h"
#include "../Model/Player.h"
#include"../Controller/PlayerInformation.h"
#define PLAYER_1_INDEX 0
#define PLAYER_2_INDEX 1
#define LOSE 0
#define DRAW 1
#define WIN 2
class GameController
{
public:
    GameController()
    {
        current_player_turn = 0;
        intitializeChessBoard();
        initializePlayers(Player(),Player());

    }
    GameController(const Player &_player_1, const Player &_player_2)
    {
        current_player_turn = 0;
        intitializeChessBoard();
        initializePlayers(_player_1, _player_2);
    }
    void initializePlayers(const Player &_player_1,const Player &_player_2)
    {
        //Copy 2 object
        player_1 = _player_1;
        player_2 = _player_2;
    }
    // Khởi tạo bàn cờ
    void intitializeChessBoard()
    {
        for (int _row = 0; _row < DEFAULT_CHESSBOARD_DIMENSION; _row++)
        {
            for (int _col = 0; _col < DEFAULT_CHESSBOARD_DIMENSION; _col++)
            {
                chessboard.setCell(_row, _col, NON_PLAYER_SIGN);
            }
        }
    }
    std::string getPlayerName(bool _cur_player) { return _cur_player == 0 ? player_1.getName() : player_2.getName(); }
    void setPlayer(bool _cur_player, Player _player)
    {
        if (_cur_player == PLAYER_1_INDEX)
            player_1 = _player;
        else
            player_2 = _player;
    }
    char getChessBoardCell(int _row, int _col)
    {
        return chessboard.getCell(_row, _col);
    }
    bool setChessBoardCell(int _row, int _col)
    {
        if (!current_player_turn) // đang là lượt chơi của player 1 
        {
            if(getChessBoardCell(_row, _col) != NON_PLAYER_SIGN) return false; //Kiểm tra ô đó đã điền hay chưa
            chessboard.setCell(_row, _col, PLAYER_1_SIGN);
            return true;
        }
        else //Đang là lượt chơi player 2
        {
            if(getChessBoardCell(_row, _col) != NON_PLAYER_SIGN) return false; 
            chessboard.setCell(_row, _col, PLAYER_2_SIGN);
            return true;
        }
    }
    bool getPlayerTurn() { return current_player_turn; }
    void setPlayerTurn(bool _turn) { current_player_turn = _turn; }
    int getResult() { return result; }
    void setResult(int _result) { result = _result; }
    // Kiểm tra người thắng
    bool checkWinner(int row, int col)
    {
        int d = 0, k = row, h;
        try
        {
            while (getChessBoardCell(k, col) == getChessBoardCell(row, col))
            {
                bool a = getChessBoardCell(k, col) == getChessBoardCell(row, col);
                // std::cout << "row : " << k << " col : " << col << " r : " << d << std::endl;
                d++;
                k++;
                if (k >= DEFAULT_CHESSBOARD_DIMENSION)
                    break;
            }

            k = row - 1;
            if (row > 0)
            {
                while (getChessBoardCell(k, col) == getChessBoardCell(row, col))
                {
                    // std::cout << "row : " << k << " col : " << col << " - r : " << d << std::endl;
                    d++;
                    k--;
                    if (k < 0)
                        break;
                }
            }

            if (d >= DEFAULT_WIN_CONDITION)
                return true;
        }
        catch (const std::exception &e)
        {
            std::cout << " COT" << e.what() << std::endl;
        }

        // std::cout << "row : " << row << " col : " << col << std::endl;
        //  kiểm tra cột

        d = 0;
        h = col;
        try
        {
            // kiểm tra hàng
            while (getChessBoardCell(row, h) == getChessBoardCell(row, col))
            {
                d++;
                h++;
                if (h >= DEFAULT_CHESSBOARD_DIMENSION)
                    break;
            }
            h = col - 1;
            if (col > 0)
            {
                while (getChessBoardCell(row, h) == getChessBoardCell(row, col))
                {
                    d++;
                    h--;
                    if (h < 0)
                        break;
                }
            }
            if (d >= 4)
                return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "HANG " << e.what() << '\n';
        }

        // kiểm tra đường chéo 1
        h = row;
        k = col;
        d = 0;
        try
        {
            while (getChessBoardCell(h, k) == getChessBoardCell(row, col))
            {
                d++;
                h++;
                k++;
                if (h >= DEFAULT_CHESSBOARD_DIMENSION || k >= DEFAULT_CHESSBOARD_DIMENSION)
                    break;
            }
            h = row - 1;
            k = col - 1;
            if (row > 0 && col > 0)
            {
                while (getChessBoardCell(h, k) == getChessBoardCell(row, col))
                {
                    d++;
                    h--;
                    k--;
                    if (h < 0 || k < 0)
                        break;
                }
            }
            if (d >= 4)
                return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "Cheo 1" << e.what() << '\n';
        }

        // kiểm tra đường chéo 2
        h = row;
        k = col;
        d = 0;
        try
        {
            while (getChessBoardCell(h, k) == getChessBoardCell(row, col))
            {
                d++;
                h++;
                k--;
                if (h >= DEFAULT_CHESSBOARD_DIMENSION || k < 0)
                    break;
            }
            h = row - 1;
            k = col + 1;
            if (row > 0 && col < DEFAULT_CHESSBOARD_DIMENSION-1)
            {
                while (getChessBoardCell(h, k) == getChessBoardCell(row, col))
                {
                    d++;
                    h--;
                    k++;
                    if (k >= DEFAULT_CHESSBOARD_DIMENSION || h < 0)
                        break;
                }
            }
            if (d >= 4)
                return true;
        }
        catch (const std::exception &e)
        {
            std::cout << "CHEo 2 " << e.what() << '\n';
        }

        // nếu không đương chéo nào thỏa mãn thì trả về false.
        return false;
    }

private:
    Player player_1, player_2;
    Caroboard chessboard;
    bool current_player_turn;
    int result;

};