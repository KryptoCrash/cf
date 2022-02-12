#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pair<pi, ll>>;
using vb = vector<bool>;

template <typename K, typename V>
std::multimap<V, K> invertMap(std::map<K, V> const &map) {
    std::multimap<V, K> multimap;

    for (auto const &pair : map) {
        multimap.insert(std::make_pair(pair.second, pair.first));
    }

    return multimap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vpi a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }

    sort(a.begin(), a.end());
    vpi old(n);

    old = a;

    map<vpi, ll> mp;
    map<vpi, ll> mpw;
    map<vpi, ll> mptot;
    map<vpi, ll> mptie;
    map<vpi, set<vpi>> mpwins;
    map<vpi, set<vpi>> mplosses;

    set<pair<vpi, vpi>> done;

    do {
        mp[a] = 0;
        mpw[a] = 0;
        mptot[a] = 0;
        mptie[a] = 0;
    } while (next_permutation(a.begin(), a.end()));

    sort(a.begin(), a.end());

    ll mxdiff = 0;
    vpi worstmatchwin(n);
    vpi worstmatchlost(n);

    do {
        vpi b(n);
        b = old;
        do {
            ll l, r;
            l = r = 0;
            vpi c(n);
            vpi d(n);
            c = a;
            d = b;
            if (done.find({c, d}) != done.end() || done.find({d, c}) != done.end()) continue;
            done.insert({c, d});
            while (l < n && r < n) {
                if (c[l].second & 1) {
                    c[l].first.second -= max(0LL, d[r].first.first - 20);
                    c[l].second &= (1 << 16) - 1 - 1;
                } else {
                    c[l].first.second -= d[r].first.first;
                }
                if (d[r].second & 1) {
                    d[r].first.second -= max(0LL, c[l].first.first - 20);
                    d[r].second &= (1 << 16) - 1 - 1;
                } else {
                    d[r].first.second -= c[l].first.first;
                }
                if (c[l].first.second <= 0) l++;
                if (d[r].first.second <= 0) r++;
            }

            if (l == n && r == n) {
                mptie[a]++;
                mptie[b]++;
                continue;
            }

            if (abs(r - l) > mxdiff) {
                mxdiff = abs(r - l);
                if (l == n) {
                    worstmatchwin = b;
                    worstmatchlost = a;
                } else {
                    worstmatchwin = a;
                    worstmatchlost = b;
                }
            }

            if (l == n) {
                mp[a]--, mpw[b]++, mptot[a]--, mptot[b]++;
                mpwins[b].insert(a);
                mplosses[a].insert(b);
            }
            if (r == n) {
                mp[b]--, mpw[a]++, mptot[b]--, mptot[a]++;
                mpwins[a].insert(b);
                mplosses[b].insert(a);
            }

        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    std::multimap<ll, vpi> multimap = invertMap(mp);

    map<pair<pair<pi, ll>, ll>, ll> cp;

    ll avg = 0;
    ll cnt = 0;
    for (pair<vpi, ll> p : mp) {
        cnt++;
        avg += p.second;
    }

    avg /= cnt;

    for (pair<ll, vpi> p : multimap) {
        cout << "SET(w/l/w-l/t) " << mpw[p.second] << " / " << mp[p.second] << " / " << mptot[p.second] << " / " << mptie[p.second] << " : ";
        for (ll i = p.second.size() - 1; i >= 0; i--) {
            cout << "(" << p.second[i].first.first << " " << p.second[i].first.second << " " << p.second[i].second << ") ";
            cp[{p.second[i], i}] += mp[p.second];  //* (avg - mp[p.second]) * (avg - mp[p.second]);
            // cout << "TEST: " << cp[{p.second[i], i}] << " " << mp[p.second] << " " << i << " (" << p.second[i].first.first << " " << p.second[i].first.second << ") " << endl;
        }
        cout << endl;
    }

    pair<pi, ll> last = {{-1, -1}, -1};
    ll mx = -1e9;
    ll avg2 = 0;
    for (pair<pair<pair<pi, ll>, ll>, ll> blah : cp) {
        if (blah.first.first != last) {
            cout << abs(mx - avg2 / n) << endl;

            avg2 = 0;
            mx = -1e9;
            cout << endl;
        }
        last = blah.first.first;
        mx = max(blah.second, mx);
        avg2 += blah.second;
        cout << blah.second << " (" << blah.first.first.first.first << " " << blah.first.first.first.second << " " << blah.first.first.second << ") | " << (n - blah.first.second - 1) << endl;
    }

    cout << abs(mx - avg2 / n) << endl;

    avg2 = 0;
    mx = -1e9;
    cout << endl;

    cout << mxdiff << endl;
    for (ll i = worstmatchwin.size() - 1; i >= 0; i--) {
        cout << "(" << worstmatchwin[i].first.first << " " << worstmatchwin[i].first.second << " " << worstmatchwin[i].second << ") ";
    }
    cout << endl;
    for (ll i = worstmatchlost.size() - 1; i >= 0; i--) {
        cout << "(" << worstmatchlost[i].first.first << " " << worstmatchlost[i].first.second << " " << worstmatchlost[i].second << ") ";
    }
    cout << endl;
    cout << endl;

    while (true) {
        string s;
        cin >> ws;
        getline(cin, s);

        s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());

        stringstream ss(s);

        vpi match(n);
        vpi match2(n);
        char ch;
        ch = 'a';
        while (!ss.eof()) {
            if (ch == 'v') {
                for (int i = 0; i < n; i++) {
                    ss >> match2[i].first.first >> match2[i].first.second >> match2[i].second;
                }
            } else {
                for (int i = 0; i < n; i++) {
                    ss >> match[i].first.first >> match[i].first.second >> match[i].second;
                }
                ss >> ch;
            }
        }

        reverse(match.begin(), match.end());
        reverse(match2.begin(), match2.end());

        if (ch == 'v') {
            vpi c(n);
            vpi d(n);
            c = match;
            d = match2;
            ll l = 0;
            ll r = 0;
            for (ll i = c.size() - 1; i >= l; i--) {
                cout << "(" << c[i].first.first << " " << c[i].first.second << " " << c[i].second << ") ";
            }
            cout << " / ";

            for (ll i = r; i < d.size(); i++) {
                cout << "(" << d[i].first.first << " " << d[i].first.second << " " << d[i].second << ") ";
            }

            cout << " --> " << endl;
            while (l < n && r < n) {
                if (c[l].second & 1) {
                    c[l].first.second -= max(0LL, d[r].first.first - 20);
                    c[l].second &= (1 << 16) - 1 - 1;
                } else {
                    c[l].first.second -= d[r].first.first;
                }
                if (d[r].second & 1) {
                    d[r].first.second -= max(0LL, c[l].first.first - 20);
                    d[r].second &= (1 << 16) - 1 - 1;
                } else {
                    d[r].first.second -= c[l].first.first;
                }
                if (c[l].first.second <= 0) l++;
                if (d[r].first.second <= 0) r++;

                cout << endl;

                for (ll i = c.size() - 1; i >= l; i--) {
                    cout << "(" << c[i].first.first << " " << c[i].first.second << " " << c[i].second << ") ";
                }
                cout << " / ";

                for (ll i = r; i < d.size(); i++) {
                    cout << "(" << d[i].first.first << " " << d[i].first.second << " " << d[i].second << ") ";
                }

                cout << " --> " << endl;
            }

            cout << endl;
            if (l == n && r == n) {
                cout << "TIE" << endl;
            }

            if (l == n) {
                cout << "P1 LOST" << endl;
            }
            if (r == n) {
                cout << "P1 WON" << endl;
            }
        } else if (ch == 'w') {
            cout << "WON AGAINST:" << endl;
            for (vpi beat : mpwins[match]) {
                for (ll i = beat.size() - 1; i >= 0; i--) {
                    cout << "(" << beat[i].first.first << " " << beat[i].first.second << " " << beat[i].second << ") ";
                }
                cout << endl;
            }
        } else {
            cout << "LOST AGAINST:" << endl;
            for (vpi loss : mplosses[match]) {
                for (ll i = loss.size() - 1; i >= 0; i--) {
                    cout << "(" << loss[i].first.first << " " << loss[i].first.second << " " << loss[i].second << ") ";
                }
                cout << endl;
            }
        }

        cin >> ws;
    }

    return 0;
}