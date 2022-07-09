/* SAMPLE
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

int main() {
    cin >> n >> m;

    vector<vector<bool>> wall(n, vector<bool>(m, 0));
    set<pi> monsters;
    pi start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') wall[i][j] = true;
            if (c == 'M') monsters.insert({i, j});
            if (c == 'A') start = {i, j};
        }
    }

    queue<pair<pi, bool>> q;
    vector<vector<bool>> visitedByMonster(n, vector<bool>(m, 0));
    vector<vector<bool>> visit(n, vector<bool>(m, 0));

    vector<vector<char>> dirs(n, vector<char>(m, 0));
    vector<vector<pi>> parent(n, vector<pi>(m, {-1, -1}));

    for (pi mon : monsters) {
        q.push({mon, true});
        visitedByMonster[mon.first][mon.second] = true;
    }

    q.push({start, false});
    visit[start.first][start.second] = true;

    vector<pi> adj = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (!q.empty()) {
        pair<pi, bool> top = q.front();
        q.pop();
        pi loc = top.first;
        bool isMonster = top.second;

        if ((loc.first == 0 || loc.first == n - 1 || loc.second == 0 || loc.second == m - 1) && !isMonster) {
            vector<char> seq;

            for (pi curr = loc; curr != start; curr = parent[curr.first][curr.second]) {
                seq.push_back(dirs[curr.first][curr.second]);
            }

            cout << "YES" << endl;

            reverse(seq.begin(), seq.end());
            cout << seq.size() << endl;

            for (char c : seq) cout << c;
            cout << endl;

            return 0;
        }

        for (pi dir : adj) {
            int i = dir.first + loc.first;
            int j = dir.second + loc.second;
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (wall[i][j] || visitedByMonster[i][j]) continue;
            if (!isMonster && visit[i][j]) continue;

            q.push({{i, j}, isMonster});
            if (isMonster) visitedByMonster[i][j] = true;
            else {
                if (dir.first == -1) dirs[i][j] = 'U';
                if (dir.first == 1) dirs[i][j] = 'D';
                if (dir.second == 1) dirs[i][j] = 'R';
                if (dir.second == -1) dirs[i][j] = 'L';
                parent[i][j] = {loc.first, loc.second};
                visit[i][j] = true;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}