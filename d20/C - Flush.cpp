#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<long long> prefix(n + 1,0);
    for(int i = 0 ; i < n ; i ++){
        prefix[i + 1] = arr[i] + prefix[i];
    }
    //1 4 4 8
    while(q --){
        int target;
        cin >> target;
        if(arr.back() < target){
            cout << -1 << "\n";
            continue;
        }
        long long ans = 0;
        int place = (int)(lower_bound(arr.begin(),arr.end(),target) - arr.begin());
        ans += prefix[place] + (long long)(n - place) * (target - 1);
        cout << ans + 1 << "\n" ;
    }
    
}