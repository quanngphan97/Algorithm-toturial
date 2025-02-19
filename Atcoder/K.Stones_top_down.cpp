#include <iostream>
#include <vector>
using namespace std;

// Hàm đệ quy để xác định trạng thái thắng/thua
bool winner(int k, const vector<int>& A, vector<int>& memo) {
    if (k == 0) return false; // Không còn đá, người chơi hiện tại thua
    if (memo[k] != -1) return memo[k]; // Nếu đã tính trước, trả về kết quả

    for (int x : A) {
        if (x <= k && !winner(k - x, A, memo)) {
            memo[k] = true; // Tìm được trạng thái để đối thủ thua
            return true;
        }
    }

    memo[k] = false; // Không có nước đi nào khiến đối thủ thua
    return false;
}

string findWinnerTopDown(int K, const vector<int>& A) {
    vector<int> memo(K + 1, -1); // Mảng memoization, khởi tạo -1
    return winner(K, A, memo) ? "First" : "Second";
}

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(auto i = 0; i < n; ++i) cin >> v[i];

    cout <<  findWinnerTopDown(k, v) << endl;
    return 0;
}

