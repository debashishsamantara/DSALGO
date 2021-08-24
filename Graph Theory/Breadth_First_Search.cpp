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

const int N = 1e5+2;
bool visited[N];
vector<int> adj[N];

int main(){
    loop(i, 0, N)
        visited[i] = 0;
    int n, m;
    cin >> n >> m;
    int x ,y;
    loop(i, 0, m){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << endl;
        vector<int> :: iterator it;
        for(it = adj[node].begin(); it != adj[node].end(); it++){
            if(!visited[*it]){
                visited[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}