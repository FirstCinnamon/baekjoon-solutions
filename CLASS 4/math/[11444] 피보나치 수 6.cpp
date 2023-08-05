// 11444 피보나치 수 6
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;  // 큰 숫자를 다루기 위해 long long을 사용
typedef vector<vector<ll>> matrix;  // 행렬은 vector를 이용해 표현
const ll mod = 1000000007LL;  // 결과값을 나눠줄 mod 값

// 행렬 곱셈 함수. 행렬 a와 b를 받아 곱한 결과를 반환
matrix multiply(matrix &a, matrix &b) {
    matrix c(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

// 행렬의 거듭제곱을 구하는 함수. 행렬 a와 거듭제곱할 수 n을 받아 계산
const matrix identity = {{1, 0},
                         {0, 1}};  // 단위행렬

// 행렬의 거듭제곱을 계산하는 함수. 행렬 a와 거듭제곱할 수 n을 받아 계산
matrix power(matrix a, ll n) {
    matrix res = identity;
    while (n > 0) {
        if (n % 2 == 1) {
            res = multiply(res, a);
        }
        a = multiply(a, a);
        n /= 2;
    }
    return res;
}

// 피보나치 수를 계산하는 함수
ll fibonacci(ll n) {
    if (n == 0)
        return 0;
    matrix a = {{1, 1},
                {1, 0}};
    a = power(a, n - 1);
    return a[0][0];
}

int main() {
    ll n;
    cin >> n;  // n을 입력 받음

    cout << fibonacci(n);  // n번째 피보나치 수를 출력
}
