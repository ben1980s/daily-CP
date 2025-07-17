#include <bits/stdc++.h>

using namespace std;

int main(){
    // 6  
    // 2 5 3 4 6 1
    long long n;
    cin >> n;
    vector<long long> arr;
    for(long long i = 1 ; i <= n ; i ++){
        long long s;
        cin >> s;
        auto it = lower_bound(arr.begin(),arr.end(),s);
        if(it == arr.end()){
            arr.push_back(s);
        }
        else{
            *it = s;
        }
    }
    cout << arr.size() << "\n";
}