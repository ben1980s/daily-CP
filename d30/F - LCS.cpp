#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string t;
    cin >> s >> t;
    int l1 = (int)s.length();
    int l2 = (int)t.length();

    vector<vector<int>> dp(l1 + 1,vector<int>(l2 + 1,0));
    for(int i = 1 ; i <= l1 ; i ++){
        for(int j = 1 ; j <= l2 ; j ++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    string ans = "";
    int i = l1,j = l2;
    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            ans += s[i - 1];
            i --;
            j --;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]){
            i --;
        }
        else{
            j --;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << "\n";
}