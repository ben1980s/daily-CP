#include <bits/stdc++.h>

using namespace std;

int main(){
int n,test = 1;
vector<int> arr;
while(cin >> n){
   if(n == -1){
      if(arr.empty()) break;
      int ans = 1;
      vector<int> dp(arr.size(),1);
      for(int i = 0 ; i < arr.size() ; i ++){
         for(int j = 0 ; j < i ; j ++){
            if(arr[j] >= arr[i]){
               dp[i] = max(dp[i],dp[j] + 1);
               }
            }
            ans = max(dp[i],ans);
         }
      if(test > 1) cout << "\n";
      cout << "Test #" << test++ << ":\n";
      cout << "  maximum possible interceptions: " << ans << "\n";
      arr.clear();
      }
   else{
   arr.push_back(n);
      }
   }
   }
