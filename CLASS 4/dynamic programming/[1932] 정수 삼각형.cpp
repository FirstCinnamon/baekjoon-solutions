// 1932 정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);  // 입출력 속도 향상을 위해 사용
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;  // 삼각형의 크기 입력

    vector<vector<int>> triangle(n);  // 삼각형을 저장할 벡터 선언
    vector<vector<int>> dp(n);  // 동적 계획 테이블을 저장할 벡터 선언

    // 삼각형 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int tmp;
            cin >> tmp;
            triangle[i].push_back(tmp);
        }
    }

    dp[0].push_back(triangle[0][0]);  // 동적 계획 테이블 초기값 설정

    // 동적 계획법을 사용하여 최대 합 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int curr = triangle[i][j];
            if (j == 0)  // 왼쪽 끝의 경우
                dp[i].push_back(curr + dp[i - 1][j]);
            else if (j == i)  // 오른쪽 끝의 경우
                dp[i].push_back(curr + dp[i - 1][j - 1]);
            else  // 그 외의 경우 (왼쪽 끝과 오른쪽 끝 제외)
                dp[i].push_back(curr + max(dp[i - 1][j - 1], dp[i - 1][j]));  // 이전 층에서 가능한 최대값을 선택
        }
    }

    // 최대 합 계산 결과 출력
    int max = *max_element(dp[n - 1].begin(), dp[n - 1].end());  // 마지막 층에서 최대 합을 찾아 출력
    cout << max;
}
