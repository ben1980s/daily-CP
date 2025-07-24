#include <bits/stdc++.h>

using namespace std;

int main(){
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    char dir[4] = {'U', 'R', 'D', 'L'};
    int n,m;
    cin >> n >> m;
    vector<vector<int>> monster_dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> people_dist(n, vector<int>(m, INT_MAX));
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<pair<int,int>>> prev(n,vector<pair<int,int>>(m,{-1,-1}));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
        }
    }
    queue<pair<int,int>> q;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(grid[i][j] == 'M'){
                q.push({i,j});
                monster_dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front();q.pop();
        for(int d = 0 ; d < 4 ; d ++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && monster_dist[nx][ny] == INT_MAX){
                monster_dist[nx][ny] = monster_dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }

    /*
    ########
    #M..A..#
    #.#.M#.#
    #M#..#..
    #.######
    */
    while(!q.empty()) q.pop();
    int people_x = -1,people_y = -1;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(grid[i][j] == 'A'){
                q.push({i,j});
                people_x = i,people_y = j;
                people_dist[i][j] = 0;
            }
        }
    }
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();
        for(int d = 0 ; d < 4 ; d ++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && people_dist[nx][ny] == INT_MAX){
                if(people_dist[x][y] + 1< monster_dist[nx][ny]){
                    people_dist[nx][ny] = people_dist[x][y] + 1;
                    prev[nx][ny] = {x,y};
                    q.push({nx,ny}); 
                }
            }
        }
    }
    bool found = false;
    pair<int,int> escape = {-1,-1};
    for(int i = 0 ; i < n && !found ; i ++){
        for(int j : {0, m - 1}){
            if(people_dist[i][j] != INT_MAX){
                escape = {i,j};
                found = true;
                break;
            }
        }
    }
    if(!found){
    for(int i = 0 ; i < m && !found; i ++){
        for(int j : {0,n - 1}){
            if(people_dist[j][i] != INT_MAX){
                escape = {j,i};
                found = true;
                break;
            }
        }
    }
    }
    /*
    ########
    #M..A..#
    #.#.M#.#
    #M#..#.. <- escape 點
    #.######
    */
   if(escape == make_pair(-1,-1)){
    cout << "NO\n";
    return 0;
   }
   string path;
   pair<int,int> cur = escape;
   while(cur != make_pair(people_x,people_y)){
    auto [px,py] = prev[cur.first][cur.second];
    if(px == -1 && py == -1) break;
    for(int d = 0 ; d < 4 ; d ++){
        if(px + dx[d] == cur.first && py + dy[d] == cur.second){
            path += dir[d];
            break;
        }
    }
    cur = {px,py};
   }
reverse(path.begin(),path.end());
cout << "YES\n" <<path.length() << "\n" << path << "\n";

}