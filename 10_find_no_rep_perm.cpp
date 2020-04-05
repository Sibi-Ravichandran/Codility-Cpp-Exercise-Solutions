/*
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
*/
// ******************************************************************************************************


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // Check if min element is 1 and max element = size:
    int min=A[0];
    int max=A.size();
    for (uint i=0;i<A.size();i++)
    {
        if (min>A[i]) min=A[i];
        if (max<A[i]) max=A[i];
    }
    
    if (min!=1) return 0;
    if (uint(max)!=A.size()) return 0;
    
    // check for duplicate elements and find if sums are equal::
    vector <int> hash (A.size()+1,0);
    int sum=(A.size()*(A.size()+1))/2;
    int sum1=0;
    for (uint i=0;i<A.size();i++)
    {
        if (hash[A[i]]==1)
            return 0;
        else
        {
             sum1+=A[i];
             hash[A[i]]++;
        }
    }
    return (sum1==sum);
}

