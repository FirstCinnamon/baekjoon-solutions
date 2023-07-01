// 9375 패션왕 신해빈
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; // 테스트 케이스의 수
    cin >> T;

    // 각 테스트 케이스에 대해 처리
    while (T--) {
        int n; // 의상의 수
        cin >> n;

        // 의상의 수가 0인 경우는 별도 처리
        if (n == 0) {
            cout << "0\n";
            continue;
        }

        // 해시 맵을 사용해 각 카테고리별 의상의 수를 저장
        unordered_map<string, int> closet;

        // 각 의상에 대해 카테고리를 키로 하여 카운팅
        while (n--) {
            string cloth, category;
            cin >> cloth >> category;
            if (closet.count(category)) {
                closet[category]++;
            } else {
                closet[category] = 1;
            }
        }

        // 각 카테고리의 의상 수에 1을 더하고 곱하여 경우의 수를 계산
        // 1을 더하는 이유는 해당 카테고리의 의상을 안 입는 경우를 포함하기 위함
        int sum = 1;
        for (const auto &c: closet) {
            sum *= (c.second + 1);
        }

        // 알몸인 경우를 제외하기 위해 1을 빼줌
        sum--;

        // 결과 출력
        cout << sum << '\n';
    }
}
