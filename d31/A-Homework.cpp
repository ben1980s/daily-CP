#include <bits/stdc++.h>

using namespace std;

int main(){
    // D append back
    // V append front

    int t;
    cin >> t;
    while(t --){
        deque<char> dq;
        int size_ = 0;
        cin >> size_;
        string s;
        cin >> s;
        int times = 0;
        cin >> times;
        string add,ope;
        cin >> add >> ope;
        for(char c : s){
            dq.push_back(c);
        }
        for(int i = 0 ; i < times ; i ++){
            if(ope[i] == 'D'){
                dq.push_back(add[i]);
            }
            if(ope[i] == 'V'){
                dq.push_front(add[i]);
            }
        }
        for(char c : dq){
            cout << c;
        }
        cout << "\n";
    }
    
}