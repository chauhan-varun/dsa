#include <bits/stdc++.h>
#include <climits>
using namespace std;

// Number of cities in the problem
#define N 4

/**
 * Adjacency matrix representing the distance between cities.
 * graph[i][j] is the cost to travel from city i to city j.
 */
int graph[N][N] = {
    {0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};

/**
 * DP Table for memoization.
 * dp[mask][pos] stores the minimum cost to visit all remaining cities
 * given that the current set of visited cities is represented by 'mask'
 * and the current city is 'pos'.
 */
int dp[1 << N][N];

/**
 * Function to solve TSP using Dynamic Programming and Bitmasking.
 * 
 * @param mask: A bitmask where the i-th bit is 1 if city i has been visited.
 * @param pos: The index of the current city we are at.
 * @return: The minimum cost to complete the tour from the current state.
 */
int tsp(int mask, int pos) {
  // BASE CASE: If all cities have been visited (all bits in mask are 1)
  // (1 << N) - 1 creates a bitmask with N ones (e.g., for N=4, it's 1111 in binary)
  if (mask == ((1 << N) - 1)) {
    // Return to the starting city (city 0)
    return graph[pos][0];
  }

  // MEMOIZATION: If the result for this state is already calculated, return it
  if (dp[mask][pos] != -1) {
    return dp[mask][pos];
  }

  int ans = INT_MAX;

  // Try to visit every city that hasn't been visited yet
  for (int city = 0; city < N; city++) {
    
    // Check if the 'city' has NOT been visited (if the i-th bit in mask is 0)
    if ((mask & (1 << city)) == 0) {
      
      // Calculate the cost to visit 'city' + recursive cost for remaining cities
      // (mask | (1 << city)) updates the mask to mark 'city' as visited
      int newAns = graph[pos][city] + tsp(mask | (1 << city), city);
      
      // Keep track of the minimum cost found
      ans = min(ans, newAns);
    }
  }

  // Store the result in the DP table and return it
  return dp[mask][pos] = ans;
}

int main() {
  // Initialize the DP table with -1 (meaning uncalculated)
  memset(dp, -1, sizeof(dp));

  /**
   * Start the tour from city 0.
   * mask = 1 (binary 0001) means city 0 is visited.
   * pos = 0 means we are currently at city 0.
   */
  cout << "Minimum Cost (TSP) = " << tsp(1, 0) << endl;

  return 0;
}
