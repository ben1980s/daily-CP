#include <bits/stdc++.h>
using namespace std;

/* Pragma */
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

/* Self Define */
#define IO                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define MEM(_array, _value) memset(_array, _value, sizeof(_array));
#define ALL(_array) _array.begin(), _array.end()
#define LB(_array, v) lower_bound(ALL(_array), v)
#define UB(_array, v) upper_bound(ALL(_array), v)
#define REV(_vector) reverse(ALL(_vector))
#define vc(_data) vector<_data>
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>

#define pdd pair<double, double>
#define mkp make_pair
#define sz size()
#define pb push_back
#define F first
#define S second
#define int long long
#define ll long long
#define ld long double
#define tpn typename

/* Self Define Template Function */
template <typename T>
void pV(vector<T> _vector)
{
    for (auto _it : _vector)
        cout << _it << " ";
    cout << "\n";
}

template <typename A, typename B>
bool boundry(pair<A, B> &_pair, int _n, int _m)
{
    return 1 <= _pair.F && _pair.F <= _n && 1 <= _pair.S && _pair.S <= _m;
}

template <typename A, typename B>
istream &operator>>(istream &_is, pair<A, B> &_pair)
{
    return _is >> _pair.F >> _pair.S;
}

template <typename A, typename B>
ostream &operator<<(ostream &_os, pair<A, B> _pair)
{
    return _os << '(' << _pair.F << " " << _pair.S << ')';
}

/* Self Define Const */
const auto dir = vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
const int MAXN = 1e7 + 50;
const int Mod = 1e9 + 7;
const int INF = 0x7FFFFFFF;
const ll LLINF = 0x7FFFFFFFFFFFFFFF;
const int MEMINF = 0x3F;
const int MEMINF_VAL = 0x3F3F3F3F;
const ll MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;

vector<int> cost;
int road;
int question;
int T = 1;
struct Edge
{
    int u, v;
    int w;
};
int node = 0;
int cnt = 1;
inline void solve()
{

    vector<int> cost(node + 1);
    for (int i = 1; i <= node; i++)
        cin >> cost[i];
    int road;
    cin >> road;
    vector<Edge> edge;
    vector<vector<int>> g(node + 1);
    for (int i = 0; i < road; i++)
    {
        int a, b;
        cin >> a >> b;
        int d = cost[b] - cost[a];
        int busy = d * d * d;
        edge.push_back({a, b, busy});
        g[a].push_back(b);
    }
    vector<int> dist(node + 1, LLONG_MAX);
    dist[1] = 0;
    for (int i = 1; i <= node - 1; i++)
    {
        bool updated = 0;
        for (auto &x : edge)
        {
            if (dist[x.u] == LLONG_MAX)
                continue;
            if (dist[x.u] + x.w < dist[x.v])
            {
                dist[x.v] = dist[x.u] + x.w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }
    vector<int> bad(node + 1, 0);
    queue<int> q;
    for (int i = 1; i <= node; i++)
    {
        for (auto &x : edge)
        {
            if (dist[x.u] == LLONG_MAX)
                continue;
            if (dist[x.u] + x.w < dist[x.v])
            {
                if (!bad[x.v])
                {
                    bad[x.v] = 1;
                    q.push(x.v);
                }
            }
        }
    }
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        for (auto v : g[x])
        {
            if (!bad[v])
            {
                bad[v] = 1;
                q.push(v);
            }
        }
    }
    int question;
    cout << "Set #" << cnt++ << "\n";
    cin >> question;
    while (question--)
    {
        int end = 0;
        cin >> end;
        if (end < 1 || end > node)
        {
            cout << "?\n";
            continue;
        }

        int ans = dist[end];
        if (ans == LLONG_MAX || ans < 3 || bad[end])
        {
            cout << "?\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
}

signed main()
{
    IO;
    while (cin >> node)
    {
        solve();
    }
    return 0;
}