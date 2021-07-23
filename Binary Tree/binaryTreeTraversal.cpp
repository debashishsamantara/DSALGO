//Preorder Traversal - Start from root and travel from left subtree to right subtree.
//Inorder Traversal - First travel left subtree of the root then print the value of root and then travel the right subtree.
//Postorder Traversal - First travel left and right subtree respectively and then print the value of root.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct Node* root){
    if(root == NULL)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(struct Node* root){
    if(root == NULL)
        return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void postOrder(struct Node* root){
    if(root == NULL)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main(){
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    //preOrder(root);
    //inOrder(root);
    postOrder(root);
    return 0;
}