#include <bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("fast-math")

/* Self Define */
#define IO do { ios::sync_with_stdio(false); cin.tie(nullptr); } while (0)
#define MEM(arr, val) memset((arr), (val), sizeof(arr))
#define ALL(x) begin(x), end(x)
#define LB(x, v) lower_bound(ALL(x), (v))
#define UB(x, v) upper_bound(ALL(x), (v))
#define REV(x) reverse(ALL(x))
#define pb push_back
#define F first
#define S second
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pdd = pair<double,double>;
#define int long long
const int MOD = 1e9 + 7;
const int p = 999983;
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
template<typename A, typename B>
istream& operator>>(istream& is, pair<A, B>& p) {
    return is >> p.first >> p.second;
}
template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

signed main() {
    //IO;
    int t;
    cin >> t;
    while(t --){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j ++){
                cin >> arr[i][j];
            }
        }
        vector<vector<int>> dist(n,vector<int>(m,LLONG_MAX));
        dist[0][0] = arr[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({arr[0][0],{0,0}});
        while(!pq.empty()){
            auto [d,pos] = pq.top(); pq.pop();
            int x = pos.F;
            int y = pos.S;
            if (d != dist[x][y]) continue;
            for(int i = 0 ; i < 4 ; i ++){
                int ux = x + dx[i];
                int uy = y + dy[i];
                if(ux >= 0 && uy >= 0 && ux < n && uy < m){
                    int s = arr[ux][uy] + d;
                    if(s < dist[ux][uy]){
                        dist[ux][uy] = s;
                        pq.push({dist[ux][uy],{ux,uy}});
                    }
                }
            }
        }
        cout << dist[n - 1][m - 1] << "\n";
    }
   
    return 0;
}

