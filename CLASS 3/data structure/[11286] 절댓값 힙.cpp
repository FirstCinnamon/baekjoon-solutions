// 11286 절댓값 힙
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; // 연산의 개수 N
    cin >> N;
    // 절댓값이 작은 순서대로 정렬되는 우선순위 큐 선언
    priority_queue<float, vector<float>, greater<float>> pq;

    while (N--) {
        int x; // 입력 받을 정수 x
        cin >> x;
        if (x == 0) {
            if (pq.empty()) // 큐가 비어있으면 0 출력
                cout << "0\n";
            else {
                float top;
                int result;
                // 큐의 최상단 값을 확인
                top = pq.top();
                pq.pop(); // 최상단 값 제거
                if (top == static_cast<int>(top)) { // 최상단 값이 양수인 경우 음수로 변환
                    result = top * -1;
                } else { // 최상단 값이 음수 인 경우
                    result = static_cast<int>(top);
                }
                cout << result << '\n';
            }
        } else {
            // 입력 x가 양수면 0.5를 더하고, 음수면 -x로 저장
            if (x > 0)
                pq.push(x + 0.5);
            else
                pq.push(-x);
        }
    }
}
