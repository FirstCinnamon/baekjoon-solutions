// 18870 좌표 압축
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;  // 좌표의 개수
    cin >> N;

    vector<pair<int, int>> X(N);  // 좌표와 그 좌표의 원래 위치를 저장할 벡터 생성

    for (int i = 0; i < N; i++) {  // 각 좌표를 입력받고, 그 좌표의 원래 위치를 기록
        cin >> X[i].first;
        X[i].second = i;
    }

    sort(X.begin(), X.end());  // 좌표를 오름차순으로 정렬

    vector<int> result(N);  // 결과를 저장할 벡터 생성

    int idx = 0;  // 좌표 압축 결과 값을 저장할 변수
    result[X[0].second] = idx;  // 첫 번째 좌표의 압축 결과는 항상 0
    for (int i = 1; i < N; i++) {  // 각 좌표에 대해
        if (X[i].first != X[i - 1].first)  // 이전 좌표와 현재 좌표가 다르면
            idx++;  // 압축 결과 값을 증가
        result[X[i].second] = idx;  // 원래 위치에 압축 결과 값을 저장
    }

    for (int i = 0; i < N; i++) {  // 결과를 출력
        cout << result[i];
        if (i != N - 1)
            cout << " ";
    }
}
