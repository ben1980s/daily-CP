#include <bits/stdc++.h>
using namespace std;

// 建立無相圖 當此點visited 並且不是上個點的parent 就代表形成一個環
vector<vector<int>> grid;
vector<bool> visited;
vector<int> parents;
int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int par) {
    visited[node] = true;
    for (int neighbor : grid[node]) {
        if (!visited[neighbor]) {
            parents[neighbor] = node;
            if (dfs(neighbor, node)) return true;
        } else if (neighbor != par) {
            cycle_start = neighbor;
            cycle_end = node;
            return true;
        }
    }
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;

    grid.resize(n + 1);
    visited.resize(n + 1, false);
    parents.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a); 
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        //逆推路徑
        vector<int> cycle_path;
        cycle_path.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parents[v]) {
            cycle_path.push_back(v);
        }
        cycle_path.push_back(cycle_start);
        reverse(cycle_path.begin(), cycle_path.end());

        cout << cycle_path.size() << "\n";
        for (int v : cycle_path) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
