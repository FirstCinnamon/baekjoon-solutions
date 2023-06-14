// 11724 연결 요소의 개수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // 변수 선언
    int N, M, count = 0;
    cin >> N >> M;

    // 방문 여부를 저장할 벡터와 그래프를 나타낼 이중 벡터 초기화
    vector<bool> visited(N + 1, false);
    vector<vector<int>> graph(N + 1);
    queue<int> q;

    // 간선 정보 입력받아 그래프 생성
    while (M--) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    // 각 정점에 대해 BFS 탐색 수행
    for (int i = 1; i <= N; i++) {
        // 아직 방문하지 않은 정점에 대해
        if (!visited[i]) {
            // 연결 요소 개수 증가
            count++;
            // BFS 시작
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                // 큐의 맨 앞 요소를 꺼내고
                int front = q.front();
                q.pop();
                // 해당 정점과 연결된 모든 정점을 탐색
                for (int &j: graph[front]) {
                    // 아직 방문하지 않은 정점을 방문
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
        }
    }

    // 연결 요소 개수 출력
    cout << count;
}
