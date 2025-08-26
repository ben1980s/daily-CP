#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    while(n --){
        bool have = false;
        long long ans_ = 0;
        string s;
        cin >> s;
        int len = s.length();
        int max_abs = len * 9;
        for(int i = max_abs ; i >= 0 ; i --){
            string ans = to_string(stoi(s) - i);
            long long total = stoi(ans);
            long long test = stoi(ans);
            for(int i = 0 ; i < len ; i ++){
                total += test % 10;
                test /= 10;
            }
            if(total == stoi(s)){
                cout << ans << "\n";
                have = true;
                break;
            }

        }
        if(!have){
            cout << "0\n";
        }
    }
}