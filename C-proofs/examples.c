#include <stdio.h>
#include <stdlib.h>

// Hoare Logic Proofs
// Rules:
// {P}(set x exp){Q} => {Q[x/exp]}(set x exp){Q}
// {P}(iif B stmt1 stmt2){Q} => {P and B}stmt1{Q}, {P and not B}stmt2{Q}
/* 
    {P}(while B stmt ...){P}
    {P}
    (while B){
        {P and B}
        ...
    }
    {P}
*/

// 1. sum of an array
// length = length of array
// result = sum(0,length)
int sumArray(int arr[], int length){
    // length >= 1
    // sum(0,0) = 0
    int i = 0;
    // length >= i + 1
    // sum(0,i) = 0
    int sum = 0;
    // length >= i + 1
    // sum(0,0) = 0
    // invariant: sum = sum(0, i)
    while(i != length){
        // i != length
        // sum = sum(0, i)
        // sum = sum(0,i + 1) - a[i]
        sum += arr[i];
        // sum = sum(0, i+1)
        i = i + 1;
        // sum = sum(0, i)
    }
    // i == length 
    // invariant: sum = sum(0, i)
    // sum = sum(0, length)
    return sum;
}
// post-condition: sumArray(int arr[], int length) returns the sum of all elements in arr[]

// 2. sum of a list
struct Node {
    int data;
    struct Node* next;
};

// sum = sum(head, NULL)
int sumList(struct Node* head){
    // head != NULL
    struct Node* curr = head;
    // head != NULL, curr = head
    int sum = 0;
    // head != NULL, curr = head, sum = 0
    // invariant: sum = sum(head, curr)
    while(curr != NULL){
        // sum = sum(head, curr)
        int data = curr->data;
        // sum = sum(head,curr), data = curr->data
        sum = sum + data;
        // sum = sum(head, curr->next), data = curr->data
        curr = curr->next;
        // sum = sum(head, curr), data = curr->data
    }
    // curr = NULL
    // sum = sum(head, curr) = sum(head, NULL)
    return sum;
}

// 3. Count number of digits in the int (Corrected)
// i = total number of digits
int countDigits(int n){
    // n >= 0
    int count = 0;
    // count = 0, n >= 0, n = n
    int num = n;
    // count = 0, num = n

    // digits_of(num) = digits_of(n) = i
    // count = i - i = 0
    
    // invariant: count = i - digits_of(num)
    while(num != 0){
        // num != 0
        // count = i - digits_of(num) 
        // count = i - digits_of(num) - 1 + 1
        // count + 1 = i - digits_of(num) - 1
        count = count + 1;
        // count = i - digits_of(num) - 1
        // count = i - digits_of(num/10)
        num = num / 10;
        // count = i - digits_of(num)
    }
    // num == 0
    // count = i - digits_of(num) 
    // digits_of(num) = 0 
    // count = i - 0
    // count = i

    // count = i
    // i = digits_of(n)
    // count = digits_of(n)
    return  count;
}
// post-condition: count = digits_of(n)

// 5. Factorial
// pre-condition: n > 0
int factorial(int n){
    // n > 0
    // 0! = 1
    // (1-1)! = 1
    int i = 1;
    // (i-1)! = 1
    int fact = 1;
    // (i-1)! = fact
    // invariant: fact = (i-1)!
    while(i != n + 1){
        // i != n + 1
        // fact = (i-1)!
        // fact = (i*(i-1)!)/i
        fact = fact * i;
        // fact = (i*(i-1)!)
        // fact = i!
        i = i + 1;
        // fact = (i-1)!
    }
    // i == n + 1
    // fact = (i - 1)!
    // fact = (n + 1 - 1)!
    // fact = n!
    return fact;
}
// post-condition: factorial(n) returns n!

// 6. C3: isqrt(int n)
// pre-condition:
// n >= 0
// no-overflow
int isqrt(int n){
    // 0*0 <= n
    int i = 0;
    // i*i <= n
    // invariant: i*i < n+1
    while(i*i < n){
        // i*i < n
        // (i + 1)(i + 1) <= n < n + 1
        i = i + 1;
        // i*i <= n < n + 1
        // i*i < n + 1
    }
    // i*i >= n
    // i*i < n + 1
    // n <= i*i < n + 1
    return i;
}
// post-condition: gives the integer that is sqrt of n

// pre-condition:
// n >= 0
// no-overflow
int my_isqrt(int n){
    // 0*0 <= n
    int i = 0;
    // i*i <= n
    // invariant: i*i < n+1
    while(i*i < n){
        // i*i < n
        // (i + 1)(i + 1) <= n < n + 1
        i = i + 1;
        // i*i <= n < n + 1
        // i*i < n + 1
    }
    // i*i >= n
    // i*i < n + 1
    // n <= i*i < n + 1
    int res;
    // n <= i*i < n + 1
    if(i * i == n){
        // i * i == n
        res = i;
        // res * res == n
    }
    else{
        // i * i > n
        res = -1;
        // -1 = n is not perfect square
    }
    // res = i | -1
    return res;
}
// post-condition: gives the integer that is sqrt of n otherwise returns -1

