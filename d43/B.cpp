#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
long long x;
cin >> n >> x;
vector<long long> arr(n);
for(int i = 0 ; i < n ; i ++) cin >> arr[i];

sort(arr.begin(),arr.end());
// 輕 重
int i = 0;
int j = n - 1;
int count = 0;
while(i <= j){
if(arr[i] + arr[j] <= x){
count ++;
i ++;
j --;
}


else{
j --;
count ++;
}

}
cout << count << "\n";

}
