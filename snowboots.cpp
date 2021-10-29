#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;
const int maxn = 250 + 20;
const int INF = 0x3f3f3f3f;

int main(int argc, char const *argv[]) {
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");

    int n, b;
    fin >> n >> b;

    int tiles[maxn];
    for (int i = 0; i < n; i++) {
        fin >> tiles[i];
    }

    pi boots[maxn];

    for (int i = 0; i < b; i++) {
        fin >> boots[i].first >> boots[i].second;
    }

    // state: (tile, boots)
    int dp[maxn][maxn];
    memset(dp, INF, sizeof(dp));

    dp[0][0] = 0;

    for (int ti = 0; ti < n; ti++) {
        for (int bi = 0; bi < b; bi++) {
            if(dp[ti][bi] == INF) continue;

            int b_depth = boots[bi].first;
            int dist = boots[bi].second;
            int t_depth = tiles[ti];

            // Walk forward
            for (int dist_walk = 1; dist_walk <= dist; dist_walk++) {
                if(((ti + dist_walk) < n) && (b_depth >= tiles[ti + dist_walk])) {
                    dp[ti + dist_walk][bi] = min(dp[ti + dist_walk][bi], dp[ti][bi]);
                }
            }

            // Try on a new pair of shoes
            for (int bi_nxt = bi + 1; bi_nxt < b; bi_nxt++) {
                if(boots[bi_nxt].first >= t_depth) dp[ti][bi_nxt] = min(dp[ti][bi_nxt], dp[ti][bi] + (bi_nxt - bi));
            }
        }
    }

    fout << *min_element(dp[n - 1], dp[n - 1] + b) << endl;


    return 0;
}