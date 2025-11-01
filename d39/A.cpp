#include <bits/stdc++.h>

using namespace std;

int main(){
string t;
if(!getline(cin,t)) return 0;
int times = stoi(t);
getline(cin,t);
while(times --){
vector<int> arr;
while(getline(cin,t)){
   if(t.empty()) break;
   arr.push_back(stoi(t));
}
int n = (int)arr.size();
if(n == 0){
   cout << "Max hits: 0\n";
   if(times != 1) cout << "\n";
   continue;
   }
vector<int> dp(n + 1,1),parent(n,-1);
int best_idx = -1,best = 0;

for(int i = 0 ; i < n ; i ++){
   for(int j = 0 ; j < i ; j ++){
      if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
         dp[i] = dp[j] + 1;
         parent[i] = j;
         }
      
      }
      if(dp[i] > best){
         best = dp[i];
         best_idx = i;
         }
   }

cout << "Max hits: " << best << "\n";

vector<int> seq;
for(int p = best_idx ; p != -1 ; p = parent[p]) seq.push_back(arr[p]);
reverse(seq.begin(),seq.end());
for(auto x: seq) cout << x << "\n";

if(times > 0) cout << "\n";
}

}
