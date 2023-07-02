// 14500 테트로미노
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;

    cin >> N >> M;
    vector<vector<int>> paper(N, (vector<int>(M)));

    // 종이의 각 칸에 정수 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];

    int ans = 0;

    // 모든 행과 열에 대해서 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 가능한 테트로미노들에 대한 최대 합 계산
            // 1 x 4 타일에서 가능한 테트로미노 전부 계산
            if (j + 3 < M)
                ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
            // 2 x 3 타일
            if (j + 2 < M && i + 1 < N) {
                int tri = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
                for (int k = 0; k < 3; k++)
                    ans = max(ans, tri + paper[i + 1][j + k]);
                int tri2 = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
                for (int k = 0; k < 3; k++)
                    ans = max(ans, tri2 + paper[i][j + k]);
                int center = paper[i][j + 1] + paper[i + 1][j + 1];
                ans = max(ans, center + paper[i][j] + paper[i + 1][j + 2]);
                ans = max(ans, center + paper[i + 1][j] + paper[i][j + 2]);
            }
            // 2 x 2 타일
            if (j + 1 < M && i + 1 < N)
                ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1]);
            // 3 x 2 타일
            if (j + 1 < M && i + 2 < N) {
                int tri = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];
                for (int k = 0; k < 3; k++)
                    ans = max(ans, tri + paper[i + k][j + 1]);
                int tri2 = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
                for (int k = 0; k < 3; k++)
                    ans = max(ans, tri2 + paper[i + k][j]);
                int center = paper[i + 1][j] + paper[i + 1][j + 1];
                ans = max(ans, center + paper[i][j] + paper[i + 2][j + 1]);
                ans = max(ans, center + paper[i + 2][j] + paper[i][j + 1]);
            }
            // 4 x 1 타일
            if (i + 3 < N)
                ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
        }
    }

    // 최댓값 출력
    cout << ans;
}
