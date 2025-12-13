#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    string line;

    cin >> line;

    unordered_set<int> old_indicies, new_indicies;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == 'S') {
            old_indicies.insert(i);
        }
    }

    int result = 0; 
    for (int i = 0; i < n; i++) {
        cin >> line;

        for (int j = 0; j < line.size(); j++) {
            if (line[j] == '^') {
                for (int el : old_indicies) {
                    if (el == j) {
                        result++;
                        old_indicies.erase(el);
                        new_indicies.insert(j - 1);
                        new_indicies.insert(j + 1);
                        break;
                    } 
                }
            }
        }

        for (int index : old_indicies) {
            new_indicies.insert(index);
        }

        old_indicies = new_indicies;
        new_indicies.clear();
    }

    cout << "Result: " << result << "\n";

    return 0;
}
