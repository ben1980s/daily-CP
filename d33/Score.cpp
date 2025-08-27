#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n --){
        string s;
        cin >> s;
        int count = 1;
        int ans = 0;
        for(char c : s){
            if(c == 'O'){
                ans += count;
                count ++;
            }
            else{
                count = 1;
            }
        }
        cout << ans << "\n";
    }
}