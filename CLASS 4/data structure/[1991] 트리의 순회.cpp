// 1991 트리의 순회
#include <iostream>
#include <vector>

using namespace std;

// 노드의 정보를 담는 구조체
struct node {
    char self;
    char left;
    char right;
};

// 전위 순회 함수
void preorder(const vector<node> &tree, int root_idx) {
    if (root_idx == '.' - 'A') // 루트가 '.'이면 더 이상 탐색할 노드가 없으므로 리턴
        return;

    node root = tree[root_idx]; // 현재 노드를 루트로 설정

    cout << root.self; // 루트 출력
    preorder(tree, root.left - 'A'); // 왼쪽 자식으로 재귀 호출
    preorder(tree, root.right - 'A'); // 오른쪽 자식으로 재귀 호출
}

// 중위 순회 함수
void inorder(const vector<node> &tree, int root_idx) {
    if (root_idx == '.' - 'A') // 루트가 '.'이면 더 이상 탐색할 노드가 없으므로 리턴
        return;

    node root = tree[root_idx]; // 현재 노드를 루트로 설정

    inorder(tree, root.left - 'A'); // 왼쪽 자식으로 재귀 호출
    cout << root.self; // 루트 출력
    inorder(tree, root.right - 'A'); // 오른쪽 자식으로 재귀 호출
}

// 후위 순회 함수
void postorder(const vector<node> &tree, int root_idx) {
    if (root_idx == '.' - 'A') // 루트가 '.'이면 더 이상 탐색할 노드가 없으므로 리턴
        return;

    node root = tree[root_idx]; // 현재 노드를 루트로 설정

    postorder(tree, root.left - 'A'); // 왼쪽 자식으로 재귀 호출
    postorder(tree, root.right - 'A'); // 오른쪽 자식으로 재귀 호출
    cout << root.self; // 루트 출력
}

int main() {
    int N;
    cin >> N;
    vector<node> tree(N); // 노드들을 저장할 벡터

    for (int i = 0; i < N; i++) {
        char self, left, right;
        cin >> self >> left >> right;
        tree[self - 'A'].self = self; // self 저장
        tree[self - 'A'].left = left; // left 저장
        tree[self - 'A'].right = right; // right 저장
    }

    preorder(tree, 0); // 전위 순회 시작
    cout << '\n';
    inorder(tree, 0); // 중위 순회 시작
    cout << '\n';
    postorder(tree, 0); // 후위 순회 시작
    cout << '\n';
}