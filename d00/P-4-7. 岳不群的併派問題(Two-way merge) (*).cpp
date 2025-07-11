#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int times = n;
    priority_queue<int> pq;
    while(n --){
        int m;
        cin >> m;
        pq.push(-(long long)m);
    }
    long long cost = 0;
    for(int i = 0 ; i < times - 1 ; i ++){
        long long m = pq.top();
        pq.pop();
        m += pq.top();
        pq.pop();
        pq.push(m);
        cost += m;
    }
    cout << -(pq.top()) << "\n";
    cout << -(cost) << "\n";
    return 0;
}