#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string sub = S.substr(i, j - i + 1);
            int len = sub.size();
            if (len >= 3 && sub.front() == 't' && sub.back() == 't') {
                int cnt = count(sub.begin(), sub.end(), 't');
                double rate = double(cnt - 2) / double(len - 2);
                ans = max(ans, rate);
            }
        }
    }

    cout << fixed << setprecision(17) << ans << "\n";
    return 0;
}
