//                        Maps                                    Unordered Maps
//                      ----------------------------------------------------------
//         Insertion -  O(log(n))                                O(1) {on average}
//         Accessing -  O(log(n))                                      O(1)
//         Deletion  -  O(log(n))                                      O(n)
// Implemented Using -  Red-Black Trees              Hashtables(basically array of buckets)
//              Map is a key value pair                       U-Map is a key value pair
//                  map<int, int> mp;                     unordered_map<int, int> ump;


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){
    map<int, int> m;
    m[8] = 2;
    cout << m[8] << endl;
}