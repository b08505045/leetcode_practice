// prefix & suffix
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        for(int i = 0; i< n; i++) {
            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            cout << "pre = " << pre << ", suff = " << suff << '\n';
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};

int main () {
    Solution S;
    vector<int> nums1 = {-2,-3,4,-1,-2,1,5,-3};
    vector<int> nums2 = {-8,5,3,1,6};
    int ans = S.maxProduct(nums2);
    cout << ans << '\n';
    return 0;
}