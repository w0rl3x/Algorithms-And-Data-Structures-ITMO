#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}

    void Deleter() {
        if (left != nullptr) left->Deleter();
        if (right != nullptr) right->Deleter();
        delete left;
        delete right;
    }

    ~ Node() {};
};

class Tree {
private:
    Node* root;
    Node* insertNode(Node* node, int v) {
        if (node == nullptr) {
            return new Node(v);
        }
        if (v < node->val) {
            node->left = insertNode(node->left, v);
        } else {
            node->right = insertNode(node->right, v);
        }
        return node;
    }

    void inOrderTrav(Node* element) {
    if (element == nullptr) {
        return;
    }
    inOrderTrav(element->left);
    cout << element->val << " ";
    inOrderTrav(element->right);
    }

public:
    Tree() : root(nullptr) {}

    void insert(int v) {
        root = insertNode(root, v);
    }

    void inOrderTrav() {
        inOrderTrav(root);
        cout << "\n";
    }

    ~Tree () {
        delete root;}
};

int main() {
    Tree t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        t.insert(v);
    }
    t.inOrderTrav();
    return 0;
}
