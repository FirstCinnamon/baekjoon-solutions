// 9095 1, 2, 3 더하기
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 개수
    int T;
    cin >> T;

    // 동적 프로그래밍을 위한 배열 초기화
    // dp[i]는 i를 1, 2, 3의 합으로 나타내는 방법의 수
    int dp[12] = {0, 1, 2, 4};

    // 4부터 11까지 각 숫자를 1, 2, 3의 합으로 나타내는 방법의 수 계산
    for (int i = 4; i < 12; i++)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    // 각 테스트 케이스에 대해
    while (T--) {
        // 테스트 케이스 입력 받기
        int n;
        cin >> n;
        
        // n을 1, 2, 3의 합으로 나타내는 방법의 수 출력
        cout << dp[n] << '\n';
    }
}
