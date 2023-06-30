// 9461 파도반 수열
#include <iostream>

using namespace std;

// 수열 값을 저장하기 위한 배열, 이를 통해 중복된 계산을 방지함.
unsigned long long seq[101] = {0};

// P 함수를 통해 파도반 수열의 n번째 값을 구함
unsigned long long P(int N) {
    if (seq[N] != 0) // 이미 계산된 값이 있다면 이를 반환
        return seq[N];
    else { // 계산되지 않은 경우, 직전 값과 5번째 전 값을 더한 값을 저장하고 반환
        seq[N] = P(N - 1) + P(N - 5);
        return seq[N];
    }
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 속도 향상을 위한 코드
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; // 테스트 케이스 개수

    // 초기 파도반 수열의 값을 세팅
    seq[1] = 1, seq[2] = 1, seq[3] = 1, seq[4] = 2, seq[5] = 2;

    cin >> T; // 테스트 케이스 개수를 입력받음
    while (T--) { // 각 테스트 케이스에 대해
        int N; // 파도반 수열의 인덱스
        cin >> N; // 인덱스를 입력받음
        cout << P(N) << '\n'; // 파도반 수열의 N번째 값을 출력
    }
}
