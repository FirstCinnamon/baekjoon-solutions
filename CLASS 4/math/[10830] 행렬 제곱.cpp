// 10830 행렬 제곱
#include <iostream>
#include <vector>

using namespace std;
using matrix = vector<vector<int>>;

int N;

// 행렬을 출력하는 함수
void print_matrix(matrix A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] % 1000;     // 1000으로 나눈 나머지를 출력 (곱셈 연산 없이 1000의 값이 들어왔을 때 필요)  ex) 2 1 \n 1000 1000 \n 1000 1000
            if (j != N - 1)
                cout << ' ';
        }
        cout << '\n';
    }
}

// 두 행렬을 곱하는 함수
matrix multiply(matrix M1, matrix M2) {
    matrix M3(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++)
                M3[i][j] += (M1[i][k] * M2[k][j]);
            M3[i][j] %= 1000;
        }

    return M3;
}

// 분할 정복을 이용해 행렬의 거듭제곱을 구하는 함수
matrix pow_square(matrix A, long long B) {
    // 베이스 케이스
    if (B == 1)
        return A;

    // 이 행렬은 B가 짝수일 때 B/2 제곱, B가 홀수일 때 (B-1)/2 제곱이 된다.
    matrix half = pow_square(A, B / 2);
    
    // 리커시브 케이스
    if (B % 2 == 1)
        return multiply(multiply(half, half), A);   // A^B = A^(B-1)/2 * A^(B-1)/2 * A
    else
        return multiply(half, half);    // A^B = A^B/2 * A^B/2
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long B;
    cin >> N >> B;

    matrix A(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }

    print_matrix(pow_square(A, B));
}