#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n;
vector<int> BIT;

void update(int i, int x) {
    while(i <= n) {
        BIT[i] = max(BIT[i], x);
        i += i & -i;
    }
}

int query(int i) {
    int ans = 0;
    while( i > 0) {
        ans = max(ans, BIT[i]);
        i -= i & -i;
    }
    return ans;
}

void solve() {
    cin >> n;
    BIT.resize(n+1,0);
    vector<int> a(n),h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int flower = 0; flower < n; flower++) {
        update(h[flower],query(h[flower]-1) + a[flower]);
    }
    cout << query(n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
