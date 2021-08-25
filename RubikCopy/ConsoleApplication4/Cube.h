#ifndef RUBIK_CUBE_H
#define RUBIK_CUBE_H

#include <vector>
#include <iostream>
using namespace std;

class Cube {

protected:
    vector<vector<char>> cubeVec;
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};

public:
    Cube(){
        vector<vector<char>> vec1(6, vector<char>(9));
        cubeVec = vec1;
        vec1.clear();

        // загрузка вектора из файла
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = color[i];
                cubeVec[i][j] = ch;
            }
        }


    }

/// Printing the Cube
    void PrintingCube();

/// Rotation of the Side
    vector<char> rotate_clock(vector<char> vec);
    vector<char> rotate_anti_clock(vector<char> vec);

};


#endif //RUBIK_CUBE_H
