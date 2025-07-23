#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    string line;
    getline(cin, line); 

    for (int t = 0; t < n; ++t) {
        map<string, int> speciesCount;
        int total = 0;

        while (getline(cin, line)) {
            if (line.empty()) break; 
            speciesCount[line]++;
            total++;
        }

        for (auto& entry : speciesCount) {
            cout << entry.first << " " << fixed << setprecision(4) << (100.0 * entry.second / total) << "\n";
        }

        if (t != n - 1) cout << "\n"; 
    }

    return 0;
}
