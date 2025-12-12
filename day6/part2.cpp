#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("data.txt");
    string line;
    getline(file, line);
    
    vector<string> lines;

    size_t max_line_length = 0;
    while (getline(file, line)) {
        max_line_length = max(max_line_length, line.size());
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++) {
        while (lines[i].size() < max_line_length) {
            lines[i] = lines[i] + ' ';
        }
    }


    unsigned long long int result = 0;
    unsigned long long int temp = 0;

    char op = 'l';
    for (int i = 0; i < lines[0].size(); i++) {
        if (op == 'l') {
            if (lines[lines.size() - 1][i] == '+') {
                op = '+';
                temp = 0;
            } else {
                op = '*';
                temp = 1;
            }
        }
        string num = "";
        for (int j = 0; j < lines.size() - 1; j++) {
            if (lines[j][i] != ' ') {
                num += lines[j][i];
            }
        }
        if (num == "") {
            result += temp;
            op = 'l';
        } else if (op == '+') {
            temp += stoull(num);
        } else if (op == '*') {
            temp *= stoull(num);
        }
    }
    result = result + temp;
    cout << "Result: " << result << "\n";
    return 0;
}
