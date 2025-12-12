#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string strInput;

    vector<vector<int>> numbers;

    for (int i = 0; i < n - 1; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            cin >> strInput;
            
            row.push_back(stoi(strInput));
        }
        numbers.push_back(row);
    }

    unsigned long long int result = 0;

    for (int j = 0; j < m; j++) {
        cin >> strInput;

        unsigned long long int temp = 0;
        if (strInput[0] == '*') {
            temp = 1;
            for (int k = 0; k < n - 1; k++) {
                temp *= numbers[k][j];
            }
        } else {
            for (int k = 0; k < n - 1; k++) {
                temp += numbers[k][j];
            }
        }
        
        result += temp;
    }

    cout << "Result: " << result << "\n";
    return 0;
}
