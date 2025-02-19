#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
void solve() {
    int n,k; cin >> n >> k;
    vector<int> h(n),dp(n,oo);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp[i] = min(dp[i],abs(h[i] - h[i - j]) + dp[i -j]);
        }
    }
    cout << dp[n-1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}