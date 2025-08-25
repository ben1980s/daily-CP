#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int count = 1;
    while(getline(cin,s)){
        for(char c : s){
            if(c == ' ') cout << ' ';
            if(c == '"'){
                if(count % 2 == 0){
                    cout << "''";
                    count ++;
                }
                else{
                    cout << "``";
                    count ++;
                }
            }
            else{
                cout << c;
            }
        }
        cout << "\n";
    }
}