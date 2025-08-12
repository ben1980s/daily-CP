#include <bits/stdc++.h>

using namespace std;

int main(){
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        vector<int> count1(26),count2(26);
        vector<char> ans;
        if(s1.length() == 0 || s2.length() == 0){
            cout << "" << "\n";
            continue;
        }
        for(char c : s1){
            count1[c - 'a'] ++;
        }
        for(char c : s2){
            count2[c - 'a']++;
        }
        for(int i = 0 ; i < 26 ; i ++){
            if(min(count1[i],count2[i]) != 0 ){
                for(int k = 0 ; k < min(count1[i],count2[i]) ; k ++){
                    ans.push_back(i + 'a');
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(char c : ans){
            cout << c;
        }
        cout << "\n";
    }
    return 0;
    
}