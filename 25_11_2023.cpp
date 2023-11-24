/*Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
The elements can be large so return it modulo 109 + 7.*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
          vector<vector<long long>>v(n,vector<long long>(n,0));
          if(n==1) return {1};
          v[0][0] = 1;
          
          long long mod = 1000000007;
         
          for(int i=1; i<n; i++)
          {
            
               for(int j=0; j<=i; j++)
               {
                    if(j==0)
                      v[i][j] = v[i-1][j];
                  else
                     {
                      v[i][j]  = (( v[i-1][j-1])%mod+(v[i-1][j])%mod)%mod;
                        
                     }
               }
             
          }
          return v[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends