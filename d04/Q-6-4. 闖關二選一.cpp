#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,start;
    cin >> n >> start;
    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i = 0; i < n  ; i ++){
        cin >> arr[i][0] >> arr[i][1];
    }
    int dp[100005][2];
    dp[0][0] = abs(start - arr[0][0]);
    dp[0][1] = abs(start - arr[0][1]);
    for(int i = 1 ; i < n ; i ++){
        for(int j = 0 ; j < 2 ; j ++){
        dp[i][j] = min(dp[i - 1][0] + abs(arr[i - 1][0] - arr[i][j]),dp[i - 1][1] + abs(arr[i - 1][1] - arr[i][j]));
        } 
    }
    cout << min(dp[n - 1][0],dp[n - 1][1])<< "\n"; 
}