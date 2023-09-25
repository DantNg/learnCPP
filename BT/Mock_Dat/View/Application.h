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
        Player player_1;
        Player player_2; 
        GameMonitor gameMonitor(player_1, player_2);
        gameMonitor.setupGame();
        gameMonitor.startGame();
        // gameMonitor.updateGameScore(player_1, player_2);
        // cout<<"Player 1 "<<player_1.getName()<<" "<<player_1.getWinCount() <<" "<<player_1.getLoseCount() <<" "<<endl;
        // playerInfor.modifyPlayer(player_1);
        // cout<<"Player 1 "<<player_1.getName()<<" "<<player_1.getWinCount() <<" "<<player_1.getLoseCount() <<" "<<endl;
        // playerInfor.modifyPlayer(player_2);
        // try{
        //     playerInfor.saveToFile(PLAYER_INFORMATION_PATH);
        // }
        // catch(const char *error)
        // {
        //     cout<<"Error : "<<error<<endl;
        // }
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