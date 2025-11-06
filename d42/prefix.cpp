#include <bits/stdc++.h>

using namespace std;

int main(){
long long n,q;
cin >> n >> q;
vector<long long > arr(n + 1,0);
for(int i = 0 ; i < n ; i ++){
   cin >> arr[i];
}
vector<long long> prefix(n + 1,0);
for(int i = 1 ; i <= n ; i ++){
   prefix[i] = prefix[i - 1] + arr[i - 1];
   }
while(q --){
int a,b;
cin >> a >> b;
   cout << prefix[b] - prefix[a - 1] << "\n";
   }

   }
