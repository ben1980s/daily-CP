#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    //5 4 3
    //5 不需能量 4 * 2 + (3 +8) * 1 = 16
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i].first;
    }
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i].second;
    }
    sort(arr.begin(),arr.end(),[](const pair<int,int>& a,const pair<int,int>& b){
        return (long long)a.first * b.second < (long long)a.second * b.first;
    });
    long long prefix = 0;
    long long enegry = 0;
    for(auto c : arr){
        enegry += prefix * c.second;
        prefix += c.first;
    }
    cout << enegry << "\n";
    return 0;
}