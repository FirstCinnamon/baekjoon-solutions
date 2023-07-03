// 10026 적록색약
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상, 하, 좌, 우 이동을 위한 dx, dy
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// BFS 함수, 주어진 시작점에서 BFS를 통해 구역을 찾음
void BFS(int N, int i, int j, vector<vector<bool>> &visited, vector<vector<char>> const &grid, char c, bool color_weakness) {
    // 시작점이 아직 방문하지 않았다면
    if (!visited[i][j]) {
        // 방문 표시
        visited[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        // BFS 시작
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            visited[y][x] = true;
            q.pop();

            // 상, 하, 좌, 우 탐색
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                // 이동 가능한 위치면서 아직 방문하지 않았다면
                if (0 <= ny && ny < N && 0 <= nx && nx < N && !visited[ny][nx]) {
                    char g = grid[ny][nx];
                    // 색상이 같거나, 적록색약인 경우이면서 현재 색상이 빨강이고 이동할 위치의 색상이 초록색이거나 그 반대 경우
                    if (c == g || (color_weakness && ((c == 'G' && g == 'R') || (c == 'R' && g == 'G')))) {
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, cnt = 0, cnt2 = 0;
    cin >> N;
    // 그리드와 방문 여부를 저장하기 위한 2차원 벡터
    vector<vector<char>> grid(N, vector<char>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<bool>> visited2(N, vector<bool>(N, false));

    // 그리드 정보 입력
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
            grid[i][j] = s[j];
    }

    // 모든 그리드에 대해 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 적록색약이 아닌 사람의 경우
            if (!visited[i][j]) {
                BFS(N, i, j, visited, grid, grid[i][j], false);
                cnt++;
            }
            // 적록색약인 사람의 경우
            if (!visited2[i][j]) {
                BFS(N, i, j, visited2, grid, grid[i][j], true);
                cnt2++;
            }
        }
    }

    // 각각의 경우에 대한 구역의 수를 출력
    cout << cnt << " " << cnt2 << '\n';
}
