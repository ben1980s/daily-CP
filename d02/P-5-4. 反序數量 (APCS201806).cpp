#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

long long inverse(int arr[], int left, int right) {
    if (left + 1 >= right) return 0;
    int mid = (left + right) / 2;
    long long w = inverse(arr, left, mid) + inverse(arr, mid, right);
    sort(arr + mid, arr + right);
    for (int i = left; i < mid; ++i) {
    // 6
    // 3 1 9 8 9 2
    // (3 1 9),(8,9,2)
    //(3.(1,9)),(8(9,2))
    //找比他大的 找到幾個
        w += lower_bound(arr + mid, arr + right, arr[i]) - (arr + mid);
    }

    return w;
}

int main() {
    FAST_IO

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    long long result = inverse(arr, 0, n);
    cout << result << "\n";
}
