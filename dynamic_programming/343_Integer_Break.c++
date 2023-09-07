#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        vector<int> dp(n + 1, 0);
        dp[2] = 2, dp[3] = 3;
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main () {
    Solution S;
    int n = 10;
    int ans = S.integerBreak(n);
    cout << ans << '\n';
    return 0;
}