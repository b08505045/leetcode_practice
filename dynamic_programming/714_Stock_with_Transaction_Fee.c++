#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        int ans = helper(prices, dp, 0, fee, true);
        for(auto &v1 : dp){
            for(auto &v2 : v1){
                cout << v2 << ',';
            }
            cout << '\n';
        }
        return ans;
    }
    
    int helper(vector<int>& prices, vector<vector<int>>& dp, int day, int fee, bool canBuy){
        if(day > prices.size() - 1) return 0;
        if(dp[day][canBuy]) return dp[day][canBuy];

        if(canBuy){
            return dp[day][canBuy] = max(helper(prices, dp, day + 1, fee, false) - prices[day] - fee, helper(prices, dp, day + 1, fee, true));
        }
        else{
            return dp[day][canBuy] = max(helper(prices, dp, day + 1, fee, true) + prices[day], helper(prices, dp, day + 1, fee, false));
        }
    }
    
    int maxProfit_tabulation(vector<int>& prices, int fee){
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        dp[n - 1][0] = prices[n - 1], dp[n - 1][1] = 0;
        for(int i = n - 2; i >= 0; i--){
            dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + prices[i]);
            dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] - prices[i] - fee);
        }
        return dp[0][1];
    }
};

int main () {
    Solution S;
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int ans = S.maxProfit_tabulation(prices, fee);
    cout << ans << '\n';
    return 0;
}   