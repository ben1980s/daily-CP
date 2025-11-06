#include <bits/stdc++.h>

using namespace std;

int main(){
int n;
long long x;
cin >> n >> x;
multiset<long long> arr;
for(int i = 0 ; i < n ; i ++){
int number;
cin >> number;
arr.insert(number);
}
int count = 0;
while(!arr.empty()){
    auto it = prev(arr.end());
    long long max_weight = *it;
    arr.erase(it);
    auto need = arr.upper_bound(x - max_weight);
    
    if(need != arr.begin()){
        need --;
        arr.erase(need);
    }
    count ++;
}
   cout << count << "\n"; 
}



