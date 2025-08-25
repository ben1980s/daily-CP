#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
    string new1 = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    for(char c : s){
        if(c == ' ') {
            cout << ' ';
        }
        else{
        cout << new1[new1.find(c) - 1];
    }
}
    cout << "\n";
}
}