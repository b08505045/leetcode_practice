#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        if(matrix.size() == 1){
            int n = matrix[0].size();
            for(int i = 0; i < n; i++){
                if(matrix[0][i] == '1') return 1;
            }
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size(), temp = 0, ans = 0;
        // cout << "size = " << m << '\n';
        vector<int> arr(n, 0);
        for(int i = 0; i < m; i++){
            arr[i] = int(matrix[0][i] - '0');
            ans = max(arr[i], ans);
        }
        
        for(int i = 1; i < m; i++){
            arr[0] = int(matrix[i][0] - '0');
            ans = max(ans, arr[0]);
            for(int j = 1; j < n; j++){
                if(int(matrix[i][j] - '0') == 0) arr[j] == 0;
                else{
                    arr[j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
                }
                ans = max(ans, arr[i][j]);
            }
        }
        return pow(ans, 2);
    }
};

int main () {
    Solution S;
    vector<vector<char>> matrix1 = {{'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, {'1','0','0','1','0'}};
    vector<vector<char>> matrix2 = {{'1','1','1','1','0'}, {'1','1','1','1','0'}, {'1','1','1','1','1'}, {'1','1','1','1','1'}, {'0','0','1','1','1'}};
    vector<vector<char>> matrix3 = {{'0', '1'}, {'1', '0'}};
    vector<vector<char>> matrix4 = {{'0'}};
    int ans = S.maximalSquare(matrix2);
    cout << ans << '\n';
    return 0;
}