// 11054 가장 긴 바이토닉 부분 수열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> LIS(N, 1), LDS(N, 1);

    // LIS : 시작부터 가장 긴 증가하는 부분수열 찾기
    for (int i = 0; i < N; i++)
        for (int j = 0; j < i; j++)
            if (A[i] > A[j])
                LIS[i] = max(LIS[i], LIS[j] + 1);

    // LDS : 가장 긴 감소하는 부분수열 찾기 (끝에서부터)
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j > i; j--)
            if (A[i] > A[j])
                LDS[i] = max(LDS[i], LDS[j] + 1);

    int maxLBS = 0;

    for (int i = 0; i < N; i++)
        maxLBS = max(maxLBS, LIS[i] + LDS[i] - 1);  // 두 값을 더한 뒤 1을 뺀다. (1은 LIS와 LDS의 겹치는 부분)

    cout << maxLBS;
}