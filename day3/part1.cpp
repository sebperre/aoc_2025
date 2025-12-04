#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int result = 0;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        string lineResult = "";
        int bat1Index = 0;
        int curMax = -1;

        for (int i = 0; i < input.length() - 1; i++) {
            if (curMax < input[i] - '0') {
                curMax = input[i] - '0';
                bat1Index = i;
            }
        }

        lineResult += to_string(curMax);

        curMax = -1;

        for (int i = bat1Index + 1; i < input.length(); i++) {
            if (curMax < input[i] - '0') {
                curMax = input[i] - '0';
            }
        }

        lineResult += to_string(curMax);

        result += stoi(lineResult);
    }

    cout << result << "\n";
    return 0;
}
