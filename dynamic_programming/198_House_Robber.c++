#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size(), an_1 = nums[0], an_2 = max(nums[0], nums[1]), temp = 0;
        for(int i = 2; i < n; i++){
            temp = an_1;
            an_1 = an_2;
            an_2 = an_2 > temp + nums[i] ? an_2 : temp + nums[i];
            cout << "temp = " << temp << ", an_1 = " << an_1 << "an_2 = " << an_2 << '\n';
        }
        return an_2;
    }
};

int main () {
    Solution S;
    vector<int> nums1 = {2,7,9,3,1};
    vector<int> nums2 = {1,2,3,1};
    vector<int> nums3 = {2,1,1,2};
    vector<int> nums4 = {2,1,1,1};
    int ans = S.rob(nums4);
    cout << ans << '\n';
    return 0;
}