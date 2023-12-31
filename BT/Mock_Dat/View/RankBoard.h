#pragma once
#include <iostream>
#include "../Controller/PlayerInformation.h"
#include "../config.h"
using namespace std;
class Rankboard
{
public:
    Rankboard()
    {
        try
        {
            playerInfor.loadFromFile(PLAYER_INFORMATION_PATH);
        }
        catch (const char *error)
        {
            cout << "Error: " << error << endl;
        }
        // playerInfor.clearReadPlayers();
    };
    void show()
    {
        cout << "\n\n\t\t -- RANKBOARD --\n\n";
        for (const Player &player : playerInfor.getPlayers())
        {
            std::cout << "Rank: " << player.getRank() << " , Name: " << player.getName() << ", Wins: " << player.getWinCount() << ", Loses: " << player.getLoseCount() << ", Draws: " << player.getDrawCount()<<" , Score: "<<player.getScore() << std::endl;
        }
        cout << "--------------------------------------------------------\n\n";
        // playerInfor.clearReadPlayers();
    }

private:
    PlayerInformation playerInfor;
};