#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // edge case
        if(triangle.size() == 0) return 0;
        if(triangle.size() == 1) return triangle[0][0];
        
        int n = triangle.size(), ans = 0, temp = 0;
        vector<int> arr(n, 0);
        arr[0] = triangle[0][0] + triangle[1][0];
        arr[1] = triangle[0][0] + triangle[1][1];

        // sum arr : dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 1]) + triangle[i][j]
        for(int i = 2; i < n; i++){
            arr[i] = arr[i - 1] + triangle[i][i];
            for(int j = i - 1; j > 0; j--){
                arr[j] = (arr[j] + triangle[i][j]) < (arr[j - 1] + triangle[i][j]) ? (arr[j] + triangle[i][j]) : (arr[j - 1] + triangle[i][j]);
            }
            arr[0] += triangle[i][0];
        }
        
        ans = arr[0];
        for(int i = 1; i < n; i++){
            ans = arr[i] >= ans ? ans : arr[i];
        }
        return ans;
    }
};

int main () {
    Solution S;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int ans = S.minimumTotal(triangle);
    cout << ans << '\n';
    return 0;
}