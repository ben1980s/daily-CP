#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr_a(n);
    vector<int> arr_b(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr_a[i];
    }
    for(int i = 0 ; i < n ; i ++){
        cin >> arr_b[i];
    }
    sort(arr_a.begin(),arr_a.end());
    sort(arr_b.begin(),arr_b.end());
    int win = 0;
    
    for(int i = 0 ,j = 0; i < n && j < n; i ++){
        if(arr_a[j] < arr_b[i]){
            win ++;
            j++;
        }
    }
    //0 1 2 3 7
    //0 0 3 5 8
    cout << win << "\n";
}