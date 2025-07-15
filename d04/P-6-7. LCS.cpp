#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= m ; j ++){
            if(s1[i] == s2[j]){//相同+1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{//不同去比哪個比較大
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
}