struct Posn {
    int x;
    int y;
};

// 7. C4: Find all integer pairs (i,j) such that i^2 + j^2 = n^2
//        Given an array to store the pairs
// pre-condition:
// - array is empty
// - n >= 0 
struct Posn* sumsqrt(struct Posn a[], int n){
    // length > -1
    int i = 0;
    // length > (i - 1)
    // n >=0 => n + 1 > 0
    // 0^2 <= n < n + 1
    int x = 0;
    // x^2 <= n < n + 1
    // x^2 < n + 1
    while(x*x <= n){
        // x^2 <= n
        // x^2 < n + 1
        // n - x^2 >= 0
        int y = n - x^2;
        // x^2 <= n, x^2 < n + 1, y >= 0
        // sqrt(y) >= 0(if integer) | sqrt(y) == -1
        int res = isqrt(y);
        // res >= 0(if integer) | res == -1
        if(res != -1){
            // res == sqrt(y)
            // res^2 == y
            // res^2 == n - x^2
            // x^2 + res^2 == n
            // a[i] == Posn{x,res}
            a[i].x = x;
            // a[i] == Posn{a[i]->x,res}
            a[i].y = res;
            // a[i] == Posn{a[i]->x, a[i]->y}
            // length == i
            // 
        }
        else{
            // res == -1
            // Need to finish, will do later
        }
    }
}

// C6: find prime factors
// pre-conditon:
// n >= 2
// - array is empty
int* prime_factors(int a[], int n){
    // n >= 2
    // 
}

// Fibonacci (general)
// pre-condition:
// n > 0
int fibonacci(int n){
    // n > 0
    int i = n;
    // i > 0
    
    // 0 = 0
    int temp = 0;
    // temp = 0

    // 0 + 1 = 1        (fib(1))
    int fmj = 1;
    // 0 + fmj = 1
    int fmj1 = 0;
    // fmj1 + fmj = 1

    // fib(0) + fib(1) = 1  {fmj = fib(1), fmj1 = fib(0)}
    // invariant: fmj = fib(n - i + 1), fmj1 = fib(n - i)
    while(i != 1){
        // i != 1
        // fmj = fib(n - i + 1), fmj1 = fib(n - i)
        temp = fmj;
        // temp = fib(n - 1 + 1), fmj = fib(n - i + 1), fmj1 = fib(n - i)
        // fmj + fmj1 = fib(n - i + 1) + fib(n - 1)
        fmj = fmj + fmj1;
        // temp = fib(n - 1 + 1), fmj = fib(n - i + 1) + fib(n - i), fmj1 = fib(n - i)
        // temp = fib(n - 1 + 1), fmj = fib(n - i + 2), fmj1 = fib(n - i)
        fmj1 = temp;
        // fmj1 = fib(n - i + 1), fmj = fib(n - i + 2)
        // fmj1 = fib(n - (i - 1)), fmj = fib(n - (i - 1) + 1)
        i = i - 1;
        // fmj = fib(n - i + 1), fmj1 = fib(n - i)
    }
    // i == 1
    // fmj = fib(n - i + 1), fmj1 = fib(n - i)
    // fmj = fib(n - 1 + 1), fmj1 = fib(n - 1)
    // fmj = fib(n), fmj1 = fib(n - 1)

    // fmj = fib(n), fmj1 = fib(n - 1)
    return fmj;
}
// post-condition: The function returns fib(n) as the result.


// Linear Search (low-search)
// Pre: 
// - n is the length of A
// - 0<=i<=n, minimum A[i]>=n
int linearSearch(int A[], int key, int n){
    
}

// Lowsearch (Prabhav Khera)
// Pre:
// all (i,j) i < j ==> A[i] <= A[j]
// n is the length of A
int lowsearch(int A[], int key, int n){
    // all (i,j) i < j ==> A[i] <= A[j]
    // all i > -1 A[i+1] < key  (vacous)
    // all j < n  A[j] >= key   (vacous)
    // 0 <= n                   (tautology)
    int low =-1;
    // all (i,j) i < j ==> A[i] <= A[j]
    // all i > low A[i+1] < key  
    // all j < n  A[j] >= key   
    // low <= n
    int high = n;
    // all (i,j) i < j ==> A[i] <= A[j]
    // all i > low A[i+1] < key     
    // all j < high  A[j] >= key    
    // low <= high
    while(high != low + 1){
    // all (i,j) i < j ==> A[i] <= A[j]
    // all i > low A[i+1] < key     
    // all j < high  A[j] >= key    
    // low <= high
    // high != low + 1
    // low <= (low + high)/2 <= high
        int mid = (high + low)/2;
        // mid = (high + low)/2
       
        if(A[mid]>=key){
            
            high = mid;
            
        }
        else{
            
            low = mid;
            
        }
        
    }

    return high;
}
