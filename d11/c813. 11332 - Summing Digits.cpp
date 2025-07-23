#include <iostream>
using namespace std;

int f(int n) {
    if (n < 10) return n;  
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return f(sum); 
}

int main() {
    int k;
    while (cin >> k) {
        if (k == 0) return 0;
        cout << f(k) << "\n"; 
    }
    return 0;
}
