// 21736 헌내기는 친구가 필요해
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    // 상하좌우 이동 시의 x, y 좌표 변화
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int N, M;
    // 캠퍼스의 크기 입력 받기
    cin >> N >> M;

    // 캠퍼스 지도를 저장할 2차원 벡터 map 생성
    vector<vector<char>> map(N, vector<char>(M));
    // 방문 여부를 저장할 2차원 벡터 visited 생성
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    // 도연이(I)의 위치를 저장할 변수 start 선언
    pair<int, int> start;

    // 캠퍼스 지도 정보 입력
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++) {
            map[i][j] = input[j];
            // 도연이의 위치 찾기
            if (input[j] == 'I')
                start = {i, j};
        }
    }

    // BFS를 위한 큐 생성
    queue<pair<int, int>> q;
    // 만난 사람 수를 저장할 변수 cnt 초기화
    int cnt = 0;
    // 시작점을 큐에 삽입
    q.push(start);

    // 큐가 빌 때까지 BFS 수행
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        // 만난 사람 확인
        if (map[y][x] == 'P')
            cnt++;
        // 현재 위치를 큐에서 제거
        q.pop();

        // 인접한 상하좌우 위치 탐색
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            // 캠퍼스 내의 위치인지 확인
            if (0 <= ny && ny < N && 0 <= nx && nx < M) {
                // 아직 방문하지 않았고, 벽이 아닌 경우
                if (!visited[ny][nx] && map[ny][nx] != 'X') {
                    // 해당 위치를 큐에 삽입 및 방문 처리
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }
            }
        }
    }

    // 결과 출력 (만난 사람 수가 0이면 TT 출력)
    if (cnt)
        cout << cnt;
    else
        cout << "TT";
}
