// 17070 파이프 옮기기 1
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // 벽의 정보를 저장하는 2차원 배열
    vector<vector<int>> map(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> map[i][j];

    // 다이나믹 프로그래밍을 위한 3차원 배열. 첫번째는 가로, 세로, 그리고 대각선을 저장
    vector<vector<vector<int>>> dp(3, (vector<vector<int>>(N, vector<int>(N, 0))));

    // 가로는 0, 세로는 1, 대각선은 2
    const int WIDTH = 0;
    const int HEIGHT = 1;
    const int CROSS = 2;

    // 초기 파이프의 위치는 가로로 0,1 을 끝으로 놓여있음
    dp[WIDTH][0][1] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool is_bottom_empty = true;    // 아래 칸이 비어있는지 여부를 저장
            bool is_right_empty = true;     // 오른쪽 칸이 비어있는지 여부를 저장
            bool is_cross_empty = false;    // 아래와 오른쪽, 그리고 오른쪽 아래 대각선 방향 칸이 비어있는지 여부를 저장

            if (i == N - 1 || map[i + 1][j] == 1)
                is_bottom_empty = false;
            if (j == N - 1 || map[i][j + 1] == 1)
                is_right_empty = false;
            if (is_bottom_empty && is_right_empty && map[i + 1][j + 1] == 0)
                is_cross_empty = true;

            // 가로에서 옮기기
            if (is_right_empty)
                dp[WIDTH][i][j + 1] += dp[WIDTH][i][j];
            if (is_cross_empty)
                dp[CROSS][i + 1][j + 1] += dp[WIDTH][i][j];

            // 세로에서 옮기기
            if (is_bottom_empty)
                dp[HEIGHT][i + 1][j] += dp[HEIGHT][i][j];
            if (is_cross_empty)
                dp[CROSS][i + 1][j + 1] += dp[HEIGHT][i][j];

            // 대각선에서 옮기기
            if (is_right_empty)
                dp[WIDTH][i][j + 1] += dp[CROSS][i][j];
            if (is_bottom_empty)
                dp[HEIGHT][i + 1][j] += dp[CROSS][i][j];
            if (is_cross_empty)
                dp[CROSS][i + 1][j + 1] += dp[CROSS][i][j];
        }
    }
    
    int ans = 0;
    // 가로, 세로, 대각선 모든 방법의 수를 더함
    for (int i = 0; i < 3; i++)
        ans += dp[i][N - 1][N - 1];

    cout << ans;
}