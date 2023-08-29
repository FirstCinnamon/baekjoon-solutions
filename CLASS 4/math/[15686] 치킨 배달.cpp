#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;
using pii = pair<int, int>;

int max_step, min_city_chicken_dist = INF;
vector<pii> houses, chickens;

int calculate_chicken_dist(const vector<int> &selected) {
    int city_chicken_dist = 0;
    // 모든 집을 순회
    for (pii house : houses) {
        int x = house.first;
        int y = house.second;
        int chicken_dist = INF;
        // 모든 치킨 집을 순회
        for (int i = 0; i < chickens.size(); i++) {
            // 선택한 치킨 집에 대한 치킨 거리를 계산
            if (selected[i])
                chicken_dist = min(chicken_dist, abs(x - chickens[i].first) + abs(y - chickens[i].second));
        }
        // 도시의 치킨거리에 합함
        city_chicken_dist += chicken_dist;
    }
    return city_chicken_dist;
}

int main() {
    int N, M;

    cin >> N >> M;

    // 정보 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                houses.push_back({i, j});
            else if (tmp == 2)
                chickens.push_back({i, j});
        }

    int chicken_cnt = chickens.size();
    vector<int> selected(chicken_cnt, 0);

    for (int i=0; i<M; i++)
        selected[i] = 1;

    sort(selected.begin(), selected.end());

    int min_city_chicken_dist = INF;

    do {
        min_city_chicken_dist =
            min(min_city_chicken_dist, calculate_chicken_dist(selected));
    } while (next_permutation(selected.begin(), selected.end()));

    cout << min_city_chicken_dist << '\n';
}