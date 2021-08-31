#include "Cube.h"
#include "Colors.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(nullptr));

    char ans = 'y';
    char a;

    while (ans == 'y' || ans == 'Y')
    {

        Cube myCube;
        myCube.PrintingCube();
        cout << "\t";
        cout << " Colour Coding:  W = White, R = Red, B = Blue, "
                                        "O = Orange, G = Green, Y = Yellow\n";
        cout << endl;

        cout << " You have to Scramble the Cube, type {A B C D E..... or ABCDE....} from the moves given below: " << endl;
        cout << "  A: Right Clockwise " << endl;
        cout << "  B: Right Anti Clockwise " << endl;
        cout << "  C: Left Clockwise " << endl;
        cout << "  D: Left Anti Clockwise " << endl;
        cout << "  E: Up Clockwise " << endl;
        cout << "  F: Up Anti Clockwise " << endl;
        cout << "  G: Down Clockwise " << endl;
        cout << "  H: Down Anti Clockwise " << endl;
        cout << "  I: Front Clockwise " << endl;
        cout << "  J: Front Anti Clockwise " << endl;
        cout << "  K: Back Clockwise " << endl;
        cout << "  L: Back Anti Clockwise \n\n" << endl;



        Colors c;

        cout << " Choose how to solve the Cube....." << endl;
        cout << "   Type 'C' for Computer to Solve and 'U' to solve youself... " << endl;

        char choice;
        cout << "  Enter Choice: ";
        cin >> choice;
        cout << endl;
        if (choice == 'c' || choice == 'C')
        {
            cout << " Solving Rubik's Cube..... " << endl;
            cout << endl;
            c.SolvingByAlgorithm();
        }
        else if (choice == 'u' || choice == 'U')
        {
            cout << " Let's Start Solving Rubik's Cube..... " << endl;
            cout << endl;
            c.SolvingByUser();
        }


        /// Finally prints Solved cube...
        cout << endl;
        cout << " Solved Rubik's cube is..... " << endl;
        myCube.PrintingCube();

        cout << " Want to Solve again? (y/n): ";
        cin >> ans;
    }

    return 0;
}
