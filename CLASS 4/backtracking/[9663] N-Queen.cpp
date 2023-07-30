// 9663 N-Queen
#include <iostream>

using namespace std;

int N; // 체스판의 크기와 퀸의 수
int cnt; // 가능한 퀸 배치 수
int board[15][15]; // 체스판

// (x, y) 위치에 퀸을 놓을 수 있는지 확인하는 함수
// 위에서 아래로 행별로 확인하므로 현재 행보다 윗부분만 확인하면 됨에 유의
bool is_available(int x, int y) {
    int i, j;
    // 같은 열에 다른 퀸이 있는지 확인
    for (i = 0; i < x; i++)
        if (board[i][y] == 1)
            return false;
    // 왼쪽 대각선에 다른 퀸이 있는지 확인
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;
    // 오른쪽 대각선에 다른 퀸이 있는지 확인
    for (i = x, j = y; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;
    return true; // 위 조건들을 모두 만족하면 놓을 수 있음
}

// x번째 행에 퀸을 배치하는 함수
void NQ_row(int x) {
    // 모든 퀸을 배치한 경우 카운트 증가
    if (x == N) {
        cnt++;
        return;
    }
    // x번째 행의 각 열에 대해 배치 가능 여부를 확인
    for (int j = 0; j < N; j++) {
        // 배치 가능하면 배치하고 다음 행으로 이동
        if (is_available(x, j)) {
            board[x][j] = 1;
            NQ_row(x + 1);
            board[x][j] = 0; // 다른 경우의 수를 위해 배치 취소 (백트래킹)
        }
    }
}

// N-Queen 문제를 해결하는 함수
int solve_NQ() {
    cnt = 0;
    NQ_row(0); // 첫 번째 행부터 시작
    return cnt; // 가능한 배치 수 반환
}

int main() {
    cin >> N; // 체스판 크기 입력

    cout << solve_NQ(); // 결과 출력
}
