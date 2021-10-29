#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

ll n;

vector<vector<bool>> visited;
vector<vector<bool>> wall;
vector<vector<array<int, 3>>> moves;
vector<vector<vector<pi>>> reachable;

ll si, sj;

set<vector<vi>> seenBoardStates;

bool checkPos(array<int, 3> mv, vector<vi> state) {
    return state[mv[1]][mv[2]] == -1;
}

void dfs_moves(ll x, ll y, vector<vi> state) {
    array<int, 3> curr_move = moves[x][y];
    if (curr_move[0] != -1) state[curr_move[1]][curr_move[2]] = curr_move[0];
    if (seenBoardStates.find(state) != seenBoardStates.end()) return;
    seenBoardStates.insert(state);
    for (pi mv : reachable[x][y]) {
        // check if u can make the move
        if (checkPos(moves[mv.first][mv.second], state)) {
            dfs_moves(mv.first, mv.second, state);
        }
    }
}

void f_fill(ll x, ll y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (visited[x][y] || wall[x][y]) return;

    visited[x][y] = true;

    if ((moves[x][y][0] != -1) && (!(x == si && y == sj))) {
        reachable[si][sj].push_back({x, y});
        return;
    }

    f_fill(x + 1, y);
    f_fill(x - 1, y);
    f_fill(x, y + 1);
    f_fill(x, y - 1);
}

int main() {
    cin >> n;

    visited = vector<vector<bool>>(n, vector<bool>(n, 0));
    wall = vector<vector<bool>>(n, vector<bool>(n, 0));
    moves = vector<vector<array<int, 3>>>(n, vector<array<int, 3>>(n, {-1, -1, -1}));
    reachable = vector<vector<vector<pi>>>(n, vector<vector<pi>>(n, vector<pi>(0, {-1, -1})));

    pair<int, int> pos = {-1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<char> curr(3);
            for (int k = 0; k < 3; k++) {
                char c;
                cin >> c;
                curr[k] = c;
            }
            if (curr[0] == '#') {
                wall[i][j] = true;
            } else if (curr[0] == 'B') {
                pos = {i, j};
            } else if (curr[0] == '.') {
            } else {
                array<int, 3> move;
                move[0] = curr[0] == 'M' ? 1 : 0;
                move[1] = (curr[1] - '0') - 1;
                move[2] = (curr[2] - '0') - 1;
                moves[i][j] = move;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (moves[i][j][0] != -1 || (i == pos.first && j == pos.second)) {
                si = i;
                sj = j;
                fill(visited.begin(), visited.end(), vector<bool>(n, false));
                f_fill(i, j);
            }
        }
    }

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vector<pi> mvs = reachable[i][j];
            if (!mvs.empty()) {
                cout << i << ' ' << j << endl;
                for (pi mv : mvs) {
                    cout << mv.first << ' ' << mv.second << endl;
                }
                cout << endl;
            }
        }
    }
    */

    dfs_moves(pos.first, pos.second, {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}});
    ll sum = 0;
    for (vector<vi> state : seenBoardStates) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cout << (state[i][j] == -1 ? "." : (state[i][j] == 1 ? "M" : "O")) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    cout << sum << endl;

    return 0;
}