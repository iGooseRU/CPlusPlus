#ifndef RUBIK_CUBE_H
#define RUBIK_CUBE_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Cube {

protected:
    vector<vector<char>> cubeVec;
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};

public:
    Cube(char a){
        vector<vector<char>> vec1(6, vector<char>(9));
        cubeVec = vec1;
        vec1.clear();

        // загрузка вектора из файла
        std::cout << "Would u like to import cube? (y/n) \n";
        cin >> a;
        if (a == 'y')
        {
            ifstream fin;
            fin.open("cube.txt");

            if(!fin.is_open())
            {
                cout<<"Cant open file";
            } else {
                int i = 0, j = 0;
                while (!fin.eof())
                {
                    char currentSymb;
                    fin.get(currentSymb);

                    if (currentSymb != '\n')
                    {
                        cubeVec[i][j] = currentSymb;
                        j++;
                    } else {
                        j = 0;
                        i++;
                    }
                }
            }

        } else {
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    char ch = color[i];
                    cubeVec[i][j] = ch;
                }
            }
        }
        PrintingCube(cubeVec);
    }

    Cube(){
        vector<vector<char>> vec1(6, vector<char>(9));
        cubeVec = vec1;
        vec1.clear();

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = color[i];
                cubeVec[i][j] = ch;
            }
        }
    };

/// Printing the Cube
    void PrintingCube(vector<vector<char>> V);
    void PrintingCube();

/// Rotation of the Side
    vector<char> rotate_clock(vector<char> vec);
    vector<char> rotate_anti_clock(vector<char> vec);

};


#endif //RUBIK_CUBE_H
