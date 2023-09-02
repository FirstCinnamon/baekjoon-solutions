// 1509 팰린드롬 분할
#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

// 팰린드롬 여부를 체크하는 함수
bool is_palindrome(int j, int i, const string &str, vector<vector<int>> &palindrome_table) {
    if (palindrome_table[j][i] == 1)
        return true;
    else if (palindrome_table[j][i] == 0)
        return false;
    else {
        if (str[j] != str[i]) {
            palindrome_table[j][i] = 0;
            return false;
        } else if (j + 1 < i - 1) {
            if (!is_palindrome(j + 1, i - 1, str, palindrome_table)) {
                palindrome_table[j][i] = 0;
                return false;
            }
        }
        palindrome_table[j][i] = 1;
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    int n = str.size();

    // 팰린드롬 여부를 저장하는 테이블. palindrom_table[i][j] 의 값에 따라 각각 (0 : 팰린드롬 아님, 1 : 팰린드롬임, -1 : 아직 모름) 이다. 
    vector<vector<int>> palindrome_table(n, vector<int>(n, -1));

    // 한 글자는 항상 팰린드롬이다.
    for (int i = 0; i < n; i++)
        palindrome_table[i][i] = 1;

    // 다이나믹 프로그래밍을 위한 배열
    vector<int> dp(n, INF);

    // 처음 한 문자를 팰린드롬 분할하는 최소한의 가짓수는 1
    dp[0] = 1;

    // 다이나믹 프로그래밍 실행
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++)
            // 전체 0 ~ i 문자열에서 j부터 i까지가 팰린드롬이면 dp[i]는 기존의 값과 dp[j] + 1 중 작은 값을 취한다.
            if (is_palindrome(j, i, str, palindrome_table))
                dp[i] = min(dp[i], (j > 0 ? dp[j - 1] : 0) + 1);    // j-1이 인덱스 범위를 벗어나지 않도록 조치
    
    // dp 값을 출력
    cout << dp[n - 1] << '\n';
}