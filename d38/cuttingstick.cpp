#include <bits/stdc++.h>

using namespace std;

int main(){
int L,n;
while(cin >> L && L){
   cin >> n;
   int cut[55];
   int dp[55][55];
   
   for(int i = 1 ; i <= n ; i ++){
      cin >> cut[i];
   }
   cut[0] = 0;
   cut[n + 1] = L;
   sort(cut,cut + n + 2);
   for(int i = 0 ; i <= n + 1 ; i ++){
      for(int j = 0 ; j <= n + 1 ; j ++){
         dp[i][j] = INT_MAX;
      }
   }
   for(int i = 0 ; i <= n ; i ++){
      dp[i][i + 1] = 0;
   }
   
   for(int d = 2 ; d <= n + 1 ; d ++){
      for(int s = 0 ; s + d  <= n + 1 ; s ++){
         for(int k = s + 1 ; k < s + d ; k ++){
           if(dp[s][s + d] > dp[s][k] + dp[k][s + d] + cut[s + d] - cut[s]) dp[s][s + d] = dp[s][k] + dp[k][s + d] + cut[s + d] - cut[s];
           }
         }
      }
cout << "The minimum cutting is " << dp[0][n + 1] << ".\n"; 
}

   }
