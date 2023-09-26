// #pragma once
#pragma once
#include "../Model/CaroBoard.h"
#include "../Controller/PlayLogger.h"
#include <iostream>
using namespace std;
class ReplayMonitor
{
public:
    ReplayMonitor()
    {
        // playLogger.loadFromFile("moves.txt");
    }
    void startReplay()
    {
        cout << "--------- Replay ---------\n"
             << endl;
        int i = 1;
        playLogger.getListsRecord(GAME_RECORD_FOLDER);
        files = playLogger.getPlaylists();

        for (string record_file : files)
        {
            cout << i << ". " << record_file << endl;
            i++;
        }
        if(playLogger.getPlaylists().size() == 0) 
        {
            cout << "\nNo recoder file found!\n" << endl;
            return;
        }
        cout << "Select recorder to replay : " << endl;
        selectRecorder();
    }
    void selectRecorder()
    {

        int choice;
        cin >> choice;
        cout << files.at(choice - 1) << endl;
        playLogger.loadFromFile(GAME_RECORD_FOLDER + files.at(choice - 1));
        replay();
    }
    void replay()
    {
        cout << "--------- Start Replay ---------\n"
             << endl;
        queue<string> moves = playLogger.getMoves();
        std::cout << "Cac buoc di:" << std::endl;
        bool turn = true;
        while (!moves.empty())
        {
            // cout << moves.front() << endl;
            int row, col;
            string player_name;
            playLogger.parseMove(moves.front(), player_name, row, col);
            cout << "Turn Player " << player_name << " -> " << row << " " << col << endl;

            moves.pop();

            cout << endl;
            try
            {
                caroboard.setCell(row, col, turn ? PLAYER_1_SIGN : PLAYER_2_SIGN);
            }
            catch (const char *error)
            {
                cout << "Error : " << error << endl;
            }
            std::cout << std::endl;
            for (int _row = 0; _row < DEFAULT_CHESSBOARD_DIMENSION; _row++)
            {

                for (int _col = 0; _col < DEFAULT_CHESSBOARD_DIMENSION; _col++)
                {
                    std::cout << caroboard.getCell(_row, _col) << " | ";
                }
                std::cout << "\n---------------------------------------" << std::endl;
            }
            turn = !turn; // Change player
        }
        cout << "--------- End Replay ---------\n"
             << endl;
    }

private:
    std::vector<std::string> files;
    PlayLogger playLogger;
    Caroboard caroboard;
};
// int main()
// {
//     ReplayMonitor replaymonitor;
//     replaymonitor.startReplay();

//     // PlayLogger playLogger;

//     // // Mô phỏng việc nhập bước đi từ người dùng và lưu vào queue
//     // playLogger.logMove("Dat", 1, 2);
//     // playLogger.logMove("James", 3, 4);
//     // playLogger.logMove("Dat", 5, 6);

//     // // // Lưu dữ liệu từ queue vào file
//     // playLogger.saveToFile();

//     // std::cout << "Dữ liệu đã được lưu vào moves.txt" << std::endl;

//     //   // Đọc dữ liệu từ tệp tin vào queue
//     // playLogger.loadFromFile("file/moves2.txt");

//     // // In ra các bước đi
//     // playLogger.printMoves();

//     return 0;
// }