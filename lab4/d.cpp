#include <iostream>
using namespace std;

// Структура для представления узла дерева
struct Node {
    int value;
    Node* left, *right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Функция для вставки узла в бинарное дерево поиска
Node* insertNode(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->value)
        root->left = insertNode(root->left, value);
    else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Функция для поиска правых узлов на каждом уровне
void searchLastRightPerLevel(Node* root, int level, int& maxLevel) {
    if (!root) return;
    if (level > maxLevel) {
        cout << root->value << " ";
        maxLevel = level;
    }
    if (root -> right) {
        searchLastRightPerLevel(root->right, level + 1, maxLevel);
    }
    if (root -> left) {
        searchLastRightPerLevel(root->left, level + 1, maxLevel);
    }
}

void output(Node* root) {
    if (!root) return;
    int maxLevel = -1;
    searchLastRightPerLevel(root, 0, maxLevel);
    cout << "\n";
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int branchLengths;
    int branchAmounts;
    cin >> branchAmounts;

    Node* root = nullptr;
    for (int i = 0; i < branchAmounts; ++i) {
        cin >> branchLengths;
        root = insertNode(root, branchLengths);
    }
    output(root);
    deleteTree(root);
    return 0;
}
