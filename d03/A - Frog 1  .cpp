#include <bits/stdc++.h>

using namespace std;

int main(){
    int h[100005];
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> h[i];
    }
    int dp[100005];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2 ; i < n ; i ++){
        // 10 30 40 20
        //dp[2] = min(40 - 30,40 - 10) = 10
        //dp[3] = min(20 - 10,20 - 30)
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1] << "\n";
}