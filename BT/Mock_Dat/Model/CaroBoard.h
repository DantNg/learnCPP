#pragma once
#include <exception>
#include "../config.h"
#define ERROR_INVALID_ACCESS_ELEMENT_OUT_OF_RANGE "Invalid access element out of range of caro board"

class Caroboard
{
public:
    Caroboard(int size = DEFAULT_CHESSBOARD_DIMENSION)
    {
        // Khởi tạo bàn cờ với kích thước size x size và các ô trống
        boardSize = size;
        chessboard = new char *[boardSize];
        for (int i = 0; i < boardSize; i++)
        {
            chessboard[i] = new char[boardSize];
            for (int j = 0; j < boardSize; j++)
            {
                chessboard[i][j] = NON_PLAYER_SIGN;
            }
        }
    }

    // Destructor để giải phóng bộ nhớ khi đối tượng bị hủy
    ~Caroboard()
    {
        for (int i = 0; i < boardSize; i++)
        {
            delete[] chessboard[i];
        }
        delete[] chessboard;
    }

    // Phương thức getter để lấy giá trị của ô cờ tại vị trí (row, col)
    char getCell(int row, int col) const
    {
        if (isValidPosition(row, col))
        {
            return chessboard[row][col];
        }
        else
        {
            // Xử lý lỗi hoặc trả về một giá trị mặc định
            throw ERROR_INVALID_ACCESS_ELEMENT_OUT_OF_RANGE;
            // return DEFAULT_RETURN_NOT_VALID_ACCESS;
        }
    }

    // Phương thức setter để đặt giá trị cho ô cờ tại vị trí (row, col)
    void setCell(int row, int col, char symbol)
    {
        if (isValidPosition(row, col))
        {
            chessboard[row][col] = symbol;
        }
        else
        {
            // Xử lý lỗi nếu vị trí không hợp lệ
            throw ERROR_INVALID_ACCESS_ELEMENT_OUT_OF_RANGE;
        }
    }

private:
    int boardSize;
    char **chessboard;

    // Phương thức kiểm tra xem vị trí (row, col) có hợp lệ trên bàn cờ hay không
    bool isValidPosition(int row, int col) const
    {
        return (row >= 0 && row < boardSize && col >= 0 && col < boardSize);
    }
};
