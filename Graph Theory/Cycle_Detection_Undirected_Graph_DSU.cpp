#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+6;
vi parent(N);
vi sz(N);

void makeSet(int v){
    parent[v] = v;
    sz[v] = 1;
}

int findSet(int v){
    if(v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    loop(i, 0, N)
        makeSet(i);
    int n, m;
    cin >> n >> m;
    vvi edges;
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    bool cycle = false;
    for(auto i : edges){
        int u = i[0];
        int v = i[1];
        int x = findSet(u);
        int y = findSet(v);
        if(x == y)
            cycle = true;
        else
            unionSets(u, v);
    }
    if(cycle)
            cout << "Cycle is found";
        else
            cout << "No cycle is found";
    return 0;
}