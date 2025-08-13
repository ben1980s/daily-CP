#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> arr(n + 1);
    for(int i = 1 ; i <= n ; i ++){
        cin >> arr[i];
    }
    vector<long long> prefix(n + 1);
    //3 2 4 5 1 1 5 3
    prefix[1] = arr[1];
    for(int i = 2 ; i <= n ; i ++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
     // for(int c : prefix){
     //     cout << c << " ";
     // }
      while(q --){
          int left,right;
          cin >> left >> right;
          long long ans = 0;
          ans = prefix[right] - prefix[left - 1];
          cout << ans << "\n";
      }
}