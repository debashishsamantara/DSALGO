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

bool getPath(Node* root, int key, vector<int> &path){
    if(root == NULL)
        return false;
    path.push_back(root -> data);
    if(root -> data == key){
        return true;
    }
    if(getPath(root -> left, key, path) || getPath(root -> right, key, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
        return -1;
    int pc;
    for(pc = 0; pc < path1.size() && path2.size(); pc++){
        if(path1[pc] != path2[pc])
            break;
    }
    return path1[pc - 1];
}

Node* LCA_Optimized(Node* root, int n2, int n1){
    if(root == NULL)
        return NULL;
    if(root -> data == n1 || root -> data == n2)
        return root;
    Node* leftLCA = LCA_Optimized(root -> left, n2, n1);
    Node* rightLCA = LCA_Optimized(root -> right, n2, n1);
    if(leftLCA && rightLCA)
        return root;
    if(leftLCA != NULL)
        return leftLCA;
    return rightLCA;
}

int main(){
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    int n1 = 7;
    int n2 = 6;
    Node* lca = LCA_Optimized(root, n1, n2);
    if(lca == NULL)
        cout << "Doesnt exist" << endl;
    else    
        cout << "LCA:" << lca -> data << endl;
    return 0;
}