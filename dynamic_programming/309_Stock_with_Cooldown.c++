#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        
        return dp[n - 1];
    }
};

int main () {
    Solution S;
    vector<int> prices1 = {1,2,3,0,2};
    int ans = S.maxProfit(prices1);
    cout << ans << '\n';
    return 0;
}