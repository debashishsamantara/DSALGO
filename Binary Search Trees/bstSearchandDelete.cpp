//Nodes - n, Height - h
//1 + 2 + 2^2 + ..... + 2^(h-1) = n
//2^h - 1 = n
//h = log(n + 1)
//Time Complexity = O(logn)

/*  
           Binary Search Tree
                    4
                  /  \
                 2    5
                / \    \  
               1   3    6
*/               

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

Node* searchInBST(Node* root, int key){
    if(root == NULL)
        return NULL;
    if(root -> data == key)
        return root;
    if(root -> data > key)
        return searchInBST(root -> left, key);
    return searchInBST(root -> right, key);
}

Node* inOrderSucc(Node* root){
    Node* curr = root;
    while(curr && curr -> left != NULL)
        curr = curr -> left;
    return curr;
}

Node* deleteInBST(Node* root, int key){
    if(key < root -> data)
        root -> left = deleteInBST(root -> left, key);
    else if(key > root -> data)
        root -> right = deleteInBST(root -> right, key);
    else{
        if(root -> left == NULL){
            Node* temp = root -> right;
            free(root);
            return temp;
        }else if(root -> right == NULL){
            Node* temp = root -> left;
            free(root);
            return temp;
        }
        //Case3
        Node* temp = inOrderSucc(root -> right);
        root -> data = temp -> data;
        root -> right = deleteInBST(root -> right, temp -> data);
    }
    return root;
}

void inorderPrint(Node* root){
    if(root == NULL)
        return;
    inorderPrint(root -> left);
    cout << root -> data << " ";
    inorderPrint(root -> right);
}


int main(){
    Node* root = new Node(4);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> left -> left = new Node(1);
    root -> left -> right = new Node(3);
    root -> right -> right = new Node(6);
    if(searchInBST(root, 5) == NULL)
        cout << "key doesnt exist";
    else
        cout << "key exists";
    inorderPrint(root);
    cout << endl;
    root = deleteInBST(root, 2);
    inorderPrint(root);
    return 0;
}