// 14938 서강그라운드
#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    // i부터 j까지의 거리를 저장하는 2차원 배열 : dist[i][j]
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    // i의 아이템의 개수를 저장하는 배열 : items[i]
    vector<int> items(n + 1);

    // 자기 자신까지의 거리는 0
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    
    // 아이템 개수 입력받음
    for (int i = 1; i <= n; i++)
        cin >> items[i];

    // 지역들간의 거리 입력받음. 양방향
    while (r--) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // 획득 가능한 총 아이템 수
    int max_items = 0;

    // 1부터 n까지의 지역을 순회
    for (int i = 1; i <= n; i++) {
        // 각 지역에서 획득가능한 총 아이템 수 계산
        int reachable_items = 0;
        for (int j = 1; j <= n; j++)
            if (dist[i][j] <= m)
                reachable_items += items[j];
        // 최댓값으로 업데이트
        max_items = max(reachable_items, max_items);
    }

    cout << max_items;
}