#include <stdio.h>

// 5. Lowsearch (Hans Sun Template)
// pre:
// all  (i,j)  has  i < j ==> A[i] <= A[j] // definition of being sorted
// n  is length of  A
int lowsearch(int A[], int key, int n)
{
    // all  (i,j)  has  i < j ==> A[i] <= A[j]
    // n  is length of  A

    // all  (i,j)  has  i < j ==> A[i] <= A[j]
    // all  i < 0  has  A[i] < key              (by 1, 2; vacuous)
    // all  j >= n  has  A[j] >= key            (by 1, 2; vacuous)
    // 0 <= n                                   (tautology)
    int low = 0;
    // all  (i,j)  has  i < j ==> A[i] <= A[j]
    // all  i < low  has  A[i] < key
    // all  j >= n  has  A[j] >= key
    // low <= n
    int high = n;
    // all  (i,j)  has  i < j ==> A[i] <= A[j]
    // all  i < low  has  A[i] < key
    // all  j >= high  has  A[j] >= key
    // low <= high
    while (low < high)
    {
        // all  (i,j)  has  i < j ==> A[i] <= A[j]
        // all  i < low  has  A[i] < key
        // all  j >= high  has  A[j] >= key
        // low <= high
        // low < high

        // all  (i,j)  has  i < j ==> A[i] <= A[j]
        // all  i < low  has  A[i] < key
        // all  j >= high  has  A[j] >= key
        // low <= (low + high) / 2 < high            (by 5)
        int mid = (low + high) / 2;
        // all  (i,j)  has  i < j ==> A[i] <= A[j]
        // all  i < low  has  A[i] < key
        // all  j >= high  has  A[j] >= key
        // low <= mid < high
        if (A[mid] < key)
            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < low  has  A[i] < key
            // all  j >= high  has  A[j] >= key
            // low <= mid < high
            // A[mid] < key

            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < mid + 1  has  A[i] < key        (by 1, 5)
            // all  j >= high  has  A[j] >= key
            // mid + 1 <= high                          (by 4)
            low = mid + 1;
            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < low  has  A[i] < key
            // all  j >= high  has  A[j] >= key
            // low <= high
        else
            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < low  has  A[i] < key
            // all  j >= high  has  A[j] >= key
            // low <= mid < high
            // key <= A[mid]

            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < low  has  A[i] < key            (by 1, 5)
            // all  j >= mid  has  A[j] >= key
            // low <= mid                               (by 4)
            high = mid; 
            // all  (i,j)  has  i < j ==> A[i] <= A[j]
            // all  i < low  has  A[i] < key
            // all  j >= high  has  A[j] >= key
            // low <= high
        // all  (i,j)  has  i < j ==> A[i] <= A[j]
        // all  i < low  has  A[i] < key
        // all  j >= high  has  A[j] >= key
        // low <= high
    }
    // all  (i,j)  has  i < j ==> A[i] <= A[j]
    // all  i < low  has  A[i] < key
    // all  j >= high  has  A[j] >= key
    // low <= high
    // high <= low

    // all  i < low  has  A[i] < key
    // all  j >= high  has  A[j] >= key
    // low = high                                   (by 4, 5)

    // all  i < low  has  A[i] < key
    // all  j >= low  has  A[j] >= key              (by 3)

    // low  is minimum index  i  so  A[i] >= key    (by 1, 2)
    return low;
}
// post: lowsearch(A, key, n)  is minimum index  i  so  A[i] >= key