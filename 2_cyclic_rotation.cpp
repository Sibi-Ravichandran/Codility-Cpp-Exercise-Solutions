/* An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.*/

// ************************************************************************************************

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
 
	// If the shift value is 0, return the input as it is:
    if (K==0)
        return A;
	// if array size is 0, return the input as it is: 
    else if (A.size()==0)
        return A;
	// else rotate the array A by K times and return it:
    else
    {
	    // Rotate the array k times: 
        for (int i=0;i<K;i++)
        {
            int temp=A[A.size()-1];
            for (int i=A.size()-1;i>0;i--)
            {
                A[i]=A[i-1];
            }
            A[0]=temp;
        }
    }
    return A;
 