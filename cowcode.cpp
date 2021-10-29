#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int depth = 0;
ll recur(ll i, ll len) {
    depth++;
    if (i < len) return i;
    ll chunk = floor(log2(i / len));
    ll start = pow(2, chunk) * len;
    ll fc = i - start - 1;
    if (fc < 0) fc = start - 1;
    return recur(fc, len);
}

int main() {
    ifstream fin("cowcode.in");
    ofstream fout("cowcode.out");

    ll n;

    string str;
    getline(fin, str, ' ');

    fin >> n;
    n--;

    ll len = str.length();

    fout << str[recur(n, len)] << endl;
    cout << depth << endl;

    return 0;
}