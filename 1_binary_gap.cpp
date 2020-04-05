/* A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.*/

// ***************************************************************************************************************************
#include <vector>
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    // Count the number of binary digits:
    int no_of_bin_Digits=0;
    int temp=N;
    int output=0;
    while (temp>0)
    {
        temp/=2;
        no_of_bin_Digits++;
    }
    temp=N;
    
    // Create a vector and store the binary digits in it:
    vector <int> binary (no_of_bin_Digits,0);
    for (int i=binary.size()-1;i>=0;i--)
    {
        binary[i]=temp%2;
        temp/=2;
    }
    
    // Count the number of 1's in the vector:
    int count_1=0;
    for (int i=binary.size()-1;i>=0;i--)
    {
        if (binary[i]==1)
         count_1++;
    }
    
    // If the number of 1's is 1 then there will be no binary gaps so return 0:
    if (count_1==1) 
        return output;
    // Else iterate through the binary array and count the number of 0's in each binary gap
    else 
    {
        int count_0=0;
        for (int i=0;i<binary.size();i++)
        {
            // when 1 is encountered compare the previous and current number of 0's 
            if (binary[i]==1) 
            {
                if (count_0>output)
                    output=count_0;
                count_0=0;
            }
            // Else increment the counter
            else 
                count_0++;
        }
    }
    
    return output;
}
