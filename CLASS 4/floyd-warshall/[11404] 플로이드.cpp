// 11404 플로이드
#include <iostream>
#include <vector>

#define INF 1e9  // 무한대를 의미하는 값으로 1e9를 사용

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;  // n은 도시의 개수, m은 버스의 개수
    cin >> n >> m;

    // dp 배열을 초기화. 처음에는 모든 경로의 비용을 무한대로 설정
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로의 경로 비용은 0
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // 버스 정보를 입력받음. 도시 a에서 도시 b로 가는 비용 c
    // 만약 이미 입력된 경로 비용보다 새롭게 입력된 경로의 비용이 더 작다면 갱신
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    // 플로이드-워셜 알고리즘 실행
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    // 최종 결과 출력. 만약 경로가 존재하지 않는다면(비용이 무한대라면) 0을 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] != INF)
                cout << dp[i][j];
            else
                cout << '0';
            cout << ' ';
        }
        cout << '\n';
    }
}
