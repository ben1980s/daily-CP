#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long min_price = 1e9;
    long long max_diff = 0;
    
    for(int i = 0 ; i < n ; i ++){
    // 3 5 1 4 0
    long long price;
    cin >> price;
    max_diff = max(max_diff,price - min_price);
    min_price = min(min_price,price);
    }
    cout << max_diff << "\n";
}