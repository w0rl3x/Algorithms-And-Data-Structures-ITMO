#include <iostream>

struct Node {
    int value, subtreeSize = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int val) : value(val) {}
};

class Tree {
public:
    Node* root = nullptr;

    // Вставка элемента
    Node* insertNode(Node* node, int value) {
        if (!node) return new Node(value);

        if (value < node->value) node->left = insertNode(node->left, value);
        else node->right = insertNode(node->right, value);

        sizeUpdater(node);
        return balance(node);
    }

    // Удаление элемента
    Node* eraseNode(Node* node, int value) {
        if (!node) return nullptr;

        if (value < node->value) node->left = eraseNode(node->left, value);
        else if (value > node->value) node->right = eraseNode(node->right, value);
        else {
            // Удаление найденного узла
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                Node* minNode = findMinNode(node->right);
                node->value = minNode->value;
                node->right = eraseNode(node->right, minNode->value);
            }
        }

        sizeUpdater(node);
        return balance(node);
    }

    // Найти k-й максимум
    int findMaxKth(Node* node, int k) {
        int rightSize = node->right ? node->right->subtreeSize : 0;
        if (k == rightSize + 1) return node->value;
        else if (k <= rightSize) return findMaxKth(node->right, k);
        return findMaxKth(node->left, k - rightSize - 1);
    }

    void deleteTree(Node* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    ~Tree() {
        deleteTree(root);
    }

private:
    // Балансировка и вспомогательные функции
    Node* balance(Node* node) {
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) < 0) node->left = rotateToLeft(node->left);
            return rotateToRight(node);
        } else if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) > 0) node->right = rotateToRight(node->right);
            return rotateToLeft(node);
        }
        return node;
    }

    Node* rotateToRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;
        sizeUpdater(y);
        sizeUpdater(x);
        return x;
    }

    Node* rotateToLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        sizeUpdater(x);
        sizeUpdater(y);
        return y;
    }

    int getBalanceFactor(Node* node) {
        return (node ? (node->left ? node->left->subtreeSize : 0) - (node->right ? node->right->subtreeSize : 0) : 0);
    }

    void sizeUpdater(Node* node) {
        if (node) {
            node->subtreeSize = 1 + (node->left ? node->left->subtreeSize : 0) + (node->right ? node->right->subtreeSize : 0);
        }
    }

    Node* findMinNode(Node* node) {
        while (node->left) node = node->left;
        return node;
    }
};

int main() {
    Tree tree;
    int n;
    std::cin >> n;
    
    std::string output;  // Строка для накопления всех результатов команд `0 k`
    
    while (n--) {
        int command, k;
        std::cin >> command >> k;

        if (command == 1) tree.root = tree.insertNode(tree.root, k);
        else if (command == 0) output += std::to_string(tree.findMaxKth(tree.root, k)) + '\n';
        else if (command == -1) tree.root = tree.eraseNode(tree.root, k);
    }
    
    // Выводим все накопленные результаты
    std::cout << output;

    return 0;
}
