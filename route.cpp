#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int maxn = 1e5 + 8;

ll n, m;

int main() {
    cin >> n >> m;

    vector<set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    // bfs
    queue<int> q;
    int parent[maxn];
    int dist[maxn];
    memset(dist, 0x3f3f3f3f, sizeof(dist));

    q.push(0);

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        if (top == n - 1) {
            vector<int> path;
            for (int curr = top; curr != 0; curr = parent[curr]) {
                path.push_back(curr);
            }

            path.push_back(0);
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            for (int i : path) cout << i + 1 << " ";
            cout << endl;

            return 0;
        }

        for (int i : adj[top]) {
            if (dist[i] == 0x3f3f3f3f) {
                parent[i] = top;
                dist[i] = dist[top] + 1;
                q.push(i);
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}