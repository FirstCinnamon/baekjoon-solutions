// 5430 AC
#include <iostream>
#include <queue>

using namespace std;

string p, arr;  // p: 수행할 함수, arr: 초기 배열

void AC() {
    bool is_reversed = false;  // 배열이 뒤집혀있는지 여부
    deque<int> dq;  // 덱 선언

    int num = 0;
    // 문자열 arr을 통해 덱 초기화
    for (auto ch: arr) {
        if (isdigit(ch))  // 숫자인 경우
            num = num * 10 + (ch - '0');  // 숫자 변환
        else if (ch == ',') {  // 쉼표인 경우
            dq.push_back(num);  // 덱에 추가
            num = 0;  // num 초기화
        }
    }
    // arr 처리가 끝난 후 num에 남아있는 숫자 처리
    if (num != 0)
        dq.push_back(num);  // 덱에 추가

    // 문자열 p에 따른 동작 수행
    for (auto ch: p) {
        if (ch == 'D') {  // D: 첫 번째 숫자 버리기
            if (dq.empty()) {  // 덱이 비어있다면 에러
                cout << "error" << '\n';
                return;
            } else {  // 덱이 비어있지 않다면
                if (is_reversed)
                    dq.pop_back();  // 뒤집혀있다면 맨 뒤의 숫자 버리기
                else
                    dq.pop_front();  // 아니라면 맨 앞의 숫자 버리기
            }
        } else {    //ch == 'R'  // R: 배열 뒤집기
            is_reversed = !is_reversed;  // 뒤집힌 상태 토글
        }
    }

    // 결과 출력
    cout << '[';
    if (is_reversed) {  // 배열이 뒤집혀있다면
        while (!dq.empty()) {
            cout << dq.back();  // 뒤에서부터 출력
            dq.pop_back();
            if (!dq.empty())
                cout << ',';
        }
    } else {  // 아니라면
        while (!dq.empty()) {
            cout << dq.front();  // 앞에서부터 출력
            dq.pop_front();
            if (!dq.empty())
                cout << ',';
        }
    }

    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int T, n;  // T: 테스트 케이스 개수, n: 배열에 들어있는 수의 개수
    cin >> T;  // 테스트 케이스 개수 입력
    while (T--) {  // T번 반복
        cin >> p;  // 수행할 함수 입력
        cin >> n;  // 배열에 들어있는 수의 개수 입력
        cin >> arr;  // 배열 입력
        AC();  // AC 함수 수행
    }
}
