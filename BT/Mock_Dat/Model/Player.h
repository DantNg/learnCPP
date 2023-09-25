#pragma once
#include <string>
#include "../config.h"
class Player {
public:
    Player(const std::string& playerName="",int _rank=0,int _win_count=0,int _lose_count=0,int _draw_count = 0) {
        name = playerName;
        rank = _rank;
        win_count = _win_count;
        lose_count = _lose_count;
        draw_count = _draw_count;
    }

    // Phương thức getter cho name
    std::string getName() const {
        return name;
    }

    // Phương thức setter cho name
    void setName(const std::string& playerName) {
        name = playerName;
    }

    // Phương thức getter cho rank
    int getRank() const {
        return rank;
    }

    // Phương thức setter cho rank
    void setRank(int playerRank) {
        rank = playerRank;
    }

    // Phương thức getter cho win_count
    int getWinCount() const {
        return win_count;
    }

    // Phương thức setter cho win_count
    void setWinCount(int count) {
        win_count = count;
    }

    // Phương thức getter cho lose_count
    int getLoseCount() const {
        return lose_count;
    }

    // Phương thức setter cho lose_count
    void setLoseCount(int count) {
        lose_count = count;
    }

    // Phương thức getter cho draw_count
    int getDrawCount() const {
        return draw_count;
    }

    // Phương thức setter cho draw_count
    void setDrawCount(int count) {
        draw_count = count;
    }

private:
    std::string name;
    int rank;
    int win_count;
    int lose_count;
    int draw_count;
};
