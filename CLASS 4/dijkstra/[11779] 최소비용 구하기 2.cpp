// 11779 최소비용 구하기 2
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define INF 1e9

using namespace std;
using pii = pair<int, int>;

// priority_queue<pii> 에서 pii의 second 값이 작은 순으로 정렬하기 위한 비교 함수
struct compare {
    bool operator()(pii a, pii b) {
        return a.second > b.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, start, end;
    cin >> n >> m;

    // 인접행렬 그래프 생성
    vector<vector<pii>> graph (n+1);

    // 엣지 정보 입력
    while(m--) {
        int u, v, w;    // u에서 v까지 가중치 w
        cin >> u >> v >> w;

        bool updated = false;   // 이미 존재하는 엣지인지 확인하는 플래그
        for (auto & edge : graph[u]) {
            if (edge.first == v) {  // 이미 존재하는 엣지라면 플래그를 세우고 값을 최솟값으로 업데이트
                updated = true;
                edge.second = min(edge.second, w);
                break;
            }
        }

        if (!updated)   // 업데이트하지 않았다면 추가
            graph[u].push_back({v, w});
    }

    cin >> start >> end;    // 시작과 끝점 입력받음


    // 다익스트라 초기설정
    vector<int> dist (n+1, INF);    // 최소 거리를 저장하는 벡터
    vector<int> prev_node (n + 1);      // 이전 방문 노드를 저장하는 벡터
    priority_queue<pii, vector<pii>, compare> pq;   // second 값을 기준으로 최소 힙을 생성하는 우선순위 큐

    pq.push({start, 0});    // 시작 노드와 거리를 큐에 추가
    dist[start] = 0;    // 시작 노드의 거리를 0으로 설정

    // 다익스트라 알고리즘
    while(!pq.empty()) {
        int curr = pq.top().first;  // 현재 노드
        int weight = pq.top().second;   // 현재 노드까지의 거리
        pq.pop();

        if (dist[curr] < weight)    // 현재 노드까지의 거리보다 더 짧게 도달하는 경로가 있었다면 스킵
            continue;

        // 인접 노드에 대한 간선들 업데이트
        for (const auto & edge : graph[curr]) {
            int next = edge.first;  // 다음 노드
            int next_weight = weight + edge.second; // 다음 노드까지의 거리

            // 더 짧은 경로를 찾았다면 업데이트
            if(next_weight < dist[next]) {
                dist[next] = next_weight;
                prev_node[next] = curr;     // 이전 정점 정보 저장
                pq.push({next, next_weight});
            }
        }
    }

    // 최소 거리 출력
    cout << dist[end] << '\n';

    // 최단 경로 추적 (역순으로 체크하기 때문에 스택 사용)
    stack<int> path;
    for (int i=end; i != start; i = prev_node[i])
        path.push(i);
    path.push(start);   // 경로에는 시작 정점도 포함되어야 하므로 추가해줌

    // 최단 경로에서 거쳐간 정점 수 출력
    cout << path.size() << '\n';
    
    // 전체 경로 출력
    while(!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }
}