#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
vector<int> tree[N];


int ans[N];
int dfs(int node){
    int cnt = 0;
    for(auto child : tree[node]){
        cnt += 1 + dfs(child);
    }
    ans[node] = cnt;
    
    return cnt;
}

int main(){
    int n
    cin >> n;
    for(int i = 2 ; i <= n ; i ++){
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
        //tree[1] = 2 3
        //tree[2] = 4
        //tree[3] = 5
    }
    dfs(1);
    for(int i = 1 ; i <= n ; i ++){
        cout << ans[i] << " ";
    }
}