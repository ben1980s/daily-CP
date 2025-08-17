#include <bits/stdc++.h>

using namespace std;

struct Customer{
    long long a,b;
    int idx;
};
int main(){
// 3
// 1 2
// 2 4
// 4 4
// -----
// 2
// 1 2 1
//a.second < b.first
int n;
cin >> n;
vector<Customer> customer(n);
for(int i = 0 ; i < n ; i ++){
    cin >> customer[i].a >> customer[i].b;
    customer[i].idx = i;
}
sort(customer.begin(),customer.end(),[](auto &x, auto &y){
    return x.a < y.a; 
});

priority_queue<pair<long long , int>, vector<pair<long long, int>>, greater<>> pq;
// 退房,count
vector<int> ans(n);
int count = 0;
for(auto &c : customer){
    if(!pq.empty() && pq.top().first < c.a){
        auto [dep,room] = pq.top(); pq.pop();
        ans[c.idx] = room;
        pq.push({c.b,room}); 
    }
    else{
        count ++;
        ans[c.idx] = count;
        pq.push({c.b,count});
    }
}
cout << count << "\n";
for(int c : ans){
    cout << c << " ";
}
cout << "\n";
}