#include <bits/stdc++.h>

using namespace std;

int main(){
int t;
if(!(cin >> t)) return 0;
for(int r = 1 ; r <= t ; r ++){
   int n;
   cin >> n;
   vector<long long> arr(n + 1);
   for(int i = 1 ; i < n ; i ++){
      cin >> arr[i];
   }
   long long best_sum = LLONG_MIN;
   long long cur_sum = 0;
   int cur_l = 1;
   int best_l = -1,best_r = -1;
   
   for(int i = 1 ; i < n ; i ++){
      if(cur_sum + arr[i] >= arr[i]){
         cur_sum = cur_sum + arr[i];
      }
      else{
         cur_sum = arr[i];
         cur_l = i;
      }
      int cur_r  = i + 1;
      int cur_len = cur_r - cur_l;
      int best_len = (best_l == - 1 ? -1 : best_r - best_l);
      bool better = false;
      if(cur_sum > best_sum) better = true;
      else if(cur_sum == best_sum){
         if(cur_len > best_len) better = true;
         else if(cur_len == best_len && cur_l < best_l) better = true; 
      }
      if(better){
         best_sum = cur_sum;
         best_r = cur_r;
         best_l = cur_l;
      }
   }
   if (best_sum > 0) {
            cout << "The nicest part of route " << r
                 << " is between stops " << best_l << " and " << best_r << "\n";
        } else {
            cout << "Route " << r << " has no nice parts\n";
        }
}

}
