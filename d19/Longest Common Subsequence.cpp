#include <bits/stdc++.h>

using namespace std;

int main(){
    int n1,n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];
    for(int i = 0 ; i < n1 ; i ++){
        cin >> arr1[i];
    }
    for(int i = 0 ; i < n2 ; i ++){
        cin >> arr2[i];
    }
    vector<vector<int>> dp(n1 + 1,vector<int>(n2 + 1,0));
    for(int i = 1 ; i <= n1 ; i ++){
        for(int j = 1 ; j <= n2 ; j ++){
            if(arr1[i - 1] == arr2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
    }
    cout << dp[n1][n2] << "\n";
    vector<int> lcs;
    int i = n1;
    int j = n2;
    while(i > 0 && j > 0){
        if(arr1[i - 1] == arr2[j - 1]){
            lcs.push_back(arr1[i - 1]);
            i --;j --;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i --;
        }
        else{
            j --;
        }
    }
    reverse(lcs.begin(),lcs.end());
    for(auto c : lcs){
        cout << c <<" ";
    }
    cout << "\n";
}