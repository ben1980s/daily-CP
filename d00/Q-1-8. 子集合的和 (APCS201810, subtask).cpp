#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
long long n,p;
long long ans = 0;

void dfs(int i, long long sum){
    if(i == n) {
        ans = max(ans,sum);
        return;
    }
    if(arr[i] + sum > p) {
        dfs(i + 1,sum);
        return;
    }
    

    dfs(i + 1,sum + arr[i]);

    dfs(i + 1,sum);
}

int main(){
    cin >> n >> p;
    arr.resize(n);
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    dfs(0,0);
    cout << ans << endl;
}
