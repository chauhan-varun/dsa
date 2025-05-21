Here is a concise explanation of the requested topics with examples:

---

### 1. **If-Else Statement**
The `if-else` statement is used to execute a block of code based on a condition.

#### Syntax:
```cpp
if (condition) {
    // Code to execute if condition is true
} else {
    // Code to execute if condition is false
}
```

#### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num % 2 == 0) {
        cout << num << " is even." << endl;
    } else {
        cout << num << " is odd." << endl;
    }

    return 0;
}
```

---

### 2. **Switch Case**
The `switch` statement is used to execute one block of code out of many based on the value of a variable.

#### Syntax:
```cpp
switch (expression) {
    case value1:
        // Code for case value1
        break;
    case value2:
        // Code for case value2
        break;
    default:
        // Code if no case matches
}
```

#### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter a day number (1-7): ";
    cin >> day;

    switch (day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
        default: cout << "Invalid day number!";
    }

    return 0;
}
```

---

### 3. **Ternary Operator**
The ternary operator is a shorthand for `if-else` statements.

#### Syntax:
```cpp
condition ? expression1 : expression2;
```

#### Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    string result = (num % 2 == 0) ? "Even" : "Odd";
    cout << num << " is " << result << "." << endl;

    return 0;
}
```

---

### 4. **Iterative Statements**
Iterative statements (loops) are used to execute a block of code repeatedly.

#### Types:
1. **For Loop**:
   ```cpp
   for (initialization; condition; increment/decrement) {
       // Code to execute
   }
   ```
   Example:
   ```cpp
   for (int i = 1; i <= 5; i++) {
       cout << i << " ";
   }
   ```

2. **While Loop**:
   ```cpp
   while (condition) {
       // Code to execute
   }
   ```
   Example:
   ```cpp
   int i = 1;
   while (i <= 5) {
       cout << i << " ";
       i++;
   }
   ```

3. **Do-While Loop**:
   ```cpp
   do {
       // Code to execute
   } while (condition);
   ```
   Example:
   ```cpp
   int i = 1;
   do {
       cout << i << " ";
       i++;
   } while (i <= 5);
   ```

---

### Summary:
- **If-Else**: Conditional branching.
- **Switch Case**: Multi-way branching.
- **Ternary Operator**: Shorthand for `if-else`.
- **Iterative Statements**: Repeated execution of code (loops).

Similar code found with 1 license type