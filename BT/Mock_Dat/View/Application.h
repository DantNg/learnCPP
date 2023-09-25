#pragma once
#include <iostream>
#include "GameMonitor.h"
#include "RankBoard.h"
using namespace std;
class Application
{
public:
    Application(){};
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
        cout << "Enter player 1 name : " << endl;
        cin >> player_1_name;
        cout << "Enter player 2 name : " << endl;
        cin >> player_2_name;
        GameMonitor gameMonitor(player_1_name,player_2_name);
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
                //Play new game
            case PLAY_NEW_GAME: 
                playNewGame();
                break;
                //View replay game 
            case REPLAY_GAME:
                break;
                //Show rank board
            case RANK_BOARD:
                showRankBoard();
                break;
                //Exit game
            case EXIT_GAME:
                return;
            default:
                break;
            }
        }
    }

private:
    int choice;
    enum Menu
    {
        PLAY_NEW_GAME = 1,
        REPLAY_GAME,
        RANK_BOARD,
        EXIT_GAME
    };
};