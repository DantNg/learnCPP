#pragma once
#include <iostream>
#include "GameMonitor.h"
#include "RankBoard.h"
#include "../config.h"
using namespace std;
class Application
{
public:
    Application()
    {
        cout << "\n\n\t\t Loading players information\n\n";
        try
        {
            playerInfor.loadFromFile(PLAYER_INFORMATION_PATH);
        }
        catch (const char *error)
        {
            cout << "Error: " << error << endl;
        }
        for (const Player &player : playerInfor.getPlayers())
        {
            std::cout << "Rank: " << player.getRank() << " , Name: " << player.getName() << ", Wins: " << player.getWinCount() << ", Loses: " << player.getLoseCount() << ", Draws: " << player.getDrawCount() << std::endl;
        }
        cout << "--------------------------------------------------------\n\n";
    };
    void menu()
    {
        cout << "Select menu " << endl;
        cout << "1. Play new game" << endl;
        cout << "2. Replay game" << endl;
        cout << "3. Rank board" << endl;
        cout << "4. Exit" << endl;
    }
    void setChoice()
    {
        cout << "Select your choice : " << endl;
        int user_choice;
        cin >> user_choice;
        choice = user_choice;
    }
    void playNewGame()
    {
        string player_1_name, player_2_name;
        Player player_1;
        Player player_2;
        cout << "------------------------ Create player --------------------------------\n\n";
        while (true)
        {
            cout << "Enter player 1 name : " << endl;
            cin >> player_1_name;
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
                break;
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
                break;
        }; 
        
        GameMonitor gameMonitor(player_1_name, player_2_name);
        gameMonitor.startGame();
    }
    void showRankBoard()
    {
        Rankboard rankboard;
        rankboard.show();
    }
    void run()
    {
        while (true)
        {
            menu();
            setChoice();
            switch (static_cast<Menu>(choice))
            {
                // Play new game
            case PLAY_NEW_GAME:
                playNewGame();
                break;
                // View replay game
            case REPLAY_GAME:
                break;
                // Show rank board
            case RANK_BOARD:
                showRankBoard();
                break;
                // Exit game
            case EXIT_GAME:
                return;
            default:
                break;
            }
        }
    }

private:
    int choice;
    PlayerInformation playerInfor;
    enum Menu
    {
        PLAY_NEW_GAME = 1,
        REPLAY_GAME,
        RANK_BOARD,
        EXIT_GAME
    };
};