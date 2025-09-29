#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3, unroll-loops")
#pragma GCC optimize("fast-math")

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEN(_arr,_val) memset(_arr,_val,sizeof(_arr))
#define ALL(_array) _array.begin(),_array.end()
#define LB(_array,v) lower_bound(ALL(_array),v)
#define UB(_array,v) upper_bound(ALL(_array),v)
// #define REV(_vector) _vector.reverse()
#define vc(_data) vector<_data>
#define pii pair<int,int>
#define psi pair<string,int>
#define pdd pair<double,double>
#define mkp make_pair
#define sz size()
#define pb push_back
#define F first
#define S second
// #define int long long
#define ll long long
#define ld long double
#define tpn typename


int n,m;

bool cmp(const psi& a,const psi& b){
return a.S < b.S; 
}


vc(psi) new_sort(const vc(string)& s){
    vc(psi) new_vec;
    new_vec.reserve(s.size());
    for(int i = 0 ; i < m ; i ++){
        int count = 0;
        for (int j = 0 ; j < n ; j ++){
            for(int k = j + 1 ; k < n ; k ++){
                if(s[i][j] > s[i][k]) count++;
            }
        }
        new_vec.pb({s[i],count});
    }
return new_vec;
}

int main(){
IO;

int t;
cin >> t;
string line;
bool first = true;
while(t --){
cin >> n >> m;

vc(string) arr;
arr.reserve(m);
for(int i = 0 ; i < m ; i ++){
string s;
cin >> s;
arr.pb(s);


}

vc(psi) ans = new_sort(arr);
stable_sort(ALL(ans),cmp);
if(!first) {
    cout << "\n";
first = false;
}

for(int i = 0 ; i < m ; i ++){
    cout << ans[i].F << "\n";
}
}

}








