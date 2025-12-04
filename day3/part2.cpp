#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long int result = 0;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        string lineResult = "";

        int curIndex = -1;
        int prevIndex = -1;
        int curMax = -1;

        for (int numsLeftToChoose = 12; numsLeftToChoose > 0; numsLeftToChoose--) {
            for (int j = prevIndex + 1; j < input.length() - numsLeftToChoose + 1; j++) {
                if (curMax < input[j] - '0') {
                    curMax = input[j] - '0';
                    curIndex = j;
                }
            }
            lineResult += to_string(curMax);
            prevIndex = curIndex;
            curMax = -1;
        }

        result += stoll(lineResult);
    }

    cout << result << "\n"; 
}
