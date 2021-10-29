#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("shufflegold.in");
    ofstream fout("shufflegold.out");

    int n, m, q;
    fin >> n >> m >> q;

    vi p(m + 1, -1);
    for (int i = 1; i <= m; i++) {
        fin >> p[i];
        p[i]--;
    }

    vi queries(q);
    for (int i = 0; i < q; i++) {
        fin >> queries[i];
    }

    vi dist(m + 1, INF);

    int v = m;
    int c = 0;
    while (v != -1) {
        dist[v] = c++;
        v = p[v];
    }

    int path_sz = dist[0];
    dist[0] = 0;

    vi chain(m + 1);

    vi vis(m + 1);
    vi pos(m + 1);

    for (int i = 1; i <= m; i++) {
        if (dist[i] != INF) {
            dist[i] = path_sz - dist[i];
            chain[dist[i] - 1] = i;
        } else if (!vis[i]) {
            int curr = i;
            int cycle_sz = 0;
            while (!vis[curr]) {
                vis[curr] = true;
                cycle_sz++;
                curr = p[curr];
            }

            int src = i;
            int snk = i;
            for (int j = 0; j < (n - m + 1) % cycle_sz; j++) {
                snk = p[snk];
            }

            for (int j = 0; j < cycle_sz; j++) {
                pos[snk] = src;
                src = p[src];
                snk = p[snk];
            }
        }
    }

    /*
    //REDUDANT
    for (int i = m; i < n; i++) {
        chain[path_sz + i - m] = i + 1;
    }

    vi ans(n);

    for (int i = 0; i < n - m; i++) {
        ans[i] = chain[i];
    }

    for (int i = 0; i < m; i++) {
        if (dist[i] != INF) ans[n - m + i] = chain[n - m + dist[i]];
        else
            ans[n - m + i] = pos[i];
    }

    for (int i = 0; i < q; i++) {
        int qi = n - queries[i];
        fout << ans[qi] << endl;
    }
    */

    //cout << endl;

    for (int i = 0; i < q; i++) {
        int qi = n - queries[i];
        if (qi >= n - m) {
            int mi = qi - (n - m);
            if (dist[mi] != INF) {
                int cpos = n - m + dist[mi];
                if (cpos < path_sz)
                    fout << chain[cpos] << endl;
                else
                    fout << cpos - path_sz + m + 1 << endl;
            } else {
                fout << pos[mi] << endl;
            }
        } else if (qi < path_sz)
            fout << chain[qi] << endl;
        else
            fout << qi - path_sz + m + 1 << endl;
    }

    return 0;
}