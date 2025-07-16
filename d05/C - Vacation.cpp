#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10005],b[10005],c[10005];
    for(int i = 0 ; i < n ; i ++){
        cin >> a[i] >> b[i] >> c[i];
    }
    //0 = a 1 = b 2 = c
    int dp[10001][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i = 1 ; i < n ; i ++){
        dp[i][0] = max(dp[i - 1][1] + b[i],dp[i - 1][2] + c[i]);
        dp[i][1] = max(dp[i - 1][2] + c[i],dp[i - 1][0] + a[i]);
        dp[i][2] = max(dp[i - 1][0] + a[i],dp[i - 1][1] + b[i]);
    }
    cout << max(dp[n - 1][0],max(dp[n - 1][1],dp[n - 1][2])) << "\n";
    return 0;
}