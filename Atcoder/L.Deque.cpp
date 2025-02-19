#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

int solve(int cnt, int idx, int n, int k, vector<int> &a, vector<vector<int>> &dp) {
    if (cnt == k) return 0;
    if (idx > n) return 0;

    if (dp[idx][cnt] != -1) return dp[idx][cnt]; 

    int &ans = dp[idx][cnt];

    ans = max(
        a[idx] + min(solve(cnt + 1, idx + 1, n - 1, k, a, dp), solve(cnt + 1, idx + 2, n, k, a, dp)),
        a[n] + min(solve(cnt + 1, idx + 1, n - 1, k, a, dp), solve(cnt + 1, idx, n - 2, k, a, dp))
    );

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }    

    int k = n/2 + (n%2);
    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 

    int result = solve(0, 0, n - 1, k, a, dp);
    cout << 2*result-sum << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
