#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    // dp with memoization
    int coinChange(vector<int>& coins, int amount) {
        if(!amount) return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int ans = helper(dp, coins, amount, n);
        for(int i = 0; i <= amount; i++){
            cout << dp[i] << ',';
        }
        cout << '\n';
        return ans;
    }

    int helper(vector<int>& dp, vector<int>& coins, int amount, int coin_size){
        if(dp[amount] != INT_MAX || !amount) return dp[amount];
        else{
            for(int i = 0; i < coin_size; i++){
                if(amount - coins[i] >= 0){
                    int change = helper(dp, coins, amount - coins[i], coin_size);
                    dp[amount] = (change == -1) ? dp[amount] : min(dp[amount], 1 + change);
                }
            }
            dp[amount] = (dp[amount] == INT_MAX) ? -1 : dp[amount];
            // cout << "dp[" << amount << "] = " << dp[amount] << '\n';
            return dp[amount];
        }
    }

    // dp with tabulation
    int coinChange_tabulation(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] >= 0){
                    dp[i] = (dp[i - coins[j]] != -1) ? min(dp[i], 1 + dp[i - coins[j]]) : dp[i];
                }
            }
            dp[i] = dp[i] == INT_MAX ? -1 : dp[i];
        }
        return dp[amount];
    }
};

int main () {
    Solution S;
    vector<int> coins1 = {1,2,5};
    vector<int> coins2 = {2};
    int amount1 = 11, amount2 = 3;
    int ans = S.coinChange(coins1, amount1);
    cout << ans << '\n';
    ans = S.coinChange_tabulation(coins2, amount2);
    cout << ans << '\n';
    return 0;
}