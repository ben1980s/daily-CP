#include <bits/stdc++.h>

using namespace std;

int fun(long long n){
    long long ans = n;
    if(ans < 10){
        return ans;
    }
    long long new1 = 0;
    while(n > 0){
        new1 += n % 10;
        n /= 10;
    }
    return fun(new1);
}

int main(){
    long long n;
    while(cin >> n){
        if(n == 0) return 0;
        cout << fun(n) << "\n";
    }
}