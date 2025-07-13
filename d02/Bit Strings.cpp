#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);


long long fast(long long base,long long times){
    // 2 ^ 13
    if(times == 0) return 1;
    if(times % 2 == 1) return (fast(base,times - 1) * base);
     long long half = fast(base,times/2);

     return (half * half);
}

int main(){
    fast_io
    long long t;
    cin >> t;
    cout << fast(2,t);
}