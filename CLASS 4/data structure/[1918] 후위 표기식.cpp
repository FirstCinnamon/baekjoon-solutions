// 1918 후위 표기식
#include <iostream>
#include <stack>

using namespace std;

// 우선순위를 반환하는 함수
int priority(char ch) {
    if (ch == '*' || ch == '/') return 2;  // *, / 연산자는 가장 높은 우선순위
    if (ch == '+' || ch == '-') return 1;  // +, - 연산자는 그 다음 우선순위
    if (ch == '(') return 0;               // '(' 는 가장 낮은 우선순위
    return -1;
}

int main() {
    string formula;
    cin >> formula;  // 중위 표기식 입력

    stack<char> st;

    // 입력받은 중위 표기식에 대해
    for (int i = 0; i < formula.length(); i++) {
        char ch = formula[i];

        // 피연산자인 경우 바로 출력
        if ('A' <= ch && ch <= 'Z')
            cout << ch;

        // '(' 를 만나면 스택에 넣음
        else if (ch == '(')
            st.push(ch);

        // ')' 를 만나면 '('를 만날 때까지 스택에서 연산자를 꺼내 출력
        else if (ch == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();  // '(' 제거
        }

        // 연산자인 경우
        else {
            // 스택의 top에 있는 연산자의 우선순위가 현재 연산자의 우선순위보다 같거나 큰 경우 꺼내 출력
            while (!st.empty() && priority(st.top()) >= priority(ch)) {
                cout << st.top();
                st.pop();
            }
            st.push(ch);  // 현재 연산자를 스택에 넣음
        }
    }

    // 스택에 남아 있는 연산자를 모두 출력
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
