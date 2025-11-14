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

int n;
string s;
vector<int> left_prefix;
vector<int> right_prefix;
inline void solve()
{
    cin >> n >> s;
    left_prefix.resize(n + 1);
    right_prefix.resize(n + 1);
    left_prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'W')
        {
            left_prefix[i] = left_prefix[i - 1] + 1;
        }
        else
        {
            left_prefix[i] = left_prefix[i - 1];
        }
    }
    right_prefix[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i + 1] == 'E')
        {
            right_prefix[i] = right_prefix[i + 1] + 1;
        }
        else
        {
            right_prefix[i] = right_prefix[i + 1];
        }
    }
    int ans = LLONG_MAX;
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans, right_prefix[i] + left_prefix[i]);
    }
    cout << ans << "\n";
}

signed main()
{
    IO;

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}