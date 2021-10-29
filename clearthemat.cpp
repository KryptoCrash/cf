/*
Idea: do dp on 4 column prefixes
loop over piece start location and prefix mask

we claim everything up to some col n is solved
now we want to solve col n + 1
so we will place down things at n + 1

but there might be some things blocking us, so we will have to keep a mask of the 4x4 grid in front of n

first we know that all previous blocks are either on top of or to the left of it
in any case you arent going to "fit" into something if it blocks you

so our final algorithm is dp[i][j][5][5][5][5] w/ 5 transitions

*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

const int INF = 1e9;

// lmao wtf
typedef vector<int> Dim1;
typedef vector<Dim1> Dim2;
typedef vector<Dim2> Dim3;
typedef vector<Dim3> Dim4;
typedef vector<Dim4> Dim5;
typedef vector<Dim5> Dim6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    Dim6 dp(1008, Dim5(4, Dim4(5, Dim3(5, Dim2(5, Dim1(5, INF))))));

    dp[0][0][0][0][0][0] = 0;

    int c[4];

    for (int i = 0; i < 4; i++) {
        cin >> c[i];
    }

    vector<vector<bool>> a(n + 1, vector<bool>(4, true));
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < n; i++) {
            char cg;
            cin >> cg;
            a[i][j] = cg == '.';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            array<int, 4> p = {0, 0, 0, 0};
            for (p[0] = 0; p[0] < 5; p[0]++) {
                for (p[1] = 0; p[1] < 5; p[1]++) {
                    for (p[2] = 0; p[2] < 5; p[2]++) {
                        for (p[3] = 0; p[3] < 5; p[3]++) {
                            int cost = dp[i][j][p[0]][p[1]][p[2]][p[3]];
                            if (cost == INF) continue;
                            //cout << i << ' ' << j << ' ' << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << ' ' << cost << endl;
                            // dont add block
                            if (a[i][j] || p[j] > 0) {
                                if (j == 3)
                                    dp[i + 1][0][max(0, p[0] - 1)][max(0, p[1] - 1)][max(0, p[2] - 1)][max(0, p[3] - 1)] = min(dp[i + 1][0][max(0, p[0] - 1)][max(0, p[1] - 1)][max(0, p[2] - 1)][max(0, p[3] - 1)], cost);
                                else
                                    dp[i][j + 1][p[0]][p[1]][p[2]][p[3]] = min(dp[i][j + 1][p[0]][p[1]][p[2]][p[3]], cost);
                            }

                            // try to add block of size s at i,j
                            for (int s = 1; s <= 4; s++) {
                                array<int, 4> nm = p;

                                // check for issues with placing down
                                bool issue = false;
                                for (int jc = 0; jc < s; jc++) {
                                    // out of bounds
                                    if (jc + j >= 4 || i + s > n)
                                        issue = true;
                                    else {
                                        nm[jc + j] = s;
                                    }
                                }

                                if (issue) continue;

                                // if everything works place it down and update the new mask
                                if (j == 3)
                                    dp[i + 1][0][max(0, nm[0] - 1)][max(0, nm[1] - 1)][max(0, nm[2] - 1)][max(0, nm[3] - 1)] = min(dp[i + 1][0][max(0, nm[0] - 1)][max(0, nm[1] - 1)][max(0, nm[2] - 1)][max(0, nm[3] - 1)], cost + c[s - 1]);
                                else
                                    dp[i][j + 1][nm[0]][nm[1]][nm[2]][nm[3]] = min(dp[i][j + 1][nm[0]][nm[1]][nm[2]][nm[3]], cost + c[s - 1]);
                            }
                        }
                    }
                }
            }
        }
    }

    // ok pray to the dp gods
    cout << dp[n][0][0][0][0][0] << endl;

    return 0;
}