#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int total = n;
        int empty = n;
        while(empty >= 3){
            int newcola = empty / 3;
            total += newcola;
            empty = empty % 3 + newcola;
        }
        if(empty == 2){
            total += 1;
        }
        cout << total << "\n";
    }
}