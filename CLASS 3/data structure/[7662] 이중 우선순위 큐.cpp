// 7662 이중 우선순위 큐
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  // 테스트 케이스의 수
    cin >> T;

    while (T--) {  // 각 테스트 케이스에 대하여
        multiset<int> Q;  // 이중 우선순위 큐로 사용할 multiset 생성
        int k;  // 연산의 개수
        cin >> k;
        while (k--) {  // 각 연산에 대하여
            char op;  // 연산의 종류 ('I': 삽입, 'D': 삭제)
            int num;  // 연산에 사용할 수
            cin >> op >> num;
            if (op == 'I') {  // 삽입 연산일 경우
                Q.insert(num);  // num을 multiset에 삽입
            } else {  // 삭제 연산일 경우
                if (Q.empty())  // multiset이 비어 있으면 연산 무시
                    continue;
                else if (num == 1) {  // num이 1이면 최댓값 삭제
                    Q.erase(--Q.end());  // multiset의 마지막 원소(최댓값) 삭제
                } else {  // num이 -1이면 최솟값 삭제
                    Q.erase(Q.begin());  // multiset의 첫 원소(최솟값) 삭제
                }
            }
        }
        if (Q.empty()) {  // 모든 연산 후 multiset이 비어 있으면
            cout << "EMPTY\n";  // "EMPTY" 출력
        } else {  // multiset에 원소가 남아 있으면
            cout << *Q.rbegin() << " " << *Q.begin() << '\n';  // 최댓값과 최솟값 출력
        }
    }
}
