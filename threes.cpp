#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

vector<int> co(1008);
int sz = 0;

void solve() {
    int n;
    cin >> n;

    cout << co[n - 1] << endl;
}

void precomp() {
    int i = 0;
    while (sz < 1004) {
        if (i % 3 != 0 && i % 10 != 3) {
            co[sz] = i;
            sz++;
        }
         i++;
    }
}


int main() {
    precomp();

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}