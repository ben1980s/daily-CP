#include <bits/stdc++.h>

using namespace std;

int main(){
    map<char,float> ex= {{'C',12.01},{'H',1.008},{'O',16.00},{'N',14.01}};
    int n;
    cin >> n;
    while(n --){
        string s;
        cin >> s;
        int len = s.length();
        double total = 0;
        for(int i = 0 ; i < len;){
            char ele = s[i];
            i ++;
            int num = 0;
            while(i < len && isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
                i ++;
            }
            if(num == 0) num = 1;
            total += num * ex[ele];
        }
        cout << fixed << setprecision(3) << total << "\n"; 
    }
}