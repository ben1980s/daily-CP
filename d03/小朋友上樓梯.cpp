#include <bits/stdc++.h>

using namespace std;

int main(){
    int f[100005];
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3 ; i < n ; i ++){
        f[i] = f[i-1] + f[i -2];
    }   
}