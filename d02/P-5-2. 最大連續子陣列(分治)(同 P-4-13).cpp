#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);

vector<int> arr;

int suffix(int left, int right) {
    int now = 0, max_suffix = INT_MIN;
    for (int i = right - 1; i >= left; i--) {
        now += arr[i];
        max_suffix = max(max_suffix, now);
    }
    return max_suffix;
}

int prefix(int left, int right) {
    int now = 0, max_prefix = INT_MIN;
    for (int i = left; i < right; i++) {
        now += arr[i];
        max_prefix = max(max_prefix, now);
    }
    return max_prefix;
}

int main() {
    FAST_IO
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int mid = n / 2;
    int left_max = suffix(0, mid);
    int right_max = prefix(mid, n);
    int total_max = max({left_max, right_max, left_max + right_max});

    cout << total_max << "\n";
}
