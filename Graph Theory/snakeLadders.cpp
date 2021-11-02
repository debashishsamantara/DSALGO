//The game of snake and ladder.
//You are at square 1 and have to reach sqare 100. You have complete control over the die and can get any number from 1 - 6.
//For given ladders and snakes, find the minimum steps to reach.

//Idea
//1. BFS
//2. Push 1 into the queue,
//      For all possibilities in the dice:
//          Check if the next position is ladder, snake or empty.
//          Mark the square as visited and push into queue.
//3. Stop the traversal, when you reached 100.

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

int main(){
    int ladders, snakes;
    cin >> ladders;
    map<int, int> lad;
    map<int, int> snak;
    loop(i, 0, ladders){
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }
    cin >> snakes;
    loop(i, 0, snakes){
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }
    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vi visited(101, 0);
    visited[1] = true;
    while(!q.empty() and !found){
        int sz = q.size();
        while(sz--){
            int t = q.front();
            q.pop();
            loop(die, 1, 7){
                if(t + die == 100)
                    found = true;
                if(t + die <= 100 and lad[t+die] and !visited[lad[t + die]]){
                    visited[lad[t + die]] = true;
                    if(lad[t + die] == 100)
                        found = true;
                    q.push(lad[t + die]);
                }else if(t + die <= 100 and snak[t + die] and !visited[snak[t + die]]){
                    visited[snak[t + die]] = true;
                    if(snak[t + die] == 100)
                        found = true;
                    q.push(snak[t + die]);
                }else if(t + die <= 100 and !visited[t + die] and !snak[t + die] and !lad[t + die]){
                    visited[t + die] = true;
                    q.push(t + die);
                }
            }
        }
        moves++;
    }
    if(found)
        cout << moves;
    else
        cout << "-1";
    return 0;
}