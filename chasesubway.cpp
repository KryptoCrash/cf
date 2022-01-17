#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using vb = vector<bool>;

const int maxn = 32767+8;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<set<int>> ed(maxn);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int last = -1;

        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;

            if (last != -1) {
                ed[x].insert(last);
                ed[last].insert(x);
            }

            last = x;
        }
    }

    int m;
    cin >> m;

    vi path(m);
    for (int i = 0; i < m; i++) {
        cin >> path[i];
    }

    int a = path[0];
    int b = path[m - 1];

    vector<array<int, 2>> dist(maxn, {INF, INF});

    for (int i = 0; i < 2; i++) {
        queue<int> q;
        q.push(i ? b : a);

        vi vis(maxn);
        vis[q.front()] = true;
        dist[q.front()][i] = 0;

        while (!q.empty()) {
            ll top = q.front();
            //cout << top << endl;
            q.pop();

            for (int c : ed[top]) {
                if (vis[c]) continue;
                vis[c] = true;
                q.push(c);

                dist[c][i] = min(dist[c][i], dist[top][i] + 1);
            }
        }
    }

    for (int v = 1; v < maxn; v++) {
        //if(dist[v][1] != INF) cout << v << " " << dist[v][0] << " " << dist[v][1] << endl;

        if ((dist[v][1] != INF) && ((m - 1) + dist[v][1]) == dist[v][0]) cout << v << endl;
    }

    return 0;
}