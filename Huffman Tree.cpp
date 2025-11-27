#include <iostream>
using namespace std;

struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newnode(char data, int freq) {
    struct node* temp = new struct node;
    temp->data = data;
    temp->freq = freq;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to find the two smallest frequency nodes
void findTwoSmallest(node* arr[], int n, int &smallest, int &secondSmallest) {
    smallest = -1;
    secondSmallest = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == NULL) continue;
        if (smallest == -1 || arr[i]->freq < arr[smallest]->freq) {
            secondSmallest = smallest;
            smallest = i;
        }
        else if (secondSmallest == -1 || arr[i]->freq < arr[secondSmallest]->freq) {
            secondSmallest = i;
        }
    }
}

// Recursive function to print Huffman codes
void printCodes(struct node* root, string code) {
    if (root == NULL)
        return;

    // If leaf node, print the character and its code
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char chars[20];
    int freq[20];
    node* arr[20];

    cout << "Enter character and frequency:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i] >> freq[i];
        arr[i] = newnode(chars[i], freq[i]);
    }

    int size = n;

    // Build Huffman Tree
    while (true) {
        int i1, i2;
        findTwoSmallest(arr, size, i1, i2);
        if (i2 == -1) break;  // only one node left (root)

        // Merge the two smallest
        node* newNode = newnode('\0', arr[i1]->freq + arr[i2]->freq);
        newNode->left = arr[i1];
        newNode->right = arr[i2];

        arr[i1] = newNode; // replace one of them with new node
        arr[i2] = NULL;    // mark other as used
    }

    // Find root (the last remaining non-null node)
    node* root = NULL;
    for (int i = 0; i < size; i++)
        if (arr[i] != NULL)
            root = arr[i];

    cout << "\nHuffman Codes:\n";
    printCodes(root, "");

    return 0;
}

