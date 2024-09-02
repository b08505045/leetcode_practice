#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            int target = -nums[i];
            unordered_map<int, int> umap;
            for(int j = i + 1; j < n; j++){
                if(umap.count(target - nums[j]) == 0){
                    umap[nums[j]] = j;
                }
                else{
                    res.push_back({nums[i], nums[umap[target - nums[j]]], nums[j]});
                }
            }
        }
        return res;
    }
};

int main () {
    Solution S;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = S.threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        cout << res[i][0] << ", " << res[i][1] << ", " << res[i][2];
        cout << "\n";
    }
    return 0;
}