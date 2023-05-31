#include <iostream>
#include <vector>
using namespace std;

int maximumChocolates(int N, int K, vector<int>& A, vector<int>& W) {
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (W[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-W[i-1]] + A[i-1]);
            }
        }
    }

    return dp[N][K];
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> W(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    int maxChocolates = maximumChocolates(N, K, A, W);
    cout << maxChocolates << endl;

    return 0;
}