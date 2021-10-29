#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 2147483647;

int n;
int f[maxn+5]{0};

int query(int i) {
    int res;
    cout << "? " << i << endl;
    cout.flush();
    cin >> res;
    return res;
}

int found(int k) {
    cout << "! " << k << endl;
    exit(0);
}

bool ok(int m) {
    int lv = f[m - 1] ? f[m - 1] : (m == 1 ? INF : query(m - 1));
    int mv = f[m] ? f[m] : query(m);
    int rv = f[m + 1] ? f[m + 1] : (m == n ? INF : query(m + 1));

    f[m - 1] = lv;
    f[m] = mv;
    f[m + 1] = rv;

    if ((f[m - 1] > f[m]) && (f[m + 1] > f[m])) found(m);

    return f[m] > f[m + 1];
}

int main() {
    cin >> n;

    // bin search
    int lo = 1;
    int hi = n;

    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;

        if(ok(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    found(lo);

    return 0;
} 