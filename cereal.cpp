#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int maxn = 1e5 + 8;

int belong[maxn];
pi choices[maxn];
int tot = 0;

void prepend(int c_taking, int fc) {
    
    // Now belongs to the senior cow

    // This cereal was never taken
    if(c_taking < 0) {
        tot++;
        return;
    }

    // Cereal was taken by c_taking
    
    // it is c_taking's second choice
    if(choices[c_taking].second == fc) {
        return;
    }
    // it is c_taking's first choice
    else {
        // is c_taking's second choice available
        int c_sc = choices[c_taking].second;

        // It is
        if(belong[c_sc] < 0) {
            belong[c_sc] = c_taking;
            tot++;
            return;
        }
        // It isn't
        else if(belong[c_sc] < c_taking) {
            return;
        }
        // It is, but we also have to recurse
        else {
            int c_sc_taking = belong[c_sc];
            belong[c_sc] = c_taking; 
            prepend(c_sc_taking, c_sc);
            return;
        }
    }
}

int main(int argc, char const *argv[]) {
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");

    int n, m;
    fin >> n >> m;

    int ans[maxn];

    memset(belong, -1, sizeof(belong));

    for (int i = 0; i < n; i++) {
        fin >> choices[i].first >> choices[i].second;
    }

    for (int i = n - 1; i >= 0; i--) {
        int fc = choices[i].first;
        int c_taking = belong[fc];
        belong[fc] = i;
        prepend(c_taking, fc);

        ans[i] = tot;
    }

    for (int i = 0; i < n; i++) {
        fout << ans[i] << endl;
    }

    return 0;
}