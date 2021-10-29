#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("shufflegold.in");
    ofstream fout("shufflegold.out");

    int n, m, q;
    fin >> n >> m >> q;

    vi p(m + 1, -1);
    vi pi(m + 1, -1);
    for (int i = 1; i <= m; i++) {
        fin >> p[i];
        p[i]--;

        pi[p[i]] = i;
    }

    vi start;
    vi dist(m + 1, -1);
    int curr = 0;
    int curr_dist = 0;
    while (curr != -1) {
        if(curr != 0) start.push_back(curr);
        dist[curr] = curr_dist++;
        curr = pi[curr];
    }

    int psz = start.size();

    // cycles

    vector<bool> vis(m + 1);
    vi from(m + 1);
    for (int i = 0; i < m; i++) {
        if (vis[i] || dist[i] != -1) continue;

        int v = i;
        int cy_sz = 0;

        while(!vis[v]) {
            vis[v] = true;
            v = p[v];

            cy_sz++;
        }

        int src = i;
        int snk = i;
        for (int j = 0; j < (n - m + 1) % cy_sz; j++) {
            snk = p[snk];
        }

        for (int j = 0; j < cy_sz; j++) {
            from[snk] = src;
            src = p[src];
            snk = p[snk];
        }
    }

    int qi;
    for (int i = 0; i < q; i++) {
        fin >> qi;
        qi = n - qi;

        if (qi >= n - m) {
            int mi = qi - (n - m);
            if (dist[mi] != -1) {
                int chain_pos = n - m + dist[mi];
                if (chain_pos < psz) fout << start[chain_pos] << endl;
                else fout << chain_pos - psz + m + 1 << endl;
            } else fout << from[mi] << endl;

        }

        else if (qi < psz) fout << start[qi] << endl;
        else fout << qi - psz + m + 1 << endl;
    }

    return 0;
}