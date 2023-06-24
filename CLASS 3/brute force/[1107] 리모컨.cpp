// 1107 리모컨
#include <iostream>
#include <vector>

#define MAX 987654321  // 초기 최대값 설정

using namespace std;

// 해당 채널에 직접 접근 가능한지 확인하는 함수
int directly_possible(int i, const vector<int> &broken) {
    int answer = 0;  // 눌러야하는 버튼의 수를 저장
    if (i == 0) {  // 채널이 0인 경우
        for (auto b: broken) {  // 모든 고장난 버튼에 대해
            if (b == 0)  // 고장난 버튼이 0인지 확인
                return -1;  // 0이 고장났다면 -1을 반환
        }
        return 1;  // 0이 고장나지 않았다면 1을 반환
    }
    while (i) {  // i가 0이 될 때까지
        answer++;  // 버튼을 누른 횟수 증가
        for (auto b: broken) {  // 모든 고장난 버튼에 대해
            if (i % 10 == b)  // 고장난 버튼이 i의 마지막 숫자와 같은지 확인
                return -1;  // 고장난 버튼이라면 -1을 반환
        }
        i /= 10;  // 다음 자리 숫자로 이동
    }
    return answer;  // 눌러야하는 버튼의 수를 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;  // N: 이동하려는 채널, M: 고장난 버튼의 개수
    cin >> N >> M;

    vector<int> broken;  // 고장난 버튼을 저장할 벡터

    while (M--) {  // 고장난 버튼의 개수만큼 반복
        int broken_input;
        cin >> broken_input;  // 고장난 버튼 입력 받음
        broken.push_back(broken_input);  // 벡터에 추가
    }

    int near = MAX, press = MAX;  // 가장 가까운 채널과 버튼을 누른 횟수 초기화

    // 모든 가능한 채널에 대해 반복
    for (int i = 0; i <= 1000000; i++) {
        int dp_i = directly_possible(i, broken);  // 직접 접근 가능한지 확인
        if (dp_i != -1) {  // 접근 가능하다면
            if (abs(N - i) < abs(N - near)) {  // 현재 가장 가까운 채널보다 더 가까운지 확인
                near = i;  // 더 가까우면 업데이트
                press = dp_i + abs(N - i);  // 버튼을 누른 횟수 업데이트
            }
        }
    }
    int direct = abs(100 - N);  // 현재 채널(100번 채널)에서 바로 이동하는 경우

    // 버튼을 최소로 누르는 경우 출력
    cout << min(direct, press) << endl;
}
