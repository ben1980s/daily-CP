#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int max_ = 0;
        if(n >= 2){
            max_ = n + (n / 2);
        }
        else{ 
            max_ = n;
        }
        cout << max_ << "\n"; 
    }
}