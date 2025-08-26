#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int count = 1;
    while(cin >> n){
        if(n == 0) break;
        cout << "Game " << count << ":\n";

        vector<int> ans(n);
        //1 3 5 5
        for(int i = 0 ; i < n ; i ++){
            cin >> ans[i];
        }
        while(true){
            int ans_A = 0;
            int ans_B = 0;
            vector<int> guess(n);
            vector<int> code_ans(10,0),code_guess(10,0);
            for(int i = 0 ; i < n ; i ++){
                cin >> guess[i];
            }
            if(all_of(guess.begin(),guess.end(), [](int x){ return x == 0;})){
                break;
            }
            for(int i = 0 ; i < n ; i ++){
                if(guess[i] == ans[i]){
                    ans_A ++;
                }
                else{
                    code_ans[ans[i]] ++;
                    code_guess[guess[i]] ++;
                }
            }
            for(int i = 1 ; i <= 9 ; i ++){
                ans_B += min(code_ans[i],code_guess[i]);
            }
            cout << "    (" << ans_A << "," << ans_B << ")\n";
            
        }
        count ++;
    }
}