#include "Colors.h"
#include <fstream>
using namespace std;

Colors::Colors() {

    std::string str = "";
    std::cout << "1: Import cube \n 2: Generate cube \n 3: Enter Sequence\n";
    char a; cin >> a;

    bool flag = false;

    switch (a) {
        case '1':
            importCube();
            break;

        case '2':
            str = generateCube();
            flag = true;

        default:
            if (!flag){
                cout << " Now Enter Sequence to Scramble the Cube: ";
                cin >> str;
            }

            for (int i = 0; i < str.length(); i++)
            {
                char ch = str.at(i);
                if (islower(ch))
                {
                    ch = toupper(ch);
                }
                if (ch == 'A' || ch == 'M' || ch == 'Y')
                {
                    cubeVec = Blue_Right_Clock(cubeVec);
                }
                else if (ch == 'B' || ch == 'N' || ch == 'Z')
                {
                    cubeVec = Blue_Right_Anti_Clock(cubeVec);
                }
                else if (ch == 'C' || ch == 'O')
                {
                    cubeVec = Blue_Left_Clock(cubeVec);
                }
                else if (ch == 'D' || ch == 'P')
                {
                    cubeVec = Blue_Left_Anti_Clock(cubeVec);
                }
                else if (ch == 'E' || ch == 'Q')
                {
                    cubeVec = Blue_Up_Clock(cubeVec);
                }
                else if (ch == 'F' || ch == 'R')
                {
                    cubeVec = Blue_Up_Anti_Clock(cubeVec);
                }
                else if (ch == 'G' || ch == 'S')
                {
                    cubeVec = Blue_Down_Clock(cubeVec);
                }
                else if (ch == 'H' || ch == 'T')
                {
                    cubeVec = Blue_Down_Anti_Clock(cubeVec);
                }
                else if (ch == 'I' || ch == 'U')
                {
                    cubeVec = Blue_Front_Clock(cubeVec);
                }
                else if (ch == 'J' || ch == 'V')
                {
                    cubeVec = Blue_Front_Anti_Clock(cubeVec);
                }
                else if (ch == 'K' || ch == 'W')
                {
                    cubeVec = Blue_Back_Clock(cubeVec);
                }
                else if (ch == 'L' || ch == 'X')
                {
                    cubeVec = Blue_Back_Anti_Clock(cubeVec);
                }
            }
            break;
    }

        // saving vector in file
        ofstream fout("cube.txt");
        int cnt = 0;
        for(int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                fout << cubeVec[i][j];
            }
            fout << "\n";
        }

    vec = cubeVec;

    cout << " Scrambled Cube is.....\n";
    PrintingCube(vec);
}



