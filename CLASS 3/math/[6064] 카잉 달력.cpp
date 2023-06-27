// 6064 카잉 달력
#include <iostream>

using namespace std;

// 최대공약수를 구하는 함수
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// 카잉 달력 문제를 해결하는 함수
int kaing(int M, int N, int x, int y) {
    int k;

    // M이 N보다 작다면 서로 교환
    if (M < N) {
        swap(M, N);
        swap(x, y);
    }

    k = x;
    // k를 M과 N의 최소 공배수까지 M씩 증가시키면서 y와 비교
    while (k <= lcm(M, N)) {
        if ((k-y) % N == 0)
            return k;
        k += M;
    }

    // k를 찾지 못했다면 -1 반환
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    // 테스트 케이스의 수 입력 받음
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        // 카잉 달력 함수를 이용해 결과 출력
        cout << kaing(M, N, x, y) << '\n';
    }
}
