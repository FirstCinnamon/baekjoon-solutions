#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
using pli = pair<long long, int>;

int main() {
    long long A, B;
    cin >> A >> B;

    queue<pli> q;
    q.push({A, 0});

    // BFS 수행
    while (!q.empty()) {
        long long curr = q.front().first;
        int step = q.front().second;
        q.pop();

        if (curr == B) {
            cout << step + 1;
            return 0;
        }

        if (curr * 2 <= B)
            q.push({curr * 2, step + 1});

        if (curr * 10 + 1 <= B)
            q.push({curr * 10 + 1, step + 1});
    }

    cout << "-1";
}