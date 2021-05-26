//Binary Tree
//Properties of Binary Trees
//1. Maximum nodes at level L = 2^L
//2. Maximum nodes in a height H = 2^H-1
//3. For N nodes, minimum possible height or minimum number of levels are log2(N+1).
//4. A binary tree with L leaves has atleast log2(N+1)+1 number of levels. 
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

int main(){
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    return 0;
}