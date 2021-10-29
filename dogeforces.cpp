#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
using pi = pair<int, int>;

int main() {
    int n;
    cin >> n;

    set<int, greater<int>> lca[maxn];
    map<int, int> first_n;
    map<int, int> first_n_inv;
    int best = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            cin >> v;
            if (i == j) {
                first_n[i + 1] = v;
                first_n_inv[v] = i + 1;
            }
            best = max(best, v);
            lca[i].insert(v);
        }
    }

    map<vector<pi>, vector<pi>> par;

    for (int i = 0; i < n; i++) {
        set<int, greater<int>> curr_set = lca[i];
        int curr_depth = 0;

        vector<pi> last = {};
        for(int l : curr_set) {
            last.push_back({l, curr_depth++});
        }
        while(last.size() > 0) {
            vector<pi> temp = last;

            for (pi th : last) cout << th.first << " ";
            last.pop_back();
            cout << endl;
            par[temp] = last;
        }
    }

    map<vector<pi>, int> ind;
    int i = 0;

    cout << par.size() + 1 << endl;
    for (auto thing : par) {
        vector<pi> node = thing.first;
        for (pi th : node) cout << th.first << " ";
        cout << endl;
        if (node.size() < 1) continue;
        ind[node] = i;
        cout << node.back().first << " ";
    }

    cout << best << endl;

    cout << par.size() + 1 << endl;

    for (auto node : par) {
        if (node.first.size() < 1) continue;
        int c = ind[node.first];
        int p = node.second.front().first == best ? par.size() + 1 : ind[node.second];
        cout << c << " " << p << endl;
    }

    return 0;
}