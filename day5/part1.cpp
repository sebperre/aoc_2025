#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string strInput;

    vector<unsigned long long int> startNumbers, endNumbers;

    for (int i = 0; i < n; i++) {
        cin >> strInput;

        int breakpoint = strInput.find('-');

        startNumbers.push_back(stoull(strInput.substr(0, breakpoint)));
        endNumbers.push_back(stoull(strInput.substr(breakpoint + 1, strInput.length())));
    }

    cout << "\n";
    int result = 0;

    unsigned long long int ingID;

    for (int j = 0; j < m; j++) {
        cin >> ingID;

        for (int i = 0; i < startNumbers.size(); i++) {
            if (startNumbers[i] <= ingID && ingID <= endNumbers[i]) {
                result++;
                break;
            }
        }
    }

    cout << "Result: " << result << "\n";
    return 0;
}
