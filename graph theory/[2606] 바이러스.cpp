// [2606]바이러스
#include <iostream>
#include <vector>

using namespace std;

// 이 함수는 깊이 우선 탐색(Depth First Search, DFS) 알고리즘을 사용해서
// 그래프를 탐색하고, 웜 바이러스가 퍼진 컴퓨터의 수를 계산한다.
void dfs(vector<vector<int>> &graph, vector<bool> &visited, int v, int &cnt) {
    cnt++; // 방문한 컴퓨터를 하나 증가시킨다.
    visited[v] = true; // 현재 컴퓨터를 방문했다고 표시한다.
    
    // 현재 컴퓨터와 연결된 모든 컴퓨터를 확인한다.
    for (int i = 0; i < graph[v].size(); i++) {
        // 만약 아직 방문하지 않은 컴퓨터가 있다면 그 컴퓨터를 방문한다.
        if (!visited[graph[v][i]])
            dfs(graph, visited, graph[v][i], cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T, cnt = 0;

    cin >> N; // 컴퓨터의 수를 입력받는다.
    cin >> T; // 직접 연결된 컴퓨터 쌍의 수를 입력받는다.

    vector<vector<int>> graph(N + 1); // 컴퓨터 간의 연결 정보를 저장하는 그래프를 생성한다.
    vector<bool> visited(N + 1, false); // 컴퓨터의 방문 정보를 저장하는 벡터를 생성한다.

    // 직접 연결된 컴퓨터 쌍의 정보를 입력받는다.
    while (T--) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end); // 각 컴퓨터간의 연결 정보를 그래프에 추가한다.
        graph[end].push_back(start); // 양방향이므로 반대 방향도 추가한다.
    }

    dfs(graph, visited, 1, cnt); // 1번 컴퓨터에서 시작하는 DFS를 실행한다.

    cout << cnt - 1; // 1번 컴퓨터를 제외한 웜 바이러스에 걸린 컴퓨터의 수를 출력한다.
}
