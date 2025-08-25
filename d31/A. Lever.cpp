#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n --){
        long long sum = 0;
        int times = 0;
        cin >> times;
        vector<long long> arr1(times);
        vector<long long> arr2(times);
        for(int i = 0 ; i < times ; i ++){
            cin >> arr1[i];
        }
        for(int i = 0 ; i < times ; i ++){
        cin >> arr2[i];
        }
        for(int i = 0 ; i < times ; i ++){
            sum += max(arr1[i] - arr2[i],0LL);
        }
        cout << sum + 1<< "\n";
    }
}