#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string strInput;

    vector<unsigned long long int> beforeMerge;
    vector<unsigned long long int> afterMerge;

    for (int i = 0; i < n; i++) {
        cin >> strInput;

        int breakpoint = strInput.find('-');

        unsigned long long int startNumber = stoull(strInput.substr(0, breakpoint));
        unsigned long long int endNumber = stoull(strInput.substr(breakpoint + 1, strInput.length()));
        
        bool insertedStart = false;
        unsigned long long int start = -1;
        bool inserted = false;

        for (int j = 0; j < beforeMerge.size(); j+=2) {
            if (!inserted) {
                if (!insertedStart) {
                    if (endNumber < beforeMerge[j]) {
                        afterMerge.push_back(startNumber);
                        afterMerge.push_back(endNumber);

                        afterMerge.push_back(beforeMerge[j]);
                        afterMerge.push_back(beforeMerge[j+1]);
                        insertedStart = true;
                        inserted = true;
                    } else if (startNumber < beforeMerge[j]) {
                        afterMerge.push_back(startNumber);
                        insertedStart = true;
                    } else if (startNumber <= beforeMerge[j+1]) {
                        afterMerge.push_back(beforeMerge[j]);
                        insertedStart = true;
                    }
                } 

                if (!inserted && insertedStart) {
                    if (endNumber < beforeMerge[j]) {
                        afterMerge.push_back(endNumber);
                        afterMerge.push_back(beforeMerge[j]);
                        afterMerge.push_back(beforeMerge[j+1]);
                        inserted = true;
                    } else if (endNumber <= beforeMerge[j+1]) {
                        afterMerge.push_back(beforeMerge[j+1]);
                        inserted = true;
                    }
                }

                if (!insertedStart) {
                    afterMerge.push_back(beforeMerge[j]);
                    afterMerge.push_back(beforeMerge[j+1]);
                }
            } else {
                afterMerge.push_back(beforeMerge[j]);
                afterMerge.push_back(beforeMerge[j+1]);
            }
        }

        if (!inserted && !insertedStart) {
            afterMerge.push_back(startNumber);
            afterMerge.push_back(endNumber);
        } else if (!inserted) {
            afterMerge.push_back(endNumber);
        }


        beforeMerge = afterMerge;
        afterMerge = {};

        for (unsigned long long int el : beforeMerge) {
            cout << el << " ";
        }

        cout << "\n\n";
    }

    unsigned long long int result = 0;

    for (int i = 0; i < beforeMerge.size(); i+=2) {
        result += beforeMerge[i+1] - beforeMerge[i] + 1;
    }

    cout << "Result: " << result << "\n";
    return 0;
}
