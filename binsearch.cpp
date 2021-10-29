#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;

bool ok(int x){
    return x > 42;
}

int main(int argc, char const *argv[]) {
    // NORMAL
    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (ok(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo << endl;

    // REVERSED
    int lo = 0;
    int hi = n;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (ok(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << hi << endl;

    return 0;
}
