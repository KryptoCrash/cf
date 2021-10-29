#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<bool>;

ll n, m;

int main() {
    cin >> n >> m;

    vector<vi> a(n, vi(m, 0));

    pi start;
    pi end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') a[i][j] = true;
            if (c == 'A') start = {i, j};
            if (c == 'B') end = {i, j};
        }
    }

    // bfs
    queue<pi> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<pi>> parent(n, vector<pi>(m, {-1, -1}));

    dist[start.first][start.second] = 0;
    q.push(start);

    vector<pi> adj = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}};

    while (!q.empty()) {
        pi top = q.front();
        q.pop();

        if (top == end) {
            cout << "YES" << endl;
            cout << dist[top.first][top.second] << endl;
            vector<char> seq;
            for (pi curr = top; curr != start; curr = parent[curr.first][curr.second]) {
                int ud_diff = curr.first - parent[curr.first][curr.second].first;
                int lr_diff = curr.second - parent[curr.first][curr.second].second;

                if (ud_diff > 0) seq.push_back('D');
                if (ud_diff < 0) seq.push_back('U');
                if (lr_diff > 0) seq.push_back('R');
                if (lr_diff < 0) seq.push_back('L');
            }

            reverse(seq.begin(), seq.end());
            for (char c : seq) cout << c;
            cout << endl;

            return 0;
        }

        for (pi dir : adj) {
            pi loc = {dir.first + top.first, dir.second + top.second};
            if (loc.first < 0 || loc.first >= n || loc.second < 0 || loc.second >= m) continue;
            if (dist[loc.first][loc.second] == INT_MAX && !a[loc.first][loc.second]) {
                parent[loc.first][loc.second] = top;
                dist[loc.first][loc.second] = dist[top.first][top.second] + 1;
                q.push(loc);
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}