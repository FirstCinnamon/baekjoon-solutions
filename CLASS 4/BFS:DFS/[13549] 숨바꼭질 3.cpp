// 13549 숨바꼭질 3
#include <iostream>
#include <vector>
#include <queue>

// 순간이동시 최대 두배까지 이동할 수 있으므로 100000 * 2 + 1 (인덱스를 1부터 사용하므로 +1 해줌) 인 200001을 최댓값으로 설정
#define MAX 200001 

using namespace std;
using pii = pair<int, int>;

int N, K; // 수빈이와 동생의 위치
vector<bool> visited(MAX, false); // 방문 여부 체크

int BFS() {
    priority_queue<pii, vector<pii>, greater<pii>> q; // 최소 힙
    q.push({0, N}); // 시작 위치와 시간
    visited[N] = true;

    while (!q.empty()) {
        int time = q.top().first; // 현재 시간
        int curr = q.top().second; // 현재 위치
        q.pop();

        if (curr == K)
            return time; // 동생을 찾으면 시간 반환

        // 순간이동 (시간 변화 없음)
        if (curr * 2 < MAX && !visited[curr * 2]) {
            q.push({time, curr * 2});
            visited[curr * 2] = true;
        }

        // 오른쪽으로 걷기 (시간 +1)
        if (curr + 1 < MAX && !visited[curr + 1]) {
            q.push({time + 1, curr + 1});
            visited[curr + 1] = true;
        }

        // 왼쪽으로 걷기 (시간 +1)
        if (curr - 1 >= 0 && !visited[curr - 1]) {
            q.push({time + 1, curr - 1});
            visited[curr - 1] = true;
        }
    }
    return -1;
}

int main() {
    cin >> N >> K; // 수빈이와 동생의 위치 입력
    cout << BFS() << '\n'; // 결과 출력
}
