// 16236 아기 상어
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9; // 무한대 값 저장
pii baby_shark; // 아기 상어의 위치를 저장
int N;

// 상하좌우 이동을 위한 상수 배열
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int swim(const int size, int &stack, vector<vector<int>> &map) {
    // BFS 를 위한 준비
    queue<pii> q;
    q.push(baby_shark);

    vector<vector<int>> visited(N, vector<int>(N, INF));    // 걸린 시간을 저장하는 배열
    visited[baby_shark.first][baby_shark.second] = 0;   // 아기 상어의 위치까지 걸린 시간은 0

    int min_time = INF; // 먹잇감까지 걸린 최소 시간을 저장하는 변수

    // BFS로 먹이를 탐색
    while (!q.empty()) {
        // 큐의 현재 위치와 시간을 불러옴
        int x = q.front().first;
        int y = q.front().second;
        int time = visited[x][y];
        q.pop();

        // 먹을 수 있는 먹이인지 확인하고 맞다면 먹이의 위치를 저장 (걸린 시간이 동일하다면 위쪽, 왼쪽을 선호)
        if (map[x][y] != 0 && map[x][y] < size) {
            bool baby_shark_eats = false;
            if (time < min_time) {
                baby_shark_eats = true;
            } else if (time == min_time) {
                if (x < baby_shark.first)
                    baby_shark_eats = true;
                else if (baby_shark.first == x && y < baby_shark.second)
                    baby_shark_eats = true;
            }
            if (baby_shark_eats) {
                baby_shark = {x, y};
                min_time = time;
            }
        }

        // 상하좌우로 이동하며 탐색
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 범위 안에 있고 미방문한 곳이며 비어있거나 아기 상어의 크기보다 작은 물고기가 있다면
            if (0 <= nx && nx < N && 0 <= ny && ny < N && visited[nx][ny] == INF && map[nx][ny] <= size) {
                q.push({nx, ny});
                visited[nx][ny] = min(visited[nx][ny], time + 1);
            }
        }
    }
    // 스택을 1 증가
    stack++;
    // 아기 상어의 위치를 빈 곳으로 설정
    map[baby_shark.first][baby_shark.second] = 0;
    // 현재 위치까지 오는데 걸린 시간을 리턴 (만약 먹이가 없다면 0을 리턴)
    return visited[baby_shark.first][baby_shark.second];
}

int calculate_time(vector<vector<int>> &map) {
    int time = 0;   // 걸린 총 시간
    int size = 2;   // 아기상어의 크기
    int stack = 0;  // 아기상어가 먹은 먹이의 수
    int time_searched = 0;  // 한 번의 탐색에 걸린 시간

    do {
        time_searched = swim(size, stack, map); // 먹이 탐색에 걸린 시간을 저장
        if (time_searched)  // 0이 아니면 
            time += time_searched;  // 총 시간에 더해줌
        if (stack == size) {    // 아기상어가 본인 크기만큼 먹었다면
            stack = 0;  // 스택 초기화
            size++; // 아기 상어의 크기 증가
        }
    } while (time_searched);    // 아기 상어에게 먹이가 있는 동안

    return time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    vector<vector<int>> map(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                // 아기 상어의 위치를 저장하고 그 위치를 0으로 설정
                baby_shark = {i, j};
                map[i][j] = 0;
            }
        }
    
    cout << calculate_time(map);
}