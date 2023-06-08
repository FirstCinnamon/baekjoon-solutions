// 2579 계단 오르기
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  // 계단의 개수를 입력받을 변수
    cin >> N;
    vector<int> stairs(N + 1, 0);  // 각 계단의 점수를 저장할 벡터 (인덱스를 1부터 사용하기 위해 N+1 크기로 초기화)

    // DP를 위한 벡터. 각 계단에서 한 계단씩 오르는 경우와 두 계단씩 오르는 경우의 최대 점수를 저장.
    // dp[i].first는 i번째 계단에서 한 계단씩 오를 때의 최대 점수, dp[i].second는 두 계단씩 오를 때의 최대 점수를 의미.
    vector<pair<int, int>> dp(N + 1, pair<int, int>({0, 0}));

    for (int i = 1; i < N + 1; i++)  // 각 계단의 점수를 입력받아 저장
        cin >> stairs[i];

    // 첫 번째 계단의 경우, 한 계단씩 오르는 경우와 두 계단씩 오르는 경우의 점수는 동일함
    dp[1].first = stairs[1];
    dp[1].second = stairs[1];

    // 두 번째 계단부터 시작하여 각 경우의 최대 점수를 계산
    for (int i = 2; i <= N; i++) {
        // 한 계단씩 오르는 경우는 바로 이전 계단에서 두 계단씩 올라온 경우에만 가능하므로 dp[i-1].second에 현재 계단 점수를 더한 것이 최대 점수가 됨
        dp[i].first = dp[i - 1].second + stairs[i];

        // 두 계단씩 오르는 경우는 두 계단 전에서 한 계단씩 올라오거나 두 계단씩 올라온 경우 중 최대 점수를 가진 경우를 선택하고 현재 계단의 점수를 더함
        dp[i].second = max(dp[i - 2].first, dp[i - 2].second) + stairs[i];
    }

    // 마지막 계단에서 한 계단씩 오르는 경우와 두 계단씩 오르는 경우 중 최대 점수를 출력
    cout << max(dp[N].first, dp[N].second);

    return 0;
}
