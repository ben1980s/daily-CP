#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i].first;
    }
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i].second;
    }
    sort(arr.begin(),arr.end(),[](pair<int,int>& a,pair<int,int>& b){
        return (long long)a.first * b.second < (long long)b.first * a.second;

    });
    int total = 0;
    int time = 0;
    for(auto c : arr){
        time += c.first;
        total += time * c.second;
    }
    cout << total;
    return 0;
}