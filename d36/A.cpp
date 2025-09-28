#include <bits/stdc++.h>

using namespace std;

int main(){
string s1,s2;
while(getline(cin,s1)){
   getline(cin,s2);
int n1 = s1.length();
int n2 = s2.length();

vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));

for(int i = 1 ; i <= n1 ; i ++){
   for(int j = 1 ; j <= n2 ; j ++){
      if(s1[i - 1] == s2[j - 1]){
         dp[i][j] = dp[i - 1][j - 1] + 1;
         }
      else{
         dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
         }
      }
   }
   cout << dp[n1][n2] << "\n";
   }

   }
