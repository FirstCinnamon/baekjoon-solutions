// 2667 단지 번호 붙이기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 단지내 집을 세는 함수
void count_complex(vector<vector<int>> &map, vector<vector<bool>> &visited, int i, int j, int &total, int N) {
    // 네 방향 (상, 우, 하, 좌)에 대한 dx, dy
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    // 맵 밖이거나, 이미 방문한 곳이거나, 집이 없는 곳이면 return
    if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || map[i][j] != 1)
        return;

    // 현재 위치 방문 처리 후 집 수 증가
    visited[i][j] = true;
    total++;

    // 네 방향으로 탐색
    for (int dir = 0; dir < 4; dir++)
        count_complex(map, visited, i + dx[dir], j + dy[dir], total, N);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 지도의 크기 입력
    int N;

    cin >> N;

    // 지도와 방문 정보를 담는 벡터 초기화
    vector<vector<int>> map(N, vector<int>(N, 0));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // 각 단지내 집의 수를 저장할 벡터
    vector<int> complex;

    // 지도 정보 입력
    for (int i = 0; i < N; i++) {
        string input = "";
        cin >> input;
        for (int j = 0; j < N; j++)
            map[i][j] = input[j] - '0';
    }


    // 전체 지도를 돌면서 방문하지 않은 집이 있으면 단지를 찾아서 단지내 집의 수를 센다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                int total_houses = 0;
                count_complex(map, visited, i, j, total_houses, N);
                complex.push_back(total_houses);
            }
        }
    }

    // 각 단지내 집의 수를 오름차순으로 정렬
    sort(complex.begin(), complex.end());

    // 총 단지수 출력
    cout << complex.size() << '\n';

    // 각 단지내 집의 수를 출력
    for (auto &c: complex)
        cout << c << '\n';

}
