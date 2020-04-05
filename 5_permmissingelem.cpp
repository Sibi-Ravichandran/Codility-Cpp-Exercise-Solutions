/* An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.*/

// ******************************************************************************************************

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
	// find the sum of N-series:
    int output=(A.size()*(A.size()+1))/2;
	// if array is empty return 1:
    if (A.size()==0)    
        return 1;
    else 
    {
        int sum_of_given=0;
        for (uint i=0;i<A.size();i++)
            sum_of_given+=A[i];
        output=(A.size()-(abs(sum_of_given-output)))+1;
    }
    return output;
}

