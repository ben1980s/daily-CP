#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long >dp(n + 1,INT_MAX);
    dp[0] = 0;
    for(int i = 0 ; i <= n ; i ++){
        int x = i;
        while(x > 0){
            int dig = x % 10;
            x /= 10;
            if(dig == 0) continue;
            dp[i] = min(dp[i],dp[i - dig] + 1);
        }
    }
    cout << dp[n] << "\n";
}