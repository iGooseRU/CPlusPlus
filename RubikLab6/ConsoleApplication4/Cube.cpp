#include "Cube.h"
#include <cstdlib>
#include <ctime>

using namespace std;

/// Rotation of Side Clockwise
vector<char> Cube::rotate_clock(vector<char> vec)
{
    char a = vec[2];
    char b = vec[1];
    char c = vec[0];

    vec[2] = vec[0];
    vec[1] = vec[3];
    vec[0] = vec[6];

    vec[0] = vec[6];
    vec[3] = vec[7];
    vec[6] = vec[8];

    vec[6] = vec[8];
    vec[7] = vec[5];
    vec[8] = vec[2];

    vec[8] = a;
    vec[5] = b;
    vec[2] = c;

    return vec;
}

/// Rotation of Side Anti-Clockwise
vector<char> Cube::rotate_anti_clock(vector<char> vec)
{
    char a = vec[0];
    char b = vec[1];
    char c = vec[2];

    vec[0] = vec[2];
    vec[1] = vec[5];
    vec[2] = vec[8];

    vec[2] = vec[8];
    vec[5] = vec[7];
    vec[8] = vec[6];

    vec[8] = vec[6];
    vec[7] = vec[3];
    vec[6] = vec[0];

    vec[6] = a;
    vec[3] = b;
    vec[0] = c;

    return vec;
}


/**
 *   Skeleton of the Rubik's Cube
 *
 *                 ------------
 *                 | W0 W1 W2 |
 *                 | W3 W4 W5 |
 *                 | W6 W7 W8 |
 *                 ------------
 *   ------------  ------------  ------------  ------------
 *   | R0 R1 R2 |  | B0 B1 B2 |  | O0 O1 O2 |  | G0 G1 G2 |
 *   | R3 R4 R5 |  | B3 B4 B5 |  | O3 O4 O5 |  | G3 G4 G5 |
 *   | R6 R7 R8 |  | B6 B7 B8 |  | O6 O7 O8 |  | G6 G7 G8 |
 *   ------------  ------------  ------------  ------------
 *                 ------------
 *                 | Y0 Y1 Y2 |
 *                 | Y3 Y4 Y5 |
 *                 | Y6 Y7 Y8 |
 *                 ------------
 *
 *  Colour Coding:  W = White, R = Red, B = Blue, O = Orange, G = Green, Y = Yellow
 *
 *  Vec = {
 *          0 : WHITE
 *          1 : RED
 *          2 : BLUE
 *          3 : ORANGE
 *          4 : GREEN
 *          5 : YELLOW
 *        }
 *
 */

/// Printing the Cube.....
void Cube::PrintingCube(vector<vector<char>> V)
{
    /// Printing WHITE Layer...
    cout << endl;
    int cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << V[0][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;

    /// Printing RED, BLUE, ORANGE and GREEN Layer...
    cout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        cout << "\t | " << V[2][j] << " " << V[2][j + 1] << " " << V[2][j + 2] << " | ";
        cout << "| " << V[1][j] << " " << V[1][j + 1] << " " << V[1][j + 2] << " | ";
        cout << "| " << V[4][j] << " " << V[4][j + 1] << " " << V[4][j + 2] << " | ";
        cout << "| " << V[3][j] << " " << V[3][j + 1] << " " << V[3][j + 2] << " | ";
        cout << endl;
    }
    cout << "\t --------- --------- --------- ---------" << endl;

    /// Printing YELLOW Layer...
    cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << V[5][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;
    cout << endl;
}

void Cube::PrintingCube()
{
    cout << endl;
    int cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << cubeVec[0][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;

    /// Printing RED, BLUE, ORANGE and GREEN Layer...
    cout << "\t --------- --------- --------- ---------" << endl;
    for (int j = 0; j < 9; j += 3)
    {
        cout << "\t | " << cubeVec[2][j] << " " << cubeVec[2][j + 1] << " " << cubeVec[2][j + 2] << " | ";
        cout << "| " << cubeVec[1][j] << " " << cubeVec[1][j + 1] << " " << cubeVec[1][j + 2] << " | ";
        cout << "| " << cubeVec[4][j] << " " << cubeVec[4][j + 1] << " " << cubeVec[4][j + 2] << " | ";
        cout << "| " << cubeVec[3][j] << " " << cubeVec[3][j + 1] << " " << cubeVec[3][j + 2] << " | ";
        cout << endl;
    }
    cout << "\t --------- --------- --------- ---------" << endl;

    /// Printing YELLOW Layer...
    cnt = 0;
    cout << "\t           ---------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t           ";
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << cubeVec[5][cnt] << " ";
            cnt++;
        }
        cout << "|" << endl;
    }
    cout << "\t           ---------" << endl;
    cout << endl;
}

void Cube::importCube() {
    ifstream fin;
    fin.open("cube.txt");

    if (!fin.is_open()) {
        cout << "Cant open file";
    } else {
        int i = 0, j = 0;
        while (!fin.eof()) {
            char currentSymb;
            fin.get(currentSymb);

            if (currentSymb != '\n') {
                cubeVec[i][j] = currentSymb;
                j++;
            } else {
                j = 0;
                i++;
            }
        }
    }
}

std::string Cube::generateCube() {
    std::string commands = "ABCDEFGHIJKL";
    std::string generatedString = "";
    int b = rand() % 5 + 1;

    for (int i = 0; i < b; ++i) {
        int a = rand() % 12;
        generatedString += commands[a];
    }

    std::cout << generatedString << std::endl;

    return generatedString;
}
