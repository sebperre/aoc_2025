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

        result = result + numRotations / 100;
        numRotations = numRotations % 100;

        if (rotationDirection == 'L') {
            if (curPos != 0 && curPos - numRotations <= 0) {
                result++;
            }

            curPos = (curPos - numRotations) % 100;

            // Techincally, you don't have to do this, but I want
            // the output of "Position after..." to not have negative
            // numbers
            if (curPos < 0) {
                curPos = 100 + curPos;
            }
        } else {
            curPos = curPos + numRotations;

            if (curPos >= 100) {
                result++;
            }

            curPos = curPos % 100;
        }

        cout << "Position and result after " << strInput << " is " << curPos << " and " << result << "\n"; 
    }

    cout << "Result is " << result << "\n";

    return 0;
}
