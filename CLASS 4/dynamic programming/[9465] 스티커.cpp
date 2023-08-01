// 9465 스티커
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; // 테스트 케이스의 수
    cin >> T;
    while (T--) { // 각 테스트 케이스에 대하여
        int n; // 스티커의 열의 수
        cin >> n;
        vector<vector<int>> stickers(n, vector<int>(2)); // 스티커 점수 저장 배열
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < n; i++)
                cin >> stickers[i][j]; // 스티커 점수 입력

        vector<vector<int>> dp(n, vector<int>(3)); // 동적 프로그래밍을 위한 dp 배열

        const int FIRST = 0; // 첫 번째 행의 스티커를 뜯는 경우
        const int SECOND = 1; // 두 번째 행의 스티커를 뜯는 경우
        const int NONE = 2; // 스티커를 뜯지 않는 경우

        dp[0][FIRST] = stickers[0][FIRST]; // 첫 번째 열에서 첫 번째 행의 스티커를 뜯는 경우의 최대 점수
        dp[0][SECOND] = stickers[0][SECOND]; // 첫 번째 열에서 두 번째 행의 스티커를 뜯는 경우의 최대 점수
        dp[0][NONE] = 0; // 스티커를 뜯지 않는 경우의 최대 점수는 0

        for (int i = 1; i < n; i++) {
            // 각 열에서 첫 번째 행의 스티커를 뜯는 경우의 최대 점수는, 이전 열에서 두 번째 행의 스티커를 뜯거나 스티커를 뜯지 않은 경우의 점수에 현재 스티커의 점수를 더한 것
            dp[i][FIRST] = max(dp[i - 1][SECOND], dp[i - 1][NONE]) + stickers[i][FIRST];
            // 각 열에서 두 번째 행의 스티커를 뜯는 경우의 최대 점수는, 이전 열에서 첫 번째 행의 스티커를 뜯거나 스티커를 뜯지 않은 경우의 점수에 현재 스티커의 점수를 더한 것
            dp[i][SECOND] = max(dp[i - 1][FIRST], dp[i - 1][NONE]) + stickers[i][SECOND];
            // 스티커를 뜯지 않는 경우의 최대 점수는, 이전 열에서 첫 번째 행 또는 두 번째 행의 스티커를 뜯는 경우의 점수 중 큰 것
            dp[i][NONE] = max(dp[i - 1][FIRST], dp[i - 1][SECOND]);
        }

        // 마지막 열까지 고려한 최대 점수 출력
        cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << '\n';
    }
}
