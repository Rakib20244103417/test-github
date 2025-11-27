#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* newnode(int idata) {
    struct node* Node = new struct node;
    Node->data = idata;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

// Swap values of 2 nodes
void swapData(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Heapify the tree (max heap)
void heapify(struct node* root) {
    if (root == NULL) return;

    struct node* largest = root;

    if (root->left && root->left->data > largest->data)
        largest = root->left;
    if (root->right && root->right->data > largest->data)
        largest = root->right;

    if (largest != root) {
        swapData(root, largest);
        heapify(largest);
    }
}

// Manual insert like your style (not automatic heap insert)
struct node* buildHeap() {
    struct node* root = newnode(10);
    root->left = newnode(12);
    root->right = newnode(1);
    root->left->left = newnode(15);
    root->left->right = newnode(8);

    // Turn this binary tree into a max heap
    heapify(root->left);
    heapify(root->right);
    heapify(root);

    return root;
}

// Print tree sideways
void printTree(struct node* root, int space = 0, int height = 10) {
    if (root == NULL) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

int main() {
    struct node* root = buildHeap();

    cout << "Max Heap (Pointer-based, like your code):\n";
    printTree(root);

    return 0;
}

