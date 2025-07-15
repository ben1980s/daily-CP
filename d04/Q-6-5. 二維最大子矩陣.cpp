#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    int maxsum = INT_MIN;

    for (int row1 = 0; row1 < n; row1++) {
        vector<int> temp(m, 0);
        for (int row2 = row1; row2 < n; row2++) {
            for (int col = 0; col < m; col++)
                temp[col] += arr[row2][col];

            int cursum = temp[0];
            int best = temp[0];
            for (int i = 1; i < m; i++) {
                cursum = max(temp[i], cursum + temp[i]);
                best = max(best, cursum);
            }
            maxsum = max(maxsum, best);
        }
    }

    cout << maxsum << "\n";
}
