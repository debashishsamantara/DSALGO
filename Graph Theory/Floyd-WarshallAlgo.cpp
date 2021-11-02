//To find all pair shortest paths.
//i.e. for every u, v in Graph G, find the shortest path from u to v. 

//Pseude Code
//for(int k = 0; k < n; ++k){
//     for(int i = 0; i < n; ++i){
//         for(int j = 0; j < n; ++j){
//             d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//         }
//     }
// }

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

const int INF = 1e9;

int main(){
    vvi graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    int n = graph.size();
    vvi dist = graph;
    loop(k, 0, n){
        loop(i, 0, n){
            loop(j, 0, n){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    loop(i, 0, n){
        loop(j, 0, n){
            if(dist[i][j] == INF)
                cout << "I ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dist[1][3];
    return 0;
}