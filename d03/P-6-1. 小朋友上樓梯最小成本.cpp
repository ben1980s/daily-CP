#include <bits/stdc++.h>

using namespace std;


// int main(){
//     long long cost[1e5];
//     long long arr[1e5];
//     int n;
//     cin >> n;
//     for(int i = 0 ; i < n ; i ++){
//         cin >> arr[i];
//     }
//     for(int i = 3 ; i < n ; i ++){
//         cost[i] = min(cost[i - 1],cost[i -2]);
//     }
// }
//8
//2 1 1 7 3 2 9 2
int main(){
    int n,cost,p = 0,pp = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> cost;
        cost += min(p,pp);
        p = pp;
        pp =cost;
    }
    
}