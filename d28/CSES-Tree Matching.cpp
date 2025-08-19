#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dp;
void dfs(int u,int p){
    dp[u][0] = dp[u][1] = 0;
    int base = 0
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v,u);
        base += max(dp[v][0],dp[v][1]);
    }
    dp[u][0] = base;
    // 選
    for(int v : adj[u]){
        if(v == p) continue;
        int candidate = base - max(dp[v][0],dp[v][1]) + dp[v][0] + 1;
        dp[u][1] = max(dp[u][1],candidate);
    }
    
    
}


int main(){
    int n;
    cin >> n;
    dp.assign(n+1, {0,0});
    adj.resize(n + 1);
    for(int i = 0 ; i < n - 1 ; i ++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);

    cout << max(dp[1][1],dp[1][0]) << "\n";
}