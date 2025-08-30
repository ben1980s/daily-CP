#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n --){
        map <char,int> arr = {{'0',0},{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0}};

        int t;
        cin >> t;
        string s = "";
        for(int i = 1 ; i <= t ; i ++){
            s += to_string(i);
        }
        for(char c : s){
            arr[c] ++;
        }
        int count = -1;
        for(auto [x,u] : arr){
            count ++;
            if(count != 9){
            cout << u << " ";
            }
            else if(count == 9){
                cout << u << "\n";
            }
        }
    }
}