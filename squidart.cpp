#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n, m;

vector<vector<bool>> visited;
vector<vector<bool>> grid;
vector<vector<int>> sections;
int section_id = 0;

vector<set<int>> adj;
set<pair<pair<int, int>, pair<int, int>>> ed;

void f_fill(ll x, ll y, ll par_x, ll par_y, bool color) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (grid[x][y] != color) {
        ed.insert({{x, y}, {par_x, par_y}});
        return;
    }
    if (visited[x][y]) return;

    visited[x][y] = true;
    sections[x][y] = section_id;

    f_fill(x + 1, y, x, y, color);
    f_fill(x - 1, y, x, y, color);
    f_fill(x, y + 1, x, y, color);
    f_fill(x, y - 1, x, y, color);
    if (x % 2 == 0) {
        f_fill(x + 1, y + 1, x, y, color);
        f_fill(x - 1, y + 1, x, y, color);
    } else {
        f_fill(x + 1, y - 1, x, y, color);
        f_fill(x - 1, y - 1, x, y, color);
    }
}

int main() {
    cin >> n >> m;

    visited = vector<vector<bool>>(n, vector<bool>(m, 0));
    grid = vector<vector<bool>>(n, vector<bool>(m, 0));
    sections = vector<vector<int>>(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                f_fill(i, j, -1, -1, grid[i][j]);
                section_id++;
                adj.push_back({});
            }
        }
    }

    for (pair<pair<int, int>, pair<int, int>> edge : ed) {
        pair<int, int> a = edge.first;
        pair<int, int> b = edge.second;
        adj[sections[a.first][a.second]].insert(sections[b.first][b.second]);
        adj[sections[b.first][b.second]].insert(sections[a.first][a.second]);
    }

    int V = section_id;

    queue<int> q;

    // from geeksforgeeks
    //  first enqueue all leaf nodes in queue
    for (int i = 0; i < section_id; i++) {
        if (adj[i].size() == 1) q.push(i);
    }

    int ans = 0;

    //  loop untill total vertex remains less than 2
    while (V > 2) {
        int popEle = q.size();
        ans++;
        V -= popEle;  // popEle number of vertices will be popped

        for (int i = 0; i < popEle; i++) {
            int t = q.front();
            q.pop();

            // for each neighbour, decrease its degree and
            // if it become leaf, insert into queue
            for (auto j = adj[t].begin(); j != adj[t].end(); j++) {
                adj[*j].erase(t);
                if (adj[*j].size() == 1)
                    q.push(*j);
            }
        }
    }

    //  copying the result from queue to result vector
    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }

    // res are candidates
    bool isblue = false;
    bool isred = false;
    if (res.size() == 2) ans += 1;
    for (int k : res) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (sections[i][j] == k) {
                    if (grid[i][j] == 1)
                        isblue = true;
                    else
                        isred = true;
                }
            }
        }
    }

    if (isblue && isred) {
        cout << ans << endl;
        return 0;
    }

    if (ans % 2 == 0) {
        if (isblue)
            cout << ans << endl;
        else
            cout << ans + 1 << endl;

    } else {
        if (isred)
            cout << ans << endl;
        else
            cout << ans + 1 << endl;
    }

    return 0;
}