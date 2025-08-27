#include <bits/stdc++.h>

using namespace std;

//move way and choose dir smallest  
int booth(const string &s){
    int len = s.size();
    string t = s + s;
    int i = 0,j = 1,k = 0;
    while(i < len && j < len){
        if(t[i + k] == t[j + k]){
            k ++;
            if (k == len) break;
        }
        else{
            if(t[i + k] > t[j + k]){
                i = i + k + 1;
            }
            else if(t[i + k] < t[j + k]){
                j = j + k + 1;
            }
            if(i == j) i++;
            k = 0;
        }
        
    }
    return min(i,j);
}
int main(){
    int n;

    cin >> n;
    while(n --){
        string s;
        cin >> s;
        int start = booth(s);
        string t = s + s;
        cout << t.substr(start,s.size()) << "\n";
    }
    return 0;
}