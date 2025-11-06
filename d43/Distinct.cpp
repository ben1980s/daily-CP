#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
cin >> n;
vector<long long> arr(n,0);

for(int i = 0 ; i < n ; i ++) cin >> arr[i];

sort(arr.begin(),arr.end());
auto it = arr.begin();
int count = 0;

while(it != arr.end()){
   count ++;
   long long val = *it;
   it = upper_bound(it,arr.end(),val);

   }
cout << count << "\n";

   }
