//Analisis de big-O de tres diferentes funciones para calcular la secuencia de fibonacci

#include <iostream>
#include <map>
#include "mytimer.h"
using namespace std;

// fib: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
// idx: 0, 1, 2, 3, 4, 5, 6,  7,  8,  9, 10
int fibonacci(int n)
{
    if (n < 0) // c1
        throw "illegal negative number";

    if (n < 2) // c2
        return n;
    
    return fibonacci(n-1) + fibonacci(n-2); 
    // T(n-1) * T(n-2) + 1
    // 2*T(n-1) = 2*2*T(n-2) .... 2^n*T(n-i)
    // O(2^n) es el orden de fibonacci
}

// memoized implementation
int fibonacci_v2(int n, map<int, int> &cache)
{
    if (n < 0) // c1
        throw "illegal negative number";
    
    if (n < 2) // c2
        return n;

    if (cache.find(n) != cache.end()) // c3
        return cache[n];

    int val = fibonacci_v2(n-1, cache) + fibonacci_v2(n-2, cache);
    //T(n) = T(n-1) + T(n-2)
    //Como f(n-2) ya estaría en el cache cuando se calcula f(n-1), f(n-2) sería de tiempo constante, osea 1
    //T(n) = T(n-1) + 1 = T(n-2) + 1 + 1 = ... = T(n-n) + n = T(0) + n = 1 + n 
    //T(n) = O(n+1) = O(n)
    //O(n) es el orden de fibonacci_v2
    cache[n] = val;
    return val;
    
}



int fibonacci_iter(int n)
{
    int a = 0, b = 1, fib = 0; // O(1)
    for (int i = 0; i < n-1; i++) // O(n)
    {
        fib = a + b; // c1 O(1)
        a = b;       // c2 O(1)
        b = fib;     // c3 O(1)
    }
    return fib;      // O(1)
}
// O(n) es el orden de fibonacci_iter

int main()
{
    int ans, nth;
    cout << "Enter an index for the Fibonacci sequence: ";
    cin >> nth;
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    ans = fibonacci(nth);
    STOP_TIMING(t1);
    cout << ans << endl;
    SHOW_TIMING(t1, "Fibonacci version 1");


    map<int, int> cache;
    DECLARE_TIMING(t2);
    START_TIMING(t2);
    int ans2 = fibonacci_v2(nth, cache);
    STOP_TIMING(t2);
    cout << ans2 << endl;
    SHOW_TIMING(t2, "Fibonacci version 2");

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    int ans3 = fibonacci_iter(nth);
    STOP_TIMING(t3);
    cout << ans3 << endl;
    SHOW_TIMING(t3, "Fibonacci version iter");

    return 0;
}