vector<vector<char>> Colors::SolvingByUser()
{
    cout << " Rules:" << endl;
    cout << "  1) You have to enter the SIDE of the cube and the MOVE to be used." << endl;
    cout << "  2) To enter the SIDE, type following color codes:" << endl;
    cout << "       'R' : RED Side" << endl;
    cout << "       'B' : BLUE Side" << endl;
    cout << "       'O' : ORANGE Side" << endl;
    cout << "       'G' : GREEN Side" << endl;
    cout << "      And" << endl;
    cout << "       'stop'  : To STOP Solving" << endl;
    cout << "  3) To enter the MOVE, type following move codes:" << endl;
    cout << "       'A' : Right Clockwise " << endl;
    cout << "       'B' : Right Anti Clockwise " << endl;
    cout << "       'C' : Left Clockwise " << endl;
    cout << "       'D' : Left Anti Clockwise " << endl;
    cout << "       'E' : Up Clockwise " << endl;
    cout << "       'F' : Up Anti Clockwise " << endl;
    cout << "       'G' : Down Clockwise " << endl;
    cout << "       'H' : Down Anti Clockwise " << endl;
    cout << "       'I' : Front Clockwise " << endl;
    cout << "       'J' : Front Anti Clockwise " << endl;
    cout << "       'K' : Back Clockwise " << endl;
    cout << "       'L' : Back Anti Clockwise " << endl;
    cout << endl;

    string side;
    char move;
    char color[6] = {'W', 'B', 'R', 'G', 'O', 'Y'};

    while (side != "stop")
    {
        Side:
        cout << " Enter Side: ";
        cin >> side;
        char ch = side[0];
        if (islower(ch))
        {
            ch = toupper(ch);
        }
        if (side == "stop")
        {
            break;
        }

        switch (ch)
        {
            case 'R':
            MoveR:
                cout << " Enter Move: ";
                cin >> move;
                if (islower(move))
                {
                    move = toupper(move);
                }
                switch (move)
                {
                    case 'A':
                        vec = Red_Right_Clock(vec);
                        break;
                    case 'B':
                        vec = Red_Right_Anti_Clock(vec);
                        break;
                    case 'C':
                        vec = Red_Left_Clock(vec);
                        break;
                    case 'D':
                        vec = Red_Left_Anti_Clock(vec);
                        break;
                    case 'E':
                        vec = Red_Up_Clock(vec);
                        break;
                    case 'F':
                        vec = Red_Up_Anti_Clock(vec);
                        break;
                    case 'G':
                        vec = Red_Down_Clock(vec);
                        break;
                    case 'H':
                        vec = Red_Down_Anti_Clock(vec);
                        break;
                    case 'I':
                        vec = Red_Front_Clock(vec);
                        break;
                    case 'J':
                        vec = Red_Front_Anti_Clock(vec);
                        break;
                    case 'K':
                        vec = Red_Back_Clock(vec);
                        break;
                    case 'L':
                        vec = Red_Back_Anti_Clock(vec);
                        break;

                    default:
                        cout << "   Invalid Move!!, Enter again..." << endl;
                        goto MoveR;
                        break;
                }
            case 'B':
            MoveB:
                cout << " Enter Move: ";
                cin >> move;
                if (islower(move))
                {
                    move = toupper(move);
                }
                switch (move)
                {
                    case 'A':
                        vec = Blue_Right_Clock(vec);
                        break;
                    case 'B':
                        vec = Blue_Right_Anti_Clock(vec);
                        break;
                    case 'C':
                        vec = Blue_Left_Clock(vec);
                        break;
                    case 'D':
                        vec = Blue_Left_Anti_Clock(vec);
                        break;
                    case 'E':
                        vec = Blue_Up_Clock(vec);
                        break;
                    case 'F':
                        vec = Blue_Up_Anti_Clock(vec);
                        break;
                    case 'G':
                        vec = Blue_Down_Clock(vec);
                        break;
                    case 'H':
                        vec = Blue_Down_Anti_Clock(vec);
                        break;
                    case 'I':
                        vec = Blue_Front_Clock(vec);
                        break;
                    case 'J':
                        vec = Blue_Front_Anti_Clock(vec);
                        break;
                    case 'K':
                        vec = Blue_Back_Clock(vec);
                        break;
                    case 'L':
                        vec = Blue_Back_Anti_Clock(vec);
                        break;

                    default:
                        cout << "   Invalid Move!!, Enter again..." << endl;
                        goto MoveB;
                        break;
                }
                break;
            case 'O':
            MoveO:
                cout << " Enter Move: ";
                cin >> move;
                if (islower(move))
                {
                    move = toupper(move);
                }
                switch (move)
                {
                    case 'A':
                        vec = Orange_Right_Clock(vec);
                        break;
                    case 'B':
                        vec = Orange_Right_Anti_Clock(vec);
                        break;
                    case 'C':
                        vec = Orange_Left_Clock(vec);
                        break;
                    case 'D':
                        vec = Orange_Left_Anti_Clock(vec);
                        break;
                    case 'E':
                        vec = Orange_Up_Clock(vec);
                        break;
                    case 'F':
                        vec = Orange_Up_Anti_Clock(vec);
                        break;
                    case 'G':
                        vec = Orange_Down_Clock(vec);
                        break;
                    case 'H':
                        vec = Orange_Down_Anti_Clock(vec);
                        break;
                    case 'I':
                        vec = Orange_Front_Clock(vec);
                        break;
                    case 'J':
                        vec = Orange_Front_Anti_Clock(vec);
                        break;
                    case 'K':
                        vec = Orange_Back_Clock(vec);
                        break;
                    case 'L':
                        vec = Orange_Back_Anti_Clock(vec);
                        break;

                    default:
                        cout << "   Invalid Move!!, Enter again..." << endl;
                        goto MoveO;
                        break;
                }
            case 'G':
            MoveG:
                cout << " Enter Move: ";
                cin >> move;
                if (islower(move))
                {
                    move = toupper(move);
                }
                switch (move)
                {
                    case 'A':
                        vec = Green_Right_Clock(vec);
                        break;
                    case 'B':
                        vec = Green_Right_Anti_Clock(vec);
                        break;
                    case 'C':
                        vec = Green_Left_Clock(vec);
                        break;
                    case 'D':
                        vec = Green_Left_Anti_Clock(vec);
                        break;
                    case 'E':
                        vec = Green_Up_Clock(vec);
                        break;
                    case 'F':
                        vec = Green_Up_Anti_Clock(vec);
                        break;
                    case 'G':
                        vec = Green_Down_Clock(vec);
                        break;
                    case 'H':
                        vec = Green_Down_Anti_Clock(vec);
                        break;
                    case 'I':
                        vec = Green_Front_Clock(vec);
                        break;
                    case 'J':
                        vec = Green_Front_Anti_Clock(vec);
                        break;
                    case 'K':
                        vec = Green_Back_Clock(vec);
                        break;
                    case 'L':
                        vec = Green_Back_Anti_Clock(vec);
                        break;

                    default:
                        cout << "   Invalid Move!! Enter again..." << endl;
                        goto MoveG;
                        break;
                }
                break;

            default:
                cout << "   Invalid Side!! Enter again..." << endl;
                goto Side;
                break;
        }

        cout << "  Applied the Move... Cube looks like..." << endl;
        PrintingCube(vec);
        cout << endl;

        /// Checking if Cube is solved.....
        char flag = 'T';
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (vec[i][j] != color[i])
                {
                    flag = 'F';
                    break;
                }
            }
            if (flag == 'F')
            {
                break;
            }
        }
        if (flag == 'T')
        {
            cout << "Hurray!!! You have Solved the Rubik's Cube..... :)" << endl;
            break;
        }
    }

    return vec;
}

