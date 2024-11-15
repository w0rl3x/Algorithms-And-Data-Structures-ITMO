#include <iostream>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
  ~Node() {
    delete left;
    delete right;
  }
};

Node* createNode(int value) {
  Node* newNode = new Node;
  newNode->value = value;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

Node* insertNode(Node* root, int value) {
  if (root == nullptr) {
    return createNode(value);
  }
  if (value < root->value) {
    root->left = insertNode(root->left, value);
  } else if (value > root->value) {
    root->right = insertNode(root->right, value);
  }
  return root;
}

bool searchNode(Node* root, int value) {
  if (root == nullptr) {
    return false;
  }
  if (root->value == value) {
    return true;
  }
  if (value < root->value) {
    return searchNode(root->left, value);
  }
  return searchNode(root->right, value);
}
Node* findPrevNode(Node* root) {
  while (root != nullptr && root->left != nullptr) {
    root = root->left;
  }
  return root;
}

Node* removeNode(Node* root, int value) {
  if (root == nullptr) {
    return nullptr;
  }
  if (value < root->value) {
    root->left = removeNode(root->left, value);
  } else if (value > root->value) {
    root->right = removeNode(root->right, value);
  } else {
    if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    Node* temp = findPrevNode(root->right);
    root->value = temp->value;
    root->right = removeNode(root->right, temp->value);
  }
  return root;
}
int findNextNode(Node* root, int value) {
  int result = -1;
  while (root != nullptr) {
    if (root->value > value) {
      result = root->value;
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return result;
}

int findPrevNode(Node* root, int value) {
  int result = -1;
  while (root != nullptr) {
    if (root->value < value) {
      result = root->value;
      root = root->right;
    } else {
      root = root->left;
    }
  }
  return result;
}

int main() {
  Node* root = nullptr;
  int command;
  int x;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> command >> x) {
    if (command == 0) {
      root = insertNode(root, x);
    } else if (command == 1) {
      root = removeNode(root, x);
    } else if (command == 2) {
      if (searchNode(root, x)) {
        cout << "true\n";
      } else {
        cout << "false\n";
      }
    } else if (command == 3) {
      int next = findNextNode(root, x);
      if (next == -1) {
        cout << "none\n";
      } else {
        cout << next << "\n";
      }
    } else if (command == 4) {
      int prev = findPrevNode(root, x);
      if (prev == -1) {
        cout << "none\n";
      } else {
        cout << prev << "\n";
      }
    }
  }

  delete root;
  return 0;
}