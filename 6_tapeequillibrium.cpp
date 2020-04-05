/* A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7 */

// ******************************************************************************************************

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    if (A.size()==2)
        return abs(A[1]-A[0]);
    else
    {
        int diff=10001;
        vector <int> sum_left(A.size(),0);
        vector <int> sum_right(A.size(),0);
        int sum1=0,sum2=0;
        for (uint i=0,j=A.size()-1;(i<A.size()&&j>=0);i++,j--)
        {
            sum1+=A[i];
            sum2+=A[j];
            sum_left[i]=sum1;
            sum_right[i]=sum2;
        }
        for (uint i=0,j=A.size()-2;((i<A.size()-1)&&j>=0);i++,j--)
        {
            if (diff>abs(sum_left[i]-sum_right[j]))
                diff=abs(sum_left[i]-sum_right[j]);
        }
        return diff;
    }
    return 0;
}
