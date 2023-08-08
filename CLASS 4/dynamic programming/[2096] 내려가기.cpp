// 2096 내려가기
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N; // 줄의 수
    cin >> N;

    int dp_max[3] = {0}; // 최대 점수를 저장할 배열
    int dp_min[3] = {0}; // 최소 점수를 저장할 배열
    int max_prev[3], min_prev[3]; // 이전 단계의 점수를 저장할 배열

    for (int i = 0; i < N; i++) {
        int a, b, c; // 현재 줄의 세 숫자
        cin >> a >> b >> c;

        // 이전 단계의 점수를 복사
        for (int j = 0; j < 3; j++) {
            max_prev[j] = dp_max[j];
            min_prev[j] = dp_min[j];
        }

        // 현재 줄에서 얻을 수 있는 최대 점수 계산
        dp_max[0] = max(max_prev[0], max_prev[1]) + a;
        dp_max[1] = max(max(max_prev[0], max_prev[1]), max_prev[2]) + b;
        dp_max[2] = max(max_prev[1], max_prev[2]) + c;

        // 현재 줄에서 얻을 수 있는 최소 점수 계산
        dp_min[0] = min(min_prev[0], min_prev[1]) + a;
        dp_min[1] = min(min(min_prev[0], min_prev[1]), min_prev[2]) + b;
        dp_min[2] = min(min_prev[1], min_prev[2]) + c;
    }

    // 전체 최대, 최소 점수 계산
    int ans_max = max(dp_max[0], max(dp_max[1], dp_max[2]));
    int ans_min = min(dp_min[0], min(dp_min[1], dp_min[2]));

    cout << ans_max << ' ' << ans_min << '\n'; // 결과 출력
}
