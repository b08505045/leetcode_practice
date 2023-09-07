// hasn't solved edge case (m or n <=)

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;

        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> row(n);

        for(int i = 1; i < n; i++){
            row[i] = obstacleGrid[0][i] == 0 ? 1 : 0;
        }
        // for(int i = 1; i < row.size(); i++){
        //         cout << row[i] << ",";
        // }
        // cout << "\n";
        for(int i = 1; i < m; i++){
            row[1] = obstacleGrid[i][1] == 0 ? row[1] + 1 : 0;
            for(int j = 2; j < n; j++){
                row[j] = obstacleGrid[i][j] == 0 ? row[j] + row[j - 1] : 0;
            }
            // for(int i = 1; i < row.size(); i++){
            //     cout << row[i] << ",";
            // }
            // cout << "\n";
        }
        return row[n - 1];
    }
};

int main () {
    vector<vector<int>> obstacleGrid = {{0,0,0}, {0,0,1}, {0,0,0}};
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    cout << m << "\n" << n << "\n\n";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << obstacleGrid[i][j] << ",";
        }
        cout << "\n";
    }

    Solution S;
    int ans = S.uniquePathsWithObstacles(obstacleGrid);
    cout << "ans : " << ans << "\n";
    return 0;
}