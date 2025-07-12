//貪心+二分搜
#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> arr;

bool test(int r){
    int amount = k;
    int endline = -1;
    for(int i = 0 ; i < n ; i ++){
        if(arr[i] <= endline) continue; //包含在內

        if(amount == 0) return false; //數量不夠

        amount --;
        endline = arr[i] + r; //更新覆蓋到的最大位置
    }
    return true;
}
int main(){
    //input N = 6 K = 2 
    // 5 2 1 7 5 8
    
    //set index = 1() 
    int ans = 0;
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    //sort 1 2 5 5 7 8
    int l = 0,r = arr[n - 1] - arr[0];
    
    while(l <= r){
        int mid = (l + r) / 2;
        if(test(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l= mid + 1;
        }
        
    }
cout << ans << "\n";
}