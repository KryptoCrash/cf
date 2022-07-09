/*

At first i thought i could binary search to find the answer
then i got WA and realized that apartments are filled when you use them, hence greedy is needed
this reminded me of an old usaco problem, this is slightly easier since all the ranges are constant size
we will use two pointers and sort everything first
now it becomes obvious that we should use the first point possible for the first range to maximize oppurtunities
we will iterate over a and if a[i] is within the current range, use it and move on
if it is before the current range move to next a but keep range the same
if it is after the current range move to next a and move to next range

formally:
    sort a and b by increasing order
    set i = 0, j = 0
    while i != n and j != m:
        if a[i] < b[j] - x: i++
        if a[i] > b[j] + x: i++, j++
        else: i++, j++, sum++
    sum is the answer
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int n, m, k;

const int maxn = 100;

int main() {
    cin >> n >> m >> k;

    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i, j, sum;
    i = j = sum = 0;

    while (i != n && j != m) {
        if (a[i] < b[j] - k)
            i++;
        else if (a[i] > b[j] + k)
            j++;
        else
            i++, j++, sum++;
    }

    cout << sum << endl;

    return 0;
}