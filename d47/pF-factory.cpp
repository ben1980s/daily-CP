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

vector<int> arr;
int n, t;
int ans = 1e9;
inline void solve()
{
    cin >> n >> t;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int l = 1;
    int r = 1e18;
    while (l < r)
    {
        int total = 0;
        int mid = (l + r) / 2;
        for (auto x : arr)
        {
            total += mid / x;
            if (total >= t)
                break;
        }
        if (total >= t)
        {
            r = mid;
        }
        else if (total < t)
        {
            l = mid + 1;
        }
    }
    cout << l << "\n";
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