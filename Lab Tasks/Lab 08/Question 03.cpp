#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int score;

    Student() {}
    Student(string n, int r, int s) {
        name = n;
        roll = r;
        score = s;
    }
};

class Node {
public:
    Student data;
    Node *left, *right;

    Node(Student s) {
        data = s;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, Student s) {
    if (root == NULL)
        return new Node(s);

    if (s.name < root->data.name)
        root->left = insertBST(root->left, s);
    else
        root->right = insertBST(root->right, s);

    return root;
}

bool searchBST(Node* root, string key) {
    if (root == NULL)
        return false;

    if (root->data.name == key)
        return true;

    if (key < root->data.name)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

Node* getMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteByName(Node* root, string key) {
    if (root == NULL)
        return NULL;

    if (key < root->data.name)
        root->left = deleteByName(root->left, key);
    else if (key > root->data.name)
        root->right = deleteByName(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Node* t = root->right;
            delete root;
            return t;
        }
        else if (root->right == NULL) {
            Node* t = root->left;
            delete root;
            return t;
        }
        else {
            Node* s = getMin(root->right);
            root->data = s->data;
            root->right = deleteByName(root->right, s->data.name);
        }
    }
    return root;
}

Node* deleteLowScore(Node* root) {
    if (root == NULL)
        return NULL;

    root->left = deleteLowScore(root->left);
    root->right = deleteLowScore(root->right);

    if (root->data.score < 10)
        return deleteByName(root, root->data.name);

    return root;
}

Student getMaxScore(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return root->data; // leaf node, just return its student
    }

    Student maxStudent = root->data;

    if (root->left != NULL) {
        Student leftMax = getMaxScore(root->left);
        if (leftMax.score > maxStudent.score)
            maxStudent = leftMax;
    }

    if (root->right != NULL) {
        Student rightMax = getMaxScore(root->right);
        if (rightMax.score > maxStudent.score)
            maxStudent = rightMax;
    }

    return maxStudent;
}

void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data.name << " | Roll " 
         << root->data.roll << " | Score " 
         << root->data.score << endl;
    inOrder(root->right);
}

int main() {

    Student arr[10] = {
        {"Burair", 1, 95},
        {"Ali", 2, 8},
        {"Haris", 3, 77},
        {"Daniyal", 4, 12},
        {"Zain", 5, 5},
        {"Bilal", 6, 44},
        {"Owais", 7, 67},
        {"Saad", 8, 99},
        {"Furqan", 9, 13},
        {"Ahmed", 10, 3}
    };

    Node* root = NULL;

    root =insertBST(root, arr[0]);
    root =insertBST(root, arr[2]);
    root =insertBST(root, arr[3]);
    root =insertBST(root, arr[5]);
    root =insertBST(root, arr[6]);
    root =insertBST(root, arr[7]);
    root =insertBST(root, arr[8]);

    cout << "Inorder Traversal:"<<endl;
    inOrder(root);

    cout << "Search Haris: "<<endl;;
    cout << (searchBST(root, "Haris") ? "Found" : "Not Found") << endl;

    Student topper = getMaxScore(root);
	cout << "Top Scorer: " << topper.name << " | Score: " << topper.score << endl;


    root = deleteLowScore(root);

    cout << "After Deleting Score < 10:"<<endl;;
    inOrder(root);

    return 0;
}
