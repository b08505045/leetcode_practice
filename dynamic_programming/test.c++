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
        return 0;
    }
};

int main () {
    int n = 3;
    vector<vector<bool>> v(n, vector<bool> (n, false));
    for(auto &v1 : v){
        for(auto &v2 : v1){
            cout << v2 << ',';
        }
        cout << '\n';
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << ',';
        }
        cout << '\n';
    }
    return 0;
}   