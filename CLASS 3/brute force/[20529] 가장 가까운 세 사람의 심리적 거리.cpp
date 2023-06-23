// 20529 가장 가까운 세 사람의 심리적 거리
#include <iostream>
#include <vector>

#define MAX 987654321;  // 최대 심리적 거리 설정. 초기 최소값으로 사용될 예정
using namespace std;

// 두 MBTI 유형 간의 심리적 거리를 계산하는 함수
int calDist(string a, string b) {
    int dist = 0;  // 초기 거리는 0
    for (int i = 0; i < 4; i++) {  // 각 척도를 순회하며
        if (a[i] != b[i])  // 척도가 서로 다르면
            dist++;  // 거리를 1 증가
    }
    return dist;  // 계산된 거리를 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N;  // T: 테스트 케이스 수, N: 학생 수
    string input;  // 학생의 MBTI 유형을 임시 저장
    cin >> T;  // 테스트 케이스 수 입력 받음

    while (T--) {  // 각 테스트 케이스에 대해
        cin >> N;  // 학생 수 입력 받음

        if (N > 32) {  // 학생 수가 32명을 초과한다면
            while (N--)
                cin >> input;  // MBTI 유형은 입력 받지만 처리하지 않음
            cout << "0" << '\n';  // 최소 거리는 반드시 0
        } else {
            vector<string> student(N);  // 학생들의 MBTI 유형을 저장할 벡터
            for (int i = 0; i < N; i++)
                cin >> student[i];  // 각 학생의 MBTI 유형 입력 받음
            int minDist = MAX;  // 가장 작은 심리적 거리를 저장. 초기 값은 최대 거리
            for (int i = 0; i < N; i++) {  // 모든 학생 조합을 검사
                for (int j = i + 1; j < N; j++) {
                    for (int k = j + 1; k < N; k++) {
                        int totDist = calDist(student[i], student[j]) + calDist(student[j], student[k]) +
                                      calDist(student[k], student[i]);  // 세 학생의 총 심리적 거리 계산
                        minDist = min(minDist, totDist);  // 최소 거리 업데이트
                    }
                }
            }
            cout << minDist << '\n';  // 최소 거리 출력
        }
    }
}
