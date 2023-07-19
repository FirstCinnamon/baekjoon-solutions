// 1865 웜홀
#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

// u, v, t를 멤버로 갖는 Edge 구조체 선언
struct Edge {
    int u;
    int v;
    int t;
};

// 벨만-포드 알고리즘을 위한 함수
bool bellman_ford(int N, vector<Edge> &edges) {
    vector<int> distance(N + 1, INF); // N개의 지점 거리를 저장하는 벡터 초기화
    distance[1] = 0; // 시작 지점의 거리를 0으로 설정

    // 각 지점까지의 거리를 최신화하는 과정
    for (int i = 1; i <= N; i++) {
        for (auto edge: edges) {
            if (distance[edge.v] > distance[edge.u] + edge.t) {
                distance[edge.v] = distance[edge.u] + edge.t;
            }
        }
    }

    // 간선을 다시 순회하면서 음의 순환이 발생하는지 확인
    for (auto edge: edges) {
        if (distance[edge.v] > distance[edge.u] + edge.t)
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC; // 테스트 케이스의 개수 선언
    cin >> TC;

    // 각 테스트 케이스에 대해 진행
    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<Edge> edges; // 도로와 웜홀 정보를 저장하는 벡터 선언

        // 도로의 정보 입력
        while (M--) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        // 웜홀의 정보 입력
        while (W--) {
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T}); // 줄어드는 시간을 음수로 저장
        }

        // 벨만-포드 알고리즘을 사용하여 음의 순환이 존재하는지 확인
        bool negative_cycle_exists;
        negative_cycle_exists = bellman_ford(N, edges);

        // 결과 출력
        if (negative_cycle_exists)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
