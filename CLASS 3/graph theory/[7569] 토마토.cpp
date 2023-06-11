// 7569 토마토
#include <iostream>
#include <queue>

using namespace std;

#define MAX 101

// 토마토 상자의 정보를 저장하는 3차원 배열
int box[MAX][MAX][MAX];

// 상하좌우앞뒤를 나타내는 델타값들
const int dx[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};

// BFS를 위한 큐. 토마토의 위치 정보를 담음
queue<pair<int, pair<int, int>>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N, H; // M은 상자의 가로 크기, N은 상자의 세로 크기, H는 상자의 높이
    cin >> M >> N >> H;

    // 토마토 상자 정보 입력
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1)
                    q.push({k, {i, j}}); // 익은 토마토는 큐에 넣음
            }
        }
    }

    // BFS 시작
    while (!q.empty()) {
        int x = q.front().second.second;
        int y = q.front().second.first;
        int z = q.front().first;
        q.pop();

        // 상하좌우앞뒤 6방향 탐색
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            // 범위 내에 있고 아직 익지 않은 토마토라면
            if (nx >= 0 && ny >= 0 && nz >= 0 && nz < H && nx < M && ny < N && box[nz][ny][nx] == 0) {
                // 토마토를 익히고, 익힌 토마토의 위치를 큐에 넣음
                box[nz][ny][nx] = box[z][y][x] + 1;
                q.push({nz, {ny, nx}});
            }
        }
    }

    int result = 0;

    // 최소 일수 계산
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 아직 익지 않은 토마토가 있다면
                if (box[k][i][j] == 0) {
                    cout << -1 << '\n'; // 익지 않은 토마토가 있으므로 -1 출력
                    return 0;
                }
                if (result < box[k][i][j]) {
                    result = box[k][i][j]; // 가장 오래 걸린 토마토의 시간을 저장
                }
            }
        }
    }

    cout << result - 1 << '\n'; // 토마토는 동시에 익기 시작하므로 처음 시작일을 빼줌

    return 0;
}
