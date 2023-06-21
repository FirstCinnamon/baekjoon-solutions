// 11726 2xn 타일링
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N; // 사용자로부터 입력받을 2xN 크기의 직사각형의 N 값
    cin >> N;

    vector<int> dp(N + 1); // 각 크기에 대한 타일링 방법의 수를 저장할 벡터
    dp[1] = 1; // 2x1 크기의 직사각형을 채우는 방법의 수는 1가지
    dp[2] = 2; // 2x2 크기의 직사각형을 채우는 방법의 수는 2가지

    // 3부터 N까지 각 크기에 대한 타일링 방법의 수 계산
    for (int i = 3; i <= N; i++) {
        // i 크기의 직사각형을 채우는 방법은 i-1 크기의 직사각형을 채우는 방법에 2x1 타일을 추가하는 방법과
        // i-2 크기의 직사각형을 채우는 방법에 1x2 타일 2개를 추가하는 방법을 합친 것과 같음
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[N]; // 2xN 크기의 직사각형을 채우는 방법의 수 출력
}
