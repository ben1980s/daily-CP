#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
cin >> n;
vector<long long> arr(n);
for(int i = 0 ; i < n ; i ++) cin >> arr[i];
sort(arr.begin(),arr.end());

long long need = arr[n / 2];
long long total = 0;

for(auto x : arr){
    total += abs(x - need);
}
cout << total << "\n";

}
