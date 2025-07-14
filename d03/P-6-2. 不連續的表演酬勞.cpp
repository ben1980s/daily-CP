#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int price[100005];
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> price[i];
    }
    int dp[100005];
    //定義看要拿第一天的還是第二天的
    dp[1] = price[1];
    dp[2] = max(price[2],price[1]);
    for(int i = 3 ; i <= n ; i ++){
        //拿前一天但今天不行 and 拿前兩天+今天
        dp[i] = max(dp[i -1],price[i] + dp[i - 2]);
    }
    cout << dp[n] << "\n";
}