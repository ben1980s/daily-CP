#include <bits/stdc++.h>

using namespace std;

int main(){
int n,k;
while(cin >> n >> k){
if(n == 0 && k == 0) return 0;
vector<int> primes;
vector<bool> pri(1121,true);
pri[0] = pri[1] = false;
for(int i = 2 ; i * i <= 1120 ; i ++){
   if(!pri[i]) continue;
   for(int j = i * i  ; j <= 1120 ; j += i) pri[j] = false;
   
}
for(int i = 2 ; i <= 1120 ; i ++){
   if(pri[i]) primes.push_back(i);
   }

vector<vector<long long>> dp(1122,vector<long long>(15,0));
dp[0][0] = 1;
for(auto x : primes){
   for(int i = 1120 ; i >= x ; i --){
      for(int j = 14 ; j >= 1 ; j --){
         dp[i][j] += dp[i - x][j - 1];
   
      }
   }
}
cout << dp[n][k] << "\n";
}
}


