#include <bits/stdc++.h>

using namespace std;

int main(){
    map<char, char> mirror = {
        {'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},
        {'M','M'},{'O','O'},{'S','2'},{'T','T'},{'U','U'},{'V','V'},
        {'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},
        {'3','E'},{'5','Z'},{'8','8'}
    };
    string s;
    while(getline(cin,s)){
        string rev_s = s;
        reverse(rev_s.begin(),rev_s.end());
        string mirr_s = "";
        for(int i = s.size() - 1; i >= 0 ; i --){
            if(mirror.count(s[i])){
            mirr_s += mirror[s[i]];
        }
        else{
            mirr_s += "#";
        }
    }
        bool is_palindrome = (s == rev_s);
        bool is_mirrored = (s == mirr_s);
        cout << s << " -- ";
        if (is_palindrome && is_mirrored)
            cout << "is a mirrored palindrome.\n\n";
        else if (is_palindrome)
            cout << "is a regular palindrome.\n\n";
        else if (is_mirrored)
            cout << "is a mirrored string.\n\n";
        else
            cout << "is not a palindrome.\n\n";
    }
    }
