// 12865 평범한 배낭
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1);
    vector<int> V(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];

    vector<vector<int>> dp(N + 1,vector<int>(K + 1));      // N행 K열을 갖는 dp 행렬 생성. dp[i][j] 는 i번째 물건까지 넣었을 때 무게가 j인 배낭의 최대 가치.

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++) {
            if (W[i] <= j)      // i번째 물건이 j보다 무게가 작아서 배낭에 들어갈 수 있으면
                dp[i][j] = max(V[i] + dp[i - 1][j - W[i]], dp[i - 1][j]);       // 최대 가치는 배낭에 i번째 물건을 넣거나 안넣거나 중 큰 값
            else    // i번째 물건이 j보다 무게가 커서 배낭에 들어갈 수 없으면
                dp[i][j] = dp[i - 1][j];    // 최대 가치는 i를 넣지 않은 dp[i-1][j]와 동일
        }

    cout << dp[N][K];
}