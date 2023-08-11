// 5639 이진 검색 트리
#include <iostream>

using namespace std;

// 노드 구조체
struct node {
    int key;
    node *left = nullptr;
    node *right = nullptr;
};

// 노드 추가
void push(node *&K, int num) {
    if (K == nullptr) {     // 노드가 존재하지 않을 경우 생성
        K = new node{num, nullptr, nullptr};
        return;
    }
    if (K->key > num)       // num이 더 작으면 왼쪽 서브트리로
        push(K->left, num);
    else if (K->key < num)      // num이 더 크면 오른쪽 서브트리로
        push(K->right, num);
    else
        cout << "Error" << '\n';
}

// 후위 순회
void postorder(node *K) {
    if (K == nullptr)
        return;
    postorder(K->left);
    postorder(K->right);
    cout << K->key << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int key;
    node *root = nullptr;   // 루트 노드 초기화

    while (cin >> key)
        push(root, key);

    postorder(root);
}