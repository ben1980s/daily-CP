#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(const string& s) {
    int n = s.length();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1]; 
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (getline(cin, s)) {
        if (s == ".") break;

        vector<int> arr = prefix(s);
        int len = arr.size();
        int last = arr[len - 1];
        int same = len - last;

        if (len % same == 0) {
            cout << len / same << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    return 0;
}
