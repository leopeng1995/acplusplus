### 尾递归 Tail Recursion

#### What is tail recursion?

A recursive function is tail recursive when recursive call is the last thing executed by the function. For example the following C++ function `print()` is tail recursive.

```
// An example of tail recursive function
void print(int n) {
	if (n < 0)  return;
	cout << " " << n;

    // The last executed statement is recursive call
    print(n - 1);
}

```

#### Why do we care?

The tail recursive functions considered better than non-tail recursive functions as tail-recursion can be optimized by compiler. The idea used by compilers to optimize tail-recursive functions is simple, since the recursive call is the last statement, there is nothing left to do in the current function, so saving the current function’s stack frame is of no use.

#### Can a non-tail recursive function be written as tail-recursive to optimize it?

Consider the following function to calculate factorial of n. It is a non-tail-recursive function. Although it looks like a tail recursive at first look. If we take a closer look, we can see that the value returned by fact(n - 1) is used in fact(n), so the call to fact(n - 1) is not the last thing done by fact(n).

```
// A NON-tail-recursive function.  The function is not tail
// recursive because the value returned by fact(n-1) is used in
// fact(n) and call to fact(n-1) is not the last thing done by fact(n)
unsigned int fact(unsigned int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
```

The above function can be written as a tail recursive function. The idea is to use one more argument and accumulate the factorial value in second argument. When n reaches 0, return the accumulated value.

```
// A tail recursive function to calculate factorial
unsigned factTR(unsigned int n, unsigned int a) {
  if (n == 0)  return a;
  return factTR(n - 1, n * a);
}

// A wrapper over factTR
unsigned int fact(unsigned int n) {
  return factTR(n, 1);
}
```

### Tail Call Elimination

```
// Above code after tail call elimination
void print(int n) {
start:
	if (n < 0) return;
	cout << " " << n;

	// Update parameters of recursive call
	// and replace recursive call with goto
	n = n - 1
	goto start;
}
```

QuickSort消除尾递归：QuickSort is also tail recursive (Note that MergeSort is not tail recursive, this is also one of the reason why QuickSort performs better).

Therefore job for compilers is to identify tail recursion, add a label at the beginning and update parameter(s) at the end followed by adding last goto statement.

```
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
       at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
```

```
void quickSort(int arr[], int low, int high) {
start:
  if (low < high) {
    /* pi is partitioning index, arr[p] is now
       at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);

    low = pi + 1;
    high = high;
    goto start;
  }
}
```