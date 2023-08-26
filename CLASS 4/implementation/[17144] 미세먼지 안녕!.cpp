// 17144 미세먼지 안녕!
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;
// 상하좌우 이동
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int R, C, T;
    cin >> R >> C >> T;
    
    // 방의 상태
    vector<vector<int>> map(R, vector<int>(C));
    // 공기 청정기의 위치
    vector<int> air_cleaner_axis;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            // 공기청정기의 위치에 INF를 넣고 x 좌표를 저장
            if (map[i][j] == -1) {
                map[i][j] = INF;
                air_cleaner_axis.push_back(i);
            }
        }

    while (T--) {
        // 확산
        vector<vector<int>> map2(R, vector<int>(C));    // 확산된 상태를 저장하기 위한 map2 
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // 공기청정기 부분은 그대로 옮기고 건너뛴다
                if (map[i][j] == INF) {
                    map2[i][j] = INF;
                    continue;
                }

                int spreads = map[i][j] / 5;    // 확산되는 양
                int cnt = 0;    // 확산된 수치
                // 각 칸마다 상하좌우로 확산이 가능한지 확인 후 확산 진행
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    // 확산 가능하면 cnt 증가시키고 확산시킴
                    if (0 <= nx && nx < R && 0 <= ny && ny < C && map[nx][ny] != INF) {
                        cnt++;
                        map2[nx][ny] += spreads;
                    }
                }
                // 확산된만큼 뺀 뒤 map2에 적용
                map2[i][j] += map[i][j] - spreads * cnt;
            }
        }

        // 순환 : 공기의 순환 역방향으로 따라가며 한칸씩 옮긴다
        // 위쪽 순환
        int X1 = air_cleaner_axis[0];

        for (int i = X1 - 1; i > 0; i--)
            map2[i][0] = map2[i - 1][0];
        for (int j = 1; j < C; j++)
            map2[0][j - 1] = map2[0][j];
        for (int i = 1; i <= X1; i++)
            map2[i - 1][C - 1] = map2[i][C - 1];
        for (int j = C-1; j>=2; j--)
            map2[X1][j] = map2[X1][j-1];

        map2[X1][1] = 0;    // 공기청정기에서 나오는 부분

        // 아래쪽 순환
        int X2 = air_cleaner_axis[1];

        for (int i = X2 + 1; i < R - 1; i++)
            map2[i][0] = map2[i + 1][0];
        for (int j = 0; j < C - 1; j++)
            map2[R-1][j] = map2[R-1][j+1];
        for (int i = R - 1; i > X2; i--)
            map2[i][C-1] = map2[i-1][C-1];
        for (int j = C - 1; j > 1; j--)
            map2[X2][j] = map2[X2][j-1];

        map2[X2][1] = 0;    // 공기청정기에서 나오는 부분

        map = map2;
    }

    int sum = 0;
    
    // 모든 미세먼지의 합을 계산
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (map[i][j] != INF)
                sum += map[i][j];
    
    cout << sum << '\n';
}