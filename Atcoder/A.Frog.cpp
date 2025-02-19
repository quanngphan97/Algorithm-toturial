#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> h(n),dp(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++) {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i-1],
                    abs(h[i] - h[i-2]) + dp[i-2]);
    }
    cout << dp[n-1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}