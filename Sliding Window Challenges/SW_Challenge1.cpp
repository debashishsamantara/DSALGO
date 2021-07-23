// Max sum subarray of size = K and sum < X

// For a given array and integers K and X, find the maximum sum subarray of size K and having sum less than X.

// Approach 1 - Compute sum of all subarrays of size K
// Time Complexity = O(n*k) (Very bad, will take very long time to calculate ans)

// Approach 2 - Sliding Window with two pointers
// 1. Calculate sum of first K elements
// 2. Intialize ans with this sum
// 3. Iterate over the rest of the arr. Keep adding one element in sum and removing one from start. Compare new sum with ans in each iteration.
// Time Complexity - O(n)

