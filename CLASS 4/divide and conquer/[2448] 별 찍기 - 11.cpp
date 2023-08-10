// 2448 별 찍기 - 11
#include <iostream>
#include <vector>

using namespace std;

// 삼각형을 그리는 함수. x,y 는 삼각형 맨 위 별의 좌표
void draw(int n, int x, int y, vector<vector<char>> &paint) {
    // 베이스 케이스
    if (n == 3) {   // 기본 삼각형을 그린다
        paint[x][y] = '*';
        paint[x + 1][y - 1] = paint[x + 1][y + 1] = '*';
        paint[x + 2][y - 2] = paint[x + 2][y - 1] = paint[x + 2][y] = paint[x + 2][y + 1] = paint[x + 2][y + 2] = '*';
        return;
    }

    // 리커시브 케이스
    draw(n / 2, x, y, paint);   // 위쪽 삼각형
    draw(n / 2, x + n / 2, y - n / 2, paint);   // 왼쪽  아래 삼각형
    draw(n / 2, x + n / 2, y + n / 2, paint);   // 오른쪽 아래 삼각형
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    // 그림을 저장할 2차원 벡터
    vector<vector<char>> paint(N, vector<char>(2 * N - 1, ' '));

    // 그림 그리기
    draw(N, 0, N - 1, paint);

    // 그림 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++)
            cout << paint[i][j];
        cout << '\n';
    }

}