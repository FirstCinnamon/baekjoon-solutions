// 11723 집합

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, x, S = 0;  // M: 연산의 수, x: 연산에 사용되는 숫자, S: 집합
    string op;  // 연산자
    cin >> M;  // 연산의 수 입력

    while (M--) {  // M번 반복
        cin >> op;  // 연산자 입력

        if (op != "all" && op != "empty")  // 연산자가 "all" 또는 "empty"가 아니면
            cin >> x;  // 숫자 입력

        if (op == "add")  // "add" 연산
            S |= 1 << (x - 1);  // x를 집합에 추가. 비트 OR 연산
        else if (op == "remove")  // "remove" 연산
            S &= ~(1 << (x - 1));  // x를 집합에서 제거. 비트 AND와 NOT 연산
        else if (op == "check")  // "check" 연산
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';  // x가 집합에 있는지 확인. 있으면 1, 없으면 0 출력
        else if (op == "toggle")  // "toggle" 연산
            S ^= 1 << (x - 1);  // x가 집합에 있다면 제거, 없다면 추가. XOR 연산
        else if (op == "all")  // "all" 연산
            S = (1 << 20) - 1;  // 집합을 {1, 2, ..., 20}으로 바꿈
        else if (op == "empty")  // "empty" 연산
            S = 0;  // 집합을 공집합으로 바꿈
    }
}
