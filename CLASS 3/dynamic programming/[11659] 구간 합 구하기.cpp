// 11659 구간 합 구하기
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N, M;  // N: 수의 개수, M: 합을 구해야 하는 횟수
    cin >> N >> M;  

    vector<int> vec(N + 1, 0);  // 누적 합을 저장할 벡터. 인덱스 0은 사용하지 않으므로 N+1 크기로 생성

    for (int i = 1; i <= N; i++) {  // 입력 받은 수들을 순회
        cin >> vec[i];  // 각 수를 입력 받음
        vec[i] += vec[i - 1];  // 누적 합 계산. 현재 수와 이전까지의 누적 합을 더해 다시 저장
    }

    while (M--) {  // M번의 구간에 대해 합을 구함
        int i, j;  // 구간의 시작과 끝을 의미하는 i, j
        cin >> i >> j;  // 구간의 시작과 끝 입력 받음
        cout << vec[j] - vec[i - 1] << '\n';  // j번째까지의 누적 합에서 i-1번째까지의 누적 합을 뺌. 이는 i부터 j까지의 구간 합
    }

}
