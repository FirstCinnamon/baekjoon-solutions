// 11727 2xn 타일링 2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 속도 개선
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;      // 직사각형의 가로 길이를 저장할 변수
    cin >> N;   // 사용자로부터 직사각형의 가로 길이 입력 받음

    vector<int> dp(N + 1);  // 각 크기에 대한 타일링 방법의 수를 저장할 벡터
    dp[1] = 1;  // 2x1 직사각형을 채우는 방법은 1가지
    dp[2] = 3;  // 2x2 직사각형을 채우는 방법은 3가지

    for (int i = 3; i <= N; i++)    // 3부터 N까지 동적 계획법을 이용하여 각각의 경우의 수를 계산
        // i 크기의 직사각형을 채우는 방법은 i-1 크기의 직사각형을 채우는 방법에 2x1 타일을 추가하는 방법과
        // i-2 크기의 직사각형을 채우는 방법에 1x2 타일 2개 또는 2x2 타일을 추가하는 방법을 합친 것과 같음
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;   // 이전의 두 경우의 합에 2를 곱한 것과 이전의 경우의 수를 더하여 10007로 나눈 나머지를 저장

    cout << dp[N];  // 계산된 2xN 직사각형을 채우는 방법의 수를 출력
}
