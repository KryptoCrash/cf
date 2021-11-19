#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    queue<pair<int, bool>> q;

    q.push({n-1, 0});

    vector<array<bool, 2>> vis(n, {false, false});
    vis[n-1][0] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = top; )
    }

    return 0;
}