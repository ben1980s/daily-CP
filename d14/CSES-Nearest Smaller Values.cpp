#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for(auto &x : arr){
        cin >> x;
    }
    for(int i = 0 ; i < n ; i ++){
        while(!st.empty() && st.top().first >= arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? 0 : st.top().second;
        st.push({arr[i],i + 1});
    }
    for(int c : ans){
        cout << c << " ";
    }
}