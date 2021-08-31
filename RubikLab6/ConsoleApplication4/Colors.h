#include <vector>
#include <iostream>
#include <Cube.h>
using namespace std;

#ifndef RUBIK_COLORS_H
#define RUBIK_COLORS_H

class Colors :
        public Cube{

protected:
    vector<vector<char>> vec;

public:
    Colors();


    vector<vector<char>> SolvingByUser();
    vector<vector<char>> SolvingByAlgorithm();

    /// BLUE Moves
    vector<vector<char>> Blue_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Blue_Back_Anti_Clock(vector<vector<char>> vec);

/// RED Moves
    vector<vector<char>> Red_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Red_Back_Anti_Clock(vector<vector<char>> vec);


/// ORANGE Moves
    vector<vector<char>> Orange_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Orange_Back_Anti_Clock(vector<vector<char>> vec);


/// GREEN Moves
    vector<vector<char>> Green_Right_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Right_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Left_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Left_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Up_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Up_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Down_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Down_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Front_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Front_Anti_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Back_Clock(vector<vector<char>> vec);
    vector<vector<char>> Green_Back_Anti_Clock(vector<vector<char>> vec);
};


#endif //RUBIK_COLORS_H
