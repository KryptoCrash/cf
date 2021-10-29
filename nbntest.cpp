#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ofstream fout("nbngen");

    srand(time(NULL));

    int n = 1e2;
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << to_string(rand() % (int) 9e8 + (int)1e8) << " " << 2 << endl;
    }

    return 0;
}