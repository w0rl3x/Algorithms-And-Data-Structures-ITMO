#include <iostream>
using namespace std;

// Структура для хранения информации о поддереве
struct TreeData {
    bool isBST;
    long long minValue;
    long long maxValue;
    long long sum;
};

struct Node {
    long long value;
    Node* left;
    Node* right;
    bool isBST;

    Node(long long val) : value(val), left(nullptr), right(nullptr), isBST(false) {}
};

// Функция для расчета максимальной суммы поддерева, являющегося BST
TreeData resolveBST(Node* node, long long& maxSum) {
    if (node == nullptr) {
        return {true, 1000000001, -1000000001, 0}; // Пустое поддерево как BST
    }

    TreeData leftInfo = resolveBST(node->left, maxSum);
    TreeData rightInfo = resolveBST(node->right, maxSum);

    bool isCurrentBST = leftInfo.isBST && rightInfo.isBST &&
                        (leftInfo.maxValue < node->value) &&
                        (rightInfo.minValue > node->value);

    node->isBST = isCurrentBST;

    long long curSum = node->value + leftInfo.sum + rightInfo.sum;

    if (isCurrentBST) {
        maxSum = max(maxSum, curSum);
    }

    long long minValue = (node->left) ? leftInfo.minValue : node->value;
    long long maxValue = (node->right) ? rightInfo.maxValue : node->value;

    return {isCurrentBST, minValue, maxValue, curSum};
}

// Функция для создания поддерева на основе команд
void buildSubtree(Node* node) {
    char cmd;
    while (cin >> cmd) {
        if (cmd == 'l') {
            long long value;
            cin >> value;
            node->left = new Node(value);
            buildSubtree(node->left);
        } else if (cmd == 'r') {
            long long value;
            cin >> value;
            node->right = new Node(value);
            buildSubtree(node->right);
        } else if (cmd == 'u') {
            return;
        }
    }
}

// Функция для построения дерева
Node* buildTree() {
    long long rootData;
    cin >> rootData;
    Node* rootNode = new Node(rootData);
    buildSubtree(rootNode);
    return rootNode;
}

// Функция для удаления дерева и освобождения памяти
void deleteTree(Node* node)
{
    if (node == nullptr)
        return;
    
    deleteTree(node->left);  // Рекурсивно удаляем левое поддерево
    deleteTree(node->right); // Рекурсивно удаляем правое поддерево
    delete node;             // Освобождаем память для текущего узла
}

int main() {
    Node* rootNode = buildTree();

    long long maxSum = 0;
    resolveBST(rootNode, maxSum);

    cout << maxSum << endl;

    deleteTree(rootNode);

    return 0;
}
