#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
int n,k,m;
while(cin >> n >> k >> m){
vector<vector<ll>> dp(n + 1,vector<ll>(k + 1,0));

// dp[len][count]
dp[0][0] = 1;
for(int i = 1 ; i <= n ; i ++){
   for(int j = 1 ; j <= k ; j ++){
      for(int len = 1 ; len <= m ; len ++){
         if(i - len >= 0) dp[i][j] += dp[i - len][j - 1];
         }
      }
   }
cout << dp[n][k] << "\n";
   }


}
