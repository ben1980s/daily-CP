#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long > arr(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    long long maxN = 0;
    long long total = 0;
    for(int i = 0 ; i < n ; i ++){
        maxN += arr[i];
        if(maxN < 0) maxN = 0;
        total = max(total,maxN);
    }
    cout << total << "\n";
}