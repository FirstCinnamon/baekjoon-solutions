// 9251 LCS
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string X, Y; // 두 문자열을 입력받음
    cin >> X;
    cin >> Y;

    int x = X.size(); // 문자열 X의 길이
    int y = Y.size(); // 문자열 Y의 길이

    // dp 테이블 초기화 (모두 0으로)
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

    // 문자열의 각 문자를 순차적으로 비교
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            // 만약 문자가 일치하면, dp[i][j]는 왼쪽 위 대각선의 값(dp[i-1][j-1])에 1을 더한 값이 됨
            if (X[i-1] == Y[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                // 문자가 일치하지 않으면, dp[i][j]는 왼쪽(dp[i][j-1]) 또는 위(dp[i-1][j])의 값 중 더 큰 값이 됨
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    // dp 테이블의 마지막 값 출력 (즉, 두 문자열의 LCS 길이)
    cout << dp[x][y];
}
