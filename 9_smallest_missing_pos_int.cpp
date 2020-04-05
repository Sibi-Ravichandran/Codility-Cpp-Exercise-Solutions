/* Write a function:

int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

// ******************************************************************************************************


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // find the max element in given vector:
    int max=0;
    for (uint i=0;i<A.size();i++)
        if (A[i]>max)
            max=A[i];
    
    // Create a vector of size max and populate it
    vector <int> hash (max,0);
    for (uint i=0;i<A.size();i++)
        if (A[i]>0)
            hash[A[i]-1]++;

    // if any element in the hash equals zero then it is the missing number:
    for (uint i=0;i<hash.size();i++)
    {
        if (hash[i]==0)
            return i+1;
    }
    
    // if no element in the hash equals 0, then return max element in the given array+1
    return max+1;
}