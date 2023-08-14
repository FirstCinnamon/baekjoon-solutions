// 14502 연구소
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

// 상하좌우 이동을 위한 상수 배열
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M;
int max_safe_zone = 0;  // 최대 안전 영역 넓이

void simulate(int wall_num, vector<vector<int>> map) {
    
    if (wall_num == 3) {    // 베이스 케이스 : 벽을 3개 전부 세웠을 때
        // BFS를 위한 큐
        queue<pii> q;
        // 바이러스가 있는 위치를 전부 큐에 넣음
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] == 2)
                    q.push({i, j});

        // BFS 시작
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // 상하좌우 네 방향에 대해 이동
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // 위치가 맵 안에 존재하고 그 위치가 빈 칸이면 바이러스에 감염되고 그 부분부터 다시 퍼져나갈 수 있도록 큐에 넣음
                if (0 <= nx && nx < N && 0 <= ny && ny < M && map[nx][ny] == 0) {
                    map[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }

        // 안전 영역의 넓이
        int safe_zone = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (map[i][j] == 0)     // 빈 칸이면 안전 영역 넓이 +1
                    safe_zone++;

        // 최대 안전 영역 넓이와 비교하여 큰 값으로 업데이트
        max_safe_zone = max(max_safe_zone, safe_zone);

    // 리커시브 케이스 : 벽을 3개 미만 세웠음
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) {   // 빈 공간 한 곳에 벽을 추가하고 재귀. 재귀 종료 후에는 벽을 다시 복귀시킴
                    map[i][j] = 1;
                    simulate(wall_num + 1, map);
                    map[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    simulate(0, map);

    cout << max_safe_zone;
}