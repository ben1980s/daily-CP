#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int n;
void bfs(){
    
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int i = 0 ; i < 8 ; i ++){
            int fx = x + dx[i];
            int fy = y + dy[i];
            if(fx >= 0 && fx < n && fy >= 0 && fy < n && grid[fx][fy] == -1){
                grid[fx][fy] = grid[x][y] + 1;
                q.push({fx,fy});
            }
        }
    }
}

int main(){
    cin >> n;
    grid.resize(n,vector<int>(n,-1));
    grid[0][0] = 0;
    bfs();
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}