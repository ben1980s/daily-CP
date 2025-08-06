#include <bits/stdc++.h>

using namespace std;

// 3 9
// 2 3 5

int main(){
    int mod = 1e9 + 7;
    int n,x;
    int arr[105];
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int dp[1000005];
    dp[0] = 1;
    for(int i = 0 ; i < x ; i ++ ){
        for(int j = 0 ; j < n ; j ++){
            if(i + arr[j] > x ) continue;
            
            dp[i + arr[j]] += dp[i];
            dp[i + arr[j]] % mod;
        }
    }
    cout << dp[x] << "\n";
}