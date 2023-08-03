// 1967 트리의 지름
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

int n; // 노드의 개수

// DFS로 노드들까지의 거리를 찾는 함수
void dfs(const vector<vector<pii>> &tree, vector<int> &dist, int v) {
    // 모든 인접 노드에 대해
    for (int i = 0; i < tree[v].size(); i++) {
        int node = tree[v][i].first; // 인접 노드
        int cost = tree[v][i].second; // 인접 노드까지의 거리
        if (dist[node] == -1) { // 아직 방문하지 않은 노드라면
            dist[node] = dist[v] + cost; // 거리를 갱신하고
            dfs(tree, dist, node); // DFS 수행
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n; // 노드의 개수 입력 받음

    vector<vector<pii>> tree(n + 1); // 트리를 인접 리스트로 표현
    vector<int> dist(n + 1, -1); // 각 노드까지의 거리를 저장하는 배열

    // 트리의 간선 정보 입력 받음
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    dist[1] = 0; // 시작 노드의 거리는 0
    dfs(tree, dist, 1); // 시작 노드에서 노드들까지의 거리를 찾음
    auto max_it = max_element(dist.begin(), dist.end()); // 가장 먼 노드의 거리를 찾음
    int max = distance(dist.begin(), max_it); // 가장 먼 노드의 번호를 찾음

    fill_n(dist.begin(), dist.size(), -1); // 거리 배열 초기화
    dist[max] = 0; // 가장 먼 노드를 시작으로 다시 dfs를 수행하기 위해 그 노드의 거리를 0으로 설정
    dfs(tree, dist, max); // 가장 먼 노드에서 가장 먼 노드를 찾음

    max_it = max_element(dist.begin(), dist.end()); // 가장 먼 노드의 거리를 찾음
    cout << *max_it; // 트리의 지름 출력
}
