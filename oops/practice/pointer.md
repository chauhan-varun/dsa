The reason `a` ends up with the value `20` is due to the sequence of operations in the `change` function. Let me explain step by step:

### Step-by-Step Execution:

1. **Initial State in `main`**:
   - `a = 5`, `b = 6`.
   - `&a` (address of `a`) and `&b` (address of `b`) are passed to the `change` function.

2. **Inside `change` Function**:
   - `p` points to `a` (because `p = &a`).
   - `q` points to `b` (because `q = &b`).

3. **First Operation: `*p = 10;`**:
   - `*p` means "the value at the address `p` points to."
   - Since `p` points to `a`, this sets `a = 10`.

4. **Second Operation: `q = p;`**:
   - `q` is now made to point to the same address as `p` (which is the address of `a`).
   - This change is **local to the function** and does not affect the original pointer `q` in `main`.

5. **Third Operation: `*q = 20;`**:
   - `*q` means "the value at the address `q` points to."
   - Since `q` now points to the same address as `p` (which is the address of `a`), this sets `a = 20`.

6. **Returning to `main`**:
   - The value of `a` is now `20` because it was modified twice in the `change` function (`*p = 10` and `*q = 20`).
   - The value of `b` remains `6` because the original pointer `q` in `main` was not affected by the local change to `q` in the `change` function.

### Key Point:
The reason `a` becomes `20` is that both `p` and `q` end up pointing to `a` inside the `change` function, and the value at that address is modified twice.

### Final Output:
```
20 6
```