#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int max_n = 3005;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Cơ sở: Độ dài 1 chỉ có 1 cách
    dp[1][1] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= len; i++) {
            dp[len][i] = 0; // Khởi tạo dp[len][i]
            
            if (s[len - 2] == '<') { // P[len-1] < P[len]
                for (int j = 1; j < i; j++) { // j < i
                    dp[len][i] += dp[len - 1][j];
                    dp[len][i] %= mod;
                }
            } else { // P[len-1] > P[len]
                for (int j = i + 1; j <= len; j++) { // j > i
                    dp[len][i] += dp[len - 1][j];
                    dp[len][i] %= mod;
                }
            }
        }
    }

    // Tính tổng tất cả các giá trị dp[n][i] để ra kết quả cuối cùng
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
