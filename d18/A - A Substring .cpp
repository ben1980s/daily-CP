#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a,b;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    int len = s.length();
    for(int i = a ; i < len - b ; i ++){
        cout << s[i];
    }
    cout << "\n";
}