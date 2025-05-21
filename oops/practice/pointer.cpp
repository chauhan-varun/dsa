#include <iostream>
using namespace std;
void change(int *p, int *q)
{
    *p = 10;  // Dereferences pointer p and assigns the value 10 to the variable it points to.
    q = p;    // Makes q point to the same address as p (local to the function).
    *q = 20;  // Dereferences q (now pointing to the same address as p) and assigns the value 20.
}
int main()
{
    int a = 5, b = 6;
    change(&a, &b);
    cout << a << " " << b;

    return 0;
}