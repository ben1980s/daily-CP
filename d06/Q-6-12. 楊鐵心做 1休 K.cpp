#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n + 1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i ++){
        dp[i] = max(dp[i - 1],arr[i] + (i > k ? dp[i - 1 - k] : 0));
    }
    cout << dp[n] << "\n";

    
}