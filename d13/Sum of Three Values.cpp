#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,target;
    cin >> n >> target;
    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i ++){
        int x;
        cin >> x;
        arr[i] = {x,i + 1};
    }
    sort(arr.begin(),arr.end());
    for(int i = 0 ; i < n ; i ++){
        int a = arr[i].first;
        int left = i + 1,right = n - 1;
        int need = target - a;
        while(left < right){
            int b = arr[left].first,c = arr[right].first;
            int sum = b + c;
            if(need == sum){
                cout << arr[i].second<<" "<<arr[left].second<<" "<<arr[right].second <<"\n";
                return 0;
            }
            else if(sum > need){
                right --;
            }
            else{
                left ++;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}