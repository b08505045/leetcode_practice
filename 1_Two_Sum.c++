#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            cout << target - nums[i] << ", ";
            if(umap.count(target - nums[i]) == 0){
                umap[nums[i]] = i;
            }
            else{
                res = {umap[target - nums[i]], i};
            }
        }
        return res;
    }
};

int main () {
    Solution S;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = S.twoSum(nums, target);
    for(int i = 0; i < res.size(); i++){
        cout << res[i];
    }
    return 0;
}