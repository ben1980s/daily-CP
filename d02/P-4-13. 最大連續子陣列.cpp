#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
int main() {
    fast_io

    int n;
    cin >> n;
    vector<pair<int, int>> st(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st[i].first = -x; 
    }
    for (int i = 0; i < n; i++) {
        cin >> st[i].second;
    }

    sort(st.begin(), st.end()); 

    int max_y = -1;
    int ans = 0;
    for (auto p : st) {
        int y = p.second;
        if (y > max_y) {
            ans++;
            max_y = y;
        }
    }

    cout << ans << "\n";
}
