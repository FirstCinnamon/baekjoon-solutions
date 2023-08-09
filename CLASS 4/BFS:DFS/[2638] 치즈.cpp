// 2638 치즈
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int dx[4] = {1, -1, 0, 0}; // 상하좌우 이동을 위한 배열
const int dy[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, cnt = 0; // N과 M은 모눈종이 크기, cnt는 시간 카운트
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    // 입력 받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    bool board_is_clear = false; // 치즈가 모두 녹았는지 체크하는 플래그

    while (!board_is_clear) {
        cnt++; // 시간 증가
        queue<pii> q;
        vector<vector<int>> melt(N, vector<int>(M, 0)); // 녹을 치즈 체크
        vector<vector<bool>> visited(N, vector<bool>(M, false)); // 방문 체크
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            visited[x][y] = true;
            q.pop();

            // 4방향 탐색
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (0 <= nx && nx < N && 0 <= ny && ny < M && !visited[nx][ny]) {
                    if (board[nx][ny] == 0) { // 빈 칸이면 큐에 삽입
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    } else // 치즈와 접촉한 경우 melt 값 증가
                        melt[nx][ny]++;
                }
            }
        }

        board_is_clear = true;
        
        // 치즈 녹이기
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                if (melt[i][j] >= 2)
                    board[i][j] = 0; // 2변 이상 접촉한 치즈 녹이기
                else if (board[i][j] == 1)
                    board_is_clear = false; // 아직 녹지 않은 치즈가 있다면 플래그 설정
            }
    }

    cout << cnt; // 치즈가 모두 녹는 시간 출력
}
