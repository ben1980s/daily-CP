#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> trie(5e5 + 50,vector<int>(26,0));
vector<int> node_val(5e5 + 50,0);
int node = 0;
void insert(string &s3){ 
  int now = 0;

  for(int i = 0 ; i < s3.size() ; i ++){
   if(trie[now][s3[i] - 'a'] == 0){
      trie[now][s3[i] - 'a'] = ++node;
      }
      now = trie[now][s3[i] - 'a'];
     }
   node_val[now] = 1;
   return;
  }

int query(string &s4){
   int now = 0;
   for(int i = 0 ; i < s4.size() ; i ++){
      if(trie[now][s4[i] - 'a'] == 0){
         return 0;
         }
       now = trie[now][s4[i] - 'a'];

      }
   if(node_val[now] == 0) return 0;
   if(node_val[now] != 0){
   if(node_val[now] == 1){
       node_val[now] = 2;
       return 1;
      }  
      return 2;
         }
         }
      




int main(){
int n;
cin >> n;
vector<string> arr;
for(int i = 0 ; i < n ; i ++){
   string s;
   cin >> s;
   insert(s);
}
int times;
cin >> times;
for(int i = 0 ; i < times; i ++){
   string s2;
   cin >> s2;
   int number = query(s2);
   if(number == 0){
      cout << "WRONG\n";
   }
   else if(number == 1){
      cout << "OK\n";
   }
   else{
      cout << "REPEAT\n";
   }
}


   }
