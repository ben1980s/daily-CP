#include <bits/stdc++.h>

using namespace std;

struct segment{
    int L,R,W;
};
bool camp(const segment &a,const segment &b){
    return a.R < b.R;
}


int main(){
    int n;
    cin >> n;
    vector<segment> seg(n + 1);
    for(int i = 0 ; i < n ; i ++){
        cin >> seg[i].L >> seg[i].R >> seg[i].W;
    }
    sort(seg.begin(),seg.end(),camp);

        // 3
        // 1 2 1
        // 2 3 3
        // 3 4 1
    vector<int> dp(n + 1);
    dp[0] = seg[0].W;
    for(int i = 1 ; i < n ; i ++){
        int j = i - 1;
        while(i >= 0 && seg[j].R >= seg[i].L){
            j --;
        }
        dp[i] = seg[i].W + (j >= 0 ? dp[i] : 0);
        dp[i] = max(dp[i],dp[i - 1]);
    }
    cout << dp[n - 1] << "\n";
}