// 2630 색종이 만들기
#include <iostream>
#include <vector>

using namespace std;

int blue = 0, white = 0; // 파란색과 흰색 종이의 개수를 저장할 전역변수

// 주어진 영역이 모두 같은 색인지 검사함
bool check_same(vector<vector<int>> &paper, int N, int i_start, int j_start) {
    for (int i = i_start; i < i_start + N; i++)
        for (int j = j_start; j < j_start + N; j++)
            if (paper[i_start][j_start] != paper[i][j])
                return false; // 다른 색이 발견되면 false 반환
    return true; // 모두 같은 색이면 true 반환
}

// 주어진 종이를 적절히 잘라내서 개수를 세는 함수
void cut_paper(vector<vector<int>> &paper, int N, int i_start, int j_start) {
    // 해당 영역이 모두 같은 색이거나, 더 이상 잘라낼 수 없는 경우 종이의 색을 세고 종료함
    if (N == 1 || check_same(paper, N, i_start, j_start)) {
        if (paper[i_start][j_start] == 0)
            white++;
        else
            blue++;
        return;
    } else { // 그렇지 않은 경우 4분할로 재귀적으로 분할함
        N /= 2;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                cut_paper(paper, N, i_start + i * N, j_start + j * N);
    }
}

// 주 프로그램
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 종이의 크기 입력 받음
    cin >> N;

    vector<vector<int>> paper(N, vector<int>(N, 0)); // 종이의 색 정보를 저장할 2차원 벡터 초기화

    // 종이의 색 정보를 입력 받음
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];

    cut_paper(paper, N, 0, 0); // 종이를 잘라내는 함수 호출
    
    cout << white << '\n' << blue; // 결과 출력

    return 0;
}
