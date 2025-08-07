#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    long long arr[n];
    long long ope[m];
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < m ; i ++){
        cin >> ope[i];
    }
    for(int c : ope){
        for(int i = 0 ; i < n; i ++){
            if(c == arr[i]){
                arr[i] = -1;
                break;
            }
        }
    }
    for(int c : arr){
        if(c != -1){
            cout << c << " ";
        }
    }
    cout << "\n";
}