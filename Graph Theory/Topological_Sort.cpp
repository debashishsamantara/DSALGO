//A topological ordering is an ordering of the nodes in a directed graph where for each directed edge from node A to node B, node A appears before node B in the ordering.
//Note: Topological ordering are NOT unique.
//Note: Every graph doesn't have topological ordering
//Directed Cyclic Graph cannot have a topological sort.
//Only Directed Acyclic Graph (DAG) have a valid Topological Sort.

//Algorithm
// while (All nodes are not visited){
//     Nodes with zero indegree can be added to the output array.
//     All the nodes which are adjacent to terminal nodes, gets their indegree subtracted.
// }


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> adj_list(n);
    vector<int> inDeg(n, 0);
    rep(i, 0, m){
        int u, v;
        cin >> u >> v;
        //u -> v
        adj_list[u].push_back(v);
        inDeg[v]++;
    }
    queue<int> pq;
    rep(i, 0, n){
        if(inDeg[i] == 0)
            pq.push(i);
    }
    while(!pq.empty()){
        cnt++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for(auto it : adj_list[x]){
            inDeg[it]--;
            if(inDeg[it] == 0)
                pq.push(it);
        }
    }
}