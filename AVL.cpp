#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    int height;
};

// Height of node
int getHeight(node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

// Create new node
node* newnode(int idata) {
    node* Node = new node;
    Node->data = idata;
    Node->left = NULL;
    Node->right = NULL;
    Node->height = 1;
    return Node;
}

// Get balance factor
int getBalance(node* n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

// Right rotation
node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert in AVL Tree
node* insert(node* root, int data) {
    if (root == NULL)
        return newnode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    // Perform rotations if unbalanced
    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print AVL Tree sideways
void printTree(node* root, int space = 0, int height = 10) {
    if (root == NULL)
        return;

    space += height;

    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    printTree(root->left, space);
}

int main() {
    node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 1);
    root = insert(root, 15);
    root = insert(root, 8);

    cout << "AVL Tree (Sideways View):\n";
    printTree(root);

    return 0;
}
