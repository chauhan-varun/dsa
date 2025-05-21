### Explanation of Operator Overloading:
Operator overloading in C++ allows you to redefine the behavior of operators (like `+`, `==`, `<<`, etc.) for user-defined types (classes or structs). This makes it possible to use operators with objects in a way that is intuitive and similar to built-in types.

### Key Points:
1. **What Can Be Overloaded**:
   - Most operators can be overloaded, such as `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `<<`, `>>`, etc.
   - Overloading is done using the `operator` keyword.

2. **What Cannot Be Overloaded**:
   - The following operators cannot be overloaded:
     - `::` (Scope resolution operator)
     - `.` (Member access operator)
     - `.*` (Pointer-to-member operator)
     - `sizeof` (Size operator)
     - `typeid` (Type information operator)

3. **Syntax**:
   - Operator overloading is implemented as a member function or a friend function.
   - For binary operators (e.g., `+`), the left-hand operand is the calling object, and the right-hand operand is passed as an argument.

---

### Example Program: Overloading `+`, `==`, and `<<` for a `Complex` Class

Here is a program that demonstrates operator overloading for a `Complex` class:

```cpp
#include <iostream>
using namespace std;

// Class definition for Complex numbers
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator to add two Complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload == operator to compare two Complex numbers
    bool operator==(const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Overload << operator to display a Complex number
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    // Create two Complex numbers
    Complex c1(3, 4);
    Complex c2(1, 2);

    // Add the two Complex numbers using the overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result using the overloaded << operator
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;

    // Compare two Complex numbers using the overloaded == operator
    if (c1 == c2) {
        cout << "c1 and c2 are equal." << endl;
    } else {
        cout << "c1 and c2 are not equal." << endl;
    }

    return 0;
}
```

---

### Explanation of the Code:
1. **Overloading `+`**:
   - The `+` operator is overloaded as a member function.
   - It takes another `Complex` object as an argument and returns a new `Complex` object with the sum of the real and imaginary parts.

2. **Overloading `==`**:
   - The `==` operator is overloaded as a member function.
   - It compares the real and imaginary parts of two `Complex` objects and returns `true` if they are equal, otherwise `false`.

3. **Overloading `<<`**:
   - The `<<` operator is overloaded as a friend function.
   - It allows the `ostream` object (`cout`) to access the private members of the `Complex` class and display the object in a readable format.

---

### Example Input/Output:
#### Output:
```
c1: 3 + 4i
c2: 1 + 2i
c1 + c2 = 4 + 6i
c1 and c2 are not equal.
```

---

### Notes:
- **Binary Operators** (e.g., `+`, `-`, `*`, `/`) can be overloaded as member or friend functions.
- **Stream Operators** (`<<`, `>>`) must be overloaded as friend functions because the left-hand operand (`cout` or `cin`) is not a member of the class.
- Overloading makes the code more intuitive and easier to read, especially when working with custom types.