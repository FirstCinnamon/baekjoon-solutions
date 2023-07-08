// 17219 비밀번호 찾기
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    // 저장된 사이트 주소 수와 찾고자 하는 주소 수 입력 받기
    cin >> N >> M;

    // 사이트 주소와 비밀번호를 저장할 unordered_map
    unordered_map<string, string> passwords;

    // 사이트 주소 및 비밀번호 입력 및 저장
    while (N--) {
        string site, pw;
        cin >> site >> pw;
        // 사이트 주소를 key로, 비밀번호를 value로 저장
        passwords[site] = pw;
    }

    // 비밀번호를 찾으려는 사이트 주소에 대해 처리
    while (M--) {
        string site;
        cin >> site;
        // 해당 사이트 주소의 비밀번호를 출력
        cout << passwords[site] << '\n';
    }
}
