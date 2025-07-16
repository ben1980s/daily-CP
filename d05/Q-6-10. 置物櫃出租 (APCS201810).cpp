#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
const int INF = 1e9;
int main(){
    fast
    int n,M,s;
    cin >> n >> M >> s;
    vector<long long> f(n + 1);
    long long sum = 0;
    // 3 10 6
    // 4 4 1 目前佔據9
    for(int i = 1 ; i <= n ; i ++){
        cin >> f[i];
        sum += f[i];
    }
    long long need = s - (M - sum);
    if (need <= 0){
        cout << "0"; 
        return 0;
    }
    vector<long long> dp(M + 1,INF);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i ++){
        for(int j = M ; j >= f[i] ; j --){
            dp[j] = min(dp[j],dp[j - f[i]] + f[i]);
        }
    }
    long long ans = INF;
    for(int i = need ; i <= M ; i ++){
        ans = min(ans,dp[i]); 
    }
    cout << ans << "\n";
} 