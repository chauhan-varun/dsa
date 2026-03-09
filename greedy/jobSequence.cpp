#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// A structure to represent a job
struct Job {
  // Job Id
  int id;
  // Deadline of job
  int dead;
  // Profit if job is completed before or on the deadline
  int profit;
};

class Solution {
public:
  // Comparator function to sort jobs in decreasing order of profit
  // Function to find the maximum profit and the number of jobs done
  //
  bool static cmp(Job j1, Job j2){
    return j1.profit > j2.profit;
  }
  pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, cmp);
    
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
      maxi = max(maxi , arr[i].dead);
    }

    vector<int> slot(maxi + 1, -1);

    int jobc = 0, jobp = 0;
    for(int i = 0; i<n; i++){
      for(int j = arr[i].dead; j>0; j--){
        if(slot[j]==-1){
          slot[j] = 1;
          jobc++;
          jobp+=arr[i].profit;
          break;
        }
      }
    }
    return {jobc, jobp};
  }
};

int main() {
  // Driver code
  int n = 4;
  // Define jobs with id, deadline, and profit
  Job arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

  Solution ob;
  // Function call to find the number of jobs done and total profit
  pair<int, int> ans = ob.JobScheduling(arr, n);

  // Output the number of jobs and the total profit
  cout << ans.first << " " << ans.second << endl;

  return 0;
}
