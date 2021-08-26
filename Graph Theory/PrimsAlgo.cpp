//Based on Greedy Idea

//Idea
//Select an arbitrary vertex s to start the tree from.
//      while (there are still nontree vertices)
//          Select the edge of minimum weight between a tree and nontree vertex.
//          Add the selected edge and vertex to the tree.

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

int n, m;
const int N = 1e5+3;
vvi g[N];
const int INF = 1e9;
int cost = 0;
vector<bool> visited(N);
vi dist(N), parent(N);

void primsMST(int source){
    loop(i, 0, n)
        dist[i] = INF;
    set<vi> s;
    dist[source] = 0;
    s.insert{{0, source}};
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for(auto it : g[x[1]]){
            if(visited[it[0]])
                continue;
            if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]], it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]], it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}

int main(){
    cin >> n >> m;
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << cost;
    return 0;
}