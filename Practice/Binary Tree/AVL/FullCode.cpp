#include <iostream>
#include <algorithm> // for std::max
using namespace std;

// 🌳 Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// 🧩 Utility function to get height of a node
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// 🆕 Create a new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // leaf node height = 1
    return node;
}

// ⚖️ Get Balance Factor
int getBalance(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// 🔁 Right Rotation (LL Case)
Node* rightRotate(Node* oldParent) {
    Node* newParent = oldParent->left;
    Node* orphanSubtree = newParent->right;

    // Perform rotation
    newParent->right = oldParent;
    oldParent->left = orphanSubtree;

    // Update heights
    oldParent->height = 1 + max(height(oldParent->left), height(oldParent->right));
    newParent->height = 1 + max(height(newParent->left), height(newParent->right));

    return newParent; // new root
}

// 🔁 Left Rotation (RR Case)
Node* leftRotate(Node* oldParent) {
    Node* newParent = oldParent->right;
    Node* orphanSubtree = newParent->left;

    // Perform rotation
    newParent->left = oldParent;
    oldParent->right = orphanSubtree;

    // Update heights
    oldParent->height = 1 + max(height(oldParent->left), height(oldParent->right));
    newParent->height = 1 + max(height(newParent->left), height(newParent->right));

    return newParent; // new root
}

// 🔀 Left-Right Rotation (LR Case)
Node* leftRightRotate(Node* node) {
    node->left = leftRotate(node->left);  // Step 1: Left rotate the left child
    return rightRotate(node);             // Step 2: Right rotate the node
}

// 🔀 Right-Left Rotation (RL Case)
Node* rightLeftRotate(Node* node) {
    node->right = rightRotate(node->right); // Step 1: Right rotate the right child
    return leftRotate(node);                // Step 2: Left rotate the node
}

// 🌱 AVL Insert Function
Node* insert(Node* node, int key) {
    // 1️⃣ Perform normal BST insertion
    if (node == nullptr)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate keys not allowed

    // 2️⃣ Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // 3️⃣ Get balance factor
    int balance = getBalance(node);

    // 4️⃣ Balance the tree (4 cases)
    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->key)
        return leftRightRotate(node);

    // RL Case
    if (balance < -1 && key < node->right->key)
        return rightLeftRotate(node);

    return node; // unchanged node pointer
}

// 🌿 Inorder Traversal
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// 🚀 Driver Code
int main() {
    Node* root = nullptr;

    // Insert values to test all rotations
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10); // LL rotation
    root = insert(root, 40);
    root = insert(root, 50); // RR rotation
    root = insert(root, 25); // LR rotation
    root = insert(root, 35); // RL rotation

    cout << "Inorder traversal of AVL tree after all rotations: ";
    inorder(root);
    cout << "\nRoot after balancing: " << root->key << endl;

    return 0;
}
