#include<iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *createnode(node *root, int item) { // The Main Objective of this is to create node .
    if (root == NULL) {
        root = new node;
        root->data = item;
        root->left = NULL;
        root->right = NULL;
        return root;
    } else if (item < root->data) {
        root->left = createnode(root->left, item);
    } else {
        root->right = createnode(root->right, item);
    }
    return root; 
}

void InorderTraversal(node *root) { //This is mainly for Inorder Traversal.
    if (root == NULL) {
        return;
    } else {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}

void PreorderTraversal(node *root) { //This is the Module for Preorder Searching and Perusing.
    if (root == NULL) {
        return;
    } else {
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}

void PostorderTraversal(node *root) {
    if (root == NULL) {
        return;
    } else {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
}

void SearchingData(node *root, int item, int &leftmove, int &rightmove) { // This is the Module for Searching a Data.
    if (root == NULL) {
        cout << "The Data was Never Found!";
    } else if (item == root->data) {
        cout << "The Data Has been Found!";
    } else if (item < root->data) {
        leftmove++;
        SearchingData(root->left, item, leftmove, rightmove);
    } else {
        rightmove++;
        SearchingData(root->right, item,leftmove,rightmove);
    }
}

int main() {
    node *root = NULL;
    int i, n, item;
    int leftmove = 0, rightmove = 0;

    cout << "How Many Values do you intend to Work With?: ";
    cin >> n;
    cout << "Enter the Values:\n";
    for (i = 0; i < n; i++) {
        cin >> item;
        root = createnode(root, item);
    }
    cout << "\nPreorder Version\n";
    PreorderTraversal(root);
    
    cout << "\nPostorder Version\n";
    PostorderTraversal(root);
    
    cout << "\nInorder Version\n";
    InorderTraversal(root);
    
    cout << "\nEnter a Number to Search: ";
    cin >> item;
    
    SearchingData(root, item, leftmove,rightmove);

    cout << "\nNumber of Moves to the Left: " << leftmove <<"\n";
    cout << "Number of Moves to the Right: " <<rightmove <<"\n";
}

