#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            // initialize dp[i]
            dp[i] = dp[i - 1] + arr[i];
            int localMax = arr[i];
            // For each iteration, find the subset length = j + 1 & end at arr[i] (max length = k)
            for(int j = 1; j < k && i - j >= 0; j++){
                // find max element in each subset
                localMax = max(localMax, arr[i - j]);
                // calculalte each subset's sum and return max of them
                if(i - j - 1 < 0){
                    dp[i] = dp[i] = max(dp[i], localMax * (j + 1));
                }
                else{
                    dp[i] = max(dp[i], localMax * (j + 1) + dp[i - j - 1]);
                }
            }
        }
        for(auto &v : dp){
            cout << v << ',';
        }
        cout << '\n';
        return dp[n - 1];
    }
};

int main () {
    Solution S;
    vector<int> arr1 = {1,15,7,9,2,5,10}, arr2 = {1,4,1,5,7,3,6,1,9,9,3}, arr3 = {1};
    int k1 = 3, k2 = 4, k3 = 1;
    int ans = S.maxSumAfterPartitioning(arr3, k3);
    cout << ans << '\n';
    return 0;
}   