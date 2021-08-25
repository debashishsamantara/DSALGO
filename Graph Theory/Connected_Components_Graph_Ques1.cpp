//There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other.
//You are given information in the form of M pairs (X, Y) i.e., there is an link between friend X and Y.
//Find out the number of ways in which 2 persons from different groups can be chosen.

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

vector<bool> visited;
int n, m;
vvi adj;
vi components;

int get_comp(int idx){
    if(visited[idx])
        return 0;
    visited[idx] = true;
    int ans = 1;
    for(auto i : adj[idx]){
        if(!visited[i]){
            ans += get_comp(i);
            visited[i] = true;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    adj = vvi(n);
    visited = vector<bool>(n);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i, 0, n){
        if(!visited[i])
            components.push_back(get_comp(i));
    }
    for(auto i : components){
        cout << i << " ";
    }
    cout << endl;
    long long ans = 0;
    for(auto i : components)
        ans += i*(n-i);
    cout << "No of ways in which 2 persons from different groups can be chosen:" << (ans/2);
}