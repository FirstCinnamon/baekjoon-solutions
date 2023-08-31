// 12851 숨바꼭질 2
#include <iostream>
#include <vector>
#include <queue>

// 순간이동시 최대 두배까지 이동할 수 있으므로 100000 * 2 + 1 (인덱스를 1부터 사용하므로 +1 해줌) 인 200001을 최댓값으로 설정
#define MAX 200001

using namespace std;
using pii = pair<int, int>;

int main() {
    int N, K;
    cin >> N >> K;

    // 초기 설정
    vector<int> total_times(MAX, -1);   // 해당 위치에 도달하는데 걸린 시간을 저장하는 벡터. -1은 방문하지 않았음을 의미
    int min_time = MAX;     // N에서 K까지 걸린 최소 시간
    int paths = 0;          // N에서 K까지 갈 수 있는 방법의 수

    // BFS 초기 설정
    queue<pii> q;
    q.push({N, 0}); // N에서 시작. N까지 도달하는데 걸린 시간은 0
    total_times[N] = 0; // N을 방문 처리

    // BFS 시작
    while (!q.empty()) {
        int curr = q.front().first;
        int time = q.front().second;
        q.pop();

        // 현재 위치가 K이면
        if (curr == K) {
            // 걸린 시간이 최소 시간보다 짧으면 최소 시간을 새롭게 갱신. paths 는 1로 초기화
            if (time < min_time) {
                min_time = time;
                paths = 1;
            } else if (time == min_time)    // 걸린 시간이 최소 시간과 동일하면 paths의 수를 +1 (도달가능한 방법 한 가지 추가)
                paths++;
            continue;   // 이미 K에 도달했으므로 다음 과정을 스킵
        }

        // 움직임에 따라 다음 세 가지 위치를 저장한 배열
        int next_positions[3] = {curr * 2, curr + 1, curr - 1};
        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];   // 다음 위치를 저장
            // next가 도달 가능하고 (0 <= next < MAX) next가 미방문(-1) 이거나 next까지 도달하는데 걸린 시간(total_times[next])이 time +1 보다 크면 (즉 next까지 더 빠른 시간 내에 도달할 수 있으면)
            if (next >= 0 && next < MAX && (total_times[next] == -1 || total_times[next] >= time + 1)) {    // 괄호에 주의. 괄호가 없으면 outofbounds 에러가 뜬다. 
                q.push({next, time + 1});   // 큐에 넣고
                total_times[next] = time + 1;         // 시간을 업데이트
            }
        }
    }

    cout << min_time << '\n';
    cout << paths << '\n';
}