#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string total = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while(getline(cin,s)){
        for(char c : s){
            if(c == ' '){
                cout << ' ';
                continue;
            }
            int n = total.find(c);
            cout << total[n - 2];
        }
        cout << "\n";
    }
}