//1504 특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;
typedef pair<int, int> pii;

int N, E;

// Dijkstra 알고리즘 구현
vector<int> dijkstra(int start, const vector<vector<pii>> &graph) {
    vector<int> distance(N + 1, INF); // 각 정점까지의 최단 거리를 저장할 벡터
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 최소 힙
    pq.push({0, start}); // 시작 정점과 거리의 초기 값을 힙에 추가
    distance[start] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (distance[curr] < dist) continue;

        // 현재 정점의 모든 이웃에 대하여 탐색
        for (const auto &edge: graph[curr]) {
            int next = edge.first;
            int weight = edge.second;

            int new_dist = dist + weight;

            // 최단 거리가 발견된 경우, 거리 배열과 힙을 업데이트
            if (new_dist < distance[next]) {
                distance[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }

    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> E;
    vector<vector<pii>> graph(N + 1);

    // 그래프 입력
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 시작 정점에서 다른 정점까지의 최단 거리 계산
    vector<int> dist1 = dijkstra(1, graph);
    vector<int> dist_v1 = dijkstra(v1, graph);
    vector<int> dist_v2 = dijkstra(v2, graph);

    // 최단 경로가 없는 경우 출력
    if (dist1[v1] == INF || dist_v1[v2] == INF || dist_v2[N] == INF)
        cout << "-1";
    else {
        // 두 개의 정점을 거치는 최단 경로 계산
        int total_dist = min(dist1[v1] + dist_v1[v2] + dist_v2[N], dist1[v2] + dist_v2[v1] + dist_v1[N]);
        cout << total_dist;
    }
}
