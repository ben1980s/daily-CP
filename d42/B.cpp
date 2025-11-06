#include <bits/stdc++.h>

using namespace std;

int main(){
const long long MOD = 1e6;

int n,k;
while(cin >> n >> k){
   if(n == 0 && k == 0) return 0;

   vector<vector<long long>> dp(n + 1,vector<long long>(k + 1,0));
   for(int i = 0 ; i <= k ; i ++) dp[0][i] = 1;
   for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j <= k ; j ++){
         dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;   
      }
   }
   cout << dp[n][k] % MOD << "\n";
}

}
