#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,target,l,r;
    cin >> n >> target >> l >> r;
    vector<int> grid(n);
    vector<bool> visited(n,false);
    for(int i = 0 ; i < n ; i ++){
        cin >> grid[i];
    }
    queue<pair<int,int>> q;
    visited[0] = true;
    q.push({0,0});
    while(!q.empty()){
        auto [cur,step] = q.front(); q.pop();
        if(cur == target){
            cout << step << "\n";
            return 0;
        }
        for(int move : {-l, r }){
            int next = cur + move;
            if(next < 0 && next >= n) continue;
            int tele = grid[next];
            if(tele < 0 && tele >= n) continue;
            if(!visited[tele]){
            visited[tele] = true;
            q.push({tele,step + 1});
            }
        }
    }
    cout << -1 << "\n";
}