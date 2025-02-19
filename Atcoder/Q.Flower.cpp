#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
const int mod = 1e9 + 7;

int solve(int cnt, int height, int n, vector<int> &a, vector<int> &h, vector<int> &dp) {
    cout << "cnt " << cnt << " height " << height << endl;
    if (cnt > n) return 0;
    if (dp[cnt] != -1) return dp[cnt];

    int &ans = dp[cnt];
    ans = max(ans, solve(cnt+1, height, n, a, h, dp));

    if (height < h[cnt]) {
        // cout << "cnt " << cnt << " height " << height << endl;
        ans = max(ans, a[cnt] + solve(cnt+1, h[cnt], n, a, h, dp));    
    }
    return ans;
}


void solve() {
    int n; cin >> n;
    vector<int> h(n+1),a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n+1,-1);
    cout << solve(1,0,n,a,h,dp) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}