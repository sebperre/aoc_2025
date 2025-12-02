#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream input_data{ "data.txt" };

    if (!input_data)
    {
        cerr << "Could not open";
        return 1;
    }

    string strInput;
    int curPos = 50;
    int numRotations;
    char rotationDirection;
    int result = 0;

    while (input_data >> strInput) {
        rotationDirection = strInput[0];
        numRotations = stoi(strInput.substr(1, strInput.size()));

        if (rotationDirection == 'L') {
            curPos = (curPos - numRotations) % 100;

            // Techincally, you don't have to do this, but I want
            // the output of "Position after..." to not have negative
            // numbers
            if (curPos < 0) {
                curPos = 100 + curPos;
            }
        } else {
            curPos = (curPos + numRotations) % 100;
        }

        cout << "Position after " << strInput << " is " << curPos << "\n"; 

        if (curPos == 0) {
            result++;
            cout << "Hit 0, result is now " << result;
        }
    }

    cout << "Result is " << result << "\n";

    return 0;
}
