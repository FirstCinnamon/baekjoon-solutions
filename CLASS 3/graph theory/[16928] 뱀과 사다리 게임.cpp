// 16928 뱀과 사다리 게임
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    bool board[101][101] = {{false}};
    bool visited[101] = {false};
    int teleport[101] = {0};

    // 인접 행렬 생성(주사위로 갈 수 있는 칸들 표시)
    for (int i = 1; i <= 100; i++) {
        if (i + 1 <= 100) board[i][i + 1] = true;
        if (i + 2 <= 100) board[i][i + 2] = true;
        if (i + 3 <= 100) board[i][i + 3] = true;
        if (i + 4 <= 100) board[i][i + 4] = true;
        if (i + 5 <= 100) board[i][i + 5] = true;
        if (i + 6 <= 100) board[i][i + 6] = true;
    }

    // 사다리와 뱀의 개수 입력 받기
    cin >> N >> M;

    // 사다리 정보 입력
    while (N--) {
        int start, end;
        cin >> start >> end;
        // 시작 칸에서 도착 칸으로 이동할 수 있는 정보를 teleport에 저장
        teleport[start] = end;
    }
    // 뱀 정보 입력
    while (M--) {
        int start, end;
        cin >> start >> end;
        // 시작 칸에서 도착 칸으로 이동할 수 있는 정보를 teleport에 저장
        teleport[start] = end;
    }

    // 큐를 이용해 각 위치를 탐색
    // first : 현재 위치(node), second : 주사위 굴린 횟수(count)
    queue<pair<int, int>> q;

    // 1번 칸부터 시작
    q.push({1, 0});

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        // 현재 위치를 방문 처리
        visited[front] = true;
        // 현재 위치에 사다리나 뱀이 있다면 이동
        if (teleport[front] != 0) {
            front = teleport[front];
            // 이동한 위치도 방문 처리
            visited[front] = true;
        }
        // 현재 위치를 큐에서 제거
        q.pop();

        // 인접 행렬을 통해 이동 가능한 칸들을 탐색
        for (int i = 1; i <= 100; i++) {
            // 아직 방문하지 않았고, 현재 위치에서 갈 수 있는 칸이면
            if (!visited[i] && board[front][i]) {
                // 해당 칸과 주사위 굴린 횟수를 큐에 추가
                q.push({i, count + 1});
                // 목표인 100번 칸에 도착했다면 결과 출력 후 프로그램 종료
                if (i == 100) {
                    cout << count + 1;
                    return 0;
                }
            }
        }
    }
}
