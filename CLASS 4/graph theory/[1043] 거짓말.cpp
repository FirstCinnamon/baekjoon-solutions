// 1043 거짓말
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, T;
    // 사람의 수와 파티의 수 입력 받기
    cin >> N >> M;
    // 진실을 아는 사람의 수 입력 받기
    cin >> T;

    vector<vector<int>> adj(N + 1);
    vector<vector<int>> parties(M);
    vector<bool> know_truth(N + 1, false);

    queue<int> q;

    // 진실을 아는 사람의 번호 입력 받기
    while (T--) {
        int person;
        cin >> person;
        know_truth[person] = true;
        q.push(person);
    }

    // 파티 정보 입력 받기
    for (int i = 0; i < M; i++) {
        int party_num;
        cin >> party_num;
        for (int j = 0; j < party_num; j++) {
            int party_person;
            cin >> party_person;
            parties[i].push_back(party_person);
        }

        // 인접리스트를 사용하여 파티에서 만나는 사람들의 관계 저장
        for (int j = 0; j < party_num; j++) {
            for (int k = j + 1; k < party_num; k++) {
                adj[parties[i][j]].push_back(parties[i][k]);
                adj[parties[i][k]].push_back(parties[i][j]);
            }
        }
    }

    // 진실을 아는 사람들과 연결된 사람들에 대한 정보 처리
    while (!q.empty()) {
        int person = q.front();
        q.pop();

        for (const auto &person_met: adj[person]) {
            if (!know_truth[person_met]) {
                know_truth[person_met] = true;
                q.push(person_met);
            }
        }
    }

    int cnt = 0;
    // 지민이가 거짓말을 하지 않고 이야기할 수 있는 파티의 수 구하기
    for (const auto &party: parties) {
        bool is_okay_to_lie = true;
        for (const auto &person: party) {   
            if (know_truth[person])     // 한 명이라도 진실을 알 수 있다면 거짓말을 할 수 없음
                is_okay_to_lie = false;
        }
        if (is_okay_to_lie)
            cnt++;
    }

    // 결과 출력
    cout << cnt;
}
