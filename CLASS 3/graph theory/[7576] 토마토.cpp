// 7576 토마토
#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

// 방향 이동을 위한 델타값들
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// 토마토 상자 정보를 저장하는 배열
int box[MAX][MAX];
// BFS를 위한 큐. 익은 토마토의 위치 정보를 담음
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    // 토마토 상자 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
            // 익은 토마토가 있다면 큐에 넣음
            if (box[i][j] == 1)
                q.push({i, j});
        }
    }
    
    // 모든 토마토가 익어있는 상태인 경우
    if (q.size() == M * N) {
        cout << "0";
        return 0;
    }

    // BFS 실행
    while (!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        // 상하좌우 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 내에 있고 아직 익지 않은 토마토라면
            if (nx >= 0 && ny >= 0 && nx < M && ny < N && box[ny][nx] == 0) {
                // 토마토를 익히고, 익힌 토마토의 위치를 큐에 넣음
                box[ny][nx] = box[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    int result = 0;

    // 최소 일수 계산
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 아직 익지 않은 토마토가 있다면
            if (box[i][j] == 0) {
                cout << "-1"; // 모든 토마토가 익지 못하는 경우 -1 출력
                return 0;
            }
            // 가장 많이 걸린 일수를 저장
            result = max(result, box[i][j]);
        }
    }
    // 토마토는 동시에 익기 시작하므로 최초 1일을 빼준다
    cout << result - 1;
}
