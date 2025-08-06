// input
// 5
// 3 1 2 7 4
// output
// 5

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long prefix = 0;
    int n;
    cin >> n;
    vector<long long > arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    vector<long long> cnt(n,0);
    cnt[0] = 1;
    long long ans = 0;
    for(int i = 0 ; i < n ; i ++){
        prefix += arr[i];
        long long mod = ((prefix % n) + n) % n;
        //mod = 3
        //mod = 4
        //mod = 1
        //mod = 2
        //mod = 1
        //同餘計算 
        ans += cnt[mod];
        cnt[mod] ++;
        
    }
    cout << ans << "\n";
}