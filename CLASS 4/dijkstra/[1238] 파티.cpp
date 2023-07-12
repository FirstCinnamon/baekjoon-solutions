// 1238 파티
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;
typedef pair<int, int> pii;

// 다익스트라 알고리즘 구현 함수
vector<int> dijkstra(int start, const vector<vector<pii>> &graph, const int N) {
    vector<int> distance(N + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (distance[curr] < dist)
            continue;

        for (const auto &edge: graph[curr]) {
            int next = edge.first;
            int weight = edge.second;
            int next_dist = dist + weight;

            if (next_dist < distance[next]) {
                distance[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, X;
    // 마을 수, 도로 수, 파티 장소의 마을 번호 입력 받기
    cin >> N >> M >> X;

    vector<vector<pii>> graph(N + 1);

    // 도로 정보 입력 받기
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<int> answer;

    // 각 학생에 대해 X 마을까지의 왕복 시간 구하기
    for (int i = 1; i <= N; i++) {
        if (i == X)
            continue;
        int forward_time = dijkstra(i, graph, N)[X];
        int backward_time = dijkstra(X, graph, N)[i];
        answer.push_back(forward_time + backward_time);
    }

    // 오고 가는 데 가장 오래 걸리는 소요시간 출력
    cout << *max_element(answer.begin(), answer.end()) << endl;

}
