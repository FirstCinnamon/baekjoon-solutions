// 14940 쉬운 최단거리
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int dx[4] = {1, -1, 0, 0}; // x축 이동 방향
    const int dy[4] = {0, 0, 1, -1}; // y축 이동 방향

    int n, m; // 지도 크기
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0)); // 지도 저장
    queue<pair<int, int>> q; // BFS를 위한 큐

    // 지도 정보 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            // 목표지점 큐에 추가
            if (map[i][j] == 2) {
                q.push({i, j});
            }
        }

    // BFS 실행
    while (!q.empty()) {
        int x = q.front().second; // 현재 위치 x
        int y = q.front().first; // 현재 위치 y
        q.pop();

        // 인접 지점 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; // 이동할 위치 x
            int ny = y + dy[i]; // 이동할 위치 y

            // 이동 가능하고 방문하지 않은 위치라면
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && map[ny][nx] == 1) {
                map[ny][nx] += map[y][x]; // 이동한 거리 저장
                q.push({ny, nx}); // 큐에 추가
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 지나갈 수 없는 위치
            if (map[i][j] == 0) cout << "0";
            // 지나갈 수 있는 위치
            else cout << map[i][j] - 2; 
            // 마지막 요소가 아니라면 공백 출력
            cout << (j != m - 1 ? " " : "\n");
        }
    }

}
