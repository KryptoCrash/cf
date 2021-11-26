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

    vi a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vi b(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vi dist(n+1, INF);
    dist[n] = 0;
    vi par(n + 1);
    int j = n - 1;

    for(int i = n; i > 0; i--) {
        int x = max((ll)0, i + b[i] - a[i + b[i]]);
        if (dist[i] == INF) continue;
        while (j >= x) {
            dist[j]=min(dist[j], dist[i] + 1);
            par[j] = i;
            j--;
        }
    }

    cout << (dist[0] == INF ? -1 : dist[0]) << endl;
    if (dist[0] == INF) return 0;

    int cur = 0;
    vi path;
    while(cur != n) {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(path.begin(), path.end());

    for(int i : path) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}