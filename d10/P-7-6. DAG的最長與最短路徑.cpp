#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<pair<int,int>>> grid;
vector<int> in_degree;
vector<int> topo;
int n,m;
int s,t;

void topo_sort(){
    queue<int> q;
    for(int i = 0 ; i < n ; i ++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto [v,w] : grid[u]){
            if(--in_degree[v] == 0){
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> s >> t;
    grid.assign(n,{});
    in_degree.assign(n,0);
    for(int i = 0 ; i < m ; i ++){
        int u,v,w;
        cin >> u >> v >> w;
        grid[u].emplace_back(v,w);  
        in_degree[v]++;
    }
    topo_sort();

    vector<int> dist_min(n, INF);
    dist_min[s] = 0;
    for(int u : topo){
        if(dist_min[u] == INF) continue;
        for(auto [v,w] : grid[u]){
            dist_min[v] = min(dist_min[v],dist_min[u] + w);
        } 
    }

    vector<int> dist_max(n, -INF);
    dist_max[s] = 0;
    for(int u : topo){
        if(dist_max[u] == -INF) continue;
        for(auto [v,w] : grid[u]){
            dist_max[v] = max(dist_max[v],dist_max[u] + w);
        } 
    }

    if (dist_min[t] == INF) cout << "No path\n";
    else cout << dist_min[t] << '\n';

    if (dist_max[t] == -INF) cout << "No path\n";
    else cout << dist_max[t] << '\n';

    return 0;
}
