// 1149 RGB거리
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    // 집의 수 입력받기
    cin >> N;

    // 각 집의 비용 정보를 저장할 2차원 벡터 houses
    vector<vector<int>> houses (N+1, vector<int> (3));
    // 동적 프로그래밍을 위한 2차원 벡터 dp
    vector<vector<int>> dp(N+1, vector<int> (3));

    // 각 집의 비용 정보 입력받기
    for(int i=1; i<=N; i++)
        for (int j=0; j<3; j++)
            cin >> houses[i][j];

    // 첫 집의 비용 초기화
    for (int i=0; i<3; i++)
        dp[1][i] = houses[1][i];

    // 모든 집에 대해 동적 프로그래밍 진행
    for (int i=2; i<=N; i++) {
        // 빨강(R)으로 칠할 경우의 최소 비용 계산
        dp[i][0] = houses[i][0] + min(dp[i-1][1], dp[i-1][2]);
        // 초록(G)으로 칠할 경우의 최소 비용 계산
        dp[i][1] = houses[i][1] + min(dp[i-1][0], dp[i-1][2]);
        // 파랑(B)으로 칠할 경우의 최소 비용 계산
        dp[i][2] = houses[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    // 모든 집을 칠하는 비용의 최솟값 출력
    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}
