#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
    ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
    ll eval(ll x) const { return k * x + m; }
};

deque<Line> hull;
int n;
ll c, inf = LLONG_MAX;
vector<ll> h, dp;

ll division(ll a, ll b) { // floored division
    return a / b - ((a < 0) != (b < 0) && a % b);
}

bool isect(Line &x, const Line &y) {
    if (x.k == y.k) x.p = x.m > y.m ? inf : -inf;
    else x.p = division(y.m - x.m, x.k - y.k);
    return x.p >= y.p;
}

void add(ll k, ll m) {
    Line L = {k, m, 0};
    while ((int) hull.size() >= 2 && (isect(L, hull.back()),
        isect(hull.back(), hull[(int) hull.size() - 2]), L.p < hull.back().p))
        hull.pop_back();
    hull.push_back(L);
}

ll query(ll x) {
    while ((int) hull.size() >= 2 && hull[0].eval(x) >= hull[1].eval(x))
        hull.pop_front();
    return hull[0].eval(x);
}


void ins(int i, vector<ll> &h, vector<ll> &dp) {
    add(-h[i] * 2, (dp[i] + (h[i] * h[i])));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    vector<ll> h(n), dp(n);
    for (ll&x : h) cin >> x;

    dp[0] = 0;
    ins(0, h, dp);

    for (int i = 1; i < n; ++i) {
        ll x = query(h[i]);
        dp[i] = c + (h[i] * h[i]) + x;
        ins(i, h, dp);
    }
    cout << dp[n - 1] << '\n';
}
