#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    // next weight
    vector<vector<pair<int, int>>> adj(n + 1);
    //dist node
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    vector<long long>dist(n + 1,LLONG_MAX);
    for(int i = 0 ; i < m ; i ++){
        int from,to,w;
        cin >> from >> to >> w;
        adj[from].push_back({to,w});
    }
    dist[1] = 0;
    //now weight & now node
    pq.push({0,1});
    //adj[0] = {2,6},{3,2},{3,4};
    //adj[1] = {};
    //adj[2] = {2,3};
    
    while(!pq.empty()){
        auto [curdist,u] = pq.top(); pq.pop();
        if(dist[u] < curdist) continue;
        for(auto [v,weight] : adj[u]){
            //如果有更好的走法
            //v == 下下一個點 u == 下一個點
            if(dist[v] > dist[u] + weight){
                dist[v] = dist[u] + weight;
                pq.push({dist[v],v});
            }
        }
        
        
    }
    for(int i = 1 ; i <= n ; i ++){
        cout << dist[i] << " ";
    }
    return 0;
}