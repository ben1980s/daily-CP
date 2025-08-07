#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int W;
    cin >> n >> W;
    //dp[i][w] = max(dp[i - 1][w],dp[i - 1][w - a] + b);
    vector<int> weight(n + 1);
    vector<long long> value(n + 1);
    for(int i = 1 ; i <= n ; i ++){
    cin >> weight[i] >> value[i];
    }
    vector<vector<long long>> dp(n + 1,vector<long long>(W + 1,0));

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 0 ; j <= W ; j ++){
            dp[i][j] = dp[i -1][j];
            if(j >= weight[i]){
            dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    }
    cout << dp[n][W] << "\n";
}