/* Write a function:

int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

{ i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:

A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B. */

// ******************************************************************************************************

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)
    
    int count=0;
    if (A==B)
    {
        if ((A%K)==0) count++;
    }
    else
    {
        int start=A,end=B,dist=K;
        
        // Find the first number in the series that is divisible by K:
        if ((start%K)!=0)
            start+=(K-(start%K));
            
         // Find the last number in the series that is divisible by K:
        if ((end%K)!=0)
            end-=(end%K);
            
        // Use the Arithemetic progression formula: A(n)=a+(n-1)d
        count=((end-start)/dist)+1;
    }
    return count;   
}
