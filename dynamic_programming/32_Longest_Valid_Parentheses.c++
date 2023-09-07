#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int longestValidParentheses(const std::string& str) {
        int n = str.length(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // vector<vector<bool>> v(n, vector<bool> (n, false));
        for(int i = 1; i < n; i++){
            if(str[i] == ')' && str[i - 1] == '('){
                dp[i - 1][i] = 1;
                ans = 2;
            }
        }
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                for(int k = i; k < j; k++){
                    if(dp[i][k] == 1 && dp[k + 1][j] == 1){
                        dp[i][k] == 1;
                        ans = max(ans, j - i);
                        break;
                    }
                } 
            }
        }
        
        return 0;
    }
};

int main () {
    Solution S;
    string s = ")()())";
    int ans = S.longestValidParentheses(s);
    return 0;
}   