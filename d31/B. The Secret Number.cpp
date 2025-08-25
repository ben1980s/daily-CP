#include <bits/stdc++.h>

using namespace std;

int main(){
    //output - total
    //number
    //(k < 18)
    // math sol n = x + y -> n = x + (x + 10^k) -> n = x(1 + 10^k);
    //if(n % (x(1 + 10^k) == 0) -> ans = n / (1 + 10^k) 
    int n;
    cin >> n;
    vector<long long> power_10(19,1);
    for(int i = 1 ; i <= 18 ; i ++) power_10[i] = power_10[i - 1] * 10LL;
    while(n --){
        long long number = 0;
        cin >> number;
        vector<long long> ans;
        for(int i = 1 ; i <= 18 ; i ++){
            long long d = 1 + power_10[i];
            if(d > number) break;
            if(number % d == 0) ans.push_back(number / d);
        }
        sort(ans.begin(),ans.end());
        if(ans.empty()){
            cout << 0 << "\n";
        }
        else{
            cout << ans.size() << "\n";
            for(auto x : ans){
                cout << x << " ";
            }
        cout << "\n";
        }

    }
}