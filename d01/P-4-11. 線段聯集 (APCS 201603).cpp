// 貪心+掃描線
#include <bits/stdc++.h>

using namespace std;
vector<pair<long long,long long>> arr;

int main(){
    long long n;
    cin >> n;
    arr.resize(n);
    for(long long i = 0 ; i < n ; i ++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    //5 15
    //10 20
    //20 20
    //30 75
    //40 80
    //output range[5,20] + [30,80] = 65
    long long total = 0;
    long long l = arr[0].first;
    long long r = arr[0].second;
    for(long long i = 1 ; i < n ; i ++){
        auto [new_l,new_r] = arr[i];
        if(new_l <= r){
            r = max(r,new_r);
        }
        else{
            total += r - l;
            l = new_l; //更新l r 位置到新線段
            r = new_r;
        }
    }
    total += r - l;
    cout << total << "\n";
}