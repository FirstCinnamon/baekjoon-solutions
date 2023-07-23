// [2206] 벽 부수고 이동하기
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using tiii = tuple<int, int, int>; // x, y 좌표와 벽을 부쉈는지 여부를 저장하는 튜플 정의

// 상하좌우로 움직이는 것을 표현한 상수 배열
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, M; // 행렬의 크기를 저장하는 변수
char map[1000][1000]; // 맵을 저장하는 변수
int dist[1000][1000][2]; // 해당 위치까지의 거리와 벽을 부쉈는지 여부를 저장하는 변수

int bfs() { // 너비 우선 탐색 함수
    queue<tiii> q;
    q.push(make_tuple(0, 0, 0)); // 시작점을 큐에 추가
    dist[0][0][0] = 1; // 시작점의 거리를 1로 설정

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front(); // 큐의 맨 앞에 있는 원소를 가져와서 x, y, z에 저장
        q.pop(); // 처리한 원소를 큐에서 제거

        // 도착점에 도달한 경우
        if (x == N - 1 && y == M - 1)
            return dist[x][y][z]; // 최단 거리 반환
            // BFS이므로 가장 먼저 도착한 상황이 항상 최단 거리가 된다.

        // 상하좌우로 이동
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 맵의 범위를 벗어나면 무시
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            // 벽이 있고, 벽을 아직 부수지 않았다면
            if (map[nx][ny] == '1' && z == 0) {
                dist[nx][ny][1] = dist[x][y][z] + 1; // 거리를 1 증가시키고, 벽을 부쉈다는 것을 표시
                q.push(make_tuple(nx, ny, 1)); // 큐에 추가
            }

            // 빈 공간이고, 아직 방문하지 않았다면
            if (map[nx][ny] == '0' && dist[nx][ny][z] == 0) {
                dist[nx][ny][z] = dist[x][y][z] + 1; // 거리를 1 증가시키고
                q.push(make_tuple(nx, ny, z)); // 큐에 추가
            }
        }
    }
    return -1; // 도착점에 도달할 수 없는 경우 -1 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    // 맵 정보 입력 받기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    cout << bfs(); // bfs 수행 후 결과 출력
}
