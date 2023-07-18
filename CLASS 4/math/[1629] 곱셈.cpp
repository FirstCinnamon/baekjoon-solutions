// 1629 곱셈
#include <iostream>

using namespace std;

// A를 B번 곱한 수를 C로 나눈 나머지를 구하는 함수 pow_mod
long long pow_mod(long long A, long long B, long long C) {
    // B가 0인 경우 A^0 = 1이므로 1을 반환
    if (B == 0)
        return 1;

    // A를 B/2번 곱한 값을 C로 나눈 나머지를 temp에 저장
    long long temp = pow_mod(A, B / 2, C);

    // B가 짝수인 경우, (A^(B/2) mod C * A^(B/2) mod C) mod C를 반환
    if (B % 2 == 0)
        return (temp * temp) % C;
        // B가 홀수인 경우,
        // ((A^(B/2) mod C * A^(B/2) mod C) mod C * A) mod C를 반환
    else
        return (((temp * temp) % C) * A) % C;
}

int main() {
    long long A, B, C;
    // 자연수 A, B, C를 입력 받음
    cin >> A >> B >> C;

    // A를 B번 곱한 수를 C로 나눈 나머지를 출력
    cout << pow_mod(A, B, C) << endl;

    // 참고 : 시간 복잡도는 O(logB)
}
