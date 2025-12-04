#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_set>

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
        string endNumber = strInput.substr(splitIndex + 1, strInput.length());

        unordered_set<string> numbersFound = {};

        cout << "Finding repeated numbers between " << startNumber << " and " << endNumber << "\n";

        for (int i = 1; i <= endNumber.length() / 2; i++) {
            for (int pattern = pow(10, i - 1); pattern < pow(10, i); pattern++) {
                string currNum = to_string(pattern) + to_string(pattern);
                long int lCurrNum = stol(currNum);

                while (lCurrNum <= stol(endNumber)) {
                    if (stol(startNumber) <= lCurrNum) {
                        auto it = numbersFound.find(currNum);
                        if (it == numbersFound.end()) {
                            cout << "Found number: " << currNum << "\n";
                            result += lCurrNum;
                            numbersFound.insert(currNum);
                        }
                    }
                    currNum += to_string(pattern);
                    lCurrNum = stol(currNum);
                }
            }
        }

    }
    cout << "\nResult: " << result << "\n";

    return 0;
}

