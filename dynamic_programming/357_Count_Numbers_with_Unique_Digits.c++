#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // vector<int> dp(n + 1);  // dp[] : # number of repeated digit
        // vector<int> sum(n + 1); // sum[n] = sigma(dp[i]), i <= n
        // dp[0] = sum[0] = 0;
        // for(int i = 0; i <= n; i++){
            
        // }
        vector<int> dp(n);
        return helper(n, dp);
    }

    int helper(int n, vector<int> dp){
        
    }
};

int main () {
    return 0;
}