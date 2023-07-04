// 17626 Four Squares
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    // 자연수 n 입력 받기
    cin >> n;

    // dp 배열 생성, 초기값을 4로 설정 (최대 개수)
    vector<int> dp(n + 1, 4);

    // dp[0]을 0으로 설정
    dp[0] = 0;

    // 동적 프로그래밍을 통해 n을 최소 개수의 제곱수 합으로 나타냄
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            // 이전까지의 제곱수 합들과 확인하면서 1을 더해줌
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }

    // 최종 결과 출력
    cout << dp[n];
}
