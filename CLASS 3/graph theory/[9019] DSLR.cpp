// 9019 DSLR
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 전역 변수로 시작점 A와 목표점 B를 선언
int A, B;

// 방문 여부 및 해당 위치까지 도달하는데 필요한 명령어를 저장하는 벡터 선언
vector<string> visited(10000);

// BFS를 이용한 탐색
void bfs(int start) {
    // 탐색할 노드와 그 위치까지 오는데 필요한 명령어를 저장하는 큐 선언
    queue<pair<int, string>> q;
    q.push({start, ""}); // 초기 시작점과 빈 문자열(명령어 없음)을 큐에 넣음
    visited[start] = "start"; // 시작점 방문 표시 (재방문하지 않도록)

    // 큐가 빌 때까지 반복
    while (!q.empty()) {
        int num = q.front().first; // 현재 위치
        string str = q.front().second; // 현재까지의 명령어
        q.pop(); // 큐에서 제거

        // 현재 위치가 목표점이면 명령어를 출력하고 함수 종료
        if (B == num) {
            cout << str << '\n';
            return;
        }

        // 각 명령어에 대응하는 다음 위치 계산
        int D = (num * 2) % 10000;
        int S = (num == 0) ? 9999 : num - 1;
        int L = (num % 1000) * 10 + (num / 1000);
        int R = (num % 10) * 1000 + (num / 10);

        // 각 위치에 대해 방문하지 않았으면 방문 표시 후 큐에 추가
        // empty()가 문자열 비교보다 속도가 빠르기에 사용
        if (visited[D].empty()) {
            visited[D] = str + "D";
            q.push({D, visited[D]});
        }
        if (visited[S].empty()) {
            visited[S] = str + "S";
            q.push({S, visited[S]});
        }
        if (visited[L].empty()) {
            visited[L] = str + "L";
            q.push({L, visited[L]});
        }
        if (visited[R].empty()) {
            visited[R] = str + "R";
            q.push({R, visited[R]});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; // 테스트 케이스 개수
    cin >> T;

    // 각 테스트 케이스에 대해 처리
    while (T--) {
        cin >> A >> B; // 시작점과 목표점 입력
        fill(visited.begin(), visited.end(), ""); // 방문 배열 초기화
        bfs(A); // BFS로 탐색 시작
    }
}
