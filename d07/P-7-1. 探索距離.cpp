#include <bits/stdc++.h>
using namespace std;

int n, m, s;
int grid[102][102];          // 鄰接矩陣
int distance_arr[102];       // 與 s 的距離
bool visited[102];           // 記錄拜訪狀態

int count_reachable = 0;     // 可到達的點數
int total_distance = 0;      // 與 s 的距離總和

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    distance_arr[s] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int i = 0; i < n; i++) {
            if (grid[v][i] && !visited[i]) {
                visited[i] = true;
                distance_arr[i] = distance_arr[v] + 1;
                q.push(i);

                count_reachable++;
                total_distance += distance_arr[i];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> s;

    // 清空 grid
    memset(grid, 0, sizeof(grid));
    memset(visited, false, sizeof(visited));
    memset(distance_arr, 0, sizeof(distance_arr));

    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        grid[from][to] = 1; // 有向邊
    }

    bfs(s);

    cout << count_reachable << "\n";
    cout << total_distance << "\n";

    return 0;
}
