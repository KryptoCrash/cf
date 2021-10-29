#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 0x3f3f3f3f;

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    bool ed[26][26];
    memset(ed, false, sizeof(ed));
    for (int i = 0; i < k; i++) {
        char a, b;
        cin >> a >> b;
        ed[a - 'A'][b - 'A'] = true;
    }

    int sp[26][26];
    memset(sp, INF, sizeof(sp));

    // bfs
    queue<pi> q;

    for (int i = 0; i < 26; i++) {
        bool vis[26];
        memset(vis, false, sizeof(vis));

        q.push({i, 0});
        vis[i] = true;

        while (!q.empty()) {
            pi v = q.front();
            q.pop();

            sp[i][v.first] = v.second;

            for (int e = 0; e < 26; e++) {
                if (ed[v.first][e] && !vis[e]) {
                    q.push({e, v.second + 1});
                    vis[e] = true;
                }
            }
        }
    }

    int best = INF;

    for (int c = 0; c < 26; c++) {
        int curr = 0;
        for (char i : s) {
            int dist = sp[i - 'A'][c];
            if (dist == INF) {
                curr = INF;
                break;
            }
            curr += dist;
        }

        best = min(best, curr);
    }

    cout << (best == INF ? -1 : best) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}