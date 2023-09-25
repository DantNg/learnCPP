#pragma once
#include <iostream>
#include <conio.h>
#include "../Controller/GameController.h"
#include "../Controller/PlayerInformation.h"
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
        try
        {
            playerInfor.loadFromFile(PLAYER_INFORMATION_PATH);
        }
        catch (const char *error)
        {
            cout << "Error: " << error << endl;
        }
        cout << "\n\n------------------------------ NEW GAME -----------------------------\n\n"
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
                    // count number of step players
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
    void setupGame()
    {
        // playerInfor.clearSavePlayers();
        string player_1_name, player_2_name;

        cout << "------------------------ Create player --------------------------------\n\n";
        while (true)
        {
            cout << "Enter player 1 name : " << endl;
            cin >> player_1_name;
            // Check if player 1 already exists
            if (playerInfor.checkPlayerExist(player_1_name))
            {
                cout << "Player 1 already exists, do you want to continue with the account? (y/n)" << endl;
                char choose;
                cin >> choose;
                if (choose == 'y')
                {
                    player_1 = playerInfor.getPlayerWithName(player_1_name);
                    break;
                }
            }
            else
            {
                player_1.setName(player_1_name);
                playerInfor.addPlayer(player_1); // add a new player 1  into file
                break;
            }
        };
        // cout<<"Player 1 : " <<player_1.getRank()<<" "<<player_1.getName()<<" "<<player_1.getWinCount()<<endl;
        while (true)
        {
            cout << "Enter player 2 name : " << endl;
            cin >> player_2_name;
            if (playerInfor.checkPlayerExist(player_2_name))
            {
                cout << "Player 2 already exists, do you want to continue with the account? (y/n)" << endl;
                char choose;
                cin >> choose;
                if (choose == 'y')
                {
                    player_2 = playerInfor.getPlayerWithName(player_2_name);
                    break;
                }
            }
            else
            {
                player_2.setName(player_2_name);
                playerInfor.addPlayer(player_2); // Add a new player 2 into file
                break;
            }
        };
         cout << " setup Player 1 " << player_1.getName() << " " << player_1.getWinCount() << " " << player_1.getLoseCount() << " " << endl;
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
            // When the count == number of cells in the caroboard then players will draw
            if (count_step >= DEFAULT_CHESSBOARD_DIMENSION * DEFAULT_CHESSBOARD_DIMENSION)
            {
                gameController.setResult(DRAW);
                break;
            }
        } while (gameState != true);
        printCurrentChessboard(); // Diplay final game state
        if (gameController.getPlayerTurn() && gameState == true)
        {
            cout << "Player 1 wins!" << endl;
            gameController.setResult(WIN);
        }
        else if (!gameController.getPlayerTurn() && gameState == true)
        {
            cout << "Player 2 wins!" << endl;
            gameController.setResult(LOSE);
        }
        else
        {
            cout << "Player 1 draw Player 2!" << endl;
            gameController.setResult(DRAW);
        }

        gameController.updateScore(player_1, player_2);
        playerInfor.modifyPlayer(player_1);
        playerInfor.modifyPlayer(player_2);
        cout << "Player 1 -" << player_1.getName() << " " << player_1.getWinCount() << " " << player_1.getLoseCount() << " " << endl;
        cout << "Player 2 - " << player_2.getName() << " " << player_2.getWinCount() << " " << player_2.getLoseCount() << " " << endl;
        try
        {
            playerInfor.saveToFile(PLAYER_INFORMATION_PATH);
        }
        catch (const char *error)
        {
            cout << "Error : " << error << endl;
        }
    }


private:
    GameController gameController;
    PlayerInformation playerInfor;
    Player player_1;
    Player player_2;
    int gameState;
    int count_step;
};