#include <bits/stdc++.h>

using namespace std;

vector<bool> vis; 
vector<vector<int>> grid;
vector<int> weight;

int dfs(int s){
    int w = weight[s];
    vis[s] = true;
    for(int u : grid[s]){
        if(!vis[u]){
            w += dfs(u);
        }
    }
    return w;
}

int main(){
    int n,m;
    cin >> n >> m;
    weight.resize(n);
    vis.resize(n,false);
    grid.resize(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> weight[i];
    }
    for(int i = 0 ; i < m ; i ++){
        int from,to;
        cin >> from >> to;
        grid[from].push_back(to);
        grid[to].push_back(from);
    }
    int maxn = 0;
    for(int i = 0 ; i < n ; i ++){
        if(!vis[i]){
        maxn = max(maxn,dfs(i));
    }
}
cout << maxn << "\n";
}