#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "../Model/Player.h"
#include "../config.h"
#define ERROR_CANNOT_READ_FILE "Can't read the file"
class PlayerInformation
{
private:
    std::vector<Player> readplayer;

public:
    std::vector<Player> getPlayers() const { return readplayer; }
    // Trả về thông tin 1 player đã tồn tại theo tên
    Player getPlayerWithName(const std::string name) const
    {
        for (const Player &player : readplayer)
        {
            if (player.getName() == name)
            {
                return player;
            }
        }
        return Player(); // trả về mặc đinh
    }
    // Thêm một người chơi vào danh sách
    void addPlayer(const Player &player)
    {
        readplayer.push_back(player);
    }
    void modifyPlayer(Player &_player)
    {
        for (Player &player : readplayer)
        {
            if (player.getName() == _player.getName())
            {
                player = _player; // copy player
                break;
            }
        }
    }
    // Kiểm tra tên người chơi đã tồn tại hay chưa
    bool checkPlayerExist(std::string name)
    {
        // std::cout << "checkPlayerExist" << std::endl;
        for (const Player &player : readplayer)
        {
            if (player.getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    // Hàm so sánh tùy chỉnh cho std::sort
    bool compareByScore(const Player &player1, const Player &player2)
    {
        return player1.getScore() > player2.getScore(); // Sắp xếp từ lớn đến bé
    }
    void sortPlayers()
    {
        std::sort(readplayer.begin(), readplayer.end(), [](const Player &player1, const Player &player2)
                  {
                      return player1.getScore() > player2.getScore(); // Sắp xếp từ lớn đến bé
                  });
    }
    // Lưu thông tin của tất cả người chơi vào file
    void saveToFile(const std::string &filename)
    {
        sortPlayers();
        std::ofstream file(filename);
        if (file.is_open())
        {
            int num_of_players = readplayer.size();
            int i = 0;
            for (Player &player : readplayer)
            {

                player.setRank(num_of_players - i);
                file << player.getName() << "," << player.getRank() << ","
                     << player.getWinCount() << "," << player.getLoseCount() << ","
                     << player.getDrawCount() <<","<<player.getScore()<< std::endl;
                i++;
            }
            file.close();
        }
        else
            throw "Error when saving to file " + filename;
    }

    // Đọc thông tin người chơi từ file và thêm vào danh sách
    void loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream iss(line);
                std::string name;
                int rank, win_count, lose_count, draw_count, score_count;
                if (std::getline(iss, name, ',') &&
                    iss >> rank &&
                    iss.ignore(1) && // Bỏ qua ký tự ','
                    iss >> win_count &&
                    iss.ignore(1) && // Bỏ qua ký tự ','
                    iss >> lose_count &&
                    iss.ignore(1) && // Bỏ qua ký tự ','
                    iss >> draw_count &&
                    iss.ignore(1) && // Bỏ qua ký tự ','
                    iss >> score_count)
                {
                    Player player(name, rank, win_count, lose_count, draw_count, score_count);
                    readplayer.push_back(player);
                }
                else
                {
                    // std::cout << "Error when read data from file : " << line << std::endl;
                    throw ERROR_CANNOT_READ_FILE;
                }
            }
            file.close();
        }
    }
    void clearReadPlayers()
    {
        readplayer.clear();
    }

    // Xóa tất cả thông tin người chơi trong danh sách và file
    void clearAll()
    {
        readplayer.clear();
        std::remove(PLAYER_INFORMATION_PATH); // Xóa file
    }
};

// int main()
// {
//     // Tạo và thêm các đối tượng Player vào PlayerInformation
//     PlayerInformation playerInfo;
//     Player player1("Ales", 1, 5, 2, 3);
//     Player player2("James", 2, 4, 3, 1);
//     playerInfo.addPlayer(player1);
//     playerInfo.addPlayer(player2);

//     // Lưu thông tin của tất cả người chơi vào file
//     playerInfo.saveToFile(PLAYER_INFORMATION_PATH);

//     std::cout << "Save player_info.txt" << std::endl;

//     // Đọc thông tin người chơi từ file và hiển thị
//     playerInfo.loadFromFile(PLAYER_INFORMATION_PATH);
//     for (const Player &player : playerInfo.getPlayers())
//     {
//         std::cout << "Name: " << player.getName() << ", Rank: " << player.getRank() << ", Wins: " << player.getWinCount() << ", Loses: " << player.getLoseCount() << ", Draws: " << player.getDrawCount() << std::endl;
//     }

//     // // Xóa tất cả thông tin người chơi trong danh sách và file
//     // playerInfo.clearAll();

//     // std::cout << "Tất cả thông tin người chơi đã bị xóa." << std::endl;

//     return 0;
// }
