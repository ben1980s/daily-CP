#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int h[100005];
    int dp[100005];
    for(int i = 0 ; i < n ; i ++){
        cin >> h[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2 ; i < n ; i ++){
        for(int dis = 1 ; dis <= k ; dis ++){
            if(i - dis >= 0){
                dp[i] = min(dp[i],dp[i - dis] + abs(h[i] - h[i - dis]));
            }
        }
    }
    cout << dp[n - 1] << "\n";

}