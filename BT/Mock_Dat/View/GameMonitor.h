#pragma once
#include <iostream>
#include <conio.h> // Thư viện cho phép sử dụng _getch()
#include "../Controller/GameController.h"
using namespace std;

class GameMonitor
{
public:
    GameMonitor(const string &player1Name, const string &player2Name)
    {
        gameController.setPlayerName(0, player1Name);
        gameController.setPlayerName(1, player2Name);
        gameState = false;
    }
    void printCurrentChessboard()
    {
        for (int _row = 0; _row < DEFAULT_CHESSBOARD_DIMENSION; _row++)
        {

            for (int _col = 0; _col < DEFAULT_CHESSBOARD_DIMENSION; _col++)
            {
                cout << gameController.getChessBoardCell(_row, _col) << " | ";
            }
            cout << "\n---------------------------------------" << endl;
        }
    }
    void playerEventHandler()
    {

        try
        {
            int player_col_selected, player_row_selected;

            while (true)
            {
                if (gameController.getPlayerTurn())
                {
                    cout << " Player 2 Turn : ";
                }
                else
                {
                    cout << " Player 1 Turn : ";
                }
                cin >> player_row_selected;
                cin >> player_col_selected;
                if (gameController.setChessBoardCell(player_row_selected, player_col_selected))
                {
                    break;
                }
                    cout << "cell " << player_row_selected << " - " << player_col_selected <<" has been exist please select again!"<< endl;
            }
            gameState = gameController.checkWinner(player_row_selected, player_col_selected);
        }
        catch (exception &e)
        {
            cout << e.what() << endl;
        }
    }

    void startGame()
    {
        cout << "Player 1 <" << PLAYER_1_SIGN << "> Player 2 <" << PLAYER_2_SIGN << ">\n"
             << endl;
        do
        {
            printCurrentChessboard();
            playerEventHandler();
            gameController.setPlayerTurn(!gameController.getPlayerTurn());
        } while (gameState != true);
        printCurrentChessboard(); // In ra trạng thái cuối của game
        if (gameController.getPlayerTurn())
            cout << "Player 1 wins!" << endl;
        else
            cout << "Player 2 wins!" << endl;
    }

private:
    GameController gameController;
    bool gameState;
};