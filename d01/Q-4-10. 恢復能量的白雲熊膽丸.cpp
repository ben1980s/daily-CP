#include <bits/stdc++.h>

using namespace std;

int n,times,total;
vector<int> arr;
bool test(int F){
    int cnt = 0;
    int energy = F;
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] > energy){
            cnt ++;
            energy = F;
        }
        if(arr[i] > energy) return false;
        energy -= arr[i];
    }
    return cnt <= times;
}


int main(){
    cin >> n >> times;
    arr.resize(n);
    
    for(int i = 0 ; i< n ; i ++){
        cin >> arr[i];
        total += arr[i];
    }
//     7 2
// 3 4 1 7 4 1 2
    //左界不能小於最大關卡 右界開沒吃藥一次過
    int l = *max_element(arr.begin(),arr.end()),r = total;
    auto ans = r;
    while(l <= r){
        int mid = (l + r) / 2;
        if(test(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}