#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Solves the 0/1 Knapsack problem using dynamic programming and returns
 * a binary vector indicating which items were selected.
 * 
 * @param M: Maximum capacity of the knapsack
 * @param n: Number of items
 * @param wt: Array of weights (1-indexed, size n+1)
 * @param p: Array of profits (1-indexed, size n+1)
 * @return: A binary vector of size n where 1 means item i was included, 0 otherwise
 */
vector<int> solveKnapsack(int M, int n, int wt[], int p[]) {
  // Create a 2D DP table initialized to 0
  vector<vector<int>> K(n + 1, vector<int>(M + 1, 0));

  // Build the DP table in bottom-up manner
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= M; w++) {
      if (i == 0 || w == 0) {
        K[i][w] = 0;
      } else if (wt[i] <= w) {
        K[i][w] = max(p[i] + K[i - 1][w - wt[i]], K[i - 1][w]);
      } else {
        K[i][w] = K[i - 1][w];
      }
    }
  }

  // Print maximum profit
  cout << "Maximum Profit = " << K[n][M] << endl;

  // Backtracking to find which items were selected
  vector<int> selected(n, 0);
  int i = n, j = M;
  while (i > 0 && j > 0) {
    // If the value comes from the item being included
    if (K[i][j] != K[i - 1][j]) {
      selected[i - 1] = 1; // Mark item as selected (0-indexed for the vector)
      j = j - wt[i];       // Reduce remaining capacity
    }
    i--;
  }

  return selected;
}

int main() {
  // Profit array (using 1-based indexing as per user's style)
  int p[5] = {0, 1, 2, 5, 6};

  // Weight array (using 1-based indexing)
  int wt[5] = {0, 2, 3, 4, 5};

  int M = 8; // Capacity of knapsack
  int n = 4; // Number of items

  // Solve the problem and get the selection vector
  vector<int> selection = solveKnapsack(M, n, wt, p);

  // Print the resulting 0/1 vector
  cout << "Selected items (0/1 vector): [ ";
  for (int x : selection) {
    cout << x << " ";
  }
  cout << "]" << endl;

  return 0;
}
