#pragma once
#include <iostream>
#include "../Controller/PlayerInformation.h"
#include "../config.h"
using namespace std;
class Rankboard
{
public:
    Rankboard(){};
    void show()
    {
        cout << "\n\n\t\t RANKBOARD\n\n";
        playerInfor.loadFromFile(PLAYER_INFORMATION_PATH);
        for (const Player &player : playerInfor.getPlayers())
        {
            std::cout<< "Rank: " << player.getRank() << " , Name: " << player.getName()  << ", Wins: " << player.getWinCount() << ", Loses: " << player.getLoseCount() << ", Draws: " << player.getDrawCount() << std::endl;
        }
        cout<<"--------------------------------------------------------\n\n";
    }

private:
    PlayerInformation playerInfor;
};