#include <bits/stdc++.h>

using namespace std;
int main(){
int n;
long long x;
cin >> n >> x;
vector<pair<long long,int>> arr(n);

for(int i = 0 ; i < n ; i ++){
    cin >> arr[i].first;
    arr[i].second = i + 1;
}

sort(arr.begin(),arr.end());

for(int i = 0 ; i < n ; i ++){
    int l = i + 1;
    int r = n - 1;
    long long need = x - arr[i].first;
    while(l <= r){
        int mid = (r + l) / 2;
        int left = arr[i].second;
        int right = arr[mid].second;
                if(arr[mid].first == need){
            cout << min(left,right) << " " << max(left,right) << "\n";
            return 0;
        }
        else if(arr[mid].first > need){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
}
cout << "IMPOSSIBLE\n";
}
