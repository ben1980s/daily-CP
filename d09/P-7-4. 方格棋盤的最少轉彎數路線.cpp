#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grid;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct node {
    int x, y, dir, turn;
};

int bfs() {
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
    queue<node> q;

    for (int i = 0; i < 4; i++) {
        visited[0][0][i] = 0;
        q.push({0, 0, i, 0});
    }

    while (!q.empty()) {
        node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, dir = cur.dir, turn = cur.turn;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && visited[nx][ny][dir] > turn) {
            visited[nx][ny][dir] = turn;
            q.push({nx, ny, dir, turn});
        }
        for (int nd = 0; nd < 4; nd++) {
            if (nd == dir) continue;
            nx = x + dx[nd];
            ny = y + dy[nd];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0 && visited[nx][ny][nd] > turn + 1) {
                visited[nx][ny][nd] = turn + 1;
                q.push({nx, ny, nd, turn + 1});
            }
        }
    }

    int ans = INT_MAX;
    for (int d = 0; d < 4; d++) {
        ans = min(ans, visited[n - 1][m - 1][d]);
    }
    return (ans == INT_MAX ? -1 : ans);
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    cout << bfs() << "\n";
}
