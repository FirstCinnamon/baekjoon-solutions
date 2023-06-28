// 5525 IOI
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;  // N: IOI 패턴을 찾아야 하는 수, M: 전체 문자열의 길이
    string s;  // 전체 문자열

    int count = 0, pattern_count = 0;  // count: 찾은 IOI 패턴의 수, pattern_count: 현재까지 찾은 연속적인 IOI 패턴의 수

    cin >> N;
    cin >> M;
    cin >> s;

    for (int i = 1; i < M - 1; i++) {  // 문자열을 순회하면서 IOI 패턴을 찾음
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {  // IOI 패턴이 발견되면
            pattern_count++;  // 패턴 카운트를 1 증가
            if (pattern_count == N) {  // 만약 패턴 카운트가 N과 같다면
                count++;  // 찾은 패턴의 수를 1 증가
                pattern_count--;  // 패턴 카운트를 1 감소시켜 겹치는 패턴을 찾을 수 있게 함
            }
            i++;  // IOI 패턴을 찾았으니 한 칸 더 전진
        } else  // IOI 패턴이 아닐 경우
            pattern_count = 0;  // 패턴 카운트를 0으로 초기화
    }

    cout << count;  // 찾은 IOI 패턴의 수를 출력
}
