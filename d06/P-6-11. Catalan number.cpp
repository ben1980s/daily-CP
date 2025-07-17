#include <bits/stdc++.h>
const long long p = 1e9 + 9;
using namespace std;
long long memo[101];

long long cat(int n){
    if(memo[n] >= 0) return memo[n];
    long long sum = 0;
    for(int i = 0 ; i < n ; i ++){
        long long t = cat(i) * cat(n - 1 - i) % p;
        sum = (sum + t) % p;
    }
    return memo[n] = sum;
}

int main(){
int n;
cin >> n;
for(int i = 0 ; i <= n ; i ++){
    memo[i] = -1;//沒走過
}
memo[0] = 1;
cout << cat(n) << "\n";
}