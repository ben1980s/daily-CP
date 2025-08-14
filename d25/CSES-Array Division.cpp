#include <bits/stdc++.h>

using namespace std;

vector<long long > arr;
int n,k;
int cansplit(long long m){
    int count = 1;
    long long  total = 0;
    for(long long x : arr){
        if(total + x > m){
            total = 0;
            count ++;
        }
        total += x;
    }
    return count <= k;
}

int main(){

    cin >> n >> k;
    arr.resize(n);
    long long maxn = -1e18;;
    long long sumn = 0;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
        maxn = max(maxn,arr[i]);
        sumn += arr[i];
    }
    long long left = maxn;
    long long right = sumn;
    while(left < right){
        long long mid = (right + left) / 2;
        if(cansplit(mid)) right = mid;
        else{
            left = mid + 1;
        }
    }
    cout << left << "\n";
}