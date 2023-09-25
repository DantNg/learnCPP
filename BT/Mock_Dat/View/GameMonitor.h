#pragma once
#include <iostream>
#include <conio.h> // Thư viện cho phép sử dụng _getch()
#include "../Controller/GameController.h"
using namespace std;

class GameMonitor
{
public:
    GameMonitor(const Player &player_1, const Player &player_2)
    {
        gameController.setPlayer(PLAYER_1_INDEX, player_1);
        gameController.setPlayer(PLAYER_2_INDEX, player_2);
        gameState = false;
        count_step = 0;
        cout << "\n\n------------------- NEW GAME -----------------------\n\n"
             << endl;
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
            try
            {
                if (gameController.setChessBoardCell(player_row_selected, player_col_selected))
                {
                    //count number of step players
                    count_step++;
                    break;
                }
                else
                    cout << "cell " << player_row_selected << " - " << player_col_selected << " has been exist please select again!" << endl;
            }
            catch (const char *error)
            {
                cout << "Error : " << error << endl;
            }
        }
        gameState = gameController.checkWinner(player_row_selected, player_col_selected);
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
            //When the count == number of cells in the caroboard then players will draw
            if(count_step >= DEFAULT_CHESSBOARD_DIMENSION*DEFAULT_CHESSBOARD_DIMENSION) 
            {
                gameController.setResult(DRAW);
                break;
            }
        } while (gameState != true);
        printCurrentChessboard(); // Diplay final game state
        if (gameController.getPlayerTurn() && gameState == 1)
        {
            cout << "Player 1 wins!" << endl;
            gameController.setResult(WIN);
        }
        else if (!gameController.getPlayerTurn() && gameState == 1)
        {
            cout << "Player 2 wins!" << endl;
            gameController.setResult(LOSE);
        }
        else  {
            cout << "Player 1 draw Player 2!" << endl;
            gameController.setResult(DRAW);
        }
    }

private:
    GameController gameController;
    int gameState;
    int count_step;
};