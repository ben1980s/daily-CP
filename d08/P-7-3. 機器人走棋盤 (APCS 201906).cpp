#include <bits/stdc++.h>

using namespace std;

int d[4][2] = {{1,0},{0,-1},{-1,0},{0,1}};

vector<vector<int>> grid;
vector<vector<bool>> visited;

int bfs(int start_x,int start_y){
    int total = grid[start_x][start_y];
    visited[start_x][start_y] = true;
    queue<pair<int,int>> q;
    q.push({start_x,start_y});
    while(!q.empty()){
        auto [v,u] = q.front(); q.pop();
        int min_number = INT_MAX;
        int save_x = -1,save_y = -1;
        for(int i = 0 ; i < 4 ; i ++){
            int dx = d[i][0];
            int dy = d[i][1];
            int nx = v + dx;
            int ny = u + dy;
            if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size()){
                if(!visited[nx][ny] && grid[nx][ny]){
                    if(grid[nx][ny] < min_number){
                        save_x = nx;
                        save_y = ny;
                        min_number = grid[save_x][save_y];
                    }
                }
            }
            
        }
        if(save_x != -1 && save_y != -1){
        q.push({save_x,save_y});
        visited[save_x][save_y] = true;
        total += min_number;
        }
    }
    return total;
}


int main(){
    int m,n;
    cin >> m >> n;
    grid.resize(m,vector<int>(n));
    visited.resize(m,vector<bool>(n,false));
    int min_x = 0;
    int min_y = 0;
    int min_ = INT_MAX;
    for(int i = 0 ; i < m ; i ++){
        for(int j = 0 ; j < n ; j ++){
            int target;
            cin >> target;
            grid[i][j] = target;
            if(target < min_){
                min_x = i;
                min_y = j;
                min_ = target;
            }
        }
        
    }
    cout << bfs(min_x,min_y) << "\n";
}