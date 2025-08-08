#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n --){
        long long k;
        cin >> k;
        string s;
        long long dig = 1;
        long long count = 9;
        long long start = 1;
        while(k > dig * count){
            //16
            k -= count * dig;
            dig ++;
            count *= 10;
            start *= 10;
        }
        // k = 15 - 9
        // 10 += (6 - 1) / 2 = 12
        start += (k - 1) / dig;
        s = to_string(start);
        cout << s[(k - 1) % dig] << "\n";
    }
}