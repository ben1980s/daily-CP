#include <bits/stdc++.h>

using  namespace std;

int 
main(){
string s;

while(true){
   vector<string> arr1;
   vector<string> arr2;
   if(!(cin >> s)) break;
   if(s != "#") arr1.push_back(s);
   while(cin >> s && s != "#") arr1.push_back(s);

   while(cin >> s && s != "#") arr2.push_back(s);

int n1 = arr1.size();
int n2 = arr2.size();
vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));
for(int i = 1 ; i <= n1 ; i ++){
   for(int j = 1; j <= n2 ; j ++){
      if(arr1[i - 1] == arr2[j - 1]){
         dp[i][j] = dp[i - 1][j - 1] + 1;
         }
      else{
         dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
         }
      }
   }
   int i = n1;
   int j = n2;
   vector<string> ans;
   while(i > 0 && j > 0){
      if(arr1[i - 1] == arr2[j - 1]){
         ans.push_back(arr1[i - 1]);
         i --;
         j --;
         }
      else if(dp[i - 1][j] > dp[i][j - 1]){
         i --;
         }
      else{
         j --;
         }
      }
   reverse(ans.begin(),ans.end());
   for(int k = 0 ; k < ans.size(); k ++){
      if(k) cout << " ";
      cout << ans[k];
      }
      cout << "\n";
}
}

