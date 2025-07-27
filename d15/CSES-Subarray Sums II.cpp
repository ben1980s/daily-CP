#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long target;
    cin >> n >> target;
    vector<long long> arr(n);
    for(auto &x : arr){
        cin >> x;
    }
    map<long long,int > prefix_count;
    long long prefix_sum = 0;

    long long count = 0;
    prefix_count[0] = 1;
    for(int i = 0 ; i < n ; i ++){
        prefix_sum += arr[i];
        //prefix_sum = 2 -> 1 -> 4 -> 9 -> 7;

        count += prefix_count[prefix_sum - target];
        prefix_count[prefix_sum]++;
    }
    cout << count << "\n";
    
}