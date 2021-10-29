#include <bits/stdc++.h>
using namespace std;

using ll = double;
using pi = pair<ll, ll>;
using vi = vector<ll>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<pi> f(n + 1);
    for(int i = 1; i <= n; i++) {
        double a, b;
        cin >> a >> b;
        f[i] = {a, b};
    }

    vector<double> e1(n + 1);
    vector<double> e2(n + 1);
    vector<double> dist(n + 1);

    double sum = 0;
    double di = 0;

    for (int i = 1; i <= n; i++) {
        sum += f[i].first / f[i].second;
        di += f[i].first;
        dist[i] = di;
        e1[i] = sum;
    }

    sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum += f[i + 1].first / f[i + 1].second;
        e2[i] = sum;
    }

    for (int i = 0; i <= n; i++) {
        if (e2[i] == e1[i]) {
            cout << dist[i] << endl;
            break;
        }
        if(e2[i] < e1[i]) {
            // def between [i - 1, i]
            double x = (e1[i - 1] + e2[i - 1]) / 2;
            double y = f[i].second * (x - e1[i - 1]) + dist[i - 1];

            cout << y << endl;
            break;
        }
    }

    return 0;
}