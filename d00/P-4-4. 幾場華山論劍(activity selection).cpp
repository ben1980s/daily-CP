#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    while(n --){
        int s,t;
        cin >> s >> t;
        arr.push_back({t,s});
    }
    sort(arr.begin(),arr.end());
    int end = -1;
    //3 0
    //4 1
    //4 3
    //6 4
    int ans = 0;
    for(auto c : arr){
        if(c.second > end){
            end = c.first;
            ans ++;
        }
    }
    cout << ans << "\n";
    return 0;
}