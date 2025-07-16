#include <bits/stdc++,h>

using nemaspace std;

int main() {
    int n,w;
    cin >> n >> w;
    vector<int> weight(n),value(n);
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i][0] >> arr[i][1];
    }
    vector<vector<int>> dp(n,vector<int>(2));
    
    return 0;
}