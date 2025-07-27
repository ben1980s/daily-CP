#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,target;
    cin >> n >> target;
    vector<long long> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    // target = 7
    // 2 4 1 2 7
    // 2 + 4 + 1.= 7
    // 4 + 1 + 2 = 7
    //超過 left ++ 太少 right ++;
    int left = 0;
    long long total = 0;
    int count = 0;
    for(int right = 0 ; right < n ; right ++){
        total += arr[right];
        while(total > target && left <= right){
            total -= arr[left];
            left ++;
        }
        if(total == target){
            count ++;
        }
    }
    cout << count << "\n";

    
}