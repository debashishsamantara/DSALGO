//Step 1 - Start from root node
//Step 2 - Recursively call left and right with (HD-1) and (HD+1) respectively as arguments
//   Base Case - When current node = NULL (return)
//Step 3 - Push the value into vector corresponding to the horizontal distance(HD)
//Step 4 - Output the map.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

struct Node{
    int key;
    Node *left, *right;
};

Node* newNode(int key){
    Node* node = new Node;
    node -> key = key;
    node -> left = node -> right = NULL;
    return node;
}

void getVerticalOrder(Node* root, int hdis, map<int, vi> &m){
    if(root == NULL)
        return;
    m[hdis].push_back(root -> key);
    getVerticalOrder(root -> left, hdis-1, m);
    getVerticalOrder(root -> right, hdis+1, m);
}

signed main(){
    Node *root = newNode(10);
    root -> left = newNode(7);
    root -> right = newNode(4);
    root -> left -> left = newNode(3);
    root -> left -> right = newNode(11);
    root -> right -> left = newNode(14);
    root -> right -> right = newNode(6);
    map<int, vi> m;
    int hdis = 0;
    getVerticalOrder(root, hdis, m);
    map<int, vi> :: iterator it;
    for(it = m.begin(); it != m.end(); it ++){
        rep(i, 0, it -> ss.size()){
            cout << (it -> ss)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}