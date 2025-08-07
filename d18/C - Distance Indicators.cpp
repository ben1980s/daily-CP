#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    unordered_map<int,long long>feq;
    long long ans = 0;
    for(int i = 0 ; i < arr.size() ; i ++){
        int key = (i + 1) - arr[i];
        if(feq.count(key)){
            ans += feq[key];
        }
        int new_key = (i + 1) + arr[i];
        feq[new_key] ++;
    }
    cout << ans << "\n";
}