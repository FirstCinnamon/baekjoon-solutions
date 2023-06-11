// 11399 ATM
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // C와 C++의 입출력 버퍼를 동기화하지 않음. 입출력 속도 향상
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; // 사람 수
    cin >> N;
    vector<int> P(N); // 각 사람이 돈을 인출하는데 걸리는 시간을 저장하는 벡터

    for (int i = 0; i < N; i++) // 각 사람이 돈을 인출하는데 걸리는 시간을 입력 받음
        cin >> P[i];

    sort(P.begin(), P.end()); // 시간을 오름차순으로 정렬. 돈을 인출하는 데 걸리는 시간이 짧은 사람부터 처리

    int total = 0; // 각 사람이 돈을 인출하는데 필요한 시간의 합
    for (int i = 0; i < N; i++) { // 모든 사람에 대해
        total += P[N - 1 - i] * (i + 1); // 돈을 인출하는데 필요한 시간(기다리는 시간 + 인출하는 시간)을 누적하여 합산. 큰 시간부터 작은 시간 순으로 곱하고 더함
    }

    cout << total; // 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 출력
}
