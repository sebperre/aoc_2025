#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    ifstream input_data{ "data.txt" };

    if (!input_data)
    {
        cerr << "Could not open";
        return 1;
    }

    long long int result = 0;
    string strInput;

    while (getline(input_data, strInput, ',')) {
        size_t splitIndex = strInput.find('-');

        string startNumber = strInput.substr(0, splitIndex);
        long long int iStartNumber = stol(startNumber);

        long long int endNumber = stol(strInput.substr(splitIndex + 1, strInput.length()));

        cout << "Processing " << startNumber << " and " << endNumber << "\n";

        if (startNumber.size() % 2 == 1) {
            iStartNumber = pow(10, startNumber.size());
            startNumber = to_string(iStartNumber);

            if (iStartNumber > endNumber) {
                cout << "\n";
                continue;
            }
        }

        int chunkSize = startNumber.size() / 2;

        string chunkNumber = startNumber.substr(0, chunkSize);

        long long int repeatedNumber = stol(chunkNumber + chunkNumber); 

        while (repeatedNumber <= endNumber) {
            if (repeatedNumber >= iStartNumber) { 
                result += repeatedNumber;

                cout << startNumber << " <= " << "Found repeated number: " << repeatedNumber << " <= " << endNumber << "\n";
                cout << "Result is " << result << "\n";
            }
            chunkNumber = to_string(stol(chunkNumber) + 1);
            repeatedNumber = stol(chunkNumber + chunkNumber);
        }

        cout << "\n";
    }

    cout << "\nResult: " << result << "\n";

    return 0;
}

