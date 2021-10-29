#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    srand(time(NULL));

    ofstream fout("appendsort.in");

    int t = rand() % 20;
    fout << t << endl;
    while (t--) {
        int n = rand() % 100;
        fout << n << endl;
        for (int i = 0; i < n; i++) {
            fout << (rand() % (ll)1e9) + 1 << " ";
        }
        fout << endl;
    }

    return 0;
}