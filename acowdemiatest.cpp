#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ofstream fout("acowdemia.in");

    srand(time(NULL));

    int n = rand() % 5000 + 1;
    int k = rand() % 5000;
    int l = rand() % 5000;

    fout << n << ' ' << k << ' ' << l << endl;

    for (int i = 0; i < n; i++) {
        fout << (rand() % 50000) << endl;
    }

    fout << endl;

    return 0;
}