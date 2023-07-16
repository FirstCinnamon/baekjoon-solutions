// 1067 트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS 함수 정의
void dfs(const int V, int v, const vector<vector<pair<int, int>>> &adj, vector<int> &depth, vector<bool> &visited) {
    visited[v] = true;
    // 인접한 노드들에 대해
    for (const auto &edge: adj[v]) {
        int next = edge.first;
        int weight = edge.second;
        // 방문하지 않은 경우
        if (!visited[next]) {
            depth[next] = max(depth[next], depth[v] + weight);
            dfs(V, next, adj, depth, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V;
    // 노드의 개수 입력 받기
    cin >> V;
    vector<vector<pair<int, int>>> adj(V + 1);
    vector<int> depth(V + 1, 0);
    vector<bool> visited(V + 1, false);

    // 간선 정보 입력 받기
    for (int i = 0; < V; i++) {
        int v, end = 0, weight = 0;
        cin >> v;
        while (end != -1) {
            cin >> end;
            if (end != -1) {
                cin >> weight;
                adj[v].push_back({end, weight});
            }
        }
    }

    // 첫 번째 DFS 실행
    dfs(V, 1, adj, depth, visited);
    // 임의의 노드(1)에서 가장 먼 노드를 구하기
    int max_index = max_element(depth.begin(), depth.end()) - depth.begin();

    // 배열 초기화
    fill(visited.begin(), visited.end(), false);
    fill(depth.begin(), depth.end(), 0);

    // 가장 먼 노드에서 두 번째 DFS 실행
    dfs(V, max_index, adj, depth, visited);
    
    // 결과 출력 : 두 번째 DFS에서 구한 depth의 최댓값이 트리의 지름
    // 추가 설명 : 임의의 노드에서 가장 먼 노드를 구한다. 그 노드에서 가장 먼 노드를 구한다. 그 사이의 거리가 트리의 지름이다.
    cout << *max_element(depth.begin(), depth.end());
}
