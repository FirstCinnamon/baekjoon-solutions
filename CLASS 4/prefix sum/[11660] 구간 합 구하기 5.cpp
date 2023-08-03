// 11660 구간 합 구하기 5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;  // 표의 크기 N과 합을 구해야 하는 횟수 M

    // 표와 부분합을 저장할 2차원 벡터를 선언 (표의 크기가 N이므로 N+1로 벡터를 선언)
    vector<vector<int>> table(N + 1, vector<int>(N + 1));
    vector<vector<int>> sum(N + 1, vector<int>(N + 1));

    // 표에 대한 데이터를 입력받음
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> table[i][j];

    // 각 위치까지의 부분합을 계산하고 sum 벡터에 저장
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            sum[i][j] = table[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

    // 각 쿼리에 대해 구간합을 계산하고 출력
    while (M--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;  // 구간의 시작 좌표와 끝 좌표
        // 해당 구간의 합을 구해서 출력
        // 전체 영역에서 왼쪽과 위쪽 영역을 빼고, 중복으로 빠진 왼쪽 위 영역을 다시 더함
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }
}
