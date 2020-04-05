/* A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1. */

// ******************************************************************************************************
// My solution: 

#include <map> 
#include <string>
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    
    // Empty map container:
    map<char, int> dna;
    // insert elements in map 
    dna.insert(pair<char, int>('A', 1));
    dna.insert(pair<char, int>('C', 2));
    dna.insert(pair<char, int>('G', 3));
    dna.insert(pair<char, int>('T', 4));
    
    // Create an int vector to store the impact factor of the given DNA:
    vector <int> dnaimpact (S.length(),0);
    for (uint i=0;i<S.length();i++)
        dnaimpact[i]=dna[S[i]];
    
    // Create an output vector:
    vector <int> output (P.size(),0);
    
    // Answer the queries:
    int min=5,itr=0;
    for (uint i=0;i<P.size();i++)
    {
        for (int j=P[i];j<=Q[i];j++)
        {
            if (min>dnaimpact[j])
            {
                min=dnaimpact[j];
                output[itr]=min;
            }
        }
        min=5;
        itr++;
    }
    return output;
}

// ******************************************************************************************************
// Solution - Passed timing tests:

#include <unordered_map>

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
 // write your code in C++11 (g++ 4.8.2)
 vector<int> pre_sum_A;
 vector<int> pre_sum_C;
 vector<int> pre_sum_G;
 
 int cnt_A = 0;
 int cnt_C = 0;
 int cnt_G = 0;
 
 for (size_t i = 0; i < S.size(); i++) {
 if (S[i] == 'A') cnt_A++;
 else if (S[i] == 'C') cnt_C++;
 else if (S[i] == 'G') cnt_G++;
 
        pre_sum_A.push_back(cnt_A);
        pre_sum_C.push_back(cnt_C);
        pre_sum_G.push_back(cnt_G);
    }
 
 vector<int> result(P.size());
 for (int i = 0; i < int(P.size()); i++) {
 int A = (S[P[i]] == 'A') ? 1 : 0;
 int C = (S[P[i]] == 'C') ? 1 : 0;
 int G = (S[P[i]] == 'G') ? 1 : 0;
 if (pre_sum_A[Q[i]] - pre_sum_A[P[i]] + A > 0) result[i] = 1;
 else if (pre_sum_C[Q[i]] - pre_sum_C[P[i]] + C > 0) result[i] = 2;
 else if (pre_sum_G[Q[i]] - pre_sum_G[P[i]] + G > 0) result[i] = 3;
 else result[i] = 4;
    }
 
 return result;
}
Analysis summary