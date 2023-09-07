#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - coins[i]];
                }
            }
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                cout << dp[i][j] << ',';
            }
            cout << '\n';
        }

        return dp[0][amount];
    }
};

int main () {
    Solution S;
    vector<int> coins = {1,2,5};
    int amount = 5;
    int ans = S.change(amount, coins);
    cout << ans << '\n';
    return 0;
}