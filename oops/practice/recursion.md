Here is the C++ program that calculates the factorial of a number using recursion:

```cpp
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Base case: factorial of 0 or 1 is 1
    }
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << num << " is " << factorial(num) << endl;
    }

    return 0;
}
```

---

### Explanation of Recursion in the Program:
1. **What is Recursion?**
   - Recursion is a process where a function calls itself to solve a smaller instance of the same problem.
   - It consists of two main parts:
     - **Base Case**: The condition under which the recursion stops.
     - **Recursive Case**: The part where the function calls itself with a smaller input.

2. **How Recursion Works in This Program**:
   - **Base Case**:
     - If `n == 0` or `n == 1`, the function returns `1` because the factorial of `0` or `1` is `1`.
   - **Recursive Case**:
     - For `n > 1`, the function calculates \( n \times \text{factorial}(n - 1) \).
     - This continues until the base case is reached.

3. **Example Execution**:
   - Suppose `num = 5`. The function calls proceed as follows:
     ```
     factorial(5) = 5 * factorial(4)
     factorial(4) = 4 * factorial(3)
     factorial(3) = 3 * factorial(2)
     factorial(2) = 2 * factorial(1)
     factorial(1) = 1 (base case)
     ```
   - The results are then returned step by step:
     ```
     factorial(2) = 2 * 1 = 2
     factorial(3) = 3 * 2 = 6
     factorial(4) = 4 * 6 = 24
     factorial(5) = 5 * 24 = 120
     ```

4. **Output**:
   - For input `5`, the output will be:
     ```
     Enter a number to calculate its factorial: 5
     Factorial of 5 is 120
     ```

---

### Key Points:
- **Base Case** ensures the recursion terminates.
- **Recursive Case** reduces the problem size in each step.
- Recursion is elegant but can be less efficient for large inputs due to function call overhead and stack usage. For such cases, an iterative approach may be preferred.---

### Key Points:
- **Base Case** ensures the recursion terminates.
- **Recursive Case** reduces the problem size in each step.
- Recursion is elegant but can be less efficient for large inputs due to function call overhead and stack usage. For such cases, an iterative approach may be preferred.

Similar code found with 1 license type