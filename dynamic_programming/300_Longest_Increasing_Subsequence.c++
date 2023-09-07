// arr[i][j] : the longest increasing subsequence from index i when previous chosen element's index is j
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return nums.size();
        int n = nums.size(), ans = 1, index = 0;
        vector<vector<int>> arr(n, vector<int>(n,));
        for(int i = 0; i < n; i++){
            arr[i][i] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                arr[i][j]
            }
        }
        return ans;
    }
};

int main () {
    Solution S;
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {0,1,0,3,2,3};
    vector<int> nums3 = {7,7,7,7,7,7,7};
    int ans = S.lengthOfLIS(nums3);
    cout << ans << '\n';
    return 0;
}