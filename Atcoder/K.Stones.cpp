#include <iostream>
#include <vector>
using namespace std;

string findWinnerBottomUp(int K, const vector<int>& A) {
    vector<bool> dp(K + 1, false); // dp[k] = true nếu trạng thái k là trạng thái thắng

    // Điều kiện cơ sở
    dp[0] = false; // Không còn viên đá nào, người chơi hiện tại thua

    // Tính trạng thái dp[k] từ 1 đến K
    for (int k = 1; k <= K; ++k) {
        for (int x : A) {
            if (x <= k && !dp[k - x]) { // Nếu có một nước đi khiến đối thủ thua
                dp[k] = true;
                break;
            }
        }
    }

    return dp[K] ? "First" : "Second";
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(auto i = 0; i < n; ++i) cin >> v[i];

    cout << findWinnerBottomUp(k, v) << endl;
    return 0;
}
