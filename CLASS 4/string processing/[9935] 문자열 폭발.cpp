// 9935 문자열 폭발
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str, exp;    // 문자열, 폭발 문자열
    cin >> str >> exp;

    string ans = "";    // 출력할 문자열

    for (char c: str) {
        ans += c;   // 출력할 문자열의 뒤부터 하나씩 붙임
        // 출력 문자열이 폭발 문자열보다 길고 && 출력 문자열의 끝에 폭발 문자열이 포함되면
        if (ans.length() >= exp.length() && ans.substr(ans.length() - exp.length(), exp.length()) == exp)
            ans.resize(ans.size() - exp.size());    // 뒤에서 폭발 문자열의 길이만큼 삭제
    }

    if (!ans.empty())   // 출력 문자열이 남아있으면
        cout << ans;
    else    // 출력 문자열이 비어있으면
        cout << "FRULA";
}