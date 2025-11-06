#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> cus(n,0);
    vector<long long> room(m,0);
    for(int i = 0 ; i < n ; i ++) cin >> cus[i];
    for(int i = 0 ; i < m ; i ++) cin >> room[i];
    sort(cus.begin(),cus.end());
    sort(room.begin(),room.end());
    int count = 0;
    multiset<long long> mt(room.begin(),room.end());

    for(auto x : cus){
        auto it = mt.lower_bound(x - k);
        if(it != mt.end() && *it <= x + k){
            count ++;
            mt.erase(it);
        }
    }
    
    cout << count << "\n";
}
