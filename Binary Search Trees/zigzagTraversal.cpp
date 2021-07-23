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

void zigzagTraversal(Node* root){
    stack<Node*> currLvl, nxtLvl;
    bool leftToRight = true;
    currLvl.push(root);
    while(!currLvl.empty()){
        Node* temp = currLvl.top();
        currLvl.pop();
        if(temp){
            cout << temp -> data << " ";
            if(leftToRight){
                if(temp -> left)
                    nxtLvl.push(temp -> left);
                if(temp -> right)
                    nxtLvl.push(temp -> right);
            }else{
                if(temp -> right)
                    nxtLvl.push(temp -> right);
                if(temp -> left)
                    nxtLvl.push(temp -> left);
            }
        }
        if(currLvl.empty()){
            leftToRight = !leftToRight;
            swap(currLvl, nxtLvl);
        }
    }
}

int main(){
    struct Node* root = new Node(1);
      root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);
    zigzagTraversal(root);
    cout << endl;
    return 0;
}