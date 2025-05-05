### ⚡ Quick Sort in C++

This repo contains a simple **Quick Sort** implementation in C++. It uses a modified partitioning logic and sorts an array in-place.

---

### 📌 What is Quick Sort?

Quick Sort is a popular **divide and conquer** sorting algorithm. It works by selecting a **pivot**, then partitioning the array such that:

* Elements less than or equal to the pivot go to the left
* Elements greater than the pivot go to the right

It recursively sorts the left and right subarrays.

---

### 🧠 Algorithm

#### **Function: `partitionn(l, h)`**

1. Choose the leftmost element as the pivot (`arr[l]`).
2. Initialize `i = l`, `j = h`.
3. Increment `i` while `arr[i] <= pivot`.
4. Decrement `j` while `arr[j] > pivot`.
5. If `i < j`, swap `arr[i]` and `arr[j]`.
6. After the loop, swap `arr[l]` and `arr[j]` (put pivot in the correct place).
7. Return `j` (final position of pivot).

#### **Function: `quicksort(l, h)`**

1. If `l < h`, partition the array and get the pivot index.
2. Recursively sort the two subarrays divided by the pivot.

---

### ⏱️ Time & Space Complexity

| Case       | Time Complexity | Space Complexity |
| ---------- | --------------- | ---------------- |
| Best Case  | O(n log n)      | O(log n) (stack) |
| Average    | O(n log n)      | O(log n)         |
| Worst Case | O(n²)           | O(log n)         |

Worst case occurs when the smallest or largest element is always chosen as pivot (like for already sorted arrays).

---

### 💻 Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int arr[100];

int partitionn(int l, int h) {
    int i = l, j = h;
    int pivot = arr[l];

    while(i < j) {
        while(arr[i] <= pivot && i <= h) i++;
        while(arr[j] > pivot && j >= l) j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quicksort(int l, int h) {
    if(l < h) {
        int j = partitionn(l, h);
        quicksort(l, j - 1);
        quicksort(j + 1, h);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(0, n - 1);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
```

---

### 🛠️ How to Compile and Run

```bash
g++ quicksort.cpp -o quicksort
./quicksort
```

---

### 🧪 Example

**Input:**

```
5
3 7 2 9 1
```

**Output:**

```
1 2 3 7 9
```