vector<vector<char>> Colors::SolvingByAlgorithm()
{
     //  Stage 1 : Solving WHITE CROSS in Upper Layer

     /// Solving BLUE--WHITE Edge in Upper Layer
    while (vec[0][7] != 'W' || vec[1][1] != 'B')
    {
        /**  If Edge is in Upper Layer  */
        if ((vec[2][1] == 'W' && vec[0][3] == 'B') || (vec[2][1] == 'B' && vec[0][3] == 'W'))
        {
            vec = Blue_Up_Anti_Clock(vec);
        }
        else if ((vec[3][1] == 'W' && vec[0][1] == 'B') || (vec[3][1] == 'B' && vec[0][1] == 'W'))
        {
            vec = Blue_Up_Anti_Clock(vec);
            vec = Blue_Up_Anti_Clock(vec);
        }
        else if ((vec[4][1] == 'W' && vec[0][5] == 'B') || (vec[4][1] == 'B' && vec[0][5] == 'W'))
        {
            vec = Blue_Up_Clock(vec);
        }

            /**  If Edge is in Middle Layer  */
        else if ((vec[1][3] == 'W' && vec[2][5] == 'B') || (vec[1][3] == 'B' && vec[2][5] == 'W'))
        {
            vec = Blue_Front_Clock(vec);
        }
        else if ((vec[1][5] == 'W' && vec[4][3] == 'B') || (vec[1][5] == 'B' && vec[4][3] == 'W'))
        {
            vec = Blue_Front_Anti_Clock(vec);
        }
        else if ((vec[3][3] == 'W' && vec[4][5] == 'B') || (vec[3][3] == 'B' && vec[4][5] == 'W'))
        {
            vec = Blue_Right_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[3][5] == 'W' && vec[2][3] == 'B') || (vec[3][5] == 'B' && vec[2][3] == 'W'))
        {
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }

            /**  If Edge is in Bottom Layer  */
        else if ((vec[2][7] == 'W' && vec[5][3] == 'B') || (vec[2][7] == 'B' && vec[5][3] == 'W'))
        {
            vec = Blue_Down_Clock(vec);
        }
        else if ((vec[4][7] == 'W' && vec[5][5] == 'B') || (vec[4][7] == 'B' && vec[5][5] == 'W'))
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[3][7] == 'W' && vec[5][7] == 'B') || (vec[3][7] == 'B' && vec[5][7] == 'W'))
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }

        if ((vec[1][7] == 'W' && vec[5][1] == 'B') || (vec[1][7] == 'B' && vec[5][1] == 'W'))
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
        }

        while (vec[0][7] != 'W' || vec[1][1] != 'B')
        {
            vec = Red_Right_Anti_Clock(vec);
            vec = Red_Up_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Up_Anti_Clock(vec);
        }
    }

    /// Solving ORANGE--WHITE Edge in Upper Layer
    while (vec[0][5] != 'W' || vec[4][1] != 'O')
    {
        /**  If Edge is in Upper Layer  */
        if ((vec[2][1] == 'W' && vec[0][3] == 'O') || (vec[2][1] == 'O' && vec[0][3] == 'W'))
        {
            vec = Orange_Back_Anti_Clock(vec);
            vec = Orange_Back_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if ((vec[3][1] == 'W' && vec[0][1] == 'O') || (vec[3][1] == 'O' && vec[0][1] == 'W'))
        {
            vec = Orange_Right_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
        }

            /**  If Edge is in Middle Layer  */
        else if ((vec[4][3] == 'W' && vec[1][5] == 'O') || (vec[4][3] == 'O' && vec[1][5] == 'W'))
        {
            vec = Orange_Front_Clock(vec);
        }
        else if ((vec[4][5] == 'W' && vec[3][3] == 'O') || (vec[4][5] == 'O' && vec[3][3] == 'W'))
        {
            vec = Orange_Front_Anti_Clock(vec);
        }
        else if ((vec[1][3] == 'W' && vec[2][5] == 'O') || (vec[1][3] == 'O' && vec[2][5] == 'W'))
        {
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
        }
        else if ((vec[3][5] == 'W' && vec[2][3] == 'O') || (vec[3][5] == 'O' && vec[2][3] == 'W'))
        {
            vec = Orange_Right_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
        }

            /**  If Edge is in Bottom Layer  */
        else if ((vec[1][7] == 'W' && vec[5][1] == 'O') || (vec[1][7] == 'O' && vec[5][1] == 'W'))
        {
            vec = Orange_Down_Clock(vec);
        }
        else if ((vec[3][7] == 'W' && vec[5][7] == 'O') || (vec[3][7] == 'O' && vec[5][7] == 'W'))
        {
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if ((vec[2][7] == 'W' && vec[5][3] == 'O') || (vec[2][7] == 'O' && vec[5][3] == 'W'))
        {
            vec = Orange_Down_Clock(vec);
            vec = Orange_Down_Clock(vec);
        }

        if ((vec[4][7] == 'W' && vec[5][5] == 'O') || (vec[4][7] == 'O' && vec[5][5] == 'W'))
        {
            vec = Orange_Front_Clock(vec);
            vec = Orange_Front_Clock(vec);
        }

        while (vec[0][5] != 'W' || vec[4][1] != 'O')
        {
            vec = Blue_Right_Anti_Clock(vec);
            vec = Blue_Up_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
            vec = Blue_Up_Anti_Clock(vec);
        }
    }

    /// Solving GREEN--WHITE Edge in Upper Layer
    while (vec[0][1] != 'W' || vec[3][1] != 'G')
    {
        /**  If Edge is in Upper Layer  */
        if ((vec[2][1] == 'W' && vec[0][3] == 'G') || (vec[2][1] == 'G' && vec[0][3] == 'W'))
        {
            vec = Green_Right_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
        }

            /**  If Edge is in Middle Layer  */
        else if ((vec[3][3] == 'W' && vec[4][5] == 'G') || (vec[3][3] == 'G' && vec[4][5] == 'W'))
        {
            vec = Green_Front_Clock(vec);
        }
        else if ((vec[3][5] == 'W' && vec[2][3] == 'G') || (vec[3][5] == 'G' && vec[2][3] == 'W'))
        {
            vec = Green_Front_Anti_Clock(vec);
        }
        else if ((vec[4][3] == 'W' && vec[1][5] == 'G') || (vec[4][3] == 'G' && vec[1][5] == 'W'))
        {
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
        }
        else if ((vec[2][5] == 'W' && vec[1][3] == 'G') || (vec[2][5] == 'G' && vec[1][3] == 'W'))
        {
            vec = Green_Right_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
        }

            /**  If Edge is in Bottom Layer  */
        else if ((vec[4][7] == 'W' && vec[5][5] == 'G') || (vec[4][7] == 'G' && vec[5][5] == 'W'))
        {
            vec = Green_Down_Clock(vec);
        }
        else if ((vec[2][7] == 'W' && vec[5][3] == 'G') || (vec[2][7] == 'G' && vec[5][3] == 'W'))
        {
            vec = Green_Down_Anti_Clock(vec);
        }
        else if ((vec[1][7] == 'W' && vec[5][1] == 'G') || (vec[1][7] == 'G' && vec[5][1] == 'W'))
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Down_Clock(vec);
        }

        if ((vec[3][7] == 'W' && vec[5][7] == 'G') || (vec[3][7] == 'G' && vec[5][7] == 'W'))
        {
            vec = Green_Front_Clock(vec);
            vec = Green_Front_Clock(vec);
        }

        while (vec[0][1] != 'W' || vec[3][1] != 'G')
        {
            vec = Orange_Right_Anti_Clock(vec);
            vec = Orange_Up_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
            vec = Orange_Up_Anti_Clock(vec);
        }
    }

    /// Solving RED--WHITE Edge in Upper Layer
    while (vec[0][3] != 'W' || vec[2][1] != 'R')
    {
        /**  If Edge is in Middle Layer  */
        if ((vec[2][3] == 'W' && vec[4][5] == 'R') || (vec[2][3] == 'R' && vec[4][5] == 'W'))
        {
            vec = Red_Front_Clock(vec);
        }
        else if ((vec[2][5] == 'W' && vec[1][3] == 'R') || (vec[2][5] == 'R' && vec[1][3] == 'W'))
        {
            vec = Red_Front_Anti_Clock(vec);
        }
        else if ((vec[3][3] == 'W' && vec[4][5] == 'R') || (vec[3][3] == 'R' && vec[4][5] == 'W'))
        {
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
        }
        else if ((vec[1][5] == 'W' && vec[4][3] == 'R') || (vec[1][5] == 'R' && vec[4][3] == 'W'))
        {
            vec = Red_Right_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Right_Anti_Clock(vec);
        }

            /**  If Edge is in Bottom Layer  */
        else if ((vec[3][7] == 'W' && vec[5][7] == 'R') || (vec[3][7] == 'R' && vec[5][7] == 'W'))
        {
            vec = Red_Down_Clock(vec);
        }
        else if ((vec[1][7] == 'W' && vec[5][1] == 'R') || (vec[1][7] == 'R' && vec[5][1] == 'W'))
        {
            vec = Red_Down_Anti_Clock(vec);
        }
        else if ((vec[4][7] == 'W' && vec[5][5] == 'R') || (vec[4][7] == 'R' && vec[5][5] == 'W'))
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Down_Clock(vec);
        }

        if ((vec[2][7] == 'W' && vec[5][3] == 'R') || (vec[2][7] == 'R' && vec[5][3] == 'W'))
        {
            vec = Red_Front_Clock(vec);
            vec = Red_Front_Clock(vec);
        }

        while (vec[0][3] != 'W' || vec[2][1] != 'R')
        {
            vec = Green_Right_Anti_Clock(vec);
            vec = Green_Up_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Up_Anti_Clock(vec);
        }
    }

    cout << "  Stage 1 Completed! WHITE CROSS is ready!" << endl;
    PrintingCube(vec);


     //  Stage 2 : Solving WHITE CORNERS in UPPER Layer

    /// Solving RED--BLUE--WHITE Corner in Upper Layer
    while (vec[0][6] != 'W' || vec[2][2] != 'R' || vec[1][0] != 'B')
    {
        /**  If Corner is in Upper Layer  */
        if ((vec[0][8] == 'W' || vec[1][2] == 'W' || vec[4][0] == 'W') &&
            (vec[0][8] == 'R' || vec[1][2] == 'R' || vec[4][0] == 'R') &&
            (vec[0][8] == 'B' || vec[1][2] == 'B' || vec[4][0] == 'B'))
        {
            vec = Red_Back_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Back_Clock(vec);
        }
        else if ((vec[0][2] == 'W' || vec[4][2] == 'W' || vec[3][0] == 'W') &&
                 (vec[0][2] == 'R' || vec[4][2] == 'R' || vec[3][0] == 'R') &&
                 (vec[0][2] == 'B' || vec[4][2] == 'B' || vec[3][0] == 'B'))
        {
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
        }
        else if ((vec[0][0] == 'W' || vec[3][2] == 'W' || vec[2][0] == 'W') &&
                 (vec[0][0] == 'R' || vec[3][2] == 'R' || vec[2][0] == 'R') &&
                 (vec[0][0] == 'B' || vec[3][2] == 'B' || vec[2][0] == 'B'))
        {
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
        }

            /**  If Corner is in Bottom Layer  */
        else if ((vec[1][8] == 'W' || vec[4][6] == 'W' || vec[5][2] == 'W') &&
                 (vec[1][8] == 'R' || vec[4][6] == 'R' || vec[5][2] == 'R') &&
                 (vec[1][8] == 'B' || vec[4][6] == 'B' || vec[5][2] == 'B'))
        {
            vec = Red_Down_Anti_Clock(vec);
        }
        else if ((vec[4][8] == 'W' || vec[3][6] == 'W' || vec[5][8] == 'W') &&
                 (vec[4][8] == 'R' || vec[3][6] == 'R' || vec[5][8] == 'R') &&
                 (vec[4][8] == 'B' || vec[3][6] == 'B' || vec[5][8] == 'B'))
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Down_Clock(vec);
        }
        else if ((vec[3][8] == 'W' || vec[2][6] == 'W' || vec[5][6] == 'W') &&
                 (vec[3][8] == 'R' || vec[2][6] == 'R' || vec[5][6] == 'R') &&
                 (vec[3][8] == 'B' || vec[2][6] == 'B' || vec[5][6] == 'B'))
        {
            vec = Red_Down_Clock(vec);
        }

        while (vec[0][6] != 'W' || vec[2][2] != 'R' || vec[1][0] != 'B')
        {
            vec = Red_Right_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Right_Clock(vec);
            vec = Red_Down_Clock(vec);
        }
    }

    /// Solving BLUE--ORANGE--WHITE Corner in Upper Layer
    while (vec[0][8] != 'W' || vec[1][2] != 'B' || vec[4][0] != 'O')
    {
        /**  If Corner is in Upper Layer  */
        if ((vec[0][2] == 'W' || vec[4][2] == 'W' || vec[3][0] == 'W') &&
            (vec[0][2] == 'B' || vec[4][2] == 'B' || vec[3][0] == 'B') &&
            (vec[0][2] == 'O' || vec[4][2] == 'O' || vec[3][0] == 'O'))
        {
            vec = Blue_Back_Anti_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Back_Clock(vec);
        }
        else if ((vec[0][0] == 'W' || vec[3][2] == 'W' || vec[2][0] == 'W') &&
                 (vec[0][0] == 'B' || vec[3][2] == 'B' || vec[2][0] == 'B') &&
                 (vec[0][0] == 'O' || vec[3][2] == 'O' || vec[2][0] == 'O'))
        {
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
        }

            /**  If Corner is in Bottom Layer  */
        else if ((vec[2][8] == 'W' || vec[1][6] == 'W' || vec[5][0] == 'W') &&
                 (vec[2][8] == 'B' || vec[1][6] == 'B' || vec[5][0] == 'B') &&
                 (vec[2][8] == 'O' || vec[1][6] == 'O' || vec[5][0] == 'O'))
        {
            vec = Blue_Down_Clock(vec);
        }
        else if ((vec[4][8] == 'W' || vec[3][6] == 'W' || vec[5][8] == 'W') &&
                 (vec[4][8] == 'B' || vec[3][6] == 'B' || vec[5][8] == 'B') &&
                 (vec[4][8] == 'O' || vec[3][6] == 'O' || vec[5][8] == 'O'))
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[3][8] == 'W' || vec[2][6] == 'W' || vec[5][6] == 'W') &&
                 (vec[3][8] == 'B' || vec[2][6] == 'B' || vec[5][6] == 'B') &&
                 (vec[3][8] == 'O' || vec[2][6] == 'O' || vec[5][6] == 'O'))
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }

        while (vec[0][8] != 'W' || vec[1][2] != 'B' || vec[4][0] != 'O')
        {
            vec = Blue_Right_Anti_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Right_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }
    }

    /// Solving ORANGE--GREEN--WHITE Corner in Upper Layer
    while (vec[0][2] != 'W' || vec[4][2] != 'O' || vec[3][0] != 'G')
    {
        /**  If Corner is in Upper Layer  */
        if ((vec[0][0] == 'W' || vec[3][2] == 'W' || vec[2][0] == 'W') &&
            (vec[0][0] == 'O' || vec[3][2] == 'O' || vec[2][0] == 'O') &&
            (vec[0][0] == 'G' || vec[3][2] == 'G' || vec[2][0] == 'G'))
        {
            vec = Orange_Back_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Back_Clock(vec);
        }

            /**  If Corner is in Bottom Layer  */
        else if ((vec[1][8] == 'W' || vec[4][6] == 'W' || vec[5][2] == 'W') &&
                 (vec[1][8] == 'O' || vec[4][6] == 'O' || vec[5][2] == 'O') &&
                 (vec[1][8] == 'G' || vec[4][6] == 'G' || vec[5][2] == 'G'))
        {
            vec = Orange_Down_Clock(vec);
        }
        else if ((vec[3][8] == 'W' || vec[2][6] == 'W' || vec[5][6] == 'W') &&
                 (vec[3][8] == 'O' || vec[2][6] == 'O' || vec[5][6] == 'O') &&
                 (vec[3][8] == 'G' || vec[2][6] == 'G' || vec[5][6] == 'G'))
        {
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if ((vec[2][8] == 'W' || vec[1][6] == 'W' || vec[5][0] == 'W') &&
                 (vec[2][8] == 'O' || vec[1][6] == 'O' || vec[5][0] == 'O') &&
                 (vec[2][8] == 'G' || vec[1][6] == 'G' || vec[5][0] == 'G'))
        {
            vec = Orange_Down_Clock(vec);
            vec = Orange_Down_Clock(vec);
        }

        while (vec[0][2] != 'W' || vec[4][2] != 'O' || vec[3][0] != 'G')
        {
            vec = Orange_Right_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Right_Clock(vec);
            vec = Orange_Down_Clock(vec);
        }
    }

    /// Solving GREEN--RED--WHITE Corner in Upper Layer
    while (vec[0][0] != 'W' || vec[3][2] != 'G' || vec[2][0] != 'R')
    {
        /**  If Corner is in Bottom Layer  */
        if ((vec[4][8] == 'W' || vec[3][6] == 'W' || vec[5][8] == 'W') &&
            (vec[4][8] == 'G' || vec[3][6] == 'G' || vec[5][8] == 'G') &&
            (vec[4][8] == 'R' || vec[3][6] == 'R' || vec[5][8] == 'R'))
        {
            vec = Green_Down_Clock(vec);
        }
        else if ((vec[2][8] == 'W' || vec[1][6] == 'W' || vec[5][0] == 'W') &&
                 (vec[2][8] == 'G' || vec[1][6] == 'G' || vec[5][0] == 'G') &&
                 (vec[2][8] == 'R' || vec[1][6] == 'R' || vec[5][0] == 'R'))
        {
            vec = Green_Down_Anti_Clock(vec);
        }
        else if ((vec[1][8] == 'W' || vec[4][6] == 'W' || vec[5][2] == 'W') &&
                 (vec[1][8] == 'G' || vec[4][6] == 'G' || vec[5][2] == 'G') &&
                 (vec[1][8] == 'R' || vec[4][6] == 'R' || vec[5][2] == 'R'))
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Down_Clock(vec);
        }

        while (vec[0][0] != 'W' || vec[3][2] != 'G' || vec[2][0] != 'R')
        {
            vec = Green_Right_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Right_Clock(vec);
            vec = Green_Down_Clock(vec);
        }
    }

    cout << "  Stage 2 Completed! UPPER LAYER is ready! " << endl;
    PrintingCube(vec);


     //  Stage 3 : Solving RED, BLUE, ORANGE and GREEN EDGES in MIDDLE LAYER

    /// Solving RED--BLUE Edge in Middle Layer
    while (vec[1][3] != 'B' || vec[2][5] != 'R')
    {
        /**  If Edge is in Bottom Layer  */
        if (vec[2][7] == 'B' && vec[5][3] == 'R')
        {
            vec = Blue_Down_Clock(vec);
        }
        else if (vec[1][7] == 'R' && vec[5][1] == 'B')
        {
            vec = Red_Down_Anti_Clock(vec);
        }
        else if ((vec[4][7] == 'B' && vec[5][5] == 'R') || (vec[4][7] == 'R' && vec[5][5] == 'B'))
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[3][7] == 'B' && vec[5][7] == 'R') || (vec[3][7] == 'R' && vec[5][7] == 'B'))
        {
            vec = Blue_Down_Clock(vec);
        }

            /**  If Edge is in Middle Layer  */
        else if (vec[1][3] == 'R' && vec[2][5] == 'B')
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Front_Clock(vec);
        }
        else if ((vec[2][3] == 'B' && vec[3][5] == 'R') || (vec[2][3] == 'R' && vec[3][5] == 'B'))
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Front_Clock(vec);
        }
        else if ((vec[3][3] == 'B' && vec[4][5] == 'R') || (vec[3][3] == 'R' && vec[4][5] == 'B'))
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
        }
        else if ((vec[4][3] == 'B' && vec[1][5] == 'R') || (vec[4][3] == 'R' && vec[1][5] == 'B'))
        {
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Front_Clock(vec);
        }

        /// Apply Left Shift Algo from Blue
        if (vec[1][7] == 'B' && vec[5][1] == 'R')
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Front_Clock(vec);
        }
            /// Apply Right Shift Algo from Red
        else if (vec[2][7] == 'R' && vec[5][3] == 'B')
        {
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Right_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Right_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Front_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
        }
    }

    /// Solving ORANGE--BLUE Edge in Middle Layer
    while (vec[1][5] != 'B' || vec[4][3] != 'O')
    {
        /**  If Edge is in Bottom Layer  */
        if (vec[4][7] == 'B' && vec[5][5] == 'O')
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if (vec[1][7] == 'O' && vec[5][1] == 'B')
        {
            vec = Orange_Down_Clock(vec);
        }
        else if ((vec[3][7] == 'B' && vec[5][7] == 'O') || (vec[3][7] == 'O' && vec[5][7] == 'B'))
        {
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if ((vec[2][7] == 'B' && vec[5][3] == 'O') || (vec[2][7] == 'O' && vec[5][3] == 'B'))
        {
            vec = Blue_Down_Clock(vec);
        }

            /**  If Edge is in Middle Layer  */
        else if (vec[4][3] == 'B' && vec[1][5] == 'O')
        {
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Front_Clock(vec);
        }
        else if ((vec[3][3] == 'B' && vec[4][5] == 'O') || (vec[3][3] == 'O' && vec[4][5] == 'B'))
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
        }
        else if ((vec[2][3] == 'B' && vec[3][5] == 'O') || (vec[2][3] == 'O' && vec[3][5] == 'B'))
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Front_Clock(vec);
        }

        /// Apply Left Shift Algo from Blue
        if (vec[4][7] == 'O' && vec[5][5] == 'B')
        {
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Front_Clock(vec);
        }
            /// Apply Right Shift Algo from Red
        else if (vec[1][7] == 'B' && vec[5][1] == 'O')
        {
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Right_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Right_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
        }
    }

    /// Solving RED--GREEN Edge in Middle Layer
    while (vec[2][3] != 'R' || vec[3][5] != 'G')
    {
        /**  If Edge is in Bottom Layer  */
        if (vec[2][7] == 'G' && vec[5][3] == 'R')
        {
            vec = Green_Down_Anti_Clock(vec);
        }
        else if (vec[3][7] == 'R' && vec[5][7] == 'G')
        {
            vec = Red_Down_Clock(vec);
        }
        else if ((vec[4][7] == 'G' && vec[5][5] == 'R') || (vec[4][7] == 'R' && vec[5][5] == 'G'))
        {
            vec = Green_Down_Clock(vec);
        }
        else if ((vec[1][7] == 'G' && vec[5][1] == 'R') || (vec[1][7] == 'R' && vec[5][1] == 'G'))
        {
            vec = Red_Down_Anti_Clock(vec);
        }

        /**  If Edge is in Middle Layer  */
        if ((vec[3][3] == 'G' && vec[4][5] == 'R') || (vec[3][3] == 'R' && vec[4][5] == 'G'))
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
        }
        else if (vec[2][3] == 'G' && vec[3][5] == 'R')
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Front_Clock(vec);
        }

        /// Apply Left Shift Algo from Blue
        if (vec[2][7] == 'R' && vec[5][3] == 'G')
        {
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Front_Clock(vec);
        }
            /// Apply Right Shift Algo from Red
        else if (vec[3][7] == 'G' && vec[5][7] == 'R')
        {
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Right_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Right_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
        }
    }

    /// Solving ORANGE--GREEN Edge in Middle Layer
    while (vec[3][3] != 'G' || vec[4][5] != 'O')
    {
        /**  If Edge is in Bottom Layer  */
        if (vec[3][7] == 'O' && vec[5][7] == 'G')
        {
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if (vec[4][7] == 'G' && vec[5][5] == 'O')
        {
            vec = Green_Down_Clock(vec);
        }
        else if ((vec[1][7] == 'G' && vec[5][1] == 'O') || (vec[1][7] == 'O' && vec[5][1] == 'G'))
        {
            vec = Orange_Down_Clock(vec);
        }
        else if ((vec[2][7] == 'G' && vec[5][3] == 'O') || (vec[2][7] == 'O' && vec[5][3] == 'G'))
        {
            vec = Green_Down_Anti_Clock(vec);
        }

        /**  If Edge is in Middle Layer  */
        if (vec[3][3] == 'O' && vec[4][5] == 'G')
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
        }

        /// Apply Left Shift Algo from Blue
        if (vec[3][7] == 'G' && vec[5][7] == 'O')
        {
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Front_Clock(vec);
        }
            /// Apply Right Shift Algo from Red
        else if (vec[4][7] == 'O' && vec[5][5] == 'G')
        {
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Right_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Right_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Front_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
        }
    }

    cout << "  Stage 3 Completed! MIDDLE LAYER is ready! " << endl;
    PrintingCube(vec);


     //  Stage 4 : Solving YELLOW CROSS in BOTTOM Layer

    /// Solving YELLOW CROSS
    while (vec[5][1] != 'Y' || vec[5][5] != 'Y' || vec[5][7] != 'Y' || vec[5][3] != 'Y')
    {
        /**  Case 1 : Single Yellow Center in Position  */
        if ((vec[5][1] != 'Y' && vec[5][5] != 'Y' && vec[5][7] != 'Y' && vec[5][3] != 'Y') ||
            (vec[5][1] == 'Y' && vec[5][5] != 'Y' && vec[5][7] != 'Y' && vec[5][3] != 'Y') ||
            (vec[5][1] != 'Y' && vec[5][5] == 'Y' && vec[5][7] != 'Y' && vec[5][3] != 'Y') ||
            (vec[5][1] != 'Y' && vec[5][5] != 'Y' && vec[5][7] == 'Y' && vec[5][3] != 'Y') ||
            (vec[5][1] != 'Y' && vec[5][5] != 'Y' && vec[5][7] != 'Y' && vec[5][3] == 'Y'))
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
        }

            /**  Case 2 : Two Yellow Edge in L position   */
        else if (vec[5][1] == 'Y' && vec[5][3] == 'Y' && vec[5][7] != 'Y' && vec[5][5] != 'Y')
        {
            vec = Green_Front_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
        }
        else if (vec[5][1] != 'Y' && vec[5][5] != 'Y' && vec[5][7] == 'Y' && vec[5][3] == 'Y')
        {
            vec = Orange_Front_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
        }
        else if (vec[5][1] != 'Y' && vec[5][5] == 'Y' && vec[5][7] == 'Y' && vec[5][3] != 'Y')
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
        }
        else if (vec[5][1] == 'Y' && vec[5][5] == 'Y' && vec[5][7] != 'Y' && vec[5][3] != 'Y')
        {
            vec = Red_Front_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
        }

            /**  Case 3 : Horizontal Line in Position  */
        else if (vec[5][3] == 'Y' && vec[5][5] == 'Y')
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
        }
        else if (vec[5][1] == 'Y' && vec[5][7] == 'Y')
        {
            vec = Red_Front_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
        }
    }

    cout << "  Stage 4 Completed! YELLOW CROSS is ready! " << endl;
    PrintingCube(vec);


     // Stage 5 : Solving YELLOW CORNERS in Bottom Layer

    /// Solving CORNERS of YELLOW Layer
    while (vec[5][0] != 'Y' || vec[5][2] != 'Y' || vec[5][8] != 'Y' || vec[5][6] != 'Y')
    {
        /**  Case 1 : No Corners in Position  */
        if (vec[5][0] != 'Y' && vec[5][2] != 'Y' && vec[5][8] != 'Y' && vec[5][6] != 'Y')
        {
            if (vec[4][6] == 'Y')
            {
                vec = Blue_Left_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Left_Anti_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Left_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Left_Anti_Clock(vec);
            }
            else if (vec[1][6] == 'Y')
            {
                vec = Red_Left_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Left_Anti_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Left_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Left_Anti_Clock(vec);
            }
            else if (vec[2][6] == 'Y')
            {
                vec = Green_Left_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Left_Anti_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Left_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Left_Anti_Clock(vec);
            }
            else if (vec[3][6] == 'Y')
            {
                vec = Orange_Left_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Left_Anti_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Left_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Left_Anti_Clock(vec);
            }
        }

            /**  Case 2 : One Corner in position   */
        else if (vec[5][2] == 'Y' && vec[5][0] != 'Y' && vec[5][8] != 'Y' && vec[5][6] != 'Y')
        {
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
        }
        else if (vec[5][0] == 'Y' && vec[5][2] != 'Y' && vec[5][8] != 'Y' && vec[5][6] != 'Y')
        {
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
        }
        else if (vec[5][6] == 'Y' && vec[5][0] != 'Y' && vec[5][2] != 'Y' && vec[5][8] != 'Y')
        {
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
        }
        else if (vec[5][8] == 'Y' && vec[5][0] != 'Y' && vec[5][2] != 'Y' && vec[5][6] != 'Y')
        {
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
        }

            /**  Case 3 : Any Two Corners in Position  */
        else if (vec[1][8] == 'Y')
        {
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
        }
        else if (vec[2][8] == 'Y')
        {
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Down_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
        }
        else if (vec[3][8] == 'Y')
        {
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Down_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
        }
        else if (vec[4][8] == 'Y')
        {
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Down_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
        }
    }

    cout << "  Stage 5 Completed! YELLOW LAYER is ready!" << endl;
    PrintingCube(vec);


     // Stage 6 : Solving RED, BLUE, ORANGE & GREEN CORNERS in BOTTOM Layer

    /// Solving CORNERS of YELLOW Layer
    while (vec[1][8] != 'B' || vec[1][6] != 'B' || vec[2][8] != 'R' || vec[2][6] != 'R' ||
           vec[3][8] != 'G' || vec[3][6] != 'G' || vec[4][8] != 'O' || vec[4][6] != 'O')
    {
        /**  Adjacent Corners  */
        if (vec[2][8] == 'R' && vec[2][6] == 'R')
        {
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Front_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Back_Clock(vec);
            vec = Orange_Back_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Front_Anti_Clock(vec);
            vec = Orange_Left_Anti_Clock(vec);
            vec = Orange_Back_Clock(vec);
            vec = Orange_Back_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Left_Clock(vec);
            vec = Orange_Down_Anti_Clock(vec);
        }
        else if (vec[3][8] == 'G' && vec[3][6] == 'G')
        {
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Back_Clock(vec);
            vec = Blue_Back_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Front_Anti_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Back_Clock(vec);
            vec = Blue_Back_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if (vec[4][8] == 'O' && vec[4][6] == 'O')
        {
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Front_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
        }
        else if (vec[1][8] == 'B' && vec[1][6] == 'B')
        {
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Front_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
        }
        else if ((vec[2][8] == 'B' && vec[2][6] == 'B') || (vec[3][8] == 'R' && vec[3][6] == 'R') ||
                 (vec[4][8] == 'G' && vec[4][6] == 'G') || (vec[1][8] == 'O' && vec[1][6] == 'O'))
        {
            vec = Blue_Down_Clock(vec);
        }
        else if ((vec[4][8] == 'B' && vec[4][6] == 'B') || (vec[1][8] == 'R' && vec[1][6] == 'R') ||
                 (vec[2][8] == 'G' && vec[2][6] == 'G') || (vec[3][8] == 'O' && vec[3][6] == 'O'))
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[3][8] == 'B' && vec[3][6] == 'B') || (vec[4][8] == 'R' && vec[4][6] == 'R') ||
                 (vec[1][8] == 'G' && vec[1][6] == 'G') || (vec[2][8] == 'O' && vec[2][6] == 'O'))
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }

            /**  Diagonal Corners   */
        else if (vec[1][6] == 'B' && vec[2][8] == 'R' && vec[3][6] == 'G' && vec[4][8] == 'O')
        {
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Front_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Front_Anti_Clock(vec);
            vec = Red_Left_Anti_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Back_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Left_Clock(vec);
            vec = Red_Down_Anti_Clock(vec);
        }
        else if (vec[2][6] == 'R' && vec[3][8] == 'G' && vec[4][6] == 'O' && vec[1][8] == 'B')
        {
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Front_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Front_Anti_Clock(vec);
            vec = Green_Left_Anti_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Back_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Left_Clock(vec);
            vec = Green_Down_Anti_Clock(vec);
        }
        else if ((vec[1][6] == 'R' && vec[2][8] == 'G' && vec[3][6] == 'O' && vec[4][8] == 'B') ||
                 (vec[4][6] == 'B' && vec[1][8] == 'R' && vec[2][6] == 'G' && vec[3][8] == 'O'))
        {
            vec = Blue_Down_Anti_Clock(vec);
        }
        else if ((vec[2][6] == 'B' && vec[3][8] == 'R' && vec[4][6] == 'G' && vec[1][8] == 'O') ||
                 (vec[3][6] == 'R' && vec[4][8] == 'G' && vec[1][6] == 'O' && vec[2][8] == 'B'))
        {
            vec = Blue_Down_Clock(vec);
        }
        else if ((vec[3][6] == 'B' && vec[4][8] == 'R' && vec[1][6] == 'G' && vec[2][8] == 'O') ||
                 (vec[4][6] == 'R' && vec[1][8] == 'G' && vec[2][6] == 'O' && vec[3][8] == 'B'))
        {
            vec = Blue_Down_Clock(vec);
            vec = Blue_Down_Clock(vec);
        }
    }

    cout << "  Stage 6 Completed! CORNERS of BOTTOM LAYER is ready!" << endl;
    PrintingCube(vec);


    // Stage 7 : Solving RED, BLUE, ORANGE & GREEN EDGES in BOTTOM LAYER

    /// Solving Edges of YELLOW Layer
    while (vec[1][7] != 'B' || vec[2][7] != 'R' || vec[3][7] != 'G' || vec[4][7] != 'O')
    {
        if (vec[1][7] == 'B')
        {
            /// Anti-Clockwise Rotation
            if (vec[3][7] == 'O')
            {
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Down_Anti_Clock(vec);
                vec = Green_Right_Clock(vec);
                vec = Green_Left_Anti_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Right_Anti_Clock(vec);
                vec = Green_Left_Clock(vec);
                vec = Green_Down_Anti_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
            }
                /// Clockwise Rotation
            else if (vec[3][7] == 'R')
            {
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Right_Clock(vec);
                vec = Green_Left_Anti_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Right_Anti_Clock(vec);
                vec = Green_Left_Clock(vec);
                vec = Green_Down_Clock(vec);
                vec = Green_Front_Clock(vec);
                vec = Green_Front_Clock(vec);
            }
        }
        else if (vec[2][7] == 'R')
        {
            /// Anti-Clockwise Rotation
            if (vec[4][7] == 'B')
            {
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Down_Anti_Clock(vec);
                vec = Orange_Right_Clock(vec);
                vec = Orange_Left_Anti_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Right_Anti_Clock(vec);
                vec = Orange_Left_Clock(vec);
                vec = Orange_Down_Anti_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
            }
                /// Clockwise Rotation
            else if (vec[4][7] == 'G')
            {
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Right_Clock(vec);
                vec = Orange_Left_Anti_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Right_Anti_Clock(vec);
                vec = Orange_Left_Clock(vec);
                vec = Orange_Down_Clock(vec);
                vec = Orange_Front_Clock(vec);
                vec = Orange_Front_Clock(vec);
            }
        }
        else if (vec[3][7] == 'G')
        {
            /// Anti-Clockwise Rotation
            if (vec[1][7] == 'R')
            {
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Down_Anti_Clock(vec);
                vec = Blue_Right_Clock(vec);
                vec = Blue_Left_Anti_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Right_Anti_Clock(vec);
                vec = Blue_Left_Clock(vec);
                vec = Blue_Down_Anti_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
            }
                /// Clockwise Rotation
            else if (vec[1][7] == 'O')
            {
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Right_Clock(vec);
                vec = Blue_Left_Anti_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Right_Anti_Clock(vec);
                vec = Blue_Left_Clock(vec);
                vec = Blue_Down_Clock(vec);
                vec = Blue_Front_Clock(vec);
                vec = Blue_Front_Clock(vec);
            }
        }
        else if (vec[4][7] == 'O')
        {
            /// Anti-Clockwise Rotation
            if (vec[2][7] == 'G')
            {
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Down_Anti_Clock(vec);
                vec = Red_Right_Clock(vec);
                vec = Red_Left_Anti_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Right_Anti_Clock(vec);
                vec = Red_Left_Clock(vec);
                vec = Red_Down_Anti_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
            }
                /// Clockwise Rotation
            else if (vec[2][7] == 'B')
            {
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Right_Clock(vec);
                vec = Red_Left_Anti_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Right_Anti_Clock(vec);
                vec = Red_Left_Clock(vec);
                vec = Red_Down_Clock(vec);
                vec = Red_Front_Clock(vec);
                vec = Red_Front_Clock(vec);
            }
        }
            /// Anti-Clockwise Rotation
        else if (vec[1][7] == 'R')
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Right_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Right_Anti_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Anti_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
        }
            /// Clockwise Rotation
        else if (vec[1][7] == 'O' || vec[1][7] == 'G')
        {
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Right_Clock(vec);
            vec = Blue_Left_Anti_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Right_Anti_Clock(vec);
            vec = Blue_Left_Clock(vec);
            vec = Blue_Down_Clock(vec);
            vec = Blue_Front_Clock(vec);
            vec = Blue_Front_Clock(vec);
        }
    }
    cout << "  Stage 7 Completed! BOTTOM LAYER is ready" << endl;
    PrintingCube(vec);
    cout <<endl;

    cout << " The Rubik's cube is ready! " << endl;
    return vec;
}
