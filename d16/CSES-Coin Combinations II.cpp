#include <bits/stdc++.h>

using namespace std;

int main(){
    int mod = 1e9 + 7;
    int n,x;
    int c[105];
    int dp[1000005];
    cin >> n >> x;
    for(int i = 0 ; i < n ; i ++){
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j + c[i] <= x ; j ++){
            dp[j + c[i]] += dp[j];
            dp[j + c[i]] %= mod;
        }
    }
    cout << dp[x] << "\n";
}