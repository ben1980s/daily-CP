#include <bits/stdc++.h>

using namespace std;

int main(){
    int c[100005],n;
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> c[i];
    }
    int dp[100005];
    dp[0] = c[0];
    dp[1] = c[1];
    //1 2 3 1 5
    //so dp[2] == 1
    dp[2] = min(dp[0],dp[1]);
    for(int i = 3 ; i < n ; i ++){
        //dp[3] = 1 + 1
        //dp[4] = 5 + 1  
        dp[i] = c[i] + min(min(dp[i - 3],dp[i - 2]),dp[i - 1]);
    }
    cout << min(dp[n - 2],dp[n - 1]);
}