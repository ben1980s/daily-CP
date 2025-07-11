#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prefix(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(),arr.end());
    prefix[0] = arr[0];
    for(int i = 1 ; i < n ; i ++){
        prefix[i] += arr[i] + prefix[i - 1];
    }
    // 1 3 3 4
    //prefix[0] = 1 + 0 = 1
    //prefix[1] = 3 + 1 = 4
    //prefix[2] = 3 + 4 = 7
    //prefix[3] = 7 + 4 = 11
    int total = 0;
    for(int c : prefix){
        total += c;
    }
    cout << total;
    return 0;
}