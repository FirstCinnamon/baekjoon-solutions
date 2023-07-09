// 11403 경로 찾기
#include <iostream>
#include <vector>

#define MAX 987654321 // 정수 최댓값으로 설정
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; // 정점의 개수 N
    cin >> N;
    // 그래프 정보를 행렬 형태로 저장할 벡터 생성
    vector<vector<int>> graph(N, vector<int>(N));

    // 그래프 정보 입력 받음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
                graph[i][j] = MAX; // 간선이 없는 경우, 최댓값으로 초기화
            else
                graph[i][j] = tmp; // 간선이 있는 경우, 값 입력
        }
    }

    // 플로이드-워셜 알고리즘을 사용하여 i에서 j로 가는 최단 경로 계산
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] != MAX) // 경로가 존재하는 경우 1 출력
                cout << 1;
            else // 경로가 존재하지 않는 경우 0 출력
                cout << 0;
            if (j != N)
                cout << " ";
        }
        cout << '\n';
    }
}
