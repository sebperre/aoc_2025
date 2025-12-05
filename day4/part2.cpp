#include <iostream>
#include <vector>

using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> matrix;
    string row;
    int result = 0;

    for (int i = 0; i < n; i++) {
        cin >> row;
        matrix.push_back(row);
    }

    int rowSize = matrix.size();
    int columnSize = matrix[0].length();

    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < columnSize; j++) {
                if (matrix[i][j] == '.') {
                    continue;
                }

                int rollAmount = 0;

                for (int k = max(0, i - 1); k <= min(rowSize - 1, i + 1); k++) {
                    for (int l = max(0, j - 1); l <= min(columnSize - 1, j + 1); l++) {
                        if (k == i && l == j) {
                            continue;
                        }

                        if (matrix[k][l] == '@') {
                            rollAmount++;
                        }
                    }
                }

                if (rollAmount < 4) {
                    matrix[i][j] = '.';
                    changed = true;
                    result++;
                }
            }
        }
    }

    cout << result << "\n";
    return 0;
}
