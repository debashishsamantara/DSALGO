//Leading Element / Parent
//Element which can be regarded as the leader element for that set.
//Ex - S = {1, 2, 3, 4} Leader = 2
//So, Parent[1] = Parent[2] = Parent[3] = Parent[4] = 2 = used to identify the set.
//Abbr. = DSU
//This simple optimisation reduces the time complexity from O(n) to O(log(n))
//Union by Size/Rank :- Final time complexity will be O(α(n)) {α(n) - Inverse Ackerman Function}
//Conclusion - Disjoint Set Union is O(1) time complexity and O(n) space complexity

//Applications
//-MST (Minimum Spanning Tree)
//-Connected Components in Graph
//-Cycle detection and many more