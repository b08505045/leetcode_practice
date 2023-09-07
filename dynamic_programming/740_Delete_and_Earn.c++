#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int maxNumber = nums[n - 1];
        vector<int> amount(maxNumber + 1, 0);

        for(auto &v : nums){
            amount[v] += 1;
        }

        for(auto &v : amount){
            cout << v << ',';
        }
        cout << '\n';

        vector<int> dp(maxNumber + 1, 0);
        dp[1] = amount[1];

        for(int i = 2; i <= maxNumber; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + i * amount[i]);
        }

        for(auto &v : dp){
            cout << v << ',';
        }
        cout << '\n';
        return dp[maxNumber];
    }
};

int main () {
    Solution S;
    vector<int> nums1 = {2,2,3,3,3,4};
    vector<int> nums2 = {3,4,2};
    int ans = S.deleteAndEarn(nums2);
    cout << ans << '\n';
    return 0;
}   