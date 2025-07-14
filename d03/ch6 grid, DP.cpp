#include <bits/stdc++.h>

using namespace std;

int main(){
    int grid[50][50];
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= m ; i ++){
        grid[i][1] = 1;
    }
    for(int i = 1 ; i <= n ; i ++){
        grid[1][n] = 1;
    }
    for(int i = 2 ; i <= m ; i ++){
        for(int j = 2 ; j <= n ; j ++){
            grid[i][m] = grid[i -1][j] + grid[i][j - 1];
        }
    }
}