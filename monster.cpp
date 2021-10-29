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

    vector<vector<int>> closestMonster(n, vector<int>(m, INT_MAX));
    vector<vector<int>> closestHuman(n, vector<int>(m, INT_MAX));

    queue<pair<pi, int>> q;

    //cout << "bfs to find how close each square is to a monster" << endl;
    for (pi mon : monsters) {
        q.push({mon, 0});
        closestMonster[mon.first][mon.second] = 0;
    }

    vector<pi> adj = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    while (!q.empty()) {
        pair<pi, int> top = q.front();
        q.pop();
        pi loc = top.first;
        int depth = top.second;

        for (pi dir : adj) {
            int i = dir.first + loc.first;
            int j = dir.second + loc.second;
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (wall[i][j]) continue;
            if (closestMonster[i][j] != INT_MAX) continue;
            q.push({{i, j}, depth + 1});
            closestMonster[i][j] = depth + 1;
        }
    }

    //cout << "bfs to find how close each square is to a human" << endl;
    q.push({start, 0});
    closestHuman[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<pi, int> top = q.front();
        q.pop();
        pi loc = top.first;
        int depth = top.second;

        for (pi dir : adj) {
            int i = dir.first + loc.first;
            int j = dir.second + loc.second;
            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (wall[i][j]) continue;
            if (closestHuman[i][j] != INT_MAX) continue;
            q.push({{i, j}, depth + 1});
            closestHuman[i][j] = depth + 1;
        }
    }

    vector<vector<bool>> doable(n, vector<bool>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            doable[i][j] = closestHuman[i][j] < closestMonster[i][j];
        }
    }

    //cout << "find shortest path to an ending" << endl;
    vector<vector<char>> dirs(n, vector<char>(m, 0));
    vector<vector<pi>> parent(n, vector<pi>(m, {-1, -1}));
    vector<vector<bool>> visit(n, vector<bool>(m, 0));
    q.push({start, 0});
    visit[start.first][start.second] = true;

    while (!q.empty()) {
        pair<pi, int> top = q.front();
        q.pop();
        pi loc = top.first;
        int depth = top.second;

        if(loc.first == 0 || loc.first == n - 1 || loc.second == 0 || loc.second == m - 1) {
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
            if (!doable[i][j]) continue;
            if (visit[i][j]) continue;
            if (dir.first == -1) dirs[i][j] = 'U';
            if (dir.first == 1) dirs[i][j] = 'D';
            if (dir.second == 1) dirs[i][j] = 'R';
            if (dir.second == -1) dirs[i][j] = 'L';
            parent[i][j] = {loc.first, loc.second};
            visit[i][j] = true;
            q.push({{i, j}, depth + 1});
        }
    }

    cout << "NO" << endl;

    return 0;
}