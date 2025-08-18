#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    
    cin >> n;
    vector<long long> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    int l = 0;
    long long ans = 0;
    unordered_map<long long,int> freq;
    for(int r = 0 ; r < n ; r ++){
        freq[arr[r]] ++;
        while(freq[arr[r]] > 1){
            freq[arr[l]] --;
            l ++;

        }
            ans += (r - l + 1);
        
    }
    cout << ans << "\n";
}