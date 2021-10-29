#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int maxn = 1e5;

int main() {
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    int n;
    fin >> n;

    pi freq[maxn];
    for (int i = 0; i < n; i++) {
        fin >> freq[i].second >> freq[i].first;
    }

    sort(freq, freq + n);

    int l = 0;
    int r = n - 1;

    int mx_pair = 0;

    while(l <= r) {
        int fl = freq[l].second;
        int fr = freq[r].second;

        int a = freq[l].first;
        int b = freq[r].first;

        mx_pair = max(mx_pair, a + b);

        if(fl == fr) {
            l++, r--;
        } else if(fl < fr) {
            l++;
            freq[r].second -= fl;
        } else {
            r--;
            freq[l].second -= fr;
        }
    }

    fout << mx_pair << endl;

    return 0;
}