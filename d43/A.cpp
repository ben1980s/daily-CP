#include <bits/stdc++.h>

using namespace std;

int main(){
int t;
cin >> t;
while(t --){
    bool test = false;
long long a,b;
cin >> a >> b;
if((a + b) % 3  == 0 && a <= b * 2 && b <= a * 2){
    cout << "YES\n";
}
else cout << "NO\n";
}

}
