#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sstream>
#include <dirent.h>
#include "../config.h"
#define OFFSET_LISTS_FILE 2
class PlayLogger
{
private:
    std::queue<std::string> moves;
    std::vector<std::string> playlist;
    Caroboard caroboard;

public:
    // Thêm bước đi vào queue
    void logMove(const std::string &playerName, int row, int col)
    {
        std::string move = playerName + "," + std::to_string(row) + "," + std::to_string(col);
        moves.push(move);
    }
    void parseMove(const std::string &movestring, std::string &playerName, int &row, int &col)
    {
        std::istringstream iss(movestring);
        std::getline(iss, playerName, ',');
        iss >> row;
        iss.ignore(1); // Bỏ qua dấu ',' sau số row
        iss >> col;
    }
    // Lưu dữ liệu từ queue vào file
    void saveToFile()
    {
        // Lấy thời gian hiện tại
        std::time_t now = std::time(nullptr);
        struct std::tm *tm = std::localtime(&now);

        // Tạo tên file dựa trên thời gian
        char filename[100];
        std::strftime(filename, sizeof(filename), LOG_RECORD_PATH, tm);

        std::ofstream file(filename);
        if (file.is_open())
        {
            while (!moves.empty())
            {
                file << moves.front() << std::endl;
                moves.pop();
            }
            file.close();
            // std::cout << "Dữ liệu đã được lưu vào " << filename << std::endl;
        }
    }

    // Đọc dữ liệu từ file và thêm vào queue
    void loadFromFile(const std::string &filename)
    {
        std::ifstream file(filename);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                moves.push(line);
            }
            file.close();
        }
    }

    // Lấy danh sách các bản ghi trong một folder và lưu vào playlist
    void getListsRecord(const char *folderPath)
    {
        DIR *dr;
        struct dirent *en;
        dr = opendir(folderPath); // open all or present directory
        if (dr)
        {
            while ((en = readdir(dr)) != NULL)
            {
                // printf("%s\n", en->d_name); // print all directory name
                playlist.push_back(en->d_name);
            }
            closedir(dr); // close all directory
        }
        // clear temp file
        if (playlist.size() >= OFFSET_LISTS_FILE)
        {
            playlist.erase(playlist.begin(), playlist.begin() + OFFSET_LISTS_FILE);
        }
    }
    std::vector<std::string> getPlaylists() { return playlist; }
    std::queue<std::string> getMoves() { return moves; }
};

// int main() {
//     PlayLogger playLogger;

//     // Mô phỏng việc nhập bước đi từ người dùng và lưu vào queue
//     playLogger.logMove("Dat", 1, 2);
//     playLogger.logMove("Alice", 3, 4);
//     playLogger.logMove("Bob", 5, 6);

//     // Lưu dữ liệu từ queue vào file
//     playLogger.saveToFile("moves.txt");

//     std::cout << "Dữ liệu đã được lưu vào moves.txt" << std::endl;

//       // Đọc dữ liệu từ tệp tin vào queue
//     playLogger.loadFromFile("moves.txt");

//     // In ra các bước đi
//     playLogger.printMoves();

//     return 0;
// }
