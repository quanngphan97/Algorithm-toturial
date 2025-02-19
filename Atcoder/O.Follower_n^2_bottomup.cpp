#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;


void solve() {
    int n; cin >> n;
    vector<int> a(n),h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp(n+1);

    for(int flower = 0; flower < n; flower++) {
        for(int j = 0; j < h[flower]; j++) {
            dp[h[flower]] = max(dp[h[flower]], dp[j] + a[flower]);
        }
    }
    int ans = 0 ;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